#include <ros/ros.h>
#include "learning_topic/Person.h"

// callback function
void personInfoCallback(const learning_topic::Person::ConstPtr& msg)
{
	// print
	ROS_INFO("Subscribe Person Info: name:%s  age:%d  sex:%d", msg->name.c_str(), msg->age, msg->sex);
}

int main(int argc, char **argv)
{
	// init ROS node
	ros::init(argc, argv, "person_subscriber");

	// create handler
	ros::NodeHandle n;

	// create Subscriber, topic /person_info, callback function poseCallback
	ros::Subscriber person_info_sub = n.subscribe("/person_info", 1, personInfoCallback);

	// loop wait
	ros::spin();

	return 0;
}
