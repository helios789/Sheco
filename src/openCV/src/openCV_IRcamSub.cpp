#include "ros/ros.h"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/String.h>

using namespace cv;


const int MSG_ARRAY_ROW = 6;
const int MSG_ARRAY_COL = 32;
float temperatureArray[768];

Mat HeatMap(Size(24, 32), CV_8UC1);
Mat colorHeatMap;

void msgCallback1(const std_msgs::Float32MultiArray::ConstPtr& msg)
{
    ROS_INFO("1---------");

    for(int row = 0; row < MSG_ARRAY_ROW; row++)
    {
        for(int col = 0; col < MSG_ARRAY_COL; col++)
        {
           // ROS_INFO("%f",msg->data[row * MSG_ARRAY_COL + col]);
           HeatMap.at<float>(row + MSG_ARRAY_ROW * 0, col) = msg->data[row * MSG_ARRAY_COL + col];
           ROS_INFO("%f",HeatMap.at<float>(row + MSG_ARRAY_ROW * 0, col));
        }
    }
    applyColorMap(HeatMap, colorHeatMap, COLORMAP_HOT);
    imshow( "HeatMap", colorHeatMap );
    waitKey(10);

    ROS_INFO("1---------");
}

void msgCallback2(const std_msgs::Float32MultiArray::ConstPtr& msg)
{
    ROS_INFO("2---------");

    for(int row = 0; row < MSG_ARRAY_ROW; row++)
    {
        for(int col = 0; col < MSG_ARRAY_COL; col++)
        {
           // ROS_INFO("%f",msg->data[row * MSG_ARRAY_COL + col]);
           HeatMap.at<float>(row + MSG_ARRAY_ROW * 1, col) = msg->data[row * MSG_ARRAY_COL + col]; 
            ROS_INFO("%f",HeatMap.at<float>(row + MSG_ARRAY_ROW * 1, col));    
        }
    }

    applyColorMap(HeatMap, colorHeatMap, COLORMAP_HOT);
    imshow( "HeatMap", colorHeatMap );
    waitKey(10);

    ROS_INFO("2---------");
    
}

void msgCallback3(const std_msgs::Float32MultiArray::ConstPtr& msg)
{
    ROS_INFO("3---------");

    for(int row = 0; row < MSG_ARRAY_ROW; row++)
    {
        for(int col = 0; col < MSG_ARRAY_COL; col++)
        {
          //  ROS_INFO("%f",msg->data[row * MSG_ARRAY_COL + col]);
           HeatMap.at<float>(row + MSG_ARRAY_ROW * 2, col) = msg->data[row * MSG_ARRAY_COL + col];  
         ROS_INFO("%f",HeatMap.at<float>(row + MSG_ARRAY_ROW * 2, col));  
        }
    }

    applyColorMap(HeatMap, colorHeatMap, COLORMAP_HOT);
    imshow( "HeatMap", colorHeatMap );
    waitKey(10);

    ROS_INFO("3---------");
}

void msgCallback4(const std_msgs::Float32MultiArray::ConstPtr& msg)
{
    ROS_INFO("4---------");

    for(int row = 0; row < MSG_ARRAY_ROW; row++)
    {
        for(int col = 0; col < MSG_ARRAY_COL; col++)
        {
          //  ROS_INFO("%f",msg->data[row * MSG_ARRAY_COL + col]);
           HeatMap.at<float>(row + MSG_ARRAY_ROW * 3, col) = msg->data[row * MSG_ARRAY_COL + col]; 
            ROS_INFO("%f",HeatMap.at<float>(row + MSG_ARRAY_ROW * 3, col));    
        }
    }

    applyColorMap(HeatMap, colorHeatMap, COLORMAP_HOT);
    imshow( "HeatMap", colorHeatMap );
    waitKey(10);

    ROS_INFO("4---------");

}

int main(int argc, char **argv)
{
    ROS_INFO("-- Start --");
    ros::init(argc, argv, "openCV_sub");
    ros::NodeHandle nh;
    // 노드 메인 함수
    // 노드명 초기화
    // ROS 시스템과 통신을 위한 노드 핸들 선언
    // 서브스크라이버 선언, ros_tutorials_topic 패키지의 MsgTutorial 메시지 파일을 이용한
    // 서브스크라이버 ros_tutorial_sub 를 작성한다. 토픽명은 "ros_tutorial_msg" 이며,
    // 서브스크라이버 큐(queue) 사이즈를 100개로 설정한다는 것이다

    ros::Subscriber sub_IRcamera1 = nh.subscribe("IRcam1", 100, msgCallback1);
    ros::Subscriber sub_IRcamera2 = nh.subscribe("IRcam2", 100, msgCallback2);
    ros::Subscriber sub_IRcamera3 = nh.subscribe("IRcam3", 100, msgCallback3);
    ros::Subscriber sub_IRcamera4 = nh.subscribe("IRcam4", 100, msgCallback4);


    // 콜백함수 호출을 위한 함수로써, 메시지가 수신되기를 대기,
    // 수신되었을 경우 콜백함수를 실행한다
    ros::spin();
    return 0;
}