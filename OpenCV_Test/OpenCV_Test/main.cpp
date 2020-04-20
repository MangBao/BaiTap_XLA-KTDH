#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>

using namespace std;
using namespace cv;

int main()
{
	cout << "Chuong trinh dau tien" << endl;
	Mat img = imread("C:/Users/ASUS/Downloads/84189845_794150510995506_9186256991067045888_o.jpg");
	namedWindow("Viet Nam");
	imshow("Viet Nam", img);
	waitKey(0);
	return 0;
}