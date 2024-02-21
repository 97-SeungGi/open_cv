#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat img, roi;
int mx1, my1, mx2, my2;
bool cropping = false;


void onMouse(int event, int x, int y, int flags, void* param) 
{
	if (event == EVENT_LBUTTONDOWN) {
		mx1 = x;
		my1 = y;
		cropping = true;
	}
	else if (event == EVENT_LBUTTONUP) {
		mx2 = x;
		my2 = y;
		cropping = false;
		rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);
		
		imshow("img", img);
	}
}


int main()
{

	img = imread("../images/lenna.jpg");
	imshow("img", img);
	Mat tes = img.clone();

	setMouseCallback("image", onMouse);

	while (1) {
		int key = waitKey(100);

		if (key == 'q') break;
		else if (key == 'c') {
			roi = tes(Rect(mx1, my1, mx2 - mx1, my2 - my1));
			imwrite("../images/result.jpg", roi);
		}
	}

	return 0;
}
