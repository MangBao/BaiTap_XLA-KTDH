#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>
using namespace cv;
using namespace cv::ml;
int main(int, char**)
{
    // Set up training data
    int labels[6] = { 1, 1, -1, -1, 1, -1 };
    float trainingData[6][2] = { {500, 300}, {255, 10}, {501, 255}, {10, 100}, {250, 200}, {300,100} };
    Mat trainingDataMat(6, 2, CV_32F, trainingData);
    Mat labelsMat(6, 1, CV_32SC1, labels);
    // Train the SVM
    Ptr<SVM> svm = SVM::create();
    svm->setType(SVM::C_SVC);
    svm->setKernel(SVM::LINEAR);
    svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));
    svm->train(trainingDataMat, ROW_SAMPLE, labelsMat);
    // Data for visual representation
    int width = 512, height = 512;
    Mat image = Mat::zeros(height, width, CV_8UC3);
    // Show the decision regions given by the SVM
    Vec3b green(0, 255, 0), blue(255, 0, 0);
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Mat sampleMat = (Mat_<float>(1, 2) << j, i);
            float response = svm->predict(sampleMat);
            if (response == 1)
                image.at<Vec3b>(i, j) = green;
            else if (response == -1)
                image.at<Vec3b>(i, j) = blue;
        }
    }
    // Show the training data
    int thickness = -1;
    circle(image, Point(200, 300), 5, Scalar(0, 0, 0), thickness);
    circle(image, Point(255, 10), 5, Scalar(0, 0, 0), thickness);
    circle(image, Point(701, 555), 5, Scalar(255, 255, 255), thickness);
    circle(image, Point(10, 100), 5, Scalar(255, 255, 255), thickness);
    circle(image, Point(250, 600), 5, Scalar(0, 0, 0), thickness);
    circle(image, Point(400, 100), 5, Scalar(255, 255, 255), thickness);
    // Show support vectors
    thickness = 2;
    Mat sv = svm->getUncompressedSupportVectors();
    for (int i = 0; i < sv.rows; i++)
    {
        const float* v = sv.ptr<float>(i);
        circle(image, Point((int)v[0], (int)v[1]), 6, Scalar(128, 128, 128), thickness);
    }
    imwrite("result.png", image);        // save the image
    imshow("SVM Simple Example", image); // show it to the user
    waitKey();
    return 0;
}