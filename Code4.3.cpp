#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35��
int main()
{

	Mat img = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);

	imshow("��� ����", img);

	moveWindow("��� ����", 100, 100);

	Mat oimage = img+30 ;
	//img.convertTo(oimage, -1, 1, 30);

	imshow("Newimage", oimage);
	moveWindow("Newimage", 600, 100);
	waitKey(0);
	return 0;
}
