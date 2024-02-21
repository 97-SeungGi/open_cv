#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;



int contrastEnh(int input, int x1, int y1, int x2, int y2) {
	double output;
	if (0 <= input && input <= x1) {
	
		output = y1 / x1 * input;
	
	}
	else if(x1 < input && input < x2){

		output = (y2 - y1) / (x2 - x1) * (input - x1) + y1;
	
	}
	else if (x2 < input && input < 255) {

		output = (255 - y2) / (x2 - 255) * (input - x2) + y2;

	}

	return (int)output;

}



int main()
{
	

	Mat img = imread("../images/Lenna.jpg");

	Mat oimage = img.clone();

	int x1, y1, x2, y2;
	cout << "x1값"; cin >> x1;
	cout << "y1값"; cin >> y1;

	cout << "x2값"; cin >> x2;
	cout << "y2값"; cin >> y2;

	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			for (int c = 0; c < 3; c++) {
				int output = contrastEnh(img.at<Vec3b>(y, x)[c], x1, y1, x2, y2);
				oimage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(output);
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
