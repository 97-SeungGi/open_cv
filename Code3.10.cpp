#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void sub(Mat img) {
	img = Scalar(0, 0, 0);

}

int main()
{
	Mat A;
	A = imread("../images/image1.jpg", IMREAD_COLOR);
	imshow("A", A);
	sub(A);
	imshow("newA", A);
	waitKey(0);

	return 0;
}
