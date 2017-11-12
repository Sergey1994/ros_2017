#include "ros/ros.h"
#include "sickMan.cpp"
#include "kbhit.cpp"
#include <time.h>
#include "lab2/Heal.h"

SickMan misterX;

bool play(int limbCode) {
    ROS_INFO("%s lost!", misterX.getLimbs(limbCode));
    ROS_INFO("You have only 5 seconds! Input correct code for heal");

    time_t startTime = time(0);
    int delay = 5;
    init_keyboard(); 
    int key = 0;

    do 
    {
        if (kbhit()) 
        {
            key = readch();   
            if (key == (limbCode + 48)) 
            {
                ROS_INFO("%s healed!", misterX.getLimbs(limbCode));
                close_keyboard();
                return true;
            }
        }
    } while (time(0) <= startTime + delay);
    
    ROS_INFO("Time is over!");
    close_keyboard(); 
    return false;
}

bool healLimb(lab2::Heal::Request &req, lab2::Heal::Response &res) 
{
    res.isHeal = play(req.limbCode);
    return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "doctor");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("heal_limb", healLimb);
  ROS_INFO("Ready to heal");
  ROS_INFO("Code for heal:");
  for (int i = 0; i < 5; i++)
    ROS_INFO("%d - %s", i, misterX.getLimbs(i));
  ros::spin();

  return 0;
}