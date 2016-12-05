/*
 * Copyright (c) 2016, Maria del Carmen Moreno Genis, Omair Khalid and Thomas Drevet.
 * All rights reserved.
 *
 *This class was created to achieve 3D Reconstruction, as part of a project to make a 3D Scanner. It
 *takes a registered point cloud as the input and outputs a watertight mesh which is suitable for
 *3D Printing.
 *
 *The 3D Reconstruction can be achieved by either of the two methods:
 *Poisson 3D Reconstruction or Greedy Reconstruction.
 *
 *The user can change the default parameters for the 3D Reconstruction method through the
 *GUI to achieve desirable results.
 *
 */


#ifndef RECONSTRUCTIONPROJECT_H
#define RECONSTRUCTIONPROJECT_H

#include <pcl/io/vtk_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <Windows.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/search/kdtree.h>
#include <iostream>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/mls.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/surface/vtk_smoothing/vtk_mesh_smoothing_laplacian.h>
#include <pcl/surface/poisson.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d_omp.h>


#include <pcl/io/pcd_io.h>              /////////////////////DELETE !!!!


class ReconstructionProject
{

public:

    ReconstructionProject(); /////////////////////////////////////Parametric Constructor ???

    ~ReconstructionProject();

    boost::shared_ptr<pcl::PolygonMesh> reconstruction(bool method, bool smoothing);

    unsigned int getU_octree_depth() const;

    void setU_octree_depth(unsigned int value);

    float getU_radius_search() const;

    void setU_radius_search(float value);

    float getU_mu() const;

    void setU_mu(float value);

    unsigned int getU_max_nearest_neighbor() const;

    void setU_max_nearest_neighbor(unsigned int value);

    double getU_max_surface_angle() const;

    void setU_max_surface_angle(double value);

    double getU_min_angle() const;

    void setU_min_angle(double value);

    double getU_max_angle() const;

    void setU_max_angle(double value);

    bool getU_normal_consistency() const;

    void setU_normal_consistency(bool value);

private:

    unsigned int u_octree_depth;

    float u_radius_search;

    float u_mu;

    unsigned int u_max_nearest_neighbor;

    double u_max_surface_angle;

    double u_min_angle;

    double u_max_angle;

    bool u_normal_consistency;

protected:

    void smoothing();

    pcl::PointCloud<pcl::PointNormal>::Ptr normal_estimation(pcl::PointCloud<pcl::PointXYZ>::Ptr input_point_cloud);

    boost::shared_ptr<pcl::PolygonMesh> poisson_algorithm(pcl::PointCloud<pcl::PointNormal>::Ptr input_point_cloud);

    boost::shared_ptr<pcl::PolygonMesh> greedy_triangulation(pcl::PointCloud<pcl::PointNormal>::Ptr input_point_cloud);

};

#endif // RECONSTRUCTIONPROJECT_H
