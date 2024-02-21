#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat image = imread("../images/opencv.png");

	if (image.empty()) { cout << "영상을 읽을 수 없음" << endl; return -1; }


	imshow("출력 영상", image);
	cout << image << endl;
	waitKey(0);
	return 0;
}
