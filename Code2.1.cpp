#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//p 35쪽
int main()
{
	//Mat 메트릭스의 약자 영상 데이터를 표현하기위해 사용하는 클래스
	Mat image;



	// image = imread 는 이미지 불러오기
	// image = imwrite 이미지 불러온걸 수정후 저장할때 필요한 함수 (위치경로, 파일이름을 지정해주면 저장해준다.)

	// IMREAD_COLOR => 이거 대신에 1, 0, -1 로 대체 가능 / IMREAD_COLOR (컬러) , IMREAD_GRAYSCALE (흑백) 을 많이씀
	image = imread("D:/201837027황승기/opencv_project/images/Lenna.jpg", IMREAD_COLOR);

	if (image.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	

	// 창으로 보여주기 위한것 imshow("")=> (창이름)
	imshow("출력 영상", image);

	//창 띄워주는 시간 여기에 적는 숫자는 ms임 1000 => 1초 , 0은 무한정 
	waitKey(0);
	return 0;
}

//이미지 파일처리
// 이미지 파일은 4개 값이 있고  b g r 순서 로 저장되어있다. (마지막값은 투명도임 기본값은 0 이라 없다고봄)