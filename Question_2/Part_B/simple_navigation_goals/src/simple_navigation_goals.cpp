#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/Int8.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

move_base_msgs::MoveBaseGoal createGoal(double x, double y)
{
  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  goal.target_pose.pose.position.x = x;
  goal.target_pose.pose.position.y = y;
  goal.target_pose.pose.orientation.w = 1.0;

  return goal;
}

void goalCallback(const std_msgs::Int8::ConstPtr& msg)
{
  double x = 0.0;
  double y = 0.0;

  // Check the received value and set the corresponding coordinates
  switch (msg->data)
  {
    case 1:
      x = 0.44;
      y = -2.13;
      break;
    case 2:
      x = 0.3;
      y = 1.9;
      break;
    case 3:
      x = -2.25;
      y = 0.022;
      break;
    // Add more cases for additional coordinates as needed
    //default:
      //ROS_WARN("Invalid goal location");
      
      return;
  }

  //ROS_INFO("Received goal: %d. Moving to (%.2f, %.2f)", msg->data, x, y);
  //std::cout << ""<< std::endl;
  //std::cout << "Robot is moving to goal point"<< std::endl;

  MoveBaseClient ac("move_base", true);
  while (!ac.waitForServer(ros::Duration(5.0)))
  {
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal = createGoal(x, y);
  ac.sendGoal(goal);
  ac.waitForResult();

  //if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    //ROS_INFO("The Robot has reached the goal");
  //else
    //ROS_INFO("The Robot failed to reach the goal");
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle nh;

  ros::Subscriber goal_sub = nh.subscribe("/goal_location", 10, goalCallback);

  ros::spin();

  return 0;
}

