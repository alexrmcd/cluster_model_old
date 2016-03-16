//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * Cluster_B_field.cc *                                              3/15/2016 
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|
using namespace std;//AWS20050624
#include <cmath>     //AWS20050624
#include "Cluster_Parameters"
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|


double B_field_model(double x,double y) //third argument "int model" for multile preset models
{
   double 
   float Bo, rscale, beta, eta
   float b_field=0.0;

   b_field=Bo * ( 1 + (x*x+y*y)/(rscale**2))**(-3*beta*eta/2); // Storm et al 2013 
   


// In the future we will want to include Beff, user input mag field  */

}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

