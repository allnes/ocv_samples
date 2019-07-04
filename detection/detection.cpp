#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace dnn;
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cout << "ERROR ARGS" << '\n';
        return 0;
    }

    Mat frame;

    string win_name = "Deep learning in OpenCV";
    namedWindow(win_name, WINDOW_NORMAL);

    VideoCapture cap;
    cap.open(0);
    while (waitKey(1) < 0)
    {
        cap >> frame;
        imshow(win_name, frame);
    }
    return 0;
}
