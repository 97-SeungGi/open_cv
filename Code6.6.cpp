#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src, grad, grad_x,  grad_y, abs_grad_x, abs_grad_y;

	src = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);

	Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	Sobel(src, grad_y, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x );
	convertScaleAbs(grad_y, abs_grad_y );
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

	imshow("src", src);
	imshow("Sobel", grad);
	waitKey(0);
	return 0;
}
