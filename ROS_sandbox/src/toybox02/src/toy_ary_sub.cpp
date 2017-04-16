#include "ros/ros.h"
#include "std_msgs/String.h"
#include <toybox02/szCarStat.h>
#include <toybox02/szAryCarStat.h>
#include <sstream>
#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>

using namespace std;

//cv::Mat MonImg;

void carStatCallback(const toybox02::szAryCarStat::ConstPtr& msg){
  toybox02::szCarStat car;
  for( int i = 0; i < msg->cars.size() ; i ++ ){
    car = msg->cars.at( i );
    cout <<
      "No." <<i<< ":" <<
      "X: " << car.posX << ", " <<
      "Y: " << car.posY << ", " <<
      "T: " << car.posT << endl;
  }
    
}
int main( int argc, char ** argv ){
  
  ros::init( argc, argv, "toy_ary_pub" );
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("carAryStat",1000,carStatCallback);
  cout << "Node : toy_ary_sub" << endl;
  //MonImg = cv::Mat(cv::Size(1024,512),CV_8UC3, cv::Scalar(0,0,0));
  ros::spin();
  return 0;
}
