#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;



int stretch(int x, int r1, int s1, int r2, int s2) {
	float result;

	if (0 <= x && x <= r1) {
		result = s1 / r1 * x;
	}

	else if (r1 <= x && x <= r2) {
		result = ((s2 - s1) / (r2 - r1)) * (x - r1) + s1;
	}

	else if (r2 < x && x <= 255) {
		result = ((255 - s2) / (255 - r2)) * (x - r2) + s2;
	}
	return (int)result;
}



int main()
{
	Mat image = imread("../images/Crayfish.JPG",IMREAD_GRAYSCALE );

	Mat new_img = image.clone();

	int r1, s1, r2, s2;

	cout << "r1"; 
	cin >> r1;

	cout << "r2";
	cin >> r2;

	cout << "s1";
	cin >> s1;

	cout << "s2";
	cin >> s2;

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			/*for (int c = 0; c < 3; c++) {
				int output = stretch(image.at<Vec3b>(y, x)[c], r1, s1, r2, s2);
				new_img.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(output);
			}*/

			int output = stretch (image.at<uchar>(y, x), r1, s1, r2, s2);
			new_img.at<uchar>(y, x) = saturate_cast<uchar>(output);
		

		}
	}


	imshow("입력 영상", image);
	
	imshow("출력 영상", new_img);
	waitKey();
	return 0;
}
