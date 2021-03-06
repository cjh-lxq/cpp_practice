#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
//<>先去系统目录中找头文件，如果没有在到当前目录下找。所以像标准的头文件 stdio.h、stdlib.h等用这个方法。
//而""首先在当前目录下寻找，如果找不到，再到系统目录中寻找。 这个用于include自定义的头文件，让系统优先使用当前目录中定义的。
using namespace std;
using namespace cv; 
using cv::Mat;
Mat read_image(void)
{
	Mat img = imread("D:\\jt.jpg",100);
	resize(img, img, Size(1280, 720));
	return img;
}
void fu_shi(void)
{
	Mat img_org = read_image();
	resize(img_org, img_org, Size(400, 400));
	Mat core_fs = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat img_fs;
	erode(img_org, img_fs, core_fs);
	imshow("123", img_org);
	imshow("234", img_fs);
	waitKey(0);
}
void use_blur(void)
{
	Mat img_org = read_image();
	Mat img_blur;
	blur(img_org, img_blur, Size(7, 7));
	imshow("123", img_org);
	imshow("234", img_blur);
	waitKey(0);
}
void use_canny()
{
	Mat img_org = read_image();
	Mat img_dst, img_gray, edge;
	img_dst.create(img_org.size(), img_org.type());
	cvtColor(img_org, img_gray, COLOR_BGR2GRAY);
	blur(img_gray, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	imshow("org", img_org);
	imshow("canny", edge);
	waitKey(0);
}
int main()
{

    cout << "Hello World!\n"<<endl; 
	printf("陈建宏");
	//fu_shi();
	//use_blur();
	use_canny();
}