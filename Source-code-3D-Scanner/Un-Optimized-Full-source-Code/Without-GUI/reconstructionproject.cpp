#include "reconstructionproject.h"

//-----------------------------------------------------------------------------
//*********************CONSTRUCTOR AND DESTRUCTOR******************************
//-----------------------------------------------------------------------------

ReconstructionProject::ReconstructionProject()
{
    /*
     * Constructor of the Class : we set the initial values for our Parameters (check the header file to have the description)
     */

    u_octree_depth = 10;
    //Set the default value for the u_octree_depth variable

    u_radius_search = 0.25;
    //Set the default value for the u_radius_search variable

    u_mu = 10;
    //Set the default value for the u_mu variable

    u_max_nearest_neighbor = 20;
    //Set the default value for the u_max_nearest_neighbor variable

    u_max_surface_angle = M_PI;
    //Set the default value for the u_max_surface_angle variable

    u_min_angle = M_PI/10;
    //Set the default value for the u_min_angle variable

    u_max_angle = M_PI;
    //Set the default value for the u_max_angle variable

    u_normal_consistency = false;
    //Set the default value for the u_normal_consistency variable
}

ReconstructionProject::~ReconstructionProject()
{
    /*
     * Destructor of the Class
     */
}

//-----------------------------------------------------------------------------
//***********************ACCESSORS AND MUTATORS********************************
//-----------------------------------------------------------------------------

unsigned int ReconstructionProject::getU_octree_depth() const
{
    /*
     * Accessor for the u_octree_depth parameter
     */

    return u_octree_depth;
}

void ReconstructionProject::setU_octree_depth(unsigned int value)
{   
    /*
     * Mutator for the u_octree_depth parameter
     */

    u_octree_depth = value;
}

float ReconstructionProject::getU_radius_search() const
{
    /*
     * Accessor for the u_radius_search parameter
     */

    return u_radius_search;
}

void ReconstructionProject::setU_radius_search(float value)
{
    /*
     * Mutator for the u_radius_search parameter
     */

    u_radius_search = value;
}

float ReconstructionProject::getU_mu() const
{
    /*
     * Accessor for the u_mu parameter
     */

    return u_mu;
}

void ReconstructionProject::setU_mu(float value)
{
    /*
     * Mutator for the u_mu parameter
     */

    u_mu = value;
}

unsigned int ReconstructionProject::getU_max_nearest_neighbor() const
{
    /*
     * Accessor for the u_max_nearest_neighbor parameter
     */

    return u_max_nearest_neighbor;
}

void ReconstructionProject::setU_max_nearest_neighbor(unsigned int value)
{
    /*
     * Mutator for the u_max_nearest_neighbor parameter
     */

    u_max_nearest_neighbor = value;
}

double ReconstructionProject::getU_max_surface_angle() const
{
    /*
     * Accessor for the u_max_surface_angle parameter
     */

    return u_max_surface_angle;
}

void ReconstructionProject::setU_max_surface_angle(double value)
{
    /*
     * Mutator for the u_max_surface_angle parameter
     */

    u_max_surface_angle = value;
}

double ReconstructionProject::getU_min_angle() const
{
    /*
     * Accessor for the u_min_angle parameter
     */

    return u_min_angle;
}

void ReconstructionProject::setU_min_angle(double value)
{
    /*
     * Mutator for the u_min_angle parameter
     */

    u_min_angle = value;
}

double ReconstructionProject::getU_max_angle() const
{
    /*
     * Accessor for the u_max_angle parameter
     */

    return u_max_angle;
}

void ReconstructionProject::setU_max_angle(double value)
{
    /*
     * Mutator for the u_max_angle parameter
     */

    u_max_angle = value;
}

bool ReconstructionProject::getU_normal_consistency() const
{
    /*
     * Accessor for the u_normal_consistency parameter
     */

    return u_normal_consistency;
}

void ReconstructionProject::setU_normal_consistency(bool value)
{
    /*
     * Mutator for the u_normal_consistency parameter
     */

    u_normal_consistency = value;
}

//-----------------------------------------------------------------------------
//*******************************"TOOL" FUNCTIONS******************************
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
    /*
     * This "tool" function is used to compute the normal estimation of a point
     * cloud, used in the Poisson algorithm and in the greedy triangulation
     * method. We need in input a XYZ point cloud and it returns us a normal
     * point cloud.
     */

    pcl :: NormalEstimationOMP<pcl :: PointXYZ, pcl :: Normal> t_n;
    // Create an instance of the class Normal Estimation

    pcl :: PointCloud<pcl :: Normal> :: Ptr t_normals
            (new pcl :: PointCloud<pcl ::Normal>() ) ;
    //Read and Create a pointer "t_normals" and reserving space in the memory It's datatype Normal because we'll create a normal point cloud

    t_n.setNumberOfThreads (8);
    //Initialize the scheduler and set the number of threads to use.

    t_n.setInputCloud (input_point_cloud);
    //Insert the wanted point cloud as an input to the Normal Estimation

    t_n.setRadiusSearch (0.05);
    //Set the sphere radius that is to be used for determining the k-nearest neighbors

    Eigen::Vector4f t_centroid;
    //Create an eigenvector to store the centroid

    compute3DCentroid (*input_point_cloud, t_centroid);
    //Compute the centroid of the point cloud

    t_n.setViewPoint (t_centroid[0], t_centroid[1], t_centroid[2]);

    t_n.compute (*t_normals);
    //Compute the Normals from the point cloud

    pcl :: PointCloud<pcl::PointNormal>::Ptr t_output_point_cloud
            (new pcl::PointCloud<pcl :: PointNormal >) ; ///////////////// should we delete the variable ?
    //Create a pointer (t_output_point_cloud) of the datatype PointNormal and reserve space on the memory

    for (size_t i = 0; i < t_normals->size (); ++i)
    {
    //Change the sign of our normals
        t_normals->points[i].normal_x *= -1;

        t_normals->points[i].normal_y *= -1;

        t_normals->points[i].normal_z *= -1;
    }

    pcl :: concatenateFields(*t_normals, *input_point_cloud ,
                             *t_output_point_cloud);
    //Merging the Normal Estimation output & the point cloud and saved it in "t_output_point_cloud"

    return (t_output_point_cloud);
    //Return the Normal Estimation
}

//***************************POISSON ALGORITHM*********************************

boost :: shared_ptr<pcl :: PolygonMesh>
ReconstructionProject::poisson_algorithm
(pcl :: PointCloud<pcl::PointNormal>::Ptr input_point_cloud)
{
    /*
     * This "tool" function is used to apply the Poisson algorithm, a powerful
     * way to reconstruct directly a watertight mesh. This algorithm is very sensitive
     * to noise and it has some problems to reconstruct the ... volume. It needs
     * as input a normal point cloud and it returns a polygon mesh.
     */

    pcl :: Poisson<pcl :: PointNormal> poisson;
    //Create an object to Poisson of datatype PointNormal

    poisson.setDepth (u_octree_depth) ;
    //Set the value of the depth of the octree

    boost :: shared_ptr<pcl :: PolygonMesh> t_triangles
            (new pcl :: PolygonMesh );                          ///////////////// should we delete the variable ?
    //Create a smart pointer (t_triangles) of datatype PolygonMesh and allocate space on memory

    poisson.setInputCloud (input_point_cloud) ;
    //Insert "input_point_cloud" as an input for the Poisson method

    poisson.reconstruct (*t_triangles) ;
    //Perfom the surface reconstruction method and save in "t_triangles"

    return(t_triangles);
    //Return the reconstructed Mesh
}

//****************************GREEDY TRIANGULATION*****************************

boost :: shared_ptr<pcl :: PolygonMesh>
ReconstructionProject::greedy_triangulation
(pcl :: PointCloud<pcl::PointNormal>::Ptr input_point_cloud)
{
    /*
     * This "tool" function is used to perform a greedy triangulation, a basic way to
     * reconstruct a mesh by creating triangles between the points. This algorithm
     * depends on many parameters and it don't give us a watertight mesh (we have to
     * use a holes filling algorithm after it).It needs as input a normal point cloud
     * and it returns a polygon mesh.
     */

    pcl :: GreedyProjectionTriangulation<pcl :: PointNormal> gt;
    //Create an object to GreedyProjectionTriangulation of datatype PointNormal

    boost :: shared_ptr<pcl :: PolygonMesh> t_triangles
            (new pcl :: PolygonMesh );                          ///////////////// should we delete the variable ?
    //Create a smart pointer (t_triangles) of datatype PolygonMesh and allocate space on memory

    gt.setInputCloud(input_point_cloud);
    //Insert "input_point_cloud" as an input for the Greedy triangulation method

    gt.setSearchRadius (u_radius_search) ;
    //Select the maximum allowable length of an edge of a triangle

    gt.setMu (u_mu) ;
    //Select the density parameter

    gt.setMaximumNearestNeighbors (u_max_nearest_neighbor) ;
    //Select the maximum neighbor taking in account for creating the triangles

    gt.setMaximumSurfaceAngle (u_max_surface_angle) ;
    //Select the angle between the normal of subject point and the sel point

    gt.setMinimumAngle (u_min_angle) ;
    //Select the minimal angle for a triangle

    gt.setMaximumAngle(u_max_angle);
    //Select the maximum angle for a triangle

    gt.setNormalConsistency ( u_normal_consistency ) ;
    //Set a flag if the normals are oriented consistently

    gt.reconstruct(*t_triangles);
    //Perfom the surface reconstruction method and save in "t_triangles"

    return (t_triangles);
    //Return the reconstructed Mesh
}

//-----------------------------------------------------------------------------
//*******************************CALLED FUNCTION*******************************
//-----------------------------------------------------------------------------

boost :: shared_ptr<pcl :: PolygonMesh>
ReconstructionProject::reconstruction(bool method, bool smoothing)
{
    /*This function is one called in the software to perform the 3D reconstruction
     * according to the choice from the user (buttons in the User Interface permit
     * to select the reconstruction method and if he want smoothing or not). This
     * function uses the "tool" functions created before. We need to provide to the
     * function two booleans (representing the choices of the user) and return a
     * polygon mesh.
     */

    if(smoothing == true)
    {
        //Check if a smoothing is asked by the user in his processing

        //d_icp_pointcloud =   smoothing(d_icp_pointcloud); ////////////////////change by the variable from the database
        //Use the "tool" function for smoothing to get a smoother point cloud before the processing the 3D reconstruction
    }

    //*******************************TEST**************************************
    pcl :: PCLPointCloud2 cloudblob ;
    pcl :: io :: loadPCDFile ( "C:\\Users\\dreve\\Documents\\VIBOT_LC\\Software Eng\\PCL Project\\PCLEXAMPLES\\untitled8\\chef.pcd" , cloudblob); ///////////////////DELETE !!!!
    pcl :: PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl :: PointCloud<pcl ::PointXYZ>) ;
    pcl ::fromPCLPointCloud2(cloudblob, *cloud);
    //*****************************END TEST************************************

    pcl :: PointCloud<pcl::PointNormal>::Ptr t_output_point_cloud_normal_estimation
            (new pcl::PointCloud<pcl :: PointNormal >) ; ///////////////// should we delete the variable ?
    //Read and Create a pointer "t_output_point_cloud_normal_estimation" and reserving space in the memory

    t_output_point_cloud_normal_estimation = normal_estimation(cloud);
    //Use the "tool" function for computing the normal estimation of the point cloud

    boost :: shared_ptr<pcl :: PolygonMesh> t_output_recon (new pcl :: PolygonMesh );
    //Create a smart pointer (t_output_recon) of datatype PolygonMesh and allocate space on memory

    if(method == true)
    {
        //Check which method has been selected by the user to perform the 3D reconstruction (true=Poisson, false=GT)

        t_output_recon =  poisson_algorithm(t_output_point_cloud_normal_estimation);
        //Use the "tool" function for creating the 3D mesh using the Poisson algorithm

    }
    else
    {

        t_output_recon =  greedy_triangulation(t_output_point_cloud_normal_estimation);
        //Use the "tool" function for creating the 3D mesh using the greedy triangulation method

    }

    return(t_output_recon);
    //Return the reconstructed Mesh according to the selected method
}
