#include "ros/ros.h"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>

using namespace cv;

void msgCallback(const sensor_msgs::ImageConstPtr& msg)
{
    ROS_INFO("hi");
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg,"bgr8"); 
    

    if(!cv_ptr->image.data)
    {
        ROS_INFO("image empty");
        return;
    }
    ROS_INFO("image sub!");

    imshow("Example2", cv_ptr->image);
    cv::waitKey(50);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "openCV_sub");
    ros::NodeHandle nh;
    namedWindow("Example2", WINDOW_AUTOSIZE);
    // 노드 메인 함수
    // 노드명 초기화
    // ROS 시스템과 통신을 위한 노드 핸들 선언
    // 서브스크라이버 선언, ros_tutorials_topic 패키지의 MsgTutorial 메시지 파일을 이용한
    // 서브스크라이버 ros_tutorial_sub 를 작성한다. 토픽명은 "ros_tutorial_msg" 이며,
    // 서브스크라이버 큐(queue) 사이즈를 100개로 설정한다는 것이다
    ros::Subscriber sub_img = nh.subscribe("topic", 5, msgCallback);
    // 콜백함수 호출을 위한 함수로써, 메시지가 수신되기를 대기,
    // 수신되었을 경우 콜백함수를 실행한다
    ros::spin();
    return 0;
}