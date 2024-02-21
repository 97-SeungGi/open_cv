#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {

	VideoCapture cap("../images/trailer.mp4");
	if (!cap.isOpened()) { cout << "������ ���� �� ����" << endl;}
	namedWindow("frame", 1);
	
	//for ��� ���� for(;;){ }
	while (1) {
		Mat frame;
		cap >> frame;
		imshow("frame", frame);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}