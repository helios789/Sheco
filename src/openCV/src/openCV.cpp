#include "ros/ros.h"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>

using namespace cv;

int main( int argc, char** argv )
{
    namedWindow("Example", WINDOW_AUTOSIZE);

    ros::init(argc, argv, "openCV");

    ros::NodeHandle node;
    ros::Publisher pub_img = node.advertise<sensor_msgs::Image>("topic", 5);

    VideoCapture cap;
    cap.open(0);

    Mat frame;
    Mat output;
    while(1)
    {
        cap >> frame;
        if(frame.empty())
            break;
        imshow("Example", frame);
        
        cv_bridge::CvImage img_bridge;
        sensor_msgs::Image img_msg; // >> message to be sent

        std_msgs::Header header; // empty header
        header.stamp = ros::Time::now(); // time
        // img_bridge = cv_bridge::CvImage(header, sensor_msgs::image_encodings::RGB8, frame);
        img_bridge.header = header;
        img_bridge.encoding = sensor_msgs::image_encodings::RGB8;
        img_bridge.image = frame;
        
        img_bridge.toImageMsg(img_msg); // from cv_bridge to sensor_msgs::Image
        pub_img.publish(img_msg); // ros::Publisher pub_img = node.advertise<sensor_msgs::Image>("topic", queuesize);

        if(waitKey(33) >= 0)
            break;
    }
    
    return 0;
}