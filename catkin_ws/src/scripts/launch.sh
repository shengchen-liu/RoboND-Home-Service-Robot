#!/bin/sh
gnome-terminal   -e  " gazebo " &
sleep 5
gnome-terminal   -e  " source /opt/ros/kinetic/setup.bash; roscore" & 
sleep 5
gnome-terminal   -e  " rosrun rviz rviz" 