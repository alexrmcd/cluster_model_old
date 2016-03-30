
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * Distribution.h *                       Modified from galprop * 3/30/2016 
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|



#ifndef Distribution_h
#define Distribution_h


using namespace std;            //AWS20050624
#include<iostream>              //AWS20050624
#include<cmath>                 //AWS20050624 
#include<cstdlib> //IMOS20020112  AWS20050624
#include<string>  //IMOS20020112  AWS20050624

#include"Spectrum.h"

class Distribution {

 public:

  int n_Egrid;          // number of points in momentum
  int n_xgrid;          // number of points in x (3D)
  int n_ygrid;          // number of points in y (3D)  
  
  int n_spatial_dimensions;// 1,2,3D Probably not necessary here since we have 1D
  bool arrays_assigned;
  

  Spectrum  **d2; // 2D array

  
  Distribution();   // needed for initial construction
  Distribution(const Distribution &old);
  ~Distribution();   // needed for destruction
  Distribution(int n_xgrid_,int n_ygrid_,int n_Egrid_);
  void delete_array();
  void init(int n_xgrid_,int n_ygrid_,int n_Egrid_);
  void print();
  void print(double units);
  double max();                               //AWS20050624
  Distribution &operator=(double);
  Distribution operator+(double);
  Distribution &operator+=(double);
  Distribution operator*(double);
  Distribution &operator*=(double);
  Distribution &operator/=(double);
  Distribution &operator =(const Distribution&);
  Distribution &operator+=(const Distribution&);
  Distribution &operator*=(const Distribution&);
  Distribution &operator/=(const Distribution&);
};

//  following cases have to be non-member functions since they have 2 arguments;
//  therefore their prototypes are defined outside the class

Distribution operator+(double,const Distribution&);
Distribution operator*(double,const Distribution&);
Distribution operator+(const Distribution&,const Distribution&);
Distribution operator*(const Distribution&,const Distribution&);
Distribution operator/(const Distribution&,const Distribution&);

#endif




