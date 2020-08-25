#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;
enum
{
    CV_BGR2GRAY = 6
};


/**  @function main */
int main(int argc, char** argv)
{
    Mat src, dst, srcgray;

    const char* source_window = "Source image";
    const char* equalized_window = "Equalized Image";

    /// Load image
    src = imread("anh.jpg");

    if (!src.data)
    {
        cout << "Usage: ./Histogram_Demo <path_to_image>" << endl;
        return -1;
    }

    /// Convert to grayscale
    cvtColor(src, srcgray, CV_BGR2GRAY);

    /// Apply Histogram Equalization
    equalizeHist(srcgray, dst);

    /// Display results
    namedWindow(source_window, WINDOW_AUTOSIZE);
    namedWindow(equalized_window, WINDOW_AUTOSIZE);

    imshow(source_window, src);
    imshow(equalized_window, dst);

    /// Wait until user exits the program
    waitKey(0);

    return 0;
}