#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
	//p 47��
	Mat src = imread ("D:/201837027Ȳ�±�/opencv_project/images/Lenna.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "������ ���� �� ����" << endl; }
	imshow ("src", src);

	Mat gray;
	cvtColor(src, gray, CV_BGR2GRAY);

	imshow("gray", gray);
	imwrite("D:/201837027Ȳ�±�/opencv_project/images/gray.jpg", gray);
	waitKey(0);
	return 0;
}