#include <ros/ros.h>
#include <std_msgs/Int8.h>
int main(int argc, char** argv)
{
  // Initialize ROS node
  ros::init(argc, argv, "goal_publish");
  ros::NodeHandle nh;

  // Create a publisher for the "/goal_location" topic
  ros::Publisher goal_pub = nh.advertise<std_msgs::Int8>("/goal_location", 10);

  // Create a message object
  std_msgs::Int8 msg;

  // Publish the message repeatedly
  ros::Rate loop_rate(10);  // 10 Hz publishing rate
  while (ros::ok())
  {
jump:
    // Prompt user for input
    int input;
    std::cout << "Enter a valid Goal Number(e.g:1,2,3): ";
    std::cin >> input;
    if (input == 1 || input == 2 || input == 3)
	{	
	    msg.data = input;
	    goal_pub.publish(msg);
	    ros::spinOnce();
	    loop_rate.sleep();    
	}
    else{
	    std::cout << "Invalid Goal point"<< std::endl;
	    goto jump;
	}
	
  }

  return 0;
}

