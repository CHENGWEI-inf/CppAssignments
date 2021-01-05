
#ifndef PROJECT2_IMAGEREADER_H
#define PROJECT2_IMAGEREADER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <iostream>
using namespace cv;
using namespace std;

class ImageReader {
private:
    string img_path;
    cv::Mat image;

public:
    ImageReader(const string &imgPath);
    float * toRGBTensor();

};


#endif //PROJECT2_IMAGEREADER_H
