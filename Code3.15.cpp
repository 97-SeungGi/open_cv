#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat img = imread("../images/image1.jpg");
	imshow("img", img);
	Mat roi(img, Rect(10, 10, 2, 2));

	cout << "���� �� =" << roi.rows << endl;
	cout << "���� �� =" << roi.cols << endl;
	cout << "roi =" << roi << endl;
	waitKey(0);
	return 0;
}
