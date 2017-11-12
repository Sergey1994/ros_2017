


const int LIMBS_COUNT = 5;


class SickMan
{
   private:
       static char* limbs[LIMBS_COUNT];
       bool isWork[LIMBS_COUNT];

   public:
       SickMan();
       ~SickMan() {}

       char* getLimbs(int index);
       bool isDeath();
       int countLostLimbs();
       void healLimb(int index);
       bool loseLimb(int index);

};

char* SickMan::limbs[LIMBS_COUNT] =
{
   "Head",
   "Right leg",
   "Left leg",
   "Right hand",
   "Left hand"
};

SickMan::SickMan()
{
   for (int i = 0; i < LIMBS_COUNT; i++)
       isWork[i] = true;  
}


char* SickMan::getLimbs(int index)
{
    return limbs[index];
}

bool SickMan::isDeath()
{
    int failLimbs = 0;
    for (int i = 0; i < LIMBS_COUNT; i++)
        if (!isWork[i]) failLimbs++;

    return failLimbs > 2 ? true : false;
}

int SickMan::countLostLimbs()
{
    int failLimbs = 0;
    for (int i = 0; i < LIMBS_COUNT; i++)
        if (!isWork[i]) failLimbs++;
    return failLimbs;
}

void SickMan::healLimb(int index)
{
    if (!isWork[index]) isWork[index] = true;    
}

bool SickMan::loseLimb(int index)
{
    if (isWork[index]) 
    {
        isWork[index] = false;
        return true;
    }
    else return false;
}