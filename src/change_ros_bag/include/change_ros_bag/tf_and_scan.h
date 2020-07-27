#pragma once
#include "ros/ros.h"
#include <sensor_msgs/LaserScan.h>
#include <tf/tfMessage.h>

class SubscribeAndPusblish
{
public:
    SubscribeAndPusblish();
    virtual ~SubscribeAndPusblish() = default;
    void sacn_call_back(const sensor_msgs::LaserScan::ConstPtr &msg);
   void tf_call_back(const tf::tfMessage::ConstPtr &msg);

private:
    ros::NodeHandle n;
    ros::Subscriber scan_sub;
    ros::Subscriber tf_sub;
    ros::Publisher scan_pub;
    ros::Publisher tf_pub;
};