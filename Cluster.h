
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * Cluster.h *                                                      3/15/2016 
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

int n_xgrid, n_ygrid;

};

#endif

 
