#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog" //Menda

#include "kinect_management.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // Setup the cloud pointer
    cloud.reset (new PointCloudT);
    // The number of points in the cloud
    cloud->points.resize (1000);

    // The default color
    red   = 128;
    green = 128;
    blue  = 128;

    // Fill the cloud with some points
//    for (size_t i = 0; i < cloud->points.size (); ++i)
//    {
//      cloud->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
//      cloud->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
//      cloud->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);

//      cloud->points[i].r = red;
//      cloud->points[i].g = green;
//      cloud->points[i].b = blue;
//    }

    // Set up the QVTK window
    viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
    viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
    ui->qvtkWidget->update ();

    // Connect "random" button and the function
    connect (ui->pushButton_random,  SIGNAL (clicked ()), this, SLOT (randomButtonPressed ()));

    // Connect R,G,B sliders and their functions
    connect (ui->horizontalSlider_R, SIGNAL (valueChanged (int)), this, SLOT (redSliderValueChanged (int)));
    connect (ui->horizontalSlider_G, SIGNAL (valueChanged (int)), this, SLOT (greenSliderValueChanged (int)));
    connect (ui->horizontalSlider_B, SIGNAL (valueChanged (int)), this, SLOT (blueSliderValueChanged (int)));
    connect (ui->horizontalSlider_R, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
    connect (ui->horizontalSlider_G, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
    connect (ui->horizontalSlider_B, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));

    // Connect point size slider
    connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

    viewer->addPointCloud (cloud, "cloud");
    pSliderValueChanged (6);
    viewer->resetCamera ();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    QString thefile = QFileDialog::getOpenFileName(this, tr("Open PCD file..."),"", tr("")); //Menda
    if(thefile.contains(".ply")){
        if (plyReader.read(thefile.toStdString(), *cloud) == -1) //* load the file
        {
          PCL_ERROR ("Couldn't read ply file \n");
        }
    }else if(thefile.contains(".pcd")){
        if (pcl::io::loadPCDFile<pcl::PointXYZRGBA> (thefile.toStdString(), *cloud) == -1) //* load the file
        {
          PCL_ERROR ("Couldn't read pcd file \n");
        }
    }

    viewer->updatePointCloud (cloud, "cloud");
    ui->qvtkWidget->update ();

}

void
MainWindow::randomButtonPressed ()
{
  printf ("Random button was pressed\n");

  // Set the new color
  for (size_t i = 0; i < cloud->size(); i++)
  {
    cloud->points[i].r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    cloud->points[i].g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    cloud->points[i].b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
  }

  viewer->updatePointCloud (cloud, "cloud");
  ui->qvtkWidget->update ();
}

void
MainWindow::RGBsliderReleased ()
{
  // Set the new color
  for (size_t i = 0; i < cloud->size (); i++)
  {
    cloud->points[i].r = red;
    cloud->points[i].g = green;
    cloud->points[i].b = blue;
  }
  viewer->updatePointCloud (cloud, "cloud");
  ui->qvtkWidget->update ();
}

void
MainWindow::pSliderValueChanged (int value)
{
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
  ui->qvtkWidget->update ();
}

void
MainWindow::redSliderValueChanged (int value)
{
  red = value;
  printf ("redSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
MainWindow::greenSliderValueChanged (int value)
{
  green = value;
  printf ("greenSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
MainWindow::blueSliderValueChanged (int value)
{
  blue = value;
  printf("blueSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void MainWindow::on_openButton_2_clicked()
{

}

void MainWindow::on_captureButton_clicked()
{
    typedef pcl::PointXYZRGBA PointType;

    // Retrieved Point Cloud Callback Function
    boost::mutex mutex;

    // Point Cloud
     PointCloudT::Ptr cloud2;

    viewer->setCameraPosition( 0.0, 0.0, -2.5, 0.0, 0.0, 0.0 );

    boost::function<void( const pcl::PointCloud<PointType>::ConstPtr& )> function =
        [&cloud2, &mutex]( const pcl::PointCloud<PointType>::ConstPtr& ptr ){
            boost::mutex::scoped_lock lock( mutex );

            /* Point Cloud Processing */

            cloud2 = ptr->makeShared();

        };

    // Kinect2Grabber
    boost::shared_ptr<pcl::Grabber> grabber = boost::make_shared<pcl::Kinect2Grabber>();

    // Register Callback Function
    boost::signals2::connection connection = grabber->registerCallback( function );

    // Start Grabber
    grabber->start();
    //!viewer->wasStopped()
    while(true ){
        //Sleep(5000);
        // Update Viewer
        //cloud=cloud2;
        //viewer->spinOnce();
        ui->qvtkWidget->update ();

        boost::mutex::scoped_try_lock lock( mutex );
        if( lock.owns_lock() && cloud2 ){
            // Update Point Cloud
            pcl::PointCloud<PointType>::Ptr cloud_filtered (new pcl::PointCloud<PointType>);
            // Create the filtering object
            pcl::PassThrough<PointType> pass;
            pass.setFilterFieldName ("z");
            pass.setFilterLimits (0.5, 4.5);
            pass.setInputCloud (cloud2);
            pass.filter (*cloud_filtered);
            //std::cout<<filename<<std::endl;
            //pcl::io::savePLYFile(filename, *cloud_filtered);
            //Sleep(5000);

            if( !viewer->updatePointCloud( cloud_filtered, "cloud" ) ){
                viewer->addPointCloud( cloud_filtered, "cloud" );
                viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "cloud");
            }
        }

        QCoreApplication::processEvents();
    }

    // Stop Grabber
    grabber->stop();

    // Disconnect Callback Function
    if( connection.connected() ){
        connection.disconnect();
    }
}
