#include "ros/ros.h"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int main( int argc, char** argv )
{
    namedWindow("Example", WINDOW_AUTOSIZE);
    namedWindow("Example1", WINDOW_AUTOSIZE);
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

        GaussianBlur(frame, output, Size(5,5), 3, 3);
        GaussianBlur(output, output, Size(5,5), 3, 3);
        imshow("Example1", output);

        if(waitKey(33) >= 0)
            break;
    }
    
    return 0;
}