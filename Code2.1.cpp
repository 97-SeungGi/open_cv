#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35��
int main()
{
	//Mat ��Ʈ������ ���� ���� �����͸� ǥ���ϱ����� ����ϴ� Ŭ����
	Mat image;



	// image = imread �� �̹��� �ҷ�����
	// image = imwrite �̹��� �ҷ��°� ������ �����Ҷ� �ʿ��� �Լ� (��ġ���, �����̸��� �������ָ� �������ش�.)

	// IMREAD_COLOR => �̰� ��ſ� 1, 0, -1 �� ��ü ���� / IMREAD_COLOR (�÷�) , IMREAD_GRAYSCALE (���) �� ���̾�
	image = imread("D:/201837027Ȳ�±�/opencv_project/images/Lenna.jpg", IMREAD_COLOR);

	if (image.empty()) { cout << "������ ���� �� ����" << endl; }
	

	// â���� �����ֱ� ���Ѱ� imshow("")=> (â�̸�)
	imshow("��� ����", image);

	//â ����ִ� �ð� ���⿡ ���� ���ڴ� ms�� 1000 => 1�� , 0�� ������ 
	waitKey(0);
	return 0;
}

//�̹��� ����ó��
// �̹��� ������ 4�� ���� �ְ�  b g r ���� �� ����Ǿ��ִ�. (���������� ������ �⺻���� 0 �̶� ���ٰ�)