#include "ros/ros.h"
#include "std_msgs/String.h"
//#include <toybox01/szCarStat.h>
#include <geometry_msgs/PolygonStamped.h>
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;

int main( int argc, char ** argv ){
  ros::init( argc, argv, "polychange_node" );
  ros::NodeHandle nh;
  ros::Publisher pub1 = nh.advertise<geometry_msgs::PolygonStamped>("pong1",1000);
  ros::Publisher pub2 = nh.advertise<geometry_msgs::PolygonStamped>("pong2",1000);
  cout << "polychange_node: hoge" << endl;
  ros::Rate loop_rate(10);

  geometry_msgs::PolygonStamped msg1;      
  geometry_msgs::Polygon  pg1;

  geometry_msgs::PolygonStamped msg2;      
  geometry_msgs::Polygon  pg2;

  geometry_msgs::Point32 p;      
  /*
  msg.header.seq=0;
  msg.header.stamp.secs=0;
  msg.header.stamp.nsecs=0;
  msg.header.frame_id="";*/
  msg1.header.seq=0;
  msg1.header.stamp=ros::Time::now();
  msg1.header.frame_id="/map";
  msg2.header.seq=0;
  msg2.header.stamp=msg1.header.stamp;
  msg2.header.frame_id="/map";
  int t = 0;
  //msg.polygon.push_back(pg);

  while( ros::ok() ){

    msg1.header.seq++;
    msg1.header.stamp=ros::Time::now();
    msg1.polygon.points.clear();
    for( int i = 0; i < 10; i++ ){ 
      p.x=sin(2.0*M_PI/10.0*(double)(t+i));
      p.y=i;
      p.z=0;
      msg1.polygon.points.push_back(p);
    }

    msg2.header.seq++;
    msg2.header.stamp=msg1.header.stamp;
    msg2.polygon.points.clear();
    for( int i = 0; i < 10; i++ ){ 
      p.x=i;
      p.y=sin(2.0*M_PI/10.0*(double)(t+i));
      p.z=cos(2.0*M_PI/10.0*(double)(t+i));
      msg2.polygon.points.push_back(p);
    }

    t++;
    pub1.publish( msg1 );
    pub2.publish( msg2 );
    ros::spinOnce();
    loop_rate.sleep();    
  }
  
  
  return 0;
}
