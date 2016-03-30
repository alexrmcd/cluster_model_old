
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * Cluster.h *                                                      3/28/2016 
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|

#ifndef CLUSTER_H
#define CLUSTER_H



class Cluster {

public:/*

// array variables init
double x_min = 0;
double x_max = 10;
double dx =   1;

double y_min = 0;
double y_max = 10;
double dy = 1;




// number of points in momentum
int n_xgrid = (x_max - x_min)/dx;             // number of points in x 
int n_ygrid = (y_max - y_min)/dy;             // number of points in y  
/*double* x = 0; 
double* y = 0;*/
// array variables init end

double x_min, x_max, dx, y_min, y_max, dy;

double E_min, E_max, E_factor;  

int n_xgrid, n_ygrid, n_Egrid;








//Will eventually be separate header
struct Spectrum { 

  //public: 

  double* s; //AWS20050624

};

//Belongs in own header
class Distribution {

 public:

  int n_Egrid;          // number of points in Energy
      
  int n_xgrid;          // number of points in x 
  int n_ygrid;          // number of points in y 
  

  //bool arrays_assigned;
  

  Spectrum  **d2; // 2D array

  //Distribution();   // needed for initial construction
  };



  Distribution B_field;








};

#endif

 
