#FF=$(FC)
FF=gfortran

### Compiler options ###

# Options for linux
FOPT = -O -ffixed-line-length-none

### Setups for the DarkSUSY install directory ###

# Determine where to install stuff (prefix is set in configure)
prefix=/home/alex/research/darksusy-5.1.2
# DS_INSTALL is where the library and data files will be installed
DS_INSTALL=${prefix}

LIB=$(DS_INSTALL)/lib
INC=-I./ -I$(DS_INSTALL)/include 
cfitsio=.

### you must set GALPROP_LIBS if you have compiled galprop

modtest : modtest.f $(LIB)/libdarksusy.a
	$(FF) $(FOPT) -I$(INC) -L$(LIB) -o modtest modtest.f constants.o particle.o cluster_params.o astro.o synchrotron.o \
         -ldarksusy -lFH -lHB





RadioDMcalc : RadioDMcalc.f $(LIB)/libdarksusy.a
	$(FF) $(FOPT) -I$(INC) -L$(LIB) -o RadioDMcalc RadioDMcalc.f \
         -ldarksusy -lFH -lHB

all: constants particle cluster_params astro synchrotron

constants : constants.f $(LIB)/libdarksusy.a
	$(FF) $(FOPT) -I$(INC) -L$(LIB)  -c constants.f \
         -ldarksusy -lFH -lHB


particle : particle.f $(LIB)/libdarksusy.a
	$(FF) $(FOPT) -I$(INC) -L$(LIB)  -c particle.f \
         -ldarksusy -lFH -lHB


cluster_params : cluster_params.f $(LIB)/libdarksusy.a
	$(FF) $(FOPT) -I$(INC) -L$(LIB)  -c cluster_params.f \
         -ldarksusy -lFH -lHB

astro : astro.f $(LIB)/libdarksusy.a
	$(FF) $(FOPT) -I$(INC) -L$(LIB)  -c astro.f \
         -ldarksusy -lFH -lHB


synchrotron : synchrotron.f $(LIB)/libdarksusy.a
	$(FF) $(FOPT) -I$(INC) -L$(LIB)  -c synchrotron.f \
         -ldarksusy -lFH -lHB