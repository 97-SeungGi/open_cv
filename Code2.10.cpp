#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {

	VideoCapture cap("../images/trailer.mp4");
	if (!cap.isOpened()) { cout << "영상을 읽을 수 없음" << endl;}
	namedWindow("frame", 1);
	
	//for 사용 가능 for(;;){ }
	while (1) {
		Mat frame;
		cap >> frame;
		imshow("frame", frame);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}