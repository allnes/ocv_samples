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

    string model  = string(argv[1]);
    string config = string(argv[2]);
    Net net = readNet(model, config);

    VideoCapture cap(0);

    Mat frame, blob;
    while (waitKey(1) < 0)
    {
        cap >> frame;
        blobFromImage(frame, blob, 0.017, Size(224, 224), {103.94,116.78,123.68}, swapRB, false);
        net.setInput(blob);
        Mat prob = net.forward();
    }
    return 0;
}
