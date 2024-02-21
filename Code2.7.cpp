#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("D:/201837027황승기/opencv_project/images/Lenna.jpg", IMREAD_COLOR);

	if (src.empty()) { cout << "영상을 읽을 수 없음" << endl; }

	imshow("출력 영상", src);

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

//이미지 파일처리
// 이미지 파일은 4개 값이 있고  b g r 순서 로 저장되어있다. (마지막값은 투명도임 기본값은 0 이라 없다고봄)