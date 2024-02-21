#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35��
int main()
{
	double alpha = 1.0;
	int beta = 0;


	Mat img = imread("../images/contrast.jpg");

	Mat oimage;

	cout << "���İ� �Է�:"; cin >> alpha;
	cout << "��Ÿ�� �Է�:"; cin >> beta;


	oimage = img * alpha + beta;


	imshow("Original Image", img);

	imshow("Newimage", oimage);

	waitKey(0);
	return 0;
}
