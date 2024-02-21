#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace cv;
using namespace std;

Mat src, src_gray, dst;
int threshold_value = 0;

int threshold_type = 0;



void reduceColorAt(Mat& input, uchar table[]) {

	for (int i = 0; i < input.rows; i++) {
		for (int j = 0; j < input.cols; j++) {
			input.at<uchar>(i, j) = table[input.at<uchar>(i, j)];
		}
	}

}


int main()
{

	Mat img1 = imread("../images/lenna.jpg",IMREAD_GRAYSCALE);
	imshow("오리지널", img1);

	uchar table[256];
	for (int i = 0; i < 256; i++) {
		table[i] = (uchar)((i / 100) * 100);
	}
	reduceColorAt(img1, table);
	imshow("바뀐영상", img1);
	waitKey(0);
	

	return 0;
}