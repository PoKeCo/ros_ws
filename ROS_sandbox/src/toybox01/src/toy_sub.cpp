#include "ros/ros.h"
#include "std_msgs/String.h"
#include <toybox01/szCarStat.h>
#include <sstream>
#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>

using namespace std;

//cv::Mat MonImg;

void carStatCallback(const toybox01::szCarStat::ConstPtr& msg){
  cout <<
    "X: " << msg->posX << ", " <<
    "Y: " << msg->posY << ", " <<
    "T: " << msg->posT << endl;
  
}
int main( int argc, char ** argv ){
  
  ros::init( argc, argv, "toy_pub" );
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("carStat",1000,carStatCallback);
  cout << "Node : toy_sub" << endl;
  //MonImg = cv::Mat(cv::Size(1024,512),CV_8UC3, cv::Scalar(0,0,0));
  ros::spin();
  return 0;
}
