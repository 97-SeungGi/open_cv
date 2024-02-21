#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat img;
int red, green, blue;
int drawing = false;

void on_trackbar(int, void*) { }

void drawCircle(int event, int x, int y, int flags, void* param) {
	if (event == EVENT_LBUTTONDOWN)
		drawing = true;
	else if (event == CV_EVENT_MOUSEMOVE) {
		if (drawing == true)
			circle(img, Point(x, y), 3, Scalar(blue, green, red), 10);
	}
	else if (event == CV_EVENT_LBUTTONUP)
		drawing = false;
	imshow("img", img);
}



int main() {
	
	img = imread("D:/201837027황승기/opencv_project/images/dog.jpg");
	if (img.empty()) { cout << "영상을 읽을 수 없음" << endl; return -1; }
	namedWindow("img", 1);
	imshow("img", img);
	setMouseCallback("img", drawCircle);
	createTrackbar("R", "img", &red, 255, on_trackbar);
	createTrackbar("G", "img", &green, 255, on_trackbar);
	createTrackbar("B", "img", &blue, 255, on_trackbar);
	waitKey(0);
	return 0;
}