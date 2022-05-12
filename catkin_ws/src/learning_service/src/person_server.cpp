/**
 * execute /show_person service, service data type is learning_service::Person
 */

#include <ros/ros.h>
#include "learning_service/Person.h"

// service callback function
bool personCallback(learning_service::Person::Request &req, learning_service::Person::Response &res)
{
	// show request
	ROS_INFO("Person: name:%s  age:%d  sex:%d", req.name.c_str(), req.age, req.sex);

	// set response
	res.result = "OK";

	return true;
}

int main(int argc, char **argv)
{
	// ROS node init
	ros::init(argc, argv, "person_server");

	// create handler
	ros::NodeHandle n;

	// create service /show_person, callback function is personCallback
	ros::ServiceServer person_server = n.advertiseService("/show_person", personCallback);

	ROS_INFO("Ready to receive person information.");
	ros::spin();
	
	return 0;
}
