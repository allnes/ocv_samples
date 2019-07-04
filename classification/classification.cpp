#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
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
    Net net = readNet(model, config);

    Mat frame = imread(path_image);

    Mat blob;
    blobFromImage(frame, blob, 0.017, Size(224, 224), {103.94,116.78,123.68});
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
