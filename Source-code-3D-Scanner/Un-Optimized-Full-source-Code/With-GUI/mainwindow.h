#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/passthrough.h>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void on_openButton_clicked();
private slots:
    void on_actionOpen_triggered();

    void on_actionStart_capture_triggered();

private:
    PointCloudT::Ptr cloud;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    pcl::PLYReader plyReader;

    unsigned int red;
    unsigned int green;
    unsigned int blue;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
