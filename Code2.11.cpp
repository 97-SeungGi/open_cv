#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
int drawing = false;



int main()
{
	VideoCapture cap("../images/trailer.mp4");
	if (!cap.isOpened())
		return -1;


	namedWindow("frame", 1);

	for (;;) {


		Mat frame;
		cap >> frame;
		frame += Scalar (100, 0, 0);
		imshow("frame", frame);
		if (waitKey(30) >= 0) break;
	}

	return 0;
}
