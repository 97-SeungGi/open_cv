#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("../images/city1.jpg", IMREAD_GRAYSCALE);
	Mat dst;

	Mat noise = Mat::zeros(src.rows, src.cols, CV_8U);
	randu(noise, 0, 255);

	Mat black = noise < 10;
	Mat white = noise > 245;

	Mat src1 = src.clone();
	src1.setTo(255, white);
	src1.setTo(0, black);

					//원본, 저장, 마스크크기
	medianBlur(src1, dst, 5);

	Mat src2;
					 //원본, 저장, 마스크크기,   일반적으로 0, 0, 생략가능
	GaussianBlur(src1, src2, Size(11, 11), 0, 0, BORDER_DEFAULT);


	//후추 소금뿌린거
	imshow("src1", src1);

	//중간값 필터링
	imshow("dst", dst);

	//평균값 필터링
	imshow("src2", src2);
	waitKey(0);
	return 0;
}
