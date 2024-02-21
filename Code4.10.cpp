#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{


	Mat img;

	img = imread("../images/lenna.jpg",IMREAD_GRAYSCALE);

	imshow("원본", img);

	Mat dst;
	img.convertTo(dst,-1,-1,255);
	//dst = 255 - img;
	imshow("변경", dst);
	waitKey(0);
	return 0;
}