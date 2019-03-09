#include "ros/ros.h"
// ROS 기본 헤더파일
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
int main( int argc, char** argv )
{
    // frame capture from webcam
    cv::VideoCapture capture( 0 );
  
    // is camera opened?
    if( !capture.isOpened() ) {
        std::cerr << "Cannot open camera" << std::endl;
        return 0;
    }
 
    // create a window
    cv::namedWindow( "Webcam", 1 );
 
    // while loop for image capture from webcam
    while( true ) {
        bool frame_valid = true;
  
        cv::Mat frame;
        cv::Mat gray;
  
        try {
            // get a new frame from webcam
            capture >> frame;
 
            // convert RGB image to gray
            cv::cvtColor( frame, gray, CV_RGB2GRAY );
        }
        catch( cv::Exception& e ) {
            std::cerr << "Exception occurred. Ignoring frame... " << e.err << std::endl;
            frame_valid = false;
        }
 
        if ( frame_valid ) {
            try {
                // print the output
                cv::imshow( "Webcam", gray );
            }
            catch( cv::Exception& e ) {
                std::cerr << "Exception occurred. Ignoring frame... " << e.err << std::endl;
            }
        }
 
        if ( cv::waitKey( 30 ) >= 0 ) break;
    }
 
 
    return 0;
}