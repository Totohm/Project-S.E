// Disable Error C4996 that occur when using Boost.Signals2.
#ifdef _DEBUG
#define _SCL_SECURE_NO_WARNINGS
#endif

#include "kinect_management.cpp"

//MainWindow UI

#include "mainwindow.h"
#include <QApplication>


//END MainWindow UI

//SHIT


//#include "kinect2_grabber.h"
#include <pcl/visualization/pcl_visualizer.h>
#include <Windows.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
using namespace std;
typedef pcl::PointXYZRGBA PointType;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.set_UI_Images();
    w.show();










    int i = 1;

    // PCL Visualizer
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(
        new pcl::visualization::PCLVisualizer( "Point Cloud Viewer" ) );
    viewer->setCameraPosition( 0.0, 0.0, -2.5, 0.0, 0.0, 0.0 );

    // Point Cloud
    pcl::PointCloud<PointType>::ConstPtr cloud;

    // Retrieved Point Cloud Callback Function
    boost::mutex mutex;


    boost::function<void( const pcl::PointCloud<PointType>::ConstPtr& )> function =
        [&cloud, &mutex]( const pcl::PointCloud<PointType>::ConstPtr& ptr ){
            boost::mutex::scoped_lock lock( mutex );

            /* Point Cloud Processing */

            cloud = ptr->makeShared();

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

    // Start Grabber
    grabber->start();

    while( !viewer->wasStopped() ){
        // Update Viewer
        viewer->spinOnce();

        boost::mutex::scoped_try_lock lock( mutex );
        if( lock.owns_lock() && cloud ){
            // Update Point Cloud
            pcl::PointCloud<PointType>::Ptr cloud_filtered (new pcl::PointCloud<PointType>);
            // Create the filtering object
            pcl::PassThrough<PointType> pass;
            pass.setFilterFieldName ("z");
            pass.setFilterLimits (0.5, 1.0);
            //pass.setFilterLimitsNegative (true);
            pass.setInputCloud (cloud);
            pass.filter (*cloud_filtered);
            stringstream ss;
            ss << ".\\omair-" << i << ".ply";
            string filename = ss.str();
            i++;
            //std::cout<<filename<<std::endl;
            pcl::io::savePLYFile(filename, *cloud_filtered);
            Sleep(5000);

            if( !viewer->updatePointCloud( cloud_filtered, "cloud" ) ){
                viewer->addPointCloud( cloud_filtered, "cloud" );
                viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "cloud");
            }
        }
    }

    // Stop Grabber
    grabber->stop();

    // Disconnect Callback Function
    if( connection.connected() ){
        connection.disconnect();
    }

    //UI Requierement






    return a.exec();
}
