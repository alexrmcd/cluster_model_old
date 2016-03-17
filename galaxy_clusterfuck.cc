
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * galaxy_clusterfuck.cc *                                       3/16/2016
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|
using namespace std;

#include <cmath>
#include <iostream>

// array variables declared 
/*
double x_min, x_max, dx, y_min, y_max, dy; 
   
int n_pgrid;             // number of points in momentum
int n_xgrid;             // number of points in x (3D)
int n_ygrid;             // number of points in y (3D)    
  
double* x;             // x grid
double* y;             // y grid

// array variables declared end
*/






//B_field

int B_model = 1;/*
B_model = 1;*/

double B_field_model(double x,double y, int B_model) //third argument "int model" for multile preset models
{
   float Bo = 5.0; //microGauss
   float rcore = 20; //core radius in kpc
   float beta = 0.6;
   float eta = 0.5;
   float b_field=0.0;

   if(B_model == 1){

   b_field = Bo * pow(( 1 + (x*x+y*y)/(rcore*rcore)),(-3*beta*eta/2));// Storm et al 2013 
    
  }

  else{
    b_field=Bo * pow(( 1 + (x*x+y*y)/(rcore*rcore)),(-2)); // just a fall back
  }
  return b_field;
}

//end B_field






int create_galaxy_cluster() {

  //cout<<" >>>> create_galaxy_cluster"<<endl;
  

   /* 
  void init(x_min,  x_max, dx,
  y_min,  y_max, dy);
  */
  
// array variables init
double x_min = 0;
double x_max = 20;
double dx =   .1;

double y_min = 0;
double y_max = 20;
double dy = .1;




int n_pgrid = 10;             // number of points in momentum
int n_xgrid = 20;             // number of points in x 
int n_ygrid = 20;             // number of points in y  
/*double* x = 0; 
double* y = 0;*/
// array variables init end








  // B-FIELD DISTRIBUTION
  float B_field[n_xgrid][n_ygrid];

  for (int ix = 0; ix < n_xgrid; ++ix) {
      cout<<endl;
    for (int iy = 0; iy < n_ygrid; ++iy) {

	const double r = sqrt(dx*ix*dx*ix + iy*dy*dy*iy);

	  B_field[ix][iy] =
	    B_field_model(dx*ix, iy*dy, B_model);
    cout<< B_field[ix][iy] <<" ";
	
      }
    
    }
  
  }


int main(){
  create_galaxy_cluster();
  return 0;

}