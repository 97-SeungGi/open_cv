#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{

	Mat src, dst, abs_dst;

	//이미지 불러오기
	src = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);

	//잡음(노이즈 같은거)제거
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);

	//라플레시안 함수 사용
	Laplacian(src, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);



	
	imshow("src", src);
	imshow("Laplacian", abs_dst);
	waitKey(0);
	return 0;
}
