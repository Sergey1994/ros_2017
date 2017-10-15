#include <string>


const int LIMBS_COUNT = 5;


class SickMan
{
   private:
       bool isAlive;
       static std::string limbs[LIMBS_COUNT];
       bool isWork[LIMBS_COUNT];

   public:
       SickMan();
       ~SickMan() {}

       void setAlive(bool isAlive) {this->isAlive = isAlive;} 
       bool getAlive() {return isAlive;}

};

std::string SickMan::limbs[LIMBS_COUNT] =
{
   "Head",
   "Right leg",
   "Left leg",
   "Right hand",
   "Left hand"
};

SickMan::SickMan()
{
   isAlive = true;
   for (int i = 0; i < LIMBS_COUNT; i++)
       isWork[i] = true;  
}
