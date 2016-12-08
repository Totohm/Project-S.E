#include <QCoreApplication>
#include <pcl/io/vtk_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <Windows.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/search/kdtree.h>
#include <iostream>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/mls.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/surface/vtk_smoothing/vtk_mesh_smoothing_laplacian.h>
#include <pcl/surface/poisson.h>
#include <pcl/features/normal_3d_omp.h>

//using namespace std;


int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////           LOADING FILE - INITIALIZATION            /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-  Reading and Creating a point cloud pointer (cloud) and reserving space on the memory
    pcl :: PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl :: PointCloud<pcl ::PointXYZ>) ;

    std :: cout<< " Loading f i l e . . ." << endl ;
    //- Creating an instance of the class PCLPointCloud2
    pcl :: PCLPointCloud2 cloudblob ;

    //- Loading file containing point clouds and pass it to "cloudlob"
    pcl :: io :: loadPLYFile ( "C:\\Users\\mcgen\\Documents\\FinalResult2_mesh.ply" , cloudblob);

    std :: cout << "hello" << endl ;
    // Copy the values of the point cloud to "cloud"
    pcl ::fromPCLPointCloud2(cloudblob, *cloud);

    //cerr <<" Done . \ n";
    std :: cout << "Running" << endl ;

    int D=10;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////             NORMAL ESTIMATION              //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std :: cout<<" Normal estimation . . . "<<endl ;
    // Creating an instance of the class Normal Estimation
    pcl :: NormalEstimationOMP<pcl :: PointXYZ, pcl :: Normal> n;

    // Reading and Creating a pointer "normals" and reserving space on the memory  (It's datatype Normal because we will create a normal estimation
    pcl :: PointCloud<pcl :: Normal> :: Ptr normals (new pcl :: PointCloud<pcl ::Normal>() ) ;
/*
n.setInputCloud(cloud);
n.setSearchMethod(tree);
n.setKSearch(0);
*/
    //Initialize the scheduler and set the number of threads to use.
    n.setNumberOfThreads (1); //chef 8
    //- Inserting "cloud" as an input to calculate the Normal Estimation
    n.setInputCloud (cloud);

    //Setting the sphere radius that is to be used for determining the k-nearest neighbours
    n.setRadiusSearch (0.4); //chef 0.08

    //EIGENVECTOR
    Eigen::Vector4f centroid;
    compute3DCentroid (*cloud, centroid);
    n.setViewPoint (centroid[0], centroid[1], centroid[2]);
    n.compute (*normals);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////                CONCATENATE                 ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-  Creating a pointer (cloudwithnormals) of the class ***** and reserving space on the memory
    pcl :: PointCloud<pcl::PointNormal>::Ptr cloudwithnormals (new pcl::PointCloud<pcl :: PointNormal >) ;

    for (size_t i = 0; i < normals->size (); ++i)
    {
        normals->points[i].normal_x *= -1;
        normals->points[i].normal_y *= -1;
        normals->points[i].normal_z *= -1;
   }

    std :: cout <<"Done"<<endl ;

    std :: cout<< "Concatenate XYZ and normal information . . . "<< std :: endl ;

    // Merging the Normal Estimation output & the point cloud, saved in "cloudwithnormals"
    pcl :: concatenateFields(*normals, *cloud , *cloudwithnormals);

    std :: cout <<"Done"<< std :: endl ;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////                  POISSON                   ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std :: cout<<" Poisson . . . "<<endl ;

    //Creating an object to Poisson of datatype PointNormal
    pcl :: Poisson<pcl :: PointNormal> poisson;

    //Setting the value of the depth of the octree
    poisson.setDepth (D) ;

    //- Inserting "cloudwithnormals" as an input for the Poisson method
    poisson.setInputCloud (cloudwithnormals) ;

    // Creating a smart pointer (triangles) of datatype PolygonMesh and allocate space on memory
    boost :: shared_ptr<pcl :: PolygonMesh> triangles (new pcl :: PolygonMesh );

    //Perfom the surface reconstruction method and saved in "triangles"
    poisson.reconstruct (*triangles) ;
    std :: cout<<" Donen . . . "<<endl ;

//Saving File
/*
std :: cout << "Saving File" << std :: endl;
pcl::io::savePCDFile ("mes.pcd", *triangles,false);
std :: cout << "Done . " << std :: endl;
*/
//Create a PCLVisualizer object

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////               VISUALIZATION                ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            pcl::visualization::PCLVisualizer *p;
            int vPort1 = 1;

            p = new pcl::visualization::PCLVisualizer (argc, argv, "PLEASE WORK");
            //p->removePolygonMesh("triangles", vPort1);

            p->createViewPort (0.0, 0, 1.0, 1.0, vPort1);

            p->addPolygonMesh(*triangles, "triangles", vPort1);

            p->resetCameraViewpoint();
            p->spin();
            return (0);


    return 0;
}
