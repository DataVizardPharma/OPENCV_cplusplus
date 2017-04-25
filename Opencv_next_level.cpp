// Opencv_next_level.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include "opencv2/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int start_my_vid(){

	VideoCapture cap(0);
	if (cap.isOpened()) {
		cout << "ERROR" << endl;
		return -1;
	}
	namedWindow("My Video", CV_WINDOW_AUTOSIZE);
	double dWidth=cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout << "Frame Size" << dWidth << "x" << dHeight << endl;
	Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
	VideoWriter oVideoWriter("F:/MyVideo.avi", CV_FOURCC('P', 'I', 'M', '1'), 20, frameSize, true);

	if (!oVideoWriter.isOpened()) {
		cout << "ERROR:Failed to write the video" << endl;
		return -1;
	}
	while (1) {
		Mat frame;
		bool bSuccess = cap.read(frame);
		if (!bSuccess) {
			cout << "ERROR can't read a frame from video file" << endl;
			break;
		}
		oVideoWriter.write(frame);
		imshow("My video", frame);
		if (waitKey(10) == 27) {
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	waitKey(0);
	return 0;
}

int merode(const char* s_my_image) {

	IplImage* img = cvLoadImage(s_my_image);
	cvNamedWindow("MyWindow");
	cvShowImage("MyWindow", img);
	cvErode(img, img, 0, 2);
	cvNamedWindow("Eroded");
	cvShowImage("Eroded", img);
	cvWaitKey(0);
	cvDestroyWindow("MyWindow");
	cvDestroyWindow("Eroded");
	cvReleaseImage(&img);
	waitKey(0);
	return 0;
}

int rand_func()
	{
	string imageName("F:/octopus.png");

	Mat image;
	image = imread(imageName, IMREAD_COLOR);
	if (image.empty()) 
		{
		cout << "Could not open or find the image" << endl;
		return -1;
		}
	namedWindow("Display window", WINDOW_AUTOSIZE);
	waitKey(0);
	return 0;
};

int kern_func() {
	string imageName("F:/octopus.png");
	Mat image,dst;
	image = imread(imageName, IMREAD_COLOR);
	Mat kern = (Mat_<char>(3, 3) << 0, -1, 0,
		-1, 5, -1,
		0, -1, 0);
	filter2D(image,dst, image.depth(), kern);
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window",dst);
	imshow("Display window2", image);
	waitKey(0);
	return(0);
}

int main( int argc, char** argv)
{
	//kern_func();
	//rand_func()
	merode("F:/octopus.png");
	return(0);
}

