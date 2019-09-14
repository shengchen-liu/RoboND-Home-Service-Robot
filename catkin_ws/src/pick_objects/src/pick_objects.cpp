#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Define a client for to send goal requests to the move_base server through a SimpleActionClient
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot to move 1 meter forward
  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define 2 goals with position and orientation for the robot to reach
  int num_goals = 2;
  int goals[num_goals][3] = {{3.0, 3.0, 1.0}, {-3.0, 2.0, -1.0}};

  // Loop through all goals
  for (int i = 0; i < num_goals; i++){
    // define position and orientation
    float x = goals[i][0];
    float y = goals[i][1];
    float o = goals[i][2];
    goal.target_pose.pose.position.x = x;
    goal.target_pose.pose.position.y = y;
    goal.target_pose.pose.orientation.w = o;

     // Send the goal position and orientation for the robot to reach
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    // Wait an infinite time for the results
    ac.waitForResult();

    // Check if the robot reached its goal
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("Goal %i reached! x: %f, y: %f, o: %f ", i, x, y, o);
    else
      ROS_INFO("The base failed to move for some reason");

    // Pause 5 seconeds after reaching the pickup zone
    if (i == 0){
      ros::Duration(5.0).sleep();
    }

  }


  

  return 0;
}