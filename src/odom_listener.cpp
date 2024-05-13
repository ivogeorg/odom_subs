#include "ros/duration.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "../../test_library/include/test_library/test_library.h"

void odomCallback(const nav_msgs::OdometryConstPtr &msg) {
    float x = msg->pose.pose.position.x;
    float y = msg->pose.pose.position.y;
    ros::Duration(1).sleep();
    display_pos(x, y);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "odom_listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("odom", 1000, odomCallback);
    ros::spin();
    
    return 0;
}