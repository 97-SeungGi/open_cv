#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35��
int main()
{
	double alpha = 1.0;
	int beta = 0;


	
	Mat img = imread("../images/lenna.jpg",IMREAD_GRAYSCALE);
	
	//�������� ���
	imshow("����", img);


	Mat oimage;


	//32��Ʈ¥�� ũ���� �̹����� 8��Ʈ�� ����ϴϱ� ���������� �ȳ���
	img.convertTo(oimage, CV_32F);

	imshow("CV_32F", oimage);

	//img�� CV_8UC1���� �ٲ㼭 ����ϸ� ������µ�
	oimage.convertTo(img, CV_8UC1);

	imshow("CV_8UC1", img);


	//oimage �� �ٽ� CV_8UC1 ���� �ٲٰ� ����ϴ� ���������� ���
	img.convertTo(oimage, CV_8UC1);

	imshow("CV_32F_1", oimage);


	moveWindow("Newimage", 600, 100);
	waitKey(0);
	return 0;
}
