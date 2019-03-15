#include "ros/ros.h"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
    Mat img_color;
    Mat img_gray;
    Mat img_constrast;
    Mat img_hsv;
    Mat result;

    Mat image_blurred_with_median;
    Mat image_blurred_with_gauss;
    

	img_color = imread("/home/helios789/다운로드/OilSpill-ImageSet/1.jpg", IMREAD_COLOR);

	if (img_color.empty())
	{
	    ROS_INFO("Image Load Error");
		return -1;
	}


    GaussianBlur(img_color, image_blurred_with_gauss, Size(5,5), 10, 10);

    medianBlur(img_color, image_blurred_with_median, 5);

    cvtColor(image_blurred_with_median, img_gray, COLOR_BGR2GRAY);

    equalizeHist(img_gray, img_constrast);

 threshold( img_gray, result, 100, 255, THRESH_BINARY );




	namedWindow("Original", WINDOW_AUTOSIZE);
	imshow("Original", img_color);

    namedWindow("Med", WINDOW_AUTOSIZE);
	imshow("Med", image_blurred_with_median);

    namedWindow("Gauss", WINDOW_AUTOSIZE);
	imshow("Gauss", image_blurred_with_gauss);

    namedWindow("Result", WINDOW_AUTOSIZE);
	imshow("Result", result);


	waitKey(0);


    
    return 0;
}