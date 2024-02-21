#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// &를 쓰나 안쓰나의 차이

// Mat img 값에의한 전달 얕은복사
// 함수에서 img 내용을 바꿔도 밑에있 Mat 객체는 안바뀜 (함수안에서 바꾼거지 메인안에서 바꾼게 아니라서)
//& 안쓰면 주소를 임의로 정해서 값을 바꾸고 메인에서 참조하는건 100이라서 값이 안바뀌는것.


//Mat img& 이 있으면 주소에의한 참조에 의한 전달 밑에있는 Mat img 임
//주소를 붙여주면 메인에있는 img 주소를 넘긴거라 주소안에 있는 값을 바꾼거라 결국 함수에서 값을 바꿔도 메인에서도 적용이됨.

//근데 지금건 둘다 얕은복사에 수정값은 메인에서 해가지고?(맞나?) 결과는 같음.


void brighten(Mat img, int value) {

	for (int r = 0; r < img.rows; r++)
		for (int c = 0; c < img.cols; ++c)
			img.at<uchar>(r, c) = saturate_cast<uchar>(img.at<uchar>(r, c) + value);

}


int main()
{

	Mat img = imread("../images/lenna.jpg", IMREAD_GRAYSCALE);

	imshow("출력 영상", img);

	moveWindow("출력 영상", 100, 100);


	brighten(img, 30);
	
	imshow("New Image", img);
	moveWindow("New Image",700,100);
	waitKey(0);
	return 0;
}
