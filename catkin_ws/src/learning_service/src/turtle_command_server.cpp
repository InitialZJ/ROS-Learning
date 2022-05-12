/**
 * execute /turtle_command service, service data type is std_srvs/Trigger
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>

ros::Publisher turtle_vel_pub;
bool pubCommand = false;

// service callback function
bool commandCallback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res)
{
	pubCommand = !pubCommand;

	// show request
	ROS_INFO("Publish turtle velocity command [%s]", pubCommand == true ? "YES" : "NO");

	// set response
	res.success = true;
	res.message = "Change turtle command state!";

	return true;
}

int main(int argc, char **argv)
{
	// ROS node init
	ros::init(argc, argv, "turtle_command_server");

	// create handler
	ros::NodeHandle n;

	// create service /turtle_command, callback function is commandCallback
	ros::ServiceServer command_service = n.advertiseService("/turtle_command", commandCallback);

	// create Publisher, topic is /turtle1/cmd_vel, data type is Twist
	turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

	ROS_INFO("Ready to receive turtle command.");

	// set loop rate
	ros::Rate loop_rate(10);

	// loop wait callback
	while (ros::ok())
	{
		// spin once
		ros::spinOnce();
		
		// if mark is true, publish
		if (pubCommand)
		{
			geometry_msgs::Twist vel_msg;
			vel_msg.linear.x = 0.5;
			vel_msg.angular.z = 0.2;
			turtle_vel_pub.publish(vel_msg);
		}

		// sleep
		loop_rate.sleep();
	}
	
	return 0;
}
