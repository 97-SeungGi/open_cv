#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("D:/201837027Ȳ�±�/opencv_project/images/Lenna.jpg", IMREAD_COLOR);

	if (src.empty()) { cout << "������ ���� �� ����" << endl; }

	imshow("��� ����", src);

	while (1) {
		int key = waitKeyEx(); 
		cout << key << " ";
		if (key == 'q') break;
		else if (key == 2424832) {
			src -= 50;
		}
		else if (key == 2555904){
			src += 50;
		}
		imshow("src", src);
	}
	return 0;
}

//�̹��� ����ó��
// �̹��� ������ 4�� ���� �ְ�  b g r ���� �� ����Ǿ��ִ�. (���������� ������ �⺻���� 0 �̶� ���ٰ�)