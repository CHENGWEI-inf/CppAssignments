//
// Created by AirohpuE on 21.1.3.
//

#include "../head/ImageReader.h"

ImageReader::ImageReader(const string &imgPath){
    this->img_path = imgPath;

    cv::Mat img= cv::imread(imgPath, 1);
    if(img.empty())
    {
        cout << "load image failed" << endl;
    } else{
        cout << "load image success" << endl;
    }

    this->image = img;

    cout <<"width:" << img.cols << "\theight:"<< img.rows << "\tchannels:" << img.channels() << endl;
//    cv::imshow("img",img);
//    cv::waitKey();
}

float * ImageReader::toRGBTensor() {
    if(image.channels() != 3){
        cerr << "The RGB channel num should be 3" << endl;
        return nullptr;
    }

    float * rTensor = new float[image.cols * image.rows];
    float * gTensor = new float[image.cols * image.rows];
    float * bTensor = new float[image.cols * image.rows];

    // reference : https://blog.csdn.net/varyshare/article/details/94162064
    for (size_t y = 0; y < image.rows; ++y) {
        // for each row   notice 0-256 rgb, use char to store
        auto* row_ptr= image.ptr<unsigned char>(y);
        for (size_t x = 0; x < image.cols; ++x) {
            //for each column
            unsigned char* data_ptr = &row_ptr[x*image.channels()];
            //for each channel, need to reverse to bgr
            rTensor[y * image.cols + x] = float(float(data_ptr[0]) / 255.0);
            gTensor[y * image.cols + x] = float(float(data_ptr[1]) / 255.0);
            bTensor[y * image.cols + x] = float(float(data_ptr[2]) / 255.0);
        }
    }


    float * rgbTensor = new float [3 * image.cols * image.rows];
    for(int i = 0; i < image.rows; i++){
        for(int j = 0; j < image.cols; j++){
            rgbTensor[0 * image.cols * image.rows + i * image.cols + j] = rTensor[i * image.cols + j];
            rgbTensor[1 * image.cols * image.rows + i * image.cols + j] = gTensor[i * image.cols + j];
            rgbTensor[2 * image.cols * image.rows + i * image.cols + j] = bTensor[i * image.cols + j];
        }
    }
    return rgbTensor;
}
