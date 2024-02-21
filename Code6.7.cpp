#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{

	Mat src, dst, abs_dst;

	//�̹��� �ҷ�����
	src = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);

	//����(������ ������)����
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);

	//���÷��þ� �Լ� ���
	Laplacian(src, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);



	
	imshow("src", src);
	imshow("Laplacian", abs_dst);
	waitKey(0);
	return 0;
}
