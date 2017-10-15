#include "ros/ros.h"
#include <cstdlib>
#include <lab2/sickMan.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sick");
 

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<lab2::sickMan>("sickMan");
  lab2::file1 srv;
  
  return 0;
}