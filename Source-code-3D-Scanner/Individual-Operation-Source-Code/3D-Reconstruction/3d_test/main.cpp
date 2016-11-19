#include <QCoreApplication>
#include <pcl/visualization/pcl_visualizer.h>
#include <Windows.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/search/kdtree.h>
#include <iostream>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/mls.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/surface/vtk_smoothing/vtk_mesh_smoothing_laplacian.h>
#include <pcl/surface/poisson.h>


int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);


//////////// INITIALIZATION AND IMPORT THE POINT CLOUD


int D=10;
//WE INITIALIZE THE DEPTH VALUE FOR THE POISSON ALGORITHM

pcl :: PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl :: PointCloud<pcl ::PointXYZ>) ;
pcl :: PointCloud<pcl::PointNormal>::Ptr cloudwithnormals (new pcl::PointCloud<pcl :: PointNormal >) ;
pcl :: search :: KdTree<pcl :: PointXYZ >:: Ptr tree ;
//WE CREATE THE VARIABLES FOR THE REST OF THE CODE

std :: cout<< " Loading file . . ." << endl ;
//IN THE CODE, WE ADD SOME DISPLAY ON THE SCREEN TO KNOW WHAT THE PROGRAM IS DOING BECAUSE IT S VERY LONG

pcl :: PCLPointCloud2 cloudblob ;
pcl :: io :: loadPLYFile ( "C:\\Users\\dreve\\Downloads\\horse.ply" , cloudblob);
std :: cout << "Hello" << endl ;
pcl ::fromPCLPointCloud2(cloudblob, *cloud);
std :: cout << "Program is Running" << endl ;
//WE LOAD THE POINT CLOUD


//////////// APPLY THE MEAN LEAST SQUARE SMOOTHING


std :: cout <<"Smoothing with MLS . . . "<< std :: endl;
pcl :: MovingLeastSquares<pcl :: PointXYZ ,pcl :: PointXYZ> mls ;
mls.setInputCloud (cloud) ;
mls.setPolynomialFit (true) ;
mls.setSearchRadius (0.01) ;
mls.setPolynomialOrder(2);
//WE SET THE PARAMETERS OF THE FILTER USED FOR THE SMOOTHING

//mls.setUpsamplingMethod (pcl :: MovingLeastSquares<pcl :: PointXYZ, pcl ::PointXYZ>::VOXEL_GRID_DILATION);
//mls.setUpsamplingRadius(0.005);
//mls.setUpsamplingStepSize(0.003);
//OUR TESTS ABOUT THE UPSAMPLING

pcl :: PointCloud<pcl :: PointXYZ >:: Ptr mls_cloud (new pcl ::PointCloud<pcl :: PointXYZ >() ) ;
mls.process (*mls_cloud) ;
std :: cout << "Done " << std :: endl;
//WE PROCESS THE FILTERING


/////////// APPLY THE NORMAL ESTIMATION AND CONCATENATE THE POINT CLOUDS


std :: cout <<"Create search tree . . ."<<endl;
tree.reset (new pcl :: search :: KdTree<pcl :: PointXYZ>(false));
tree->setInputCloud(mls_cloud) ;
std :: cout <<"Done"<<endl ;
//WE CREATE THE RESEARCH TREE FOR THE NORMAL ESTIMATION

std :: cout<<"Normal estimation . . . "<<endl ;
pcl :: NormalEstimation <pcl :: PointXYZ, pcl :: Normal> n ;
pcl :: PointCloud<pcl :: Normal> :: Ptr normals (new pcl :: PointCloud<pcl ::Normal>() ) ;
//WE CREATE THE VARIABLES FOR THE NORMAL ESTIMATION

n.setInputCloud(mls_cloud);
n.setSearchMethod(tree);
n.setKSearch(10);
n.compute(*normals);
std :: cout <<"Done"<<endl ;
//WE SETUP THE ESTIMATION AND CREATE IT


std :: cout<< "Concatenate XYZ and normal information . . . "<< std :: endl ;
pcl :: concatenateFields(*mls_cloud, *normals , *cloudwithnormals);
std :: cout <<"Done"<< std :: endl ;
//WE CONCATENATE THE NORMAL ESTIMATION AND THE SMOOTH POINT CLOUD

//////// APPLY THE POISSON ALGORITHM


std :: cout<< "Poisson . . . "<< std :: endl ;
pcl :: Poisson<pcl :: PointNormal> poisson;
poisson.setDepth (D) ;
poisson.setSamplesPerNode(1);
//poisson.setScale(0.9);
poisson.setInputCloud (cloudwithnormals) ;
boost :: shared_ptr<pcl :: PolygonMesh> triangles (new pcl :: PolygonMesh );
poisson.reconstruct (*triangles) ;
std :: cout<< "Done"<< std :: endl ;
//WE SETUP THE POISSON ALGORITHM AND WE APPLY IT


/////// APPLY THE LAPLACIAN SMOOTHING


std :: cout << "Begin Laplacian Smoothing . . ."<< std :: endl;
pcl :: PolygonMesh output ;
pcl :: MeshSmoothingLaplacianVTK vtk ;
vtk.setInputMesh (triangles) ;
vtk.setNumIter(20000);
vtk.setConvergence(0.0001);
vtk.setRelaxationFactor (0.0001) ;
vtk.setFeatureEdgeSmoothing (true) ;
vtk.setFeatureAngle (M_PI/5 ) ;
vtk.setBoundarySmoothing (true) ;
vtk.process(output) ;
std :: cout << "Done . " << std :: endl;
//WE SETUP A LAPLACIAN SMOOTHING AND WE APPLY IT

/////////// SAVE THE MESH

std :: cout << "Save the Mesh . . ."<< std :: endl;
pcl :: io :: savePLYFile("Mesh1.ply", *triangles);
std :: cout << "Done...Finally !!"<< std :: endl;
//WE SAVE THE MESH IN ORDER TO COMPARE OUR RESULTS OR TO APPLY EXTERNAL CHANGES


////////// DISPLAY THE OBJECT


pcl::visualization::PCLVisualizer *p;
int vPort1 = 1;

p = new pcl::visualization::PCLVisualizer (argc, argv, "FUCK YOU PCL !!!");
p->removePolygonMesh("triangles", vPort1);

p->createViewPort (0.0, 0, 1.0, 1.0, vPort1);

p->addPolygonMesh(*triangles, "triangles", vPort1);

p->resetCameraViewpoint();
p->spin();
return (0);
//WE CREATE A WINDOW TO DISPLAY THE RESULTING MESH

    return 0;
}
