#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace cv;
using namespace std;


int main()
{

	Mat img1, mask;

	img1 = imread("../images/scene.jpg", IMREAD_COLOR);

	mask = imread("../images/mask.png", IMREAD_COLOR);

	Mat dst = img1.clone();

	imshow("img1", img1);
	imshow("mask", mask);
	//bitwise_and(img1, mask, dst);
	//bitwise_or(img1, mask, dst);
	//bitwise_xor(img1, mask, dst);
	bitwise_not(mask ,dst);
	imshow("dst", dst);
	waitKey(0);
	
	return 0;
}