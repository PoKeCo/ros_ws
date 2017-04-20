#include "ros/ros.h"
#include "std_msgs/String.h"
#include <toybox03/szCarStat.h>
#include <toybox03/szAryCarStat.h>
#include <sstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
ros::Subscriber sub;
ros::Publisher  pub;

void carStatCallback(const toybox03::szAryCarStat::ConstPtr& rx_msg){
  toybox03::szAryCarStat tx_msg;      
  toybox03::szCarStat car;
  /*
  for( int i = 0; i < rx_msg->cars.size() ; i ++ ){
    car = rx_msg->cars.at( i );
    cout <<
      "RX:" <<i<< ":" <<
      "X: " << car.posX << ", " <<
      "Y: " << car.posY << ", " <<
      "T: " << car.posT << endl;
  }
  */

  for( std::vector<toybox03::szCarStat>::const_iterator icar = rx_msg->cars.begin(); icar != rx_msg->cars.end() ; icar ++ ){
  //for( auto icar = rx_msg->cars.begin(); icar != rx_msg->cars.end() ; icar ++ ){ //NG
  //for( auto icar : rx_msg->cars ){                                               //NG  
    cout <<
      "RX:" << ":" <<
      "X: " << icar->posX << ", " <<
      "Y: " << icar->posY << ", " <<
      "T: " << icar->posT << endl;
  }

  ///////////////////////////////////
  tx_msg.cars.clear();
  car.posX +=1.0;
  car.posY +=1.0;
  car.posT +=1.0;
  cout <<
	"TX:" << 1 << ":" <<
	"X: " << car.posX << ", " <<
	"Y: " << car.posY << ", " <<
	"T: " << car.posT << endl;
  tx_msg.cars.push_back( car );
  ///////////////////////////////////

  pub.publish( tx_msg );
    
}
int main( int argc, char ** argv ){
  
  ros::init( argc, argv, "toy_loop_sub" );
  ros::NodeHandle nh;
  sub = nh.subscribe("rx",1000,carStatCallback);
  pub = nh.advertise<toybox03::szAryCarStat>("tx",1000);

  cout << "Node : toy_ary_sub" << endl;
  
  
  toybox03::szAryCarStat msg;      
  toybox03::szCarStat    car;      

  ///////////////////////////////////
  msg.cars.clear();
  car.posX =0.0;
  car.posY =0.0;
  car.posT =0.0;
  cout <<
	"TX:" << 0 << ":" <<
	"X: " << car.posX << ", " <<
	"Y: " << car.posY << ", " <<
	"T: " << car.posT << endl;
  msg.cars.push_back( car );
  //////////////////////////////////

  pub.publish( msg );
  ros::spinOnce();

  ros::spin();
  return 0;
}
