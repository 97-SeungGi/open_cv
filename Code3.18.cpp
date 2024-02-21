#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat m = Mat::ones(4, 4, CV_32FC1);
	cout << m << endl;

	m = m.reshape(0, 2);
	cout << m << endl;

	return 0;
}
