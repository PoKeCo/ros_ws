#include "ros/ros.h"
#include "std_msgs/String.h"
#include <toybox01/szCarStat.h>
#include <sstream>
#include <iostream>

using namespace std;

class CHoge{
public:
  CHoge(){
    a = 10;
    b = 20;
    c = 30;
    cout << "CHoge Constracter"<<endl;
  }
  ~CHoge(){
    cout << "CHoge Destracter"<<endl;
  }
private:
  int a;
  int b;
  int c;
};

int main( int argc, char ** argv ){
  CHoge hoge;
  ros::init( argc, argv, "toy_sub" );
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<toybox01::szCarStat>("carStat",1000);
  cout << "Node : toy_pub" << endl;

  ros::Rate loop_rate(10);


  toybox01::szCarStat msg;      
  msg.posX = 0;
  msg.posY = 0;
  msg.posT = 0;
  while( ros::ok() ){
    msg.posX +=10.0;
    msg.posY += 1.0;
    msg.posT += 0.1;
    cout <<
      "X: " << msg.posX << ", " <<
      "Y: " << msg.posY << ", " <<
      "T: " << msg.posT << endl;

    pub.publish( msg );
    ros::spinOnce();
    loop_rate.sleep();    
  }
  
  
  return 0;
}
