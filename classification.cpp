#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace dnn;
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        std::cout << "ERROR ARGS" << '\n';
        return 0;
    }

    string model  = string(argv[1]);
    string config = string(argv[2]);
    string path_image = string(argv[3]);
    int backendId = DNN_BACKEND_OPENCV;
    int targetId  = DNN_TARGET_CPU;

    Net net = readNet(model, config);
    net.setPreferableBackend(backendId);
    net.setPreferableTarget(targetId);

    Mat frame = imread(path_image);

    Mat blob;
    double scale = 0.017;
    Size spatial_size = Size(224, 224);
    Scalar mean = {103.94,116.78,123.68};
    bool swapRB = false;
    bool crop   = false;
    int  ddepth = CV_32F;

    blobFromImage(frame, blob, scale, spatial_size, mean, swapRB, crop, ddepth);
    net.setInput(blob);
    Mat prob = net.forward();

    Point classIdPoint;
    double confidence;
    minMaxLoc(prob.reshape(1, 1), 0, &confidence, 0, &classIdPoint);
    int classId = classIdPoint.x;

    std::cout << "Class: " << classId << '\n';
    std::cout << "Confidence: " << confidence << '\n';

    return 0;
}
