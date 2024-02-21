#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace cv;
using namespace std;


int main()
{

	Mat img1 = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("오리지널", img1);

	Mat table(1, 256, CV_8U);

	uchar *p = table.ptr();
	for (int i = 0; i < 256; i++) {
		p[i] = ((i / 100) * 100);
	}

	Mat img2;
	LUT(img1, table, img2);
	imshow("바뀐영상", img2);
	waitKey(0);


	return 0;
}