
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * create_cluster_cluster.cc *                                       3/15/2016
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|
using namespace std;

#include "Cluster.h"
#include <sstream>



int create_galaxy_cluster() {

  //cout<<" >>>> create_cluster_cluster"<<endl;
  
  int stat=0;
  double dzz=0.01; // average with this resolution in kpc


    
    cluster.init(galdef.x_min,  galdef.x_max, galdef.dx,
    galdef.y_min,  galdef.y_max, galdef.dy);
  
                   
  // B-FIELD DISTRIBUTION


  for (int ix = 0; ix < cluster.n_xgrid; ++ix) {
      
    for (int iy = 0; iy < cluster.n_ygrid; ++iy) {

	const double r = sqrt(cluster.x[ix]*cluster.x[ix] + cluster.y[iy]*cluster.y[iy]);

	  cluster.B_field.d2[ix][iy].s[0] =
	    B_field_model(cluster.x[ix], cluster.y[iy], galdef.B_field_model);
	
      }
    
    }
  
  




















































  // SKYMAP PARAMETERS
  // moved to before gas surveys since required there                                    AWS20050913 
  
  cluster.d_long = galdef.d_long;
  cluster.long_min = galdef.long_min;
  cluster.long_max = galdef.long_max;
  
  cluster.d_lat = galdef.d_lat;
  cluster.lat_min = galdef.lat_min;
  cluster.lat_max = galdef.lat_max;
  
  cluster.n_long = int((cluster.long_max-cluster.long_min)/cluster.d_long + 1.001);
  cluster.n_lat = int((cluster. lat_max-cluster. lat_min)/cluster.d_lat  + 1.001);
  
  ostringstream buf;
  buf<<"    gamma-ray, synchrotron skymap arrays: n_long,nlat="<<cluster.n_long<<" "<<cluster.n_lat;
  DEBUGLOG(buf.str());

  // READING THE INTERSTELLAR RADIATION FIELD
  
  if (galdef.ISRF_factors) {

    cluster.fISRFFactors.resize(3);
   
    for (unsigned long i = 0; i < 3; ++i)
      cluster.fISRFFactors[i] = galdef.ISRF_factors[i];

  }

  stat = read_isrf(galdef.ISRF_filetype);
  
  if (gen_isrf_energy_density() != 0) 
    return 1;
  
  // STOCHASTIC SNR
  
  if (3 == galdef.n_spatial_dimensions && 1 == galdef.SNR_events) {

    //Moved from cluster::init    Gulli20070810
    cluster.SNR_cell_time.init(cluster.n_xgrid, cluster.n_ygrid, cluster.n_zgrid, 1);
    cluster.SNR_cell_phase.init(cluster.n_xgrid, cluster.n_ygrid, cluster.n_zgrid, 1);
    
    cluster.SNR_electron_dg.init(cluster.n_xgrid, cluster.n_ygrid, cluster.n_zgrid, 1); //AWS20010410
    cluster.SNR_nuc_dg.init(cluster.n_xgrid, cluster.n_ygrid, cluster.n_zgrid, 1); //AWS20010410
    create_SNR();
  
  }



// SYNCHROTRON EMISSION

  if (galdef.synchrotron >= 1) {                          //AWS20080229
     
    cluster.nu_synch_min =   galdef.nu_synch_min;
    cluster.nu_synch_max =   galdef.nu_synch_max;
    cluster.nu_synch_factor = galdef.nu_synch_factor;
    cluster.n_nu_synchgrid = int(log(cluster.nu_synch_max/cluster.nu_synch_min)/
				log(cluster.nu_synch_factor) + 1.001);
    
    cluster.nu_synch = new double[cluster.n_nu_synchgrid];
    //    if(galdef.verbose >= 1){ bug introduced in r330, fixed by AWS20091015

    //cout<<"synchrotron frequency grid: ";



    INFO(sBuf.str());


  }

	




  //cout<<" <<<< create_cluster"<<endl;
  return stat;

}
