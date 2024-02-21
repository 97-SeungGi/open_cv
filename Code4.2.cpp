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

	for (int r = 0; r < img.rows; r++) {
		uchar *p = img.ptr<uchar>(r);
		for (int c = 0; c < img.cols; c++) {
			p[c] = saturate_cast<uchar>(p[c] + 30);
		}
	}
	imshow("Newimage", img);
	moveWindow("Newimage", 600, 100);
	waitKey(0);
	return 0;
}
