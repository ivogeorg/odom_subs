#include "ros/duration.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "../../velocity_library/include/velocity_library/vlib.hpp"

void odomCallback(const nav_msgs::OdometryConstPtr &msg) {
    float x = msg->pose.pose.position.x;
    float y = msg->pose.pose.position.y;
    float linx = msg->twist.twist.linear.x;
    float angz = msg->twist.twist.angular.z;
    ros::Duration(1).sleep();
    display_velocity(linx, angz);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "odom_listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("odom", 1, odomCallback);
    ros::spin();
    
    return 0;
}