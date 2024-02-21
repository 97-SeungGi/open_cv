#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat img = imread("../images/Lenna.jpg");
	imshow("¿øº»", img);

	Mat result(img.rows + 20, img.cols + 20, img.type(), Scalar(0));


	copyMakeBorder(img, result,10,10,10,10,BORDER_CONSTANT );
	imshow("BORDER_CONSTANT", result);

	//copyMakeBorder(img, result, 10, 10, 10, 10, BORDER_DEFAULT);
	//imshow("BORDER_DEFAULT", result);

	//copyMakeBorder(img, result, 10, 10, 10, 10, BORDER_ISOLATED);
	//imshow("BORDER_ISOLATED", result);

	copyMakeBorder(img, result, 10, 10, 10, 10, BORDER_REFLECT);
	imshow("BORDER_REFLECT", result);

	copyMakeBorder(img, result, 10, 10, 10, 10, BORDER_REPLICATE);
	imshow("BORDER_REPLICATE", result);

	
	copyMakeBorder(img, result, 10, 10, 10, 10, BORDER_WRAP);
	imshow("BORDER_WRAP", result);


	waitKey(0);
	return 0;
}
