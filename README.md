# Home Service Robot

## Overview

In this project, you will use everything you learned in the Nanodegree Program to build a Home Service Robot in ROS.

![](videos/Home_Robot.gif)

Click [here](https://youtu.be/T2lkpL-Nbrg) for Youtube link.

## SLAM Testing

The next task of this project is to autonomously map the environment you designed earlier with the Building Editor in Gazebo. But before you tackle autonomous mapping, it’s important to test if you are able to manually perform SLAM by teleoperating your robot. The goal of this step is to manually test SLAM.

## Localization and Navigation Testing

The next task of this project is to pick two different goals and test your robot's ability to reach them and orient itself with respect to them. We will refer to these goals as the pickup and drop off zones. This section is only for testing purposes to make sure our robot is able to reach these positions before autonomously commanding it to travel towards them.

We will be using the ROS Navigation stack, which is based on the Dijkstra's, a variant of the Uniform Cost Search algorithm, to plan our robot trajectory from start to goal position. The ROS navigation stack permits your robot to avoid any obstacle on its path by re-planning a new trajectory once your robot encounters them. You are familiar with this navigation stack from the localization project where you interfaced with it and sent a specific goal for your robot to reach while localizing itself with AMCL. If you are planning to modify the ROS navigation algorithm or you are curious to know how it's done, take a look at this official tutorial which teaches you how to write a global path planner as a plugin in ROS.

## Your Home Service Robot

You will create a `add_marker.sh` file that will publish a marker to rviz.
The marker should initially be published at the pickup zone. After 5 seconds it should be hidden. Then after another 5 seconds it should appear at the drop off zone. The student should write a home_service.sh file that will run all the nodes in this project.
The student's home service robot should be simulated as follow:

- Initially show the marker at the pickup zone.

- Hide the marker once your robot reach the pickup zone.

- Wait 5 seconds to simulate a pickup.

- Show the marker at the drop off zone once your robot reaches it.

  There are many ways to solve this problem. To establish communications between the robot and the markers, one method already mentioned is to let your `add_markers` node subscribe to your robot odometry and keep track of your robot pose.

## Setup Instructions

1. create a catkin workspace:

   ```
   mkdir -p catkin_ws/src
   cd catkin_ws/src
   source /opt/ros/<DISTRO>/setup.bash
   catkin_init_workspace
   ```

2. Install openslam-gmapping:

   ```
   sudo apt-get install ros-kinetic-openslam-gmapping
   ```

3. Install Joy package:

   ```
   sudo apt-get install ros-kinetic-joy ros-kinetic-joystick-drivers
   ```

4. Install Kobuki package:

   ```
   git clone https://github.com/yujinrobot/kobuki.git 
   ```

5. ```
   sudo apt-get install ros-kinetic-ecl-*
   sudo apt-get install ros-kinetic-kobuki
   
   ```

6. ```
    sudo apt install ros-kinetic-depthimage-to-laserscan
    ```

    7. 
  ```
git clone https://github.com/turtlebot/turtlebot_msgs.git
git clone https://github.com/turtlebot/turtlebot_apps.git 

  ```
   ```

8. compile the workspace

   ```
   cd ..
   catkin_make
   ```

9. source the workspace

   ```
   source devel/setup.bash
   ```
rqt_graph
   ```# RoboND-Home-Service-Robot

   ```