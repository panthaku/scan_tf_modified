
#include "change_ros_bag/tf_and_scan.h"
#if hector_bag
SubscribeAndPusblish::SubscribeAndPusblish()
{
    std::cout << __FUNCTION__ << std::endl;
    scan_sub = n.subscribe("scan", 1000, &SubscribeAndPusblish::sacn_call_back, this);
    tf_sub = n.subscribe("tf", 1000, &SubscribeAndPusblish::tf_call_back, this);
    scan_pub = n.advertise<sensor_msgs::LaserScan>("scan_data", 1000);
    tf_pub = n.advertise<tf::tfMessage>("tf_data", 1000);
}
#else
SubscribeAndPusblish::SubscribeAndPusblish()
{
    std::cout << __FUNCTION__ << std::endl;
    scan_sub = n.subscribe("scan_data", 1000, &SubscribeAndPusblish::sacn_call_back, this);
    tf_sub = n.subscribe("tf_data", 1000, &SubscribeAndPusblish::tf_call_back, this);
    scan_pub = n.advertise<sensor_msgs::LaserScan>("scan", 1000);
    tf_pub = n.advertise<tf::tfMessage>("tf", 1000);
}

#endif
void SubscribeAndPusblish ::sacn_call_back(const sensor_msgs::LaserScan::ConstPtr &msg)
{
    std::cout << "scan_call_back" << std::endl;
    sensor_msgs::LaserScan local_object = *msg;
   /* local_object.header.seq = msg->header.seq;
    local_object.angle_min = 0.0;
    local_object.angle_max = 0.0;
    local_object.angle_increment = 0.0;
    local_object.time_increment = 0.0;
    local_object.scan_time = 0.0;
    local_object.range_min = 0.0;
    local_object.range_max = 0.0;
    local_object.ranges = {};
    local_object.intensities = {};*/
    scan_pub.publish(local_object);
}

void SubscribeAndPusblish::tf_call_back(const tf::tfMessage::ConstPtr &msg)
{
    std::cout << "tf_call_back" << std::endl;
    tf::tfMessage local_obj = *msg;
    tf_pub.publish(local_obj);
}

int main(int argc, char **argv)
{
    std::cout << "Hello from Main \n";
    ros::init(argc, argv, "listener");
    SubscribeAndPusblish sub_Pub;
    ros::spin();
    return 0;
}