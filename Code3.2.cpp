#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat image = imread("../images/opencv.png");

	if (image.empty()) { cout << "������ ���� �� ����" << endl; return -1; }


	imshow("��� ����", image);
	cout << image << endl;
	waitKey(0);
	return 0;
}
