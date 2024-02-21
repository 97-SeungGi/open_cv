#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{

	Mat A = imread("../images/image2.jpg");
	Mat B = imread("../images/image2.jpg");
	imshow("A", A);

	flip(B, B, 0);
	cout << "B¸¸ ¹ÝÀü" << endl;
	imshow("B", B);
	waitKey(0);
	return 0;
}
