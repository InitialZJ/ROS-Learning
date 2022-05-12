/**
* send /spawn service, service data type is turtlesim::Spawn
*/
#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv)
{
	// init ROS node
	ros::init(argc, argv, "turtle_spawn");
	
	// create node handler
	ros::NodeHandle node;

	// when find /spawn service, create a service client
	ros::service::waitForService("/spawn");
	ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");

	// init Spawn
	turtlesim::Spawn srv;
	srv.request.x = 2.0;
	srv.request.y = 2.0;
	srv.request.name = "turtle2";
	
	ROS_INFO("Call service to spwan turtle[x:%0.6f, y:%0.6f, name:%s]", srv.request.x, srv.request.y, srv.request.name.c_str());

	add_turtle.call(srv);

	// show result
	ROS_INFO("Spwan turtle successfully [name:%s]", srv.response.name.c_str());

	return 0;
}



