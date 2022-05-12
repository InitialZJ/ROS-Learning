/**
 * set/get turtlesim parameters
 */
 #include <string>
 #include <ros/ros.h>
 #include <std_srvs/Empty.h>

 int main(int argc, char **argv)
 {
     int red, green, blue;

     // ROS node init
     ros::init(argc, argv, "parameter_config");

     // create handler
     ros::NodeHandle node;

     // get color
     ros::param::get("/turtlesim/background_r", red);
     ros::param::get("/turtlesim/background_g", green);
     ros::param::get("/turtlesim/background_b", blue);

    ROS_INFO("Get color [%d, %d, %d]", red, green, blue);

    // set color
    ros::param::set("/turtlesim/background_r", 255);
    ros::param::set("/turtlesim/background_g", 255);
    ros::param::set("/turtlesim/background_b", 255);

    ROS_INFO("Set color [255, 255, 255]");

    // get color again
    ros::param::get("/turtlesim/background_r", red);
    ros::param::get("/turtlesim/background_g", green);
    ros::param::get("/turtlesim/background_b", blue);
    ROS_INFO("Re-get color [%d, %d, %d]", red, green, blue);

    // refresh color
    ros::service::waitForService("/clear");
    ros::ServiceClient clear_backgroud = node.serviceClient<std_srvs::Empty>("/clear");
    std_srvs::Empty srv;
    clear_backgroud.call(srv);
    sleep(1);

    return 0;
 }