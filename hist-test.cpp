#include <opencv2/opencv.hpp>
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

void drawHist(int his[]) {

	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / 256);



	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	int max = his[0];

	for (int i = 1; i < 256; i++) {
		if (max < his[i]) {
			max = his[i];
		}
	}

	for (int i = 0; i < 255; i++) {
		his[i] = floor(((double)his[i] / max)*histImage.rows);
	}


	for (int i = 0; i < 255; i++) {
		line(histImage, Point(bin_w*(i), hist_h), Point(bin_w*(i), hist_h - his[i]), Scalar(0, 0, 255));
	}
	imshow("histogram", histImage);


}



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
	//Mat src = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);
	//Mat src = imread("../images/contrast.jpg", IMREAD_GRAYSCALE);
	Mat src = imread("../images/histo_test2.jpg", IMREAD_GRAYSCALE);



	Mat image = imread("../images/histo_test2.jpg", IMREAD_GRAYSCALE);




	Mat tt = imread("../images/histo_test2.jpg", IMREAD_GRAYSCALE);

	if (tt.empty()) { return -1; }

	Mat dst;
	equalizeHist(tt, dst);





	

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

			int output = stretch(image.at<uchar>(y, x), r1, s1, r2, s2);
			new_img.at<uchar>(y, x) = saturate_cast<uchar>(output);


		}
	}


	
	int his[256] = { 0 };
	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			his[(int)src.at<uchar>(y, x)]++;

		}
	}
	for (int count : his) {
		cout << count << ",";
	}

	imshow("평활화 이미지", dst);

	imwrite("../images/eq.jpg", dst);

	imshow("원본이미지", src);
	imshow("스트레칭 이미지", new_img);



	drawHist(his);
	waitKey(0);
	return 0;

}

