#include <stdio.h>
#include <iostream>
//#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv/cv.h>
//#include <opencv/highgui.h>

typedef struct _dat{
  int x;
  int y;
  int z;
} dat;

typedef dat* dat_ptr;
using namespace std;
using namespace cv;

Mat MonImg;

void add( int &ans, int &x, int &y ){
  ans = x + y ;
}

void add( dat& d ){
  d.z = d.x + d.y ;
}

void add( dat_ptr& d ){
  d->z = d->x + d->y ;
}

int main(int argc, char *argv[] ){
  int x, y, z ;
  MonImg = cv::Mat(cv::Size(1024,512), CV_8UC3, cv::Scalar(0,0,255) ) ; 
  //IplImage *pMonImg = cvCreateImage( cvSize( 1024, 512 ), CV_8UC3, 3 );
  //cvNamedWindow("Debug", CV_WINDOW_AUTOSIZE);
  namedWindow("monimg", CV_WINDOW_AUTOSIZE);
  for( int i=0; i < 30; i ++  ){
    imshow("monimg", MonImg );
    //cvShowImage( "Debug", pMonImg );
    //waitKey(0);
    cvWaitKey(100);
  }
  
  dat d;
  dat_ptr dp = (&d);
  d.x = x = 10;
  d.y = y = 20;
  d.z = z = 0;
  printf("%d = %d + %d \n", z, x, y );
  add( z, x, y );
  printf("%d = %d + %d \n", z, x, y );
  add( d );
  printf("%d = %d + %d \n", d.z, d.x, d.y );
  add( dp );
  printf("%d = %d + %d \n", dp->z, dp->x, dp->y );

  cout << "Using cout" << endl;

  cv::destroyWindow("monimg");

  return 0;
}
