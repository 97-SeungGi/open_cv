#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35쪽
int main()
{
	double alpha = 1.0;
	int beta = 0;


	
	Mat img = imread("../images/lenna.jpg",IMREAD_GRAYSCALE);
	
	//원본영상 출력
	imshow("원본", img);


	Mat oimage;


	//32비트짜리 크기의 이미지를 8비트로 출력하니까 정상적으로 안나옴
	img.convertTo(oimage, CV_32F);

	imshow("CV_32F", oimage);

	//img를 CV_8UC1으로 바꿔서 출력하면 정상출력됨
	oimage.convertTo(img, CV_8UC1);

	imshow("CV_8UC1", img);


	//oimage 를 다시 CV_8UC1 으로 바꾸고 출력하니 정상적으로 출력
	img.convertTo(oimage, CV_8UC1);

	imshow("CV_32F_1", oimage);


	moveWindow("Newimage", 600, 100);
	waitKey(0);
	return 0;
}
