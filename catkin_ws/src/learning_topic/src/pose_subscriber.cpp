#include <ros/ros.h>
#include "turtlesim/Pose.h"

// callback function
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
	// print
	ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x, msg->y);
}

int main(int argc, char **argv)
{
	// init ROS node
	ros::init(argc, argv, "pose_subscriber");

	// create handler
	ros::NodeHandle n;

	// create Subscriber, topic /turtle1/pose, callback function poseCallback
	ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallback);

	// loop wait
	ros::spin();

	return 0;
}
