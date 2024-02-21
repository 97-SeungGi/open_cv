#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35쪽
int main()
{
	double alpha = 1.0;
	int beta = 0;


	Mat img = imread("../images/contrast.jpg");

	Mat oimage = Mat::zeros(img.size(), img.type());
	
	cout << "알파값 입력:"; cin >> alpha;
	cout << "배타값 입력:"; cin >> beta;

	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			for (int c = 0; c < 3; c++) {

				oimage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha*(img.at<Vec3b>(y, x)[c] + beta));
			}
		}
	}
	imshow("Original Image", img);
	moveWindow("Newimage", 300, 100);
	imshow("Newimage", oimage);
	moveWindow("Newimage", 600, 100);
	waitKey(0);
	return 0;
}
