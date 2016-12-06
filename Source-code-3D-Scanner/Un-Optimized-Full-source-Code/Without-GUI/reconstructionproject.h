/*
 * Copyright (c) 2016, Maria del Carmen Moreno Genis, Omair Khalid and Thomas Drevet.
 * All rights reserved.
 *
 *This class was created to achieve 3D Reconstruction, as part of a project to make a 3D Scanner. It
 *takes a registered point cloud as the input and then outputs a watertight mesh which is suitable for
 *3D Printing.
 *
 *The 3D Reconstruction can be achieved by either one of the two methods:
 *Poisson 3D Reconstruction or Greedy Reconstruction.
 *
 *The user can change the default parameters for the 3D Reconstruction method through the
 *GUI to achieve desirable results.
 *
 */


#ifndef RECONSTRUCTIONPROJECT_H
#define RECONSTRUCTIONPROJECT_H

#include <pcl/io/vtk_io.h>
#include <Windows.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/surface/vtk_smoothing/vtk_mesh_smoothing_laplacian.h>
#include <pcl/surface/poisson.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d_omp.h>


#include <pcl/io/pcd_io.h>              /////////////////////DELETE !!!!
#include <pcl/visualization/pcl_visualizer.h> ///////////////DELETE !!!!


class ReconstructionProject
{

public:

    ReconstructionProject();
    //Constructor

    ~ReconstructionProject();
    //Destructor

    boost::shared_ptr<pcl::PolygonMesh> reconstruction(bool method, bool smoothing);
    //Create the function used in the software to do the 3D Reconstruction using the "tool" functions

    unsigned int getU_octree_depth() const;
    //Accessor for the u_octree_depth parameter

    void setU_octree_depth(unsigned int value);
    //Mutator for the u_octree_depth parameter

    float getU_radius_search() const;
    //Accessor for the u_radius_search parameter

    void setU_radius_search(float value);
    //Mutator for the u_radius_search parameter

    float getU_mu() const;
    //Accessor for the u_mu parameter

    void setU_mu(float value);
    //Mutator for the u_mu parameter

    unsigned int getU_max_nearest_neighbor() const;
    //Accessor for the u_max_nearest_neighbor parameter

    void setU_max_nearest_neighbor(unsigned int value);
    //Mutator for the u_max_nearest_neighbor parameter

    double getU_max_surface_angle() const;
    //Accessor for the u_max_surface_angle parameter

    void setU_max_surface_angle(double value);
    //Mutator for the u_max_surface_angle parameter

    double getU_min_angle() const;
    //Accessor for the u_min_angle parameter

    void setU_min_angle(double value);
    //Mutator for the u_min_angle parameter

    double getU_max_angle() const;
    //Accessor for the u_max_angle parameter

    void setU_max_angle(double value);
    //Mutator for the u_max_angle parameter

    bool getU_normal_consistency() const;
    //Accessor for the u_normal_consistency parameter

    void setU_normal_consistency(bool value);
    //Mutator for the u_normal_consistency parameter

private:

    //*******************POISSON ALGORITHM************************

    unsigned int u_octree_depth;
    //Create the variable to defined the octree depth in the Poisson Algorithm

    //******************GREEDY TRIANGULATION***********************

    float u_radius_search;
    //Create the variable to defined the maximum allowable length of an edge of a triangle

    float u_mu;
    //Create the variable to defined the density parameter

    unsigned int u_max_nearest_neighbor;
    //Create the variable to defined the maximum neighbor taking in account for creating the triangles

    double u_max_surface_angle;
    //Create the variable to defined the angle between the normal of subject point and the sel point

    double u_min_angle;
    //Create the variable to defined the minimal angle for a triangle

    double u_max_angle;
    //Create the variable to defined the maximum angle for a triangle

    bool u_normal_consistency;
    //Create the variable to set a flag if the normals are oriented consistently

protected:

    void smoothing();
    //Create the "tool" function to do the smoothing

    pcl::PointCloud<pcl::PointNormal>::Ptr normal_estimation(pcl::PointCloud<pcl::PointXYZ>::Ptr input_point_cloud);
    //Create the "tool" function to do the normal estimation

    boost::shared_ptr<pcl::PolygonMesh> poisson_algorithm(pcl::PointCloud<pcl::PointNormal>::Ptr input_point_cloud);
    //Create the "tool" function to perform the Poisson algorithm

    boost::shared_ptr<pcl::PolygonMesh> greedy_triangulation(pcl::PointCloud<pcl::PointNormal>::Ptr input_point_cloud);
    //Create the "tool" function to perform the greedy triangulation

};

#endif // RECONSTRUCTIONPROJECT_H
