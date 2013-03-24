#include <cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int basicTest(int argc, char** argv)
{
	Mat A, Gray;
	char * imageName = "..\\Images\\Original.png";
	if(argc > 1)
	{
		imageName = argv[1];
	}
	A = imread(imageName, CV_LOAD_IMAGE_COLOR);
	if (!A.data)
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}

	cvtColor(A, Gray, CV_BGR2GRAY);

	imwrite("..\\Images\\Gray.jpg", Gray);

	namedWindow("Color Image", CV_WINDOW_AUTOSIZE);
	namedWindow("Gray Image", CV_WINDOW_AUTOSIZE);
	imshow("Color Image", A);
	imshow("Gray Image", Gray);

	waitKey(0);
	return 0;
}

void doSomething(Mat initial, Mat blank)
{
	// Todo: Do something interesting and save it in 'blank'
	initial.copyTo(blank);
}

int cameraTest()
{
	VideoCapture camera;
	int cameraNumber = 0;
	camera.open(cameraNumber);

	if(!camera.isOpened())
	{
		cerr << "ERROR: NO CAMERA AVAILABLE!?" << endl;
		exit(1);
	}

	camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

	// Main loop 
	while(true)
	{
		Mat cameraFrame;

		// Gets the current camera frame
		camera >> cameraFrame;

		if(cameraFrame.empty())
		{
			cerr << "ERROR: NO CAMERA FRAME!?" << endl;
			exit(1);
		}

		// Output image to be drawn onto
		Mat displayedFrame(cameraFrame.size(), CV_8UC3);

		// Do something interesting to this frame
		doSomething(cameraFrame, displayedFrame);

		// Display the interesting thing
		imshow("Cam", displayedFrame);

		char keypress = waitKey(20);
		if(keypress == 27)
		{
			break;
		}
	}
}

int main( int argc, char** argv )
{
	cameraTest();
	return 0;
}