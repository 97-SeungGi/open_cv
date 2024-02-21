#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{

	Mat src = imread("../images/Crayfish.JPG", IMREAD_GRAYSCALE);

	if (src.empty()) { return -1; }

	Mat dst;
	equalizeHist(src, dst);

	imshow("출력 영상", dst);

	waitKey(0);
	return 0;
}
