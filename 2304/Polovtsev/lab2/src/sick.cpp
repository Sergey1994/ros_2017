#include "ros/ros.h"
#include <cstdlib>
#include "sickMan.cpp"
#include <time.h>
#include "lab2/Heal.h"



int main(int argc, char **argv)
{
  ros::init(argc, argv, "sick");
 
  SickMan misterX;
  

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<lab2::Heal>("heal_limb");
  lab2::Heal srv;
  
  ROS_INFO("Ready to start");

  int lostLimb, delay = 8;

  
    while (ros::ok()) {
        if (misterX.isDeath()) 
        {
              ROS_INFO("Game over! Sick is dead!");
              return 0;
        }
  
        srand(time(0));
        int lostLimb = rand() % 6;
  
        if (misterX.loseLimb(lostLimb)) 
        {
           ROS_INFO("%s is lost!", misterX.getLimbs(lostLimb));
            srv.request.limbCode = lostLimb;
  
            if (client.call(srv)) 
            {
                if (srv.response.isHeal)
                {
                    misterX.healLimb(lostLimb);
                   ROS_INFO("Doctor healed the %s", misterX.getLimbs(lostLimb));
                }
            }
  
            ros::Duration(delay).sleep();
           ROS_INFO("Now sick lost %d limb(s)", misterX.countLostLimbs());
        }
    }
  
  ros::spinOnce();
  return 0;
}