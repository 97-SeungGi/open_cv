#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat E = Mat::eye(4, 4, CV_64F);
	cout << "E = " << endl << " " << E << endl << endl;

	Mat O = Mat::eye(2, 2, CV_64F);
	cout << "O = " << endl << " " << O << endl << endl;

	Mat Z = Mat::eye(3, 3, CV_64F);
	cout << "Z = " << endl << " " << Z << endl << endl;

	return 0;
}
