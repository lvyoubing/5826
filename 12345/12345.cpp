
/*#include "stdafx.h"

using namespace cv;
int main()
{
	IplImage*src=cvLoadImage("3.jpg");
	cvNamedWindow("example");
	cvShowImage("example",src);
	cvWaitKey(6000);
	cvReleaseImage(&src);
}*/

#include "stdafx.h"  
#include <cv.h>  
#include <highgui.h>  
  
IplImage* g_image = NULL;  
IplImage* g_gray = NULL;  
int g_thresh = 100;  
CvMemStorage* g_storage = nullptr;  
void on_trackbar(int)  
{  
    if (g_storage == nullptr)  
    {  
        g_gray = cvCreateImage(cvGetSize(g_image),8,1);  
        g_storage = cvCreateMemStorage(0);  
    }  
    else  
    {  
        cvClearMemStorage(g_storage);  
    }  
    CvSeq* contours = NULL;  
    cvCvtColor(g_image,g_gray,CV_BGR2GRAY);  
    cvThreshold(g_gray,g_gray,g_thresh,255,CV_THRESH_BINARY);  
    cvFindContours(g_gray,g_storage,&contours);  
    cvZero(g_gray);  
    if (contours)  
    {  
        cvDrawContours(g_gray,contours,cvScalarAll(255),cvScalarAll(255),100);  
    }  
    cvShowImage("Contours",g_gray);  
}  
  
int _tmain(int argc, _TCHAR* argv[])  
{  
    g_image = cvLoadImage("E:\12345\12345\\3.bmp");  
    cvNamedWindow("Contours",1);  
    cvCreateTrackbar("Threshold","Contours",&g_thresh,300,on_trackbar);  
    on_trackbar(0);  
    cvWaitKey(0);  
    printf("HELLO");  
    return 0;  
}  