/**
* send request to /show_person service, service data type is learning_service::Person
*/
#include <ros/ros.h>
#include "learning_service/Person.h"

int main(int argc, char** argv)
{
	// init ROS node
	ros::init(argc, argv, "person_client");
	
	// create node handler
	ros::NodeHandle node;

	// when find /spawn service, create a service client
	ros::service::waitForService("/show_person");
	ros::ServiceClient person_client = node.serviceClient<learning_service::Person>("/show_person");

	// init Spawn
	learning_service::Person srv;
	srv.request.name = "Tom";
	srv.request.age = 20;
	srv.request.sex = learning_service::Person::Request::male;
	
	ROS_INFO("Call service to show person[name:%s, age:%d, sex:%d]", srv.request.name.c_str(), srv.request.age, srv.request.sex);

	person_client.call(srv);

	// show result
	ROS_INFO("Show person result : %s", srv.response.result.c_str());

	return 0;
}



