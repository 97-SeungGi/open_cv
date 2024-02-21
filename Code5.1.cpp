#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("../images/histo_test2.jpg", IMREAD_GRAYSCALE);
	imshow("Inputimage", src);
	int his[256] = { 0 };

	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			his[(int)src.at<uchar>(y, x)]++;

		}
	}
	for (int count : his) {
		cout << count << ",";
	}
	waitKey(0);
	return 0;

}