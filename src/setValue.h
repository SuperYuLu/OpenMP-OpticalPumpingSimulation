//#ifndef __SETVALUE_H_INCLUDED__
//#define __SETVALUE_H_INCLUDED__

int const lifeTime = 27;    //[ns]
int const gamma = 37.196457e6;

// 3-level pumping model
int const groundStateF = 1;
int const excitedStateF = 2;
int const targetGroundStateF = 2;

double const tStep = 2e-6; //[us]
double const totTime = 4e-6;
double const dipoleElement = 2.537e-29; // from Rb87 D1 
//#endif
