#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace cv;
using namespace std;


int main()
{

	double al, bet;
	Mat src1, src2, gat;

	cout << "¾ËÆÄ°ª :";
	cin >> al;

	bet = (1.0 - al);
	src1 = imread("../images/test1.jpg");
	src2 = imread("../images/test2.jpg");
	addWeighted(src1, al, src2, bet, 0.0, gat);
	
	imshow("src1", src1);
	imshow("src2", src2);
	imshow("gat", gat);
	waitKey(0);


	return 0;
}