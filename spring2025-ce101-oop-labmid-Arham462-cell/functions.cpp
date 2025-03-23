#include"functions.h"

 int   operator  ++(Patient &p)
{
   p.healthScore=  p.getHealthScore()+ 10;
   return p.healthScore;
  
}
