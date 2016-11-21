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

public slots:
  void
  randomButtonPressed ();

  void
  RGBsliderReleased ();

  void
  pSliderValueChanged (int value);

  void
  redSliderValueChanged (int value);

  void
  greenSliderValueChanged (int value);

  void
  blueSliderValueChanged (int value);

protected:
  PointCloudT::Ptr cloud;
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
  pcl::PLYReader plyReader;

  unsigned int red;
  unsigned int green;
  unsigned int blue;

private slots:
    void on_openButton_clicked();

    void on_openButton_2_clicked();

    void on_captureButton_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
