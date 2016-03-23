c-----Main Program
c-----------------------------------------------------------------------
c-----------------------------------------------------------------------
      program radioDMcalc
      
      use constants
      use cluster_params
      use astro
      use synchrotron
      use particle

      implicit none

c-----Other variables, used only outside of functions
      real*8 sv,rmax,rmax_kpc,norm
c-----iterators, conversion factors, constants
      integer i,n
      real*8 j,ul,ll
c-----command line input variable names
      character(len=2) ch_char
      character(len=5) z_char
      character(len=4) mx_char
      character(len=3) r_char
      character(len=40) fname
c-----call darksusy initialization routine      
      call dsinit

c-----------------------------------------------------------------------
c---reference: dark matter annihilation channel numbers
c-----------------------------------------------------------------------
*** Ch No  Particles 
*** -----  ---------  
*** 13     W+ W-    
*** 15     e+ e-    
*** 17     mu+ mu-  
*** 19     tau+ tau-
*** 25     b b-bar  
c-----------------------------------------------------------------------
c-----------------------------------------------------------------------
c-----set channel,redshift as command-line arguments
      call getarg(1,ch_char)
      read(ch_char,*) ch
      call getarg(2,z_char)
      read(z_char,*) z
c     call getarg(3,mx_char)
c     read(mx_char,*) mx
c      fname='mx_sv_r300kpc_ch'//ch_char//'_z'//z_char//'.txt'
      fname='test'//ch_char//'_z'//z_char//'.txt'
c     fname='nu_Ssyn_mx'//mx_char//'GeV_ch'
c     &     //ch_char//'_z'//z_char//'.txt'
c     fname='r_rhox_jsyn_ssyn_mx'//mx_char//'_ch'
c     &     //ch_char//'_z'//z_char//'.txt'
c-----open file for saving
      open(unit=21,file=fname)
c-----------------------------------------------------------------------
c-----THIS IS WHERE THE ACTION IS      
c-----------------------------------------------------------------------
c-----whatever you're actually trying to calculate goes here
c-----spectra in this case
      n=100
      rkpc=415                  !ROI radius in kpc
      rmax=rconst(z)
      write(21,*)'#nu=',nu,'GHz | frms=',frms,'Jy/beam | B0=',b0,'muG | rmax=',rmax_kpc,'kpc | UL= ',min_flux(rmax),'Jy'
      write(21,*) 'mass (GeV) | < sigma v > (cm^3 s^-1)'
      do i=0,n
         ll=5.d0                !lower limit on mx
         ul=1000.d0             !upper limit on mx
         mx=ll*(dexp((dlog(ul)-dlog(ll))/dble(n)*dble(i)))
         Sin=ssyn(rmax)*GeVJy   !ssyn also implicitly depends on DM mass, channel, redshift, magnetic field, etc
         Sout=min_flux(rmax) !min_flux also implicitly depends on beam size, redshift
         sv=8*pi*mx**2*(Sout/Sin) !units: cm^3 s^-1
         write(*,*)mx,sv
         write(21,103)mx,sv
      enddo
      
 103  format(20(1x,e20.10))     !formatting: ew.d, where w-d>7
      
      stop
      
      end program
c-----------------------------------------------------------------------
c-----ACTION ENDS HERE
c-----------------------------------------------------------------------      
