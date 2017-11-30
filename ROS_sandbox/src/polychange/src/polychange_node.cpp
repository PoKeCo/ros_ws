#include "ros/ros.h"
#include "std_msgs/String.h"
//#include <toybox01/szCarStat.h>
#include <geometry_msgs/PolygonStamped.h>
#include <jsk_recognition_msgs/PolygonArray.h>
#include <geometry_msgs/Polygon.h>
#include <geometry_msgs/PoseStamped.h>
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;

int main( int argc, char ** argv ){
  ros::init( argc, argv, "polychange_node" );
  ros::NodeHandle nh;
  ros::Publisher pub1 = nh.advertise<geometry_msgs::PolygonStamped>("pong1",1000);
  ros::Publisher pub2 = nh.advertise<geometry_msgs::PolygonStamped>("pong2",1000);
  ros::Publisher pub3 = nh.advertise<geometry_msgs::Polygon>("pong3",1000);
  ros::Publisher pub4 = nh.advertise<jsk_recognition_msgs::PolygonArray>("pong4",1000);
  ros::Publisher pub5 = nh.advertise<geometry_msgs::PoseStamped>("pong5",1000);
  cout << "polychange_node: hoge" << endl;
  ros::Rate loop_rate(10);

  std_msgs::Header h;      
  geometry_msgs::PolygonStamped msg1;      
  geometry_msgs::Polygon  pg1;

  geometry_msgs::PolygonStamped msg2;      
  geometry_msgs::Polygon  pg2;
  geometry_msgs::Polygon  msg3;

  jsk_recognition_msgs::PolygonArray msg4;
  geometry_msgs::PolygonStamped ps;      
  geometry_msgs::Point32 p;      

  geometry_msgs::PoseStamped msg5;

  h.seq = 0;
  h.stamp=ros::Time::now();
  h.frame_id="/map";
  int t = 0;
  //msg.polygon.push_back(pg);

  while( ros::ok() ){

    //Set Header 
    h.seq ++;
    h.stamp=ros::Time::now();

    //Set msg1
    msg1.header = h;
    msg1.polygon.points.clear();
    for( int i = 0; i < 10; i++ ){ 
      p.x=sin(2.0*M_PI/10.0*(double)(t+i));
      p.y=i;
      p.z=0;
      msg1.polygon.points.push_back(p);
    }

    //Set msg2
    msg2.header = h;
    msg2.polygon.points.clear();
    for( int i = 0; i < 10; i++ ){ 
      p.x=i;
      p.y=sin(2.0*M_PI/10.0*(double)(t+i));
      p.z=cos(2.0*M_PI/10.0*(double)(t+i));
      msg2.polygon.points.push_back(p);
    }

    //Set msg3
    msg3.points.clear();
    for( int i = 0; i < 10; i++ ){ 
      p.x=i;
      p.y=sin(2.0*M_PI/10.0*(double)(t+i));
      p.z=cos(2.0*M_PI/10.0*(double)(t+i));
      msg3.points.push_back(p);
    }

    //Set msg4
    msg4.header=h;
    msg4.polygons.clear();
    msg4.labels.clear();
    msg4.likelihood.clear();
    for( int r = 1; r < 10 ; r ++ ){
      ps.header = h;
      ps.polygon.points.clear();
      for( int i = 0; i < 10; i++ ){ 
	p.x=r*cos(2.0*M_PI/10.0*(double)(i));
	p.y=r*sin(2.0*M_PI/10.0*(double)(i));
	p.z=sin(2.0*M_PI/10.0*(double)(t+i));
	ps.polygon.points.push_back(p);
      }
      msg4.polygons.push_back(ps);
      msg4.labels.push_back(r);
      msg4.likelihood.push_back((double)r/10.0);
    }

    //Decompose Example of msg4
    for( std::vector<geometry_msgs::PolygonStamped>::const_iterator ips = msg4.polygons.begin();
	 ips != msg4.polygons.end();
	 ips ++ ){
      
      for( std::vector<geometry_msgs::Point32>::const_iterator ip = ips->polygon.points.begin();
	   ip != ips->polygon.points.end();
	   ip ++ ){
	printf("%f, %f, %f\n", ip->x, ip->y, ip->z);
	
      }
      printf("---\n");
    }

    //Set msg5
    msg5.header=h;
    msg5.pose.position.x = sin(2.0*M_PI/10.0*(double)(t));
    msg5.pose.position.y = 1;
    msg5.pose.position.z = 3;
    msg5.pose.orientation.x = 0;
    msg5.pose.orientation.y = 0;
    msg5.pose.orientation.z = sin(2.0*M_PI/10.0*(double)(t));
    msg5.pose.orientation.w = 0;
    

    t++;
    pub1.publish( msg1 );
    pub2.publish( msg2 );
    pub3.publish( msg3 );
    pub4.publish( msg4 );
    pub5.publish( msg5 );
    ros::spinOnce();
    loop_rate.sleep();    
  }
  
  
  return 0;
}
