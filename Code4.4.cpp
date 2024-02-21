#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// &�� ���� �Ⱦ����� ����

// Mat img �������� ���� ��������
// �Լ����� img ������ �ٲ㵵 �ؿ��� Mat ��ü�� �ȹٲ� (�Լ��ȿ��� �ٲ۰��� ���ξȿ��� �ٲ۰� �ƴ϶�)
//& �Ⱦ��� �ּҸ� ���Ƿ� ���ؼ� ���� �ٲٰ� ���ο��� �����ϴ°� 100�̶� ���� �ȹٲ�°�.


//Mat img& �� ������ �ּҿ����� ������ ���� ���� �ؿ��ִ� Mat img ��
//�ּҸ� �ٿ��ָ� ���ο��ִ� img �ּҸ� �ѱ�Ŷ� �ּҾȿ� �ִ� ���� �ٲ۰Ŷ� �ᱹ �Լ����� ���� �ٲ㵵 ���ο����� �����̵�.

//�ٵ� ���ݰ� �Ѵ� �������翡 �������� ���ο��� �ذ�����?(�³�?) ����� ����.


void brighten(Mat img, int value) {

	for (int r = 0; r < img.rows; r++)
		for (int c = 0; c < img.cols; ++c)
			img.at<uchar>(r, c) = saturate_cast<uchar>(img.at<uchar>(r, c) + value);

}


int main()
{

	Mat img = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);

	imshow("��� ����", img);

	moveWindow("��� ����", 100, 100);


	brighten(img, 30);
	
	imshow("New Image", img);
	moveWindow("New Image",700,100);
	waitKey(0);
	return 0;
}
