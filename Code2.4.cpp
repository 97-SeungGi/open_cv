#include	 <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main() {

	//���������� �ʱ�ȭ�� 600X400 ũ���� ���� ����
	Mat image = Mat(1000, 800, CV_8UC3, Scalar(225, 255, 115));

	line(image, Point(100, 100), Point(300, 300), Scalar(0, 0, 0));

	line(image, Point(100, 100), Point(300, 300), Scalar(0, 0, 255), 7);
	
	rectangle(image, Point(250, 30), Point(450, 200), Scalar(0, 255, 0), 5);

	circle(image, Point(100, 300), 60, Scalar(255, 0, 0), 3);

	//45 �� ���̴� �� 130���� ���� �ϴ� �κ� , 270�� �����º�
	ellipse(image, Point(300, 350), Point(100, 60), 0, 0, 180, Scalar(255, 255, 255), 5);
	ellipse(image, Point(300, 350), Point(100, 60), 180, 0, 180, Scalar(0, 0, 255), 5);


	imshow("Image", image);
	waitKey(0);
	return 0;

}