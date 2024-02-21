#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace cv;
using namespace std;

void drawHist(int his[]){

	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / 256);
	


	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	int max = his[0];

	for (int i = 1; i < 256; i++) {
		if (max < his[i]) {
			max = his[i];
		}
	}

	for (int i = 0; i < 255; i++) {
		his[i] = floor(((double)his[i] / max)*histImage.rows);
	}


	for (int i = 0; i < 255; i++) {
		line(histImage, Point(bin_w*(i), hist_h), Point(bin_w*(i), hist_h - his[i]), Scalar(0, 0, 255));
	}
	imshow("histogram", histImage);

}



int main()
{
	//Mat src = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);
	//Mat src = imread("../images/contrast.jpg", IMREAD_GRAYSCALE);
	Mat src = imread("../images/plane.jpg", IMREAD_GRAYSCALE);

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

	drawHist(his);
	waitKey(0);
	return 0;

}