// Disable Error C4996 that occur when using Boost.Signals2.
#ifdef _DEBUG
#define _SCL_SECURE_NO_WARNINGS
#endif

#include "kinect2_grabber.h"
#include <pcl/visualization/pcl_visualizer.h>
#include <Windows.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include<QElapsedTimer>

#include <thread>
#include <vector>
#include <chrono>

using namespace std;
typedef pcl::PointXYZRGBA PointType;
int i = 1;

void tmr(bool* capture_parameter){
    QElapsedTimer timer;
    timer.start();
    while(true){

        if(timer.elapsed() >= 2000)
        {
            //save
            *capture_parameter = true;
            cout<< "Bla"<<endl;
            timer.restart();
        }

        this_thread::sleep_for (std::chrono::seconds(1));
    }
}
int main( int argc, char* argv[] )
{
    bool* cap = new bool;
    *cap = true;
    // boost::shared_ptr<bool> cap(ca);



    thread timer_t(tmr, cap);

    // bool counter = false;


    //    timer.start();
    //    if (timer.elapsed()== 2000)
    //    {
    //        counter = true;
    //        timer.start();
    //    }

    // declaring a vector
    vector<pcl::PointCloud<PointType>> filtered_data;







    // PCL Visualizer
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(
                new pcl::visualization::PCLVisualizer( "Point Cloud Viewer" ) );
    viewer->setCameraPosition( 0.0, 0.0, -2.5, 0.0, 0.0, 0.0 );

    // Point Cloud
    pcl::PointCloud<PointType>::ConstPtr cloud;

    // Retrieved Point Cloud Callback Function
    boost::mutex mutex;


    boost::function<void( const pcl::PointCloud<PointType>::ConstPtr& )> function =
            [&cloud, &mutex, &cap, &filtered_data]( const pcl::PointCloud<PointType>::ConstPtr& ptr ){
        boost::mutex::scoped_lock lock( mutex );

        /* Point Cloud Processing */

        cloud = ptr->makeShared();
        // Start Grabber
        if(*cap == true){
            *cap = false;
            cout<<"Bitch"<<endl;
            filtered_data.push_back(*cloud);
        }

        //std::cout << cloud->size() << std::endl;
        // Update Point Cloud
        //            pcl::PointCloud<PointType>::Ptr cloud_filtered (new pcl::PointCloud<PointType>);
        //            // Create the filtering object
        //            pcl::PassThrough<PointType> pass;
        //            pass.setFilterFieldName ("z");
        //            pass.setFilterLimits (0.5, 1.0);
        //            //pass.setFilterLimitsNegative (true);
        //            pass.setInputCloud (cloud);
        //            pass.filter (*cloud_filtered);

    };

    // Kinect2Grabber
    boost::shared_ptr<pcl::Grabber> grabber = boost::make_shared<pcl::Kinect2Grabber>();

    // Register Callback Function
    boost::signals2::connection connection = grabber->registerCallback( function );

    grabber->start();

    while( !viewer->wasStopped() ){
        // Update Viewer

        //        timer.start();
        //        if (timer.elapsed()== 2000)
        //        {
        //            counter = true;
        //            timer.restart();
        //        }
        viewer->spinOnce();

        boost::mutex::scoped_try_lock lock( mutex );
        if( lock.owns_lock() && cloud ){
            // Update Point Cloud
            pcl::PointCloud<PointType>::Ptr cloud_filtered (new pcl::PointCloud<PointType>);
            // Create the filtering object
            pcl::PassThrough<PointType> pass;
            //
            pass.setFilterFieldName ("z");
            pass.setFilterLimits (0.5, 1.0);

            pass.setFilterFieldName ("y");
            pass.setFilterLimits (-3.0,3.0);

            pass.setFilterFieldName ("x");
            pass.setFilterLimits (-0.5, 0.5);

            //pass.setFilterLimitsNegative (true);
            pass.setInputCloud (cloud);
            pass.filter (*cloud_filtered);

            //                   if (counter == true)
            //                   {
            //                 filtered_data.push_back(*cloud_filtered);
            //                   counter == false;
            //                   }
            //            stringstream ss;
            //            ss << ".\\mohit-" << i << ".ply";
            //            string filename = ss.str();
            //            i++;
            //            std::cout<<filename<<std::endl;
            //            pcl::io::savePLYFile(filename, *cloud_filtered);
            //            Sleep(300);

            if( !viewer->updatePointCloud( cloud_filtered, "cloud" ) ){
                viewer->addPointCloud( cloud_filtered, "cloud" );
                viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "cloud");
            }
        }//while loop ends
    }

    // Stop Grabber
    grabber->stop();
    
    // Disconnect Callback Function
    if( connection.connected() ){
        connection.disconnect();
    }
    timer_t.join();

    return 1;
}
