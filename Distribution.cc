
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * Distribution.cc *                           Modified from galprop 3/30/2016 
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|
//Essentially same as Galprop, just only with two spatial dimensions (x,y)
#include"Distribution.h"

#include <limits>

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
/*	
Distribution::~Distribution()
{
   cout<<"~Distribution\n";
	 
   if(n_spatial_dimensions==3)
   {
      for(int ix=0; ix<n_xgrid; ix++)
      {
         for(int iy=0; iy<n_ygrid; iy++)
         {
            for(int iy=0; iy<n_ygrid; iy++) delete[]d3[ix][iy][iy].s;  
	    delete[]d3[ix][iy]; 
         }
	 delete[]d3[ix];
      }
      delete[]d3;  
   } // 3D
};
*/
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution::Distribution(const Distribution &old){
  arrays_assigned=false;
  n_spatial_dimensions=0;
  

    init(old.n_xgrid, old.n_ygrid, old.n_Egrid);
    
    for (int ix = 0; ix < old.n_xgrid; ++ix)
      for (int iy = 0; iy < old.n_ygrid; ++iy)
	for (int iE = 0; iE < old.n_Egrid; ++iE)
	  d2[ix][iy].s[iE] = old.d2[ix][iy].s[iE];
  
  
}

Distribution::Distribution() {

  n_spatial_dimensions = 0;
  arrays_assigned = false;

}

Distribution::~Distribution() {

  delete_array();

}

Distribution::Distribution(int n_xgrid_, int n_ygrid_, int n_Egrid_) {

  n_spatial_dimensions=2;
  n_xgrid=n_xgrid_;
  n_ygrid=n_ygrid_;
  n_Egrid=n_Egrid_;
  
  d2=new Spectrum *[n_xgrid];
  for(int ix=0; ix<n_xgrid; ++ix) {
    d2[ix]=new Spectrum[n_ygrid];
    for(int iy=0; iy<n_ygrid; ++iy) {

      d2[ix][iy].s=new double [n_Egrid];//AWS20050624
      for(int iE=0; iE<n_Egrid; iE++) d2[ix][iy].s[iE]=0.;
      
    }
   
  }
  //cout<<"Distribution:generated 2D array of spectra "
  //<<n_xgrid<<" "<<n_ygrid<<" "<<n_Egrid<<endl; 
  arrays_assigned = true;

}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

void Distribution::delete_array() {

  if (arrays_assigned) {
    //cout<<"Distribution delete_array\n";
    

      for(int ix=0; ix<n_xgrid; ix++) {

	for(int iy=0;iy<n_ygrid;iy++) delete[]d2[ix][iy].s;                       
	delete[]d2[ix];  
	
      }	    

      delete[]d2;  
      

    
    arrays_assigned=false;
    n_spatial_dimensions=0;
   
  }

}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

void Distribution::init(int n_xgrid_, int n_ygrid_, int n_Egrid_) {
   
  delete_array();
  n_spatial_dimensions=2;
  n_xgrid=n_xgrid_;
  n_ygrid=n_ygrid_;
  n_Egrid=n_Egrid_;
  
  d2=new Spectrum *[n_xgrid];
  for(int ix=0; ix<n_xgrid; ix++) {

    d2[ix]=new Spectrum[n_ygrid];
    for(int iy=0; iy<n_ygrid; iy++) {

      d2[ix][iy].s=new double [n_Egrid];//AWS20050624
      for(int iE=0; iE<n_Egrid; iE++) d2[ix][iy].s[iE]=0.;
      
    }
   
  }
  //cout<<"Distribution.init:generated 2D array of spectra "
  // <<n_xgrid<<" "<<n_ygrid<<" "<<n_Egrid<<endl; 
  arrays_assigned=true;
  //return;
}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

void Distribution::print() {

  //cout<<"Distribution.print: n_spatial_dimensions="<<n_spatial_dimensions<<endl;
  

    cout<<"Distribution with "<<n_spatial_dimensions<<" spatial dimensions: "<<endl;
    for(int iE=0; iE<n_Egrid; iE++) {

      cout<<"iE="<<iE<<endl;
      for(int iy=0; iy<n_ygrid; iy++) {

	cout<<iy<<" ";
	for(int ix=0; ix<n_xgrid; ix++) cout<<d2[ix][iy].s[iE]<<" ";
	cout<<endl;
      }
      
      cout<<endl;
      
    }
   


}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

void Distribution::print(double units) {

  cout<<"Distribution.print: n_spatial_dimensions="<<n_spatial_dimensions<<endl;
  
 
      cout<<"Distribution with "<<n_spatial_dimensions<<" spatial dimensions: "<<endl;
      cout<<"units="<<units<<endl;
      for(int iE=0; iE<n_Egrid; iE++)
	{
	  cout<<"iE="<<iE<<endl;
	  for(int iy=0; iy<n_ygrid; iy++)
	    {
	      cout<<iy<<" ";
	      for(int ix=0; ix<n_xgrid; ix++) cout<<int(d2[ix][iy].s[iE]/units)<<" ";
	      cout<<endl;
	    }
	  cout<<endl;
	}
    
}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

double Distribution::max() { //AWS20050624

  double max_= -1.*(numeric_limits<double>::max() - 1.);//-1.e30;    //AWS20050624
  
 
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
	    for(int iE=0; iE<n_Egrid; iE++)
	       if(d2[ix][iy].s[iE]>max_) max_=d2[ix][iy].s[iE];
   return max_;
}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution & Distribution::operator=(double const2) 
{
  
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
	    for(int iE=0; iE<n_Egrid; iE++) d2[ix][iy].s[iE]=const2;
   return *this;
}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution & Distribution::operator=(const Distribution &dist)
{
 
    init(dist.n_xgrid, dist.n_ygrid, dist.n_Egrid);
    
    for (int ix = 0; ix < dist.n_xgrid; ++ix)
      for (int iy = 0; iy < dist.n_ygrid; ++iy)
	for (int iE = 0; iE < dist.n_Egrid; ++iE)
	  d2[ix][iy].s[iE] = dist.d2[ix][iy].s[iE];
  
   return *this;
}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution Distribution::operator+(double const2)
{
  
      Distribution tmp(n_xgrid,n_ygrid,n_Egrid);
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
            for(int iE=0; iE<n_Egrid; iE++)
	       tmp.d2[ix][iy].s[iE]=d2[ix][iy].s[iE]+const2;
      return tmp;
   



   // to avoid compiler warning 'no return statement' //AWS20050627
                               //AWS20050627
   return tmp;                                        //AWS20050627

}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution & Distribution::operator+=(double const2)
{
   
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
	    for(int iE=0; iE<n_Egrid; iE++) d2[ix][iy].s[iE]+=const2;

   return *this;
}                    //     Schildt p.392

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution Distribution::operator*(double const2)
{
  
      Distribution tmp(n_xgrid,n_ygrid,n_Egrid);
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
            for(int iE=0; iE<n_Egrid; iE++)
               tmp.d2[ix][iy].s[iE]=d2[ix][iy].s[iE]*const2;
      return tmp;
   



   // to avoid compiler warning 'no return statement' //AWS20050627
                                     //AWS20050627
   return tmp;                                        //AWS20050627
}  	 

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution &Distribution::operator*=(double const2)
{
    	 
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
            for(int iE=0; iE<n_Egrid; iE++) d2[ix][iy].s[iE]*=const2;


   return *this;
}  

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution &Distribution::operator/=(double const2)
{
   
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
            for(int iE=0; iE<n_Egrid; iE++) d2[ix][iy].s[iE]/=const2;


   return *this;
}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution &Distribution::operator+=(const Distribution &dist)
{
   	 
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
	    for(int iE=0; iE<n_Egrid; iE++) d2[ix][iy].s[iE]+=dist.d2[ix][iy].s[iE];


   return *this;
}                    //     Schildt p.392

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution &Distribution::operator*=(const Distribution &dist)
{
   
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
            for(int iE=0; iE<n_Egrid; iE++) d2[ix][iy].s[iE]*=dist.d2[ix][iy].s[iE];


   return *this;
}                    //     Schildt p.392

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution &Distribution::operator/=(const Distribution &dist) 
{
   
      for(int ix=0; ix<n_xgrid; ix++)
         for(int iy=0; iy<n_ygrid; iy++)
            for(int iE=0; iE<n_Egrid; iE++) d2[ix][iy].s[iE]/=dist.d2[ix][iy].s[iE];


   return *this;
}                    //     Schildt p.392

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
//  following cases have to be non-member functions since they have 2 arguments
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution operator+(double const2,const Distribution &dist)
{

      Distribution tmp(dist.n_xgrid,dist.n_ygrid,dist.n_Egrid);
      for(int ix=0; ix<dist.n_xgrid; ix++)
         for(int iy=0; iy<dist.n_ygrid; iy++)
	    for(int iE=0; iE<dist.n_Egrid; iE++)
	       tmp.d2[ix][iy].s[iE]=const2+dist.d2[ix][iy].s[iE];
      return tmp;
   

   // to avoid compiler warning 'no return statement' //AWS20050627
                                     //AWS20050627
   return tmp;                                        //AWS20050627

}

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution operator*(double const2,const Distribution &dist)
{
  
      Distribution tmp(dist.n_xgrid,dist.n_ygrid,dist.n_Egrid);
      for(int ix=0; ix<dist.n_xgrid; ix++)
         for(int iy=0; iy<dist.n_ygrid; iy++)
	    for(int iE=0; iE<dist.n_Egrid; iE++)
	       tmp.d2[ix][iy].s[iE]=const2 * dist.d2[ix][iy].s[iE];
      return tmp;
   



   // to avoid compiler warning 'no return statement' //AWS20050627
                                     //AWS20050627
   return tmp;                                        //AWS20050627

}  

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution operator+(const Distribution &dist,const Distribution &dist2) 
{
  
      Distribution tmp(dist.n_xgrid,dist.n_ygrid,dist.n_Egrid); 
      for(int ix=0; ix<dist.n_xgrid; ix++)
         for(int iy=0; iy<dist.n_ygrid; iy++)
            for(int iE=0; iE<dist.n_Egrid; iE++)
               tmp.d2[ix][iy].s[iE]=dist.d2[ix][iy].s[iE]+dist2.d2[ix][iy].s[iE];
      return tmp;
   



   // to avoid compiler warning 'no return statement' //AWS20050627
                                     //AWS20050627
   return tmp;                                        //AWS20050627

}  
	 
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution operator*(const Distribution &dist,const Distribution &dist2)
{
  
      Distribution tmp(dist.n_xgrid,dist.n_ygrid,dist.n_Egrid);
      for(int ix=0; ix<dist.n_xgrid; ix++)
         for(int iy=0; iy<dist.n_ygrid; iy++)
            for(int iE=0; iE<dist.n_Egrid; iE++)
               tmp.d2[ix][iy].s[iE]=dist.d2[ix][iy].s[iE] * dist2.d2[ix][iy].s[iE];
      return tmp;
   


   // to avoid compiler warning 'no return statement' //AWS20050627
                                     //AWS20050627
   return tmp;                                        //AWS20050627

}  

//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|

Distribution operator/(const Distribution & dist,const Distribution &dist2) 
{

      Distribution tmp(dist.n_xgrid,dist.n_ygrid,dist.n_Egrid);
      for(int ix=0; ix<dist.n_xgrid; ix++)
         for(int iy=0; iy<dist.n_ygrid; iy++)
            for(int iE=0; iE<dist.n_Egrid; iE++)
               tmp.d2[ix][iy].s[iE]=dist.d2[ix][iy].s[iE] / dist2.d2[ix][iy].s[iE];
      return tmp;
   

   
   // to avoid compiler warning 'no return statement' //AWS20050627
                                     //AWS20050627
   return tmp;                                        //AWS20050627


}  
