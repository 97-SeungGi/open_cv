#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{


	Mat img;

	Mat dst;

	img = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);

	threshold(img, dst, 170, 255, THRESH_BINARY);

	imshow("원본", img);

	imshow("변경", dst);
	waitKey(0);
	return 0;
}