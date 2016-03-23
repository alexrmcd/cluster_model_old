
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * galaxy_clusterfuck.cc *                                       3/16/2016
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|
using namespace std;

#include "Cluster.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>


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

int B_model = 2;

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

  else if(B_model == 2){
    b_field=Bo * pow(( 1 + (x*x+y*y)/(rcore*rcore)),(-2)); // fall back
  }
  return b_field;
}

//end B_field






int create_galaxy_cluster() {
Cluster cluster;
  //cout<<" >>>> create_galaxy_cluster"<<endl;
    cout << "Enter 1 for default"<< endl;
string input = "";

int number = 0;

getline(cin, input);
stringstream myStream(input);

myStream >> number;





   /* 
  void init(x_min,  x_max, dx,
  y_min,  y_max, dy);
  */
if(number == 1){

// array variables init
cluster.x_min = 0;
cluster.x_max = 10;
cluster.dx =   1;

cluster.y_min = 0;
cluster.y_max = 10;
cluster.dy = 1;




// number of points in momentum
cluster.n_xgrid = (cluster.x_max - cluster.x_min)/cluster.dx;             // number of points in x 
cluster.n_ygrid = (cluster.y_max - cluster.y_min)/cluster.dy;             // number of points in y  
/*double* x = 0; 
double* y = 0;*/
// array variables init end

}





  // B-FIELD DISTRIBUTION
  float B_field[cluster.n_xgrid][cluster.n_ygrid];

  for (int ix = 0; ix < cluster.n_xgrid; ++ix) {
      
    for (int iy = 0; iy < cluster.n_ygrid; ++iy) {

	const double r = sqrt(cluster.dx*ix*cluster.dx*ix + iy*cluster.dy*cluster.dy*iy);

	  B_field[ix][iy] =
	    B_field_model(cluster.dx*ix, iy*cluster.dy, B_model);
    cout<< B_field[ix][iy] <<" ";
	
      }

    cout<<endl;
    
    }
  
  }


int main(){


  create_galaxy_cluster();
  return 0;

}