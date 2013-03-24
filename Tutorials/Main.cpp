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



int main( int argc, char** argv )
{
	return basicTest(argc, argv);
}