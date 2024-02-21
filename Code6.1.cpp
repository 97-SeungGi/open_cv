#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{

	Mat image = imread("../images/Lenna.jpg", IMREAD_GRAYSCALE);
	Mat dst(image.size(), CV_8U, Scalar(0));
	if (image.empty()) { return -1; }


	for (int y = 1; y < image.rows -1; y++) {
		for (int x = 1; x < image.cols - 1; x++) {
			int sum = 0;
			sum += image.at<uchar>(y - 1, x - 1);
			sum += image.at<uchar>(y , x - 1);
			sum += image.at<uchar>(y + 1, x - 1);
			sum += image.at<uchar>(y - 1, x);
			sum += image.at<uchar>(y , x);
			sum += image.at<uchar>(y + 1, x);
			sum += image.at<uchar>(y - 1, x + 1);
			sum += image.at<uchar>(y , x + 1);
			sum += image.at<uchar>(y + 1, x + 1);
			dst.at<uchar>(y, x) = sum / 9;
		 }
	}


	imshow("출력 영상", image);
	imshow("final", dst);
	waitKey(0);
	return 0;
}