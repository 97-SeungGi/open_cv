#include "opencv2/opencv.hpp"
using namespace cv;

int main() {
	Mat A;
	A = imread("../images/Lenna.jpg", IMREAD_COLOR);

	Rect r(10, 10, 100, 100);
	Mat D = A(r);
	D = Scalar(0, 0, 0);
	imshow("src", A);
	waitKey();
	return 0;
}
