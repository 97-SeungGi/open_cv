#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{

	Mat image = imread("../images/dog.jpg", IMREAD_COLOR);
	Mat dst;

	if (image.empty()) { return -1; }

	blur(image, dst, Size(11, 11));

	imshow("출력 영상", image);
	imshow("result", dst);
	waitKey(0);
	return 0;
}
