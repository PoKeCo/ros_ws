#include "ros/ros.h"
#include "std_msgs/String.h"
#include <toybox02/szCarStat.h>
#include <toybox02/szAryCarStat.h>
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;

class CHoge{
public:
  CHoge(){
    a = 10;
    b = 20;
    cout << "CHoge Constracter"<<endl;
  }
  ~CHoge(){
    cout << "CHoge Destructor"<<endl;
  }
private:
  int a;
  int b;
};

int main( int argc, char ** argv ){
  CHoge hoge;
  ros::init( argc, argv, "toy_ary_sub" );
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<toybox02::szAryCarStat>("carAryStat",1000);
  cout << "Node : toy_ary_pub" << endl;

  ros::Rate loop_rate(10);


  toybox02::szAryCarStat msg;      
  toybox02::szCarStat    car;      

  while( ros::ok() ){
    msg.cars.clear();
    int car_cnt = (rand() & 7);
    for( int i = 0; i < car_cnt ; i ++ ){
      car.posX =(double)(rand() & 255);
      car.posY =(double)(rand() & 255);
      car.posT =(double)(rand() & 255);
      cout <<
	"No." << i << ":" <<
	"X: " << car.posX << ", " <<
	"Y: " << car.posY << ", " <<
	"T: " << car.posT << endl;
      msg.cars.push_back( car );
    }

    pub.publish( msg );
    ros::spinOnce();
    loop_rate.sleep();    
  }
  
  
  return 0;
}
