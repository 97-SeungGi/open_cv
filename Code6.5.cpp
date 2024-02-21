#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{

	Mat image = imread("../images/Lenna.jpg", 1);
	
	if (image.empty()) { return -1; }
	Mat dst;

	float weights[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };

	Mat mask = Mat(3, 3, CV_32F, weights);

	filter2D(image, dst, -1, mask, Point(-1, -1), 0, BORDER_DEFAULT);

	imshow("image", image);
	imshow("sharpen", dst);

	waitKey(0);
	return 0;
}
