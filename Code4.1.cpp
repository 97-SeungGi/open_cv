#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35쪽
int main()
{

	Mat img = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);

	imshow("출력 영상", img);

	moveWindow("출력 영상",100,100 );

	for (int r = 0; r < img.rows; r++)
		for (int c = 0; c < img.cols; c++)
			img.at<uchar>(r, c) = saturate_cast<uchar>(img.at<uchar>(r, c) + 30);

	imshow("Newimage", img);
	moveWindow("Newimage", 600, 100);
	waitKey(0);
	return 0;
}
