#include "reconstructionproject.h"

//-----------------------------------------------------------------------------
//*********************CONSTRUCTOR AND DESTRUCTOR******************************
//-----------------------------------------------------------------------------

ReconstructionProject::ReconstructionProject()
{

    u_octree_depth = 10;

    u_radius_search = 0.25;

    u_mu = 10;

    u_max_nearest_neighbor = 20;

    u_max_surface_angle = M_PI;

    u_min_angle = M_PI/10;

    u_max_angle = M_PI;

    u_normal_consistency = false;
}

ReconstructionProject::~ReconstructionProject()
{

}

//-----------------------------------------------------------------------------
//***********************ACCESSORS AND MUTATORS********************************
//-----------------------------------------------------------------------------

unsigned int ReconstructionProject::getU_octree_depth() const
{
    return u_octree_depth;
}

void ReconstructionProject::setU_octree_depth(unsigned int value)
{
    u_octree_depth = value;
}

float ReconstructionProject::getU_radius_search() const
{
    return u_radius_search;
}

void ReconstructionProject::setU_radius_search(float value)
{
    u_radius_search = value;
}

float ReconstructionProject::getU_mu() const
{
    return u_mu;
}

void ReconstructionProject::setU_mu(float value)
{
    u_mu = value;
}

unsigned int ReconstructionProject::getU_max_nearest_neighbor() const
{
    return u_max_nearest_neighbor;
}

void ReconstructionProject::setU_max_nearest_neighbor(unsigned int value)
{
    u_max_nearest_neighbor = value;
}

double ReconstructionProject::getU_max_surface_angle() const
{
    return u_max_surface_angle;
}

void ReconstructionProject::setU_max_surface_angle(double value)
{
    u_max_surface_angle = value;
}

double ReconstructionProject::getU_min_angle() const
{
    return u_min_angle;
}

void ReconstructionProject::setU_min_angle(double value)
{
    u_min_angle = value;
}

double ReconstructionProject::getU_max_angle() const
{
    return u_max_angle;
}

void ReconstructionProject::setU_max_angle(double value)
{
    u_max_angle = value;
}

bool ReconstructionProject::getU_normal_consistency() const
{
    return u_normal_consistency;
}

void ReconstructionProject::setU_normal_consistency(bool value)
{
    u_normal_consistency = value;
}

//-----------------------------------------------------------------------------
//*******************************BASIC FUNCTIONS*******************************
//-----------------------------------------------------------------------------

//******************************SMOOTHING FUNCTION*****************************

/*pcl :: PointCloud<pcl :: PointXYZ >:: Ptr
ReconstructionProject::smoothing
(pcl :: PointCloud<pcl :: PointXYZ >:: Ptr)
{

}
*/

//***************************NORMAL ESTIMATION FUNCTION************************

pcl :: PointCloud<pcl::PointNormal>::Ptr
ReconstructionProject::normal_estimation
(pcl :: PointCloud<pcl :: PointXYZ >:: Ptr input_point_cloud)
{

    // Creating an instance of the class Normal Estimation
    pcl :: NormalEstimationOMP<pcl :: PointXYZ, pcl :: Normal> t_n;

    //Reading and Creating a pointer "normals" and reserving space on the
    //memory It's datatype Normal because we'll create a normal estimation
    pcl :: PointCloud<pcl :: Normal> :: Ptr t_normals
            (new pcl :: PointCloud<pcl ::Normal>() ) ;

    //Initialize the scheduler and set the number of threads to use.
    t_n.setNumberOfThreads (8);

    //- Inserting "cloud" as an input to calculate the Normal Estimation
    t_n.setInputCloud (input_point_cloud);

    //Setting the sphere radius that is to be used
    //for determining the k-nearest neighbours
    t_n.setRadiusSearch (0.05);

    //EIGENVECTOR
    Eigen::Vector4f t_centroid;

    compute3DCentroid (*input_point_cloud, t_centroid);

    t_n.setViewPoint (t_centroid[0], t_centroid[1], t_centroid[2]);

    t_n.compute (*t_normals);

    //-  Creating a pointer (output_point_cloud) of the datatype PointNormal
    //and reserving space on the memory
    pcl :: PointCloud<pcl::PointNormal>::Ptr t_output_point_cloud
            (new pcl::PointCloud<pcl :: PointNormal >) ; ///////////////// should we delete the variable ?

    for (size_t i = 0; i < t_normals->size (); ++i)
    {
        t_normals->points[i].normal_x *= -1;

        t_normals->points[i].normal_y *= -1;

        t_normals->points[i].normal_z *= -1;
    }

    // Merging the Normal Estimation output & the point cloud,
    //saved in "t_output_point_cloud"
    pcl :: concatenateFields(*t_normals, *input_point_cloud ,
                             *t_output_point_cloud);

    return (t_output_point_cloud);
}

//***************************POISSON ALGORITHM*********************************

boost :: shared_ptr<pcl :: PolygonMesh>
ReconstructionProject::poisson_algorithm
(pcl :: PointCloud<pcl::PointNormal>::Ptr input_point_cloud)
{
    //Creating an object to Poisson of datatype PointNormal
    pcl :: Poisson<pcl :: PointNormal> poisson;

    //Setting the value of the depth of the octree
    poisson.setDepth (u_octree_depth) ;

    // Creating a smart pointer (triangles) of datatype PolygonMesh
    //and allocate space on memory
    boost :: shared_ptr<pcl :: PolygonMesh> t_triangles
            (new pcl :: PolygonMesh );                          ///////////////// should we delete the variable ?

    //- Inserting "input_point_cloud" as an input for the Poisson method
    poisson.setInputCloud (input_point_cloud) ;

    //Perfom the surface reconstruction method and saved in "triangles"
    poisson.reconstruct (*t_triangles) ;

    return(t_triangles);
}

//****************************GREEDY TRIANGULATION*****************************

boost :: shared_ptr<pcl :: PolygonMesh>
ReconstructionProject::greedy_triangulation
(pcl :: PointCloud<pcl::PointNormal>::Ptr input_point_cloud)
{
    std :: cerr << ">> GreedyProjectionTriangulation...";
    pcl :: GreedyProjectionTriangulation<pcl :: PointNormal> gt;

    boost :: shared_ptr<pcl :: PolygonMesh> t_triangles
            (new pcl :: PolygonMesh );                          ///////////////// should we delete the variable ?

    gt.setInputCloud(input_point_cloud);

    gt.setSearchRadius (u_radius_search) ; //maximum allowable length of an edge of a triangle

    gt.setMu (u_mu) ; //multiplied with the distance to the nearest neighbour, accounts for the variable density

    gt.setMaximumNearestNeighbors (u_max_nearest_neighbor) ;//no. of nearest neighbours to cater to, within the search radius

    gt.setMaximumSurfaceAngle (u_max_surface_angle) ; // angle between the normal of subject point and the sel point

    gt.setMinimumAngle (u_min_angle) ; // not alwasy followed? when is it not?

    gt.setMaximumAngle(u_max_angle);//the angle between the x-axis of the subject point and the....
    //...the maximum angle in a triangle

    gt.setNormalConsistency ( u_normal_consistency ) ;//?

    gt.reconstruct(*t_triangles);

    return (t_triangles);

}

//-----------------------------------------------------------------------------
//*******************************CALLED FUNCTION*******************************
//-----------------------------------------------------------------------------

boost :: shared_ptr<pcl :: PolygonMesh>
ReconstructionProject::reconstruction(bool method, bool smoothing)
{

    if(smoothing == true)
    {
        //d_icp_pointcloud =   smoothing(d_icp_pointcloud); ////////////////////change by the variable from the database
    }
    //*******************************TEST**************************************
    pcl :: PCLPointCloud2 cloudblob ;

    pcl :: io :: loadPCDFile ( "C:\\Users\\dreve\\Documents\\VIBOT_LC\\Software Eng\\PCL Project\\PCLEXAMPLES\\untitled8\\chef.pcd" , cloudblob); ///////////////////DELETE !!!!

    pcl :: PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl :: PointCloud<pcl ::PointXYZ>) ;

    pcl ::fromPCLPointCloud2(cloudblob, *cloud);
    //*****************************END TEST************************************
    pcl :: PointCloud<pcl::PointNormal>::Ptr t_output_point_cloud_normal_estimation
            (new pcl::PointCloud<pcl :: PointNormal >) ; ///////////////// should we delete the variable ?

    t_output_point_cloud_normal_estimation = normal_estimation(cloud);

    boost :: shared_ptr<pcl :: PolygonMesh> t_output_recon (new pcl :: PolygonMesh );


    if(method == true)
    {
        t_output_recon =  poisson_algorithm(t_output_point_cloud_normal_estimation);
    }
    else
    {
        t_output_recon =  greedy_triangulation(t_output_point_cloud_normal_estimation);
    }

    return(t_output_recon);

}
