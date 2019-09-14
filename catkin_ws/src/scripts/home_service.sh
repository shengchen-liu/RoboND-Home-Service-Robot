#!/bin/sh

# Create a test_navigation.sh shell script that launches these files
# turtlebot_world.launch: to deploy a turtlebot in your environment
# amcl_demo.launch: to localize the turtlebot
# view_home_service_navigation.launch: observe the map in rviz
# add_markers node: add virtual objects/markers in rviz


# Define workspace variable
path_catkin_ws="/home/shengchen/workspace/RoboND-Home-Service-Robot/catkin_ws"

# Open the workspace, source and launch turtlebot_world.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5
# Open the workspace, source and launch amcl_demo.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 5
# Open the workspace, source and launch view_home_service_navigation.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch add_markers view_navigation.launch rviz_path:=${path_catkin_ws}/src/rvizConfig/home_service_rvizConfig.rviz" &
sleep 5
# Open the workspace, source and launch add_markers add_markers
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun add_markers add_markers" &
# Open the workspace, source and launch pick_objects pick_objects
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun pick_objects pick_objects" 