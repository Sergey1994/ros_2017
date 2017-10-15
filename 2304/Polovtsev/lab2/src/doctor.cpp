#include "ros/ros.h"
#include "lab2/sickMan.h"



int main(int argc, char **argv)
{
  ros::init(argc, argv, "doctor");
  ros::NodeHandle n;

  ROS_INFO("Ready to heal");
  ros::spin();

  return 0;
}
