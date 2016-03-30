//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * CRadioRead.cc *                                              	3/23/2016 
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|



#include <iostream>

using namespace std;

extern"C" {
double __astro_MOD_distintegrand(double *ztemp);
}

int main()
{

   double ztemp = 1;

   __astro_MOD_distintegrand(&ztemp);
  
   return 0;
}