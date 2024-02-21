#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("../images/city1.jpg", IMREAD_GRAYSCALE);
	Mat dst;

	Mat noise = Mat::zeros(src.rows, src.cols, CV_8U);
	randu(noise, 0, 255);

	Mat black = noise < 10;
	Mat white = noise > 245;

	Mat src1 = src.clone();
	src1.setTo(255, white);
	src1.setTo(0, black);

					//����, ����, ����ũũ��
	medianBlur(src1, dst, 5);

	Mat src2;
					 //����, ����, ����ũũ��,   �Ϲ������� 0, 0, ��������
	GaussianBlur(src1, src2, Size(11, 11), 0, 0, BORDER_DEFAULT);


	//���� �ұݻѸ���
	imshow("src1", src1);

	//�߰��� ���͸�
	imshow("dst", dst);

	//��հ� ���͸�
	imshow("src2", src2);
	waitKey(0);
	return 0;
}
