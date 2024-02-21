#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35쪽
int main()
{
	Mat image;

	image = imread("../images/Lenna.jpg", IMREAD_COLOR);

	if (image.empty()) { cout << "영상을 읽을 수 없음" << endl; }

	imshow("출력 영상", image);

	waitKey(0);
	return 0;
}

//이미지 파일처리
// 이미지 파일은 4개 값이 있고  b g r 순서 로 저장되어있다. (마지막값은 투명도임 기본값은 0 이라 없다고봄)