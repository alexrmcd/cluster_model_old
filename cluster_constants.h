
//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * cluster_constants.h *                                                    3/18/2016
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|

#ifndef CLUSTER_CONSTANTS_H
#define CLUSTER_CONSTANTS_H




const double year2sec=365.25*24.*3600.; 
const double Mpc2cm  =3.08568e24;
const double c       =3.0e10;

const double m_electron = 0.511;      // MeV
const double m_proton   = 938. ;      // MeV 

const double h_planck=6.6260755e-27 ; // erg sec
const double eV_to_erg=1.60217733e-12;
const double erg_to_eV=1./eV_to_erg;

const double H0 = 70.4 // km/s/Mpc
const double OmegaM = 0.272
const double OmegaL = 0.728

const double GeVJy=1.6e20   //GeV/s/Hz/cm^2 to Jy


const double // PHYSICAL CONSTANTS:
   Pi  = 3.141592653589793,    // Pi number
   C   = 2.99792458e10,        // cm/s, =c speed of light
   H   = 6.626075540e-27,      // erg*s, =h Planck constant
   H2Pi= 6.582122020e-22,      // MeV*s, =h/(2Pi) Planck constant
   ALPHAf=1./137.035989561,    // =e^2/(hc/2Pi) fine-structure const.
   Rele= 2.8179409238e-13,     // cm, =e^2/mc^2 class. electron radius
   MEV2ERG = 1.6021773349e-6,  // MeV/erg, conversion const.
   H2PiC   = 0.19732705359e-10,// MeV*cm, =hc/(2Pi) conversion const.
             // MASSES: Particle Data Group (1990, Phys.Lett. 239)
   Mele = 0.5109990615,        // MeV/c^2, electron rest mass
   MD   = 1.232,               // GeV, Delta(1232)-isobar mean mass 
   GD   = 0.0575,              // GeV, Delta-isobar wight (0.115/2.)
   Mp   = 0.938,               // GeV, Proton rest mass
   Mn   = 0.9396,              // GeV, Neutron rest mass
   Md   = 1.8756,              // GeV, Deutron rest mass
   Mpi0 = 0.135,               // GeV, Neutral pion rest mass
   Mpi1 = 0.1396,              // GeV, Charged pion rest mass
   Mmu  = 0.10566,             // GeV, Muon rest mass
   MK   = 0.49365,             // GeV, Kaon rest mass
             // BRANCHING RATIOS:
   BR1  = 0.635,               // br. ratio for channel K -> mu +nu
   BR2  = 0.212,               // br. ratio for channel K -> pi^(+/-) +pi^0



#endif
