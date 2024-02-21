#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{

	Mat image = imread("../images/lenna.jpg", 1);
	Mat dst;

	imshow("출력 영상", image);
	if (image.empty()) { return -1; }

	for (int i = 1; i < 61; i = i + 2) {
		GaussianBlur(image, dst, Size(i, i), 0, 0);

		imshow("Gaussian filter", dst);

		waitKey(1000);
	}


	return 0;
}
