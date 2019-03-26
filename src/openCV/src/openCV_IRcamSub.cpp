#include "ros/ros.h"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/String.h>

using namespace cv;

void msgCallback(const std_msgs::Float32MultiArray::ConstPtr& msg)
{
    ROS_INFO("---------");

    for(int i = 0; i < 32; i++)
        ROS_INFO("%4f", msg->data[i]);

    ROS_INFO("---------");
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

    ros::Subscriber sub_IRcamera = nh.subscribe("IRcam", 100, msgCallback);
    // 콜백함수 호출을 위한 함수로써, 메시지가 수신되기를 대기,
    // 수신되었을 경우 콜백함수를 실행한다
    ros::spin();
    return 0;
}