#include "ros/ros.h"
// ROS 기본 헤더파일
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "openCV");
    cv::VideoCapture vc(0);
    if(!vc.isOpened())
    {
        return -1;
    }
    vc.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    vc.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    
    cv::Mat img;
    cv::Mat fliped_img; 
    while(1)
    {
        vc >> img;

        if(img.empty())
            break;
        
        cv::imshow("cam", img);
        
        cv::flip(img, fliped_img, 1); //영상 좌우 반전하기
        cv::imshow("flip", fliped_img);

        if(cv::waitKey(10) == 27)
            break;

        ROS_INFO("hello OpenCV!");
    }
    cv::destroyAllWindows();
   
    
    return 0;
}