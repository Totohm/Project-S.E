#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <time.h>
#include <iostream>
#include <iomanip>
 
using namespace std;
using namespace cv;
 
const static int SENSITIVITY_VALUE = 20;
const static int BLUR_SIZE = 10;
 
bool detectMotion(Mat thresholdImage);
string intToString(int number);
string getDateTimeForFile();
string getDateTime();
 
int main(int argc, char** argv)
{
    initModule_video();
    setUseOptimized(true);
    setNumThreads(4);
 
    VideoCapture cap;
    if (argc > 1)
        cap.open(argv[1]);
    else
        cap.open(0);
        cap.set(CV_CAP_PROP_FOURCC ,CV_FOURCC('D', 'I', 'V', '3') );
 
    if (!cap.isOpened())
    {
        std::cerr << "Cannot read video. Try moving video file to sample directory." << std::endl;
        return -1;
    }
        VideoWriter oVideoWriter;
        double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
        double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
        Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
 
        std::string l_fname = "";
 
        namedWindow("Image", WINDOW_NORMAL);
        namedWindow("Debug", WINDOW_NORMAL);
 
        Mat frame, fgMaskMOG;
 
    Ptr<BackgroundSubtractor> pMOG = new BackgroundSubtractorMOG();
    for (;;)
    {
        if(!cap.read(frame)) {
            cerr << "Unable to read next frame." << endl;
                        continue;
        }
                // process the image to obtain a mask image.
                pMOG->operator()(frame, fgMaskMOG);
 
                std::string time = getDateTime();
                cv::rectangle(frame,cv::Rect(0,cap.get(CV_CAP_PROP_FRAME_HEIGHT)-25,290,20),cv::Scalar(255,255,255),-1);
                cv::putText(frame,time,cv::Point(0,cap.get(CV_CAP_PROP_FRAME_HEIGHT)-5),1,1.5,cv::Scalar(0,0,0),2);
 
                // detect contours in the final threshold image.
                if(false){
                        string fname = "C:/Users/Familjen-Styren/Videos/VIDEO" + getDateTimeForFile() + ".avi";
                        if(l_fname == "" || l_fname != fname){
                                oVideoWriter  = VideoWriter(fname, CV_FOURCC('D', 'I', 'V', '3'), 10, frameSize, true);
                                if ( !oVideoWriter.isOpened() )
                                {
                                        std::cerr <<  "ERROR: Failed to initialize video writing" << std::endl;
                                        return -1;
                                }
                        }
                        l_fname = fname;
                        oVideoWriter.write(frame);
                        putText(frame,"REC",Point(0,60),2,2,Scalar(0,0,255),2);
                }
                // show image.
                imshow("Image", frame);
                imshow("Debug",fgMaskMOG);
        int c = waitKey(30);
        if (c == 'q' || c == 'Q' || (c & 255) == 27)
            break;
    }
        return 0;
}
 
bool detectMotion(Mat thresholdImage){
        //create motionDetected variable.
        bool motionDetected = false;
        //create temp Mat for threshold image
        Mat temp;
        thresholdImage.copyTo(temp);
        //these two vectors needed for output of findContours
        vector< vector<Point> > contours;
        vector<Vec4i> hierarchy;
        //find contours of filtered image using openCV findContours function
        //findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );// retrieves all contours
        findContours(temp,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );// retrieves external contours
 
        //if contours vector is not empty, we have found some objects
        //we can simply say that if the vector is not empty, motion in the video feed has been detected.
        if(contours.size()>0)motionDetected=true;
        else motionDetected = false;
 
        return motionDetected;
 
}
 
string intToString(int number){
 
        //this function has a number input and string output
        std::stringstream ss;
        ss << number;
        return ss.str();
}
 
string getDateTime(){
        //get the system time
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        //create string to store the date and time
        string dateTime;
        //convert year to string
        string year = intToString(aTime->tm_year + 1900);
        //use stringstream to add a leading '0' to the month (ie. 3 -> 03)
        //we use 'setw(2)' so that we force the string 2 characters wide with a zero in front of it.
        //if the month is '10' then it will remain '10'
        std::stringstream m;
        m<<std::setfill('0')<<std::setw(2)<< aTime->tm_mon + 1;
        string month = m.str();
        //day
        std::stringstream d;
        d<<std::setfill('0')<<std::setw(2)<< aTime->tm_mday;
        string day = d.str();
        //hour
        std::stringstream hr;
        hr<<setfill('0')<<std::setw(2)<<aTime->tm_hour;
        string hour = hr.str();
        //minute
        std::stringstream min;
        min<<setfill('0')<<std::setw(2)<<aTime->tm_min;
        string minute = min.str();
        //second
        std::stringstream sec;
        sec<<setfill('0')<<std::setw(2)<<aTime->tm_sec;
        string second = sec.str();
 
        //here we use the year, month, day, hour, minute info to create a custom string
        //this will be displayed in the bottom left corner of our video feed.
        dateTime = year + "-" + month + "-" + day + "  " + hour + ":" + minute + ":" + second;
 
        return dateTime;
}
 
string getDateTimeForFile(){
        //get the system time
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        //create string to store the date and time
        string dateTime;
        //convert year to string
        string year = intToString(aTime->tm_year + 1900);
        //use stringstream to add a leading '0' to the month (ie. 3 -> 03)
        //we use 'setw(2)' so that we force the string 2 characters wide with a zero in front of it.
        //if the month is '10' then it will remain '10'
        std::stringstream m;
        m<<std::setfill('0')<<std::setw(2)<< aTime->tm_mon + 1;
        string month = m.str();
        //day
        std::stringstream d;
        d<<std::setfill('0')<<std::setw(2)<< aTime->tm_mday;
        string day = d.str();
        //hour
        std::stringstream hr;
        hr<<setfill('0')<<std::setw(2)<<aTime->tm_hour;
        string hour = hr.str();
       
        dateTime = year + "_" + month + "_" + day;
        return dateTime;
}