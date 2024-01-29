#include<opencv2/opencv.hpp>
#include<iostream>
#include<fstream>
using namespace std;
using namespace cv;
typedef cv::Point3_<uint8_t> Pixel;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Please enter image location after program name" << endl;
        return -1;
    }
    Mat image = imread(argv[1]);
    if (image.empty()) {
        cout << "Could not find or open image" << endl;
        return -1;
    }
    Mat imageRS;
    int rSize = 300;                                            //Change width in image resize
    int cSize = rSize * (image.rows / image.cols);              //height based on resized width maintaining aspect ratio.
    resize(image, imageRS, Size(rSize, cSize), 0, 0, INTER_AREA);
    ofstream file;
    file.open("hold.txt");
    string s = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";   //Ascii characters sorted by how much they fill a pixel
    int brightness = 0;
    for (int x = 0; x < imageRS.rows; x++) {
        for (int y = 0; y < imageRS.cols; y++) {
            brightness = ((int) imageRS.at<Pixel>(x, y).x + (int) imageRS.at<Pixel>(x, y).y + (int) imageRS.at<Pixel>(x, y).z) / 3;
            file << s[brightness / s.size()] << s[brightness / s.size()] << s[brightness / s.size()];
        }
        file << endl;
    }
    file.close();
    return 0;
}
