#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35��
int main()
{
	Mat image;

	image = imread("../images/Lenna.jpg", IMREAD_COLOR);

	if (image.empty()) { cout << "������ ���� �� ����" << endl; }

	imshow("��� ����", image);

	waitKey(0);
	return 0;
}

//�̹��� ����ó��
// �̹��� ������ 4�� ���� �ְ�  b g r ���� �� ����Ǿ��ִ�. (���������� ������ �⺻���� 0 �̶� ���ٰ�)