#!/bin/sh



rosrun toybox03 ../../devel/bin/toy_loop_pub __name:=node1 tx:=c1
rosrun toybox03  ../../devel/bin/toy_loop_sub __name:=node2 tx:=c2 rx:=c1
