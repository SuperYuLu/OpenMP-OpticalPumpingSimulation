#include<iostream>
//#include<cstdlib>
#include "setValue.h"
#include "transitionStrength.h"
class atoms{
public:
  int l;
  int f;
  int mf;
  void pump(int);
  void repump(int);
  void emission(float);
};

// polarization = -1, 0, 1 for sigma-, pi, sigma+ polarization
void atoms :: pump(int polarization){
  if(f == 1 && l == 0){
    if((-pumpExcitedStateF <= (mf + polarization)) && ((mf + polarization) <= pumpExcitedStateF)) //check if recieving state avaliable
      {
	f = pumpExcitedStateF;
	l = 1;
	mf = mf + polarization;
      }
  
  }
}

void atoms :: repump(int polarization){
  if(f == 2 && l == 0){
    if((-pumpExcitedStateF <= (mf + polarization)) && ((mf + polarization) <= pumpExcitedStateF)) //check if recieving state avaliable
      {
	f = pumpExcitedStateF;
	l = 1;
	mf = mf + polarization;
      }
  
  }
}

void atoms :: emission(float randNum){
  double f1SigmaPlus, f1SigmaMinus, f1Pi, f2SigmaPlus, f2SigmaMinus, f2Pi, probSum;
  //float randomGen();
 
  
  if(f == pumpExcitedStateF && l == 1){ // Only excited states can decay
  
    
    // Decay is inverse of pumping.
    //first check if there is receiving ground state avaliable
    
    // Decay back to initial ground state F
    //std::cout << mf << "," <<  initGroundStateF << "," << targetGroundStateF  << std::endl;
    
    if(-initGroundStateF <= (mf + 1) && (mf + 1) <= initGroundStateF){
      // probablity of emitting sigma+ photon, index refer to transitionStrength.h
      f1SigmaPlus = Li7DLine.D1.F1.sigmaMinus[pumpExcitedStateF - 1][mf + 1 + initGroundStateF];
      //std::cout << "===================\n" << f1SigmaPlus << std::endl;
    }
    else
      f1SigmaPlus = 0.;

    if(-initGroundStateF <= mf && mf <= initGroundStateF)
      // probablity of emitting pi photon
      f1Pi = Li7DLine.D1.F1.pi[pumpExcitedStateF - 1][mf + initGroundStateF];
    else
      f1Pi = 0.;

    if(-initGroundStateF <= (mf - 1) && (mf - 1)<= initGroundStateF)
      // probabilty of emitting sigma- photon
      f1SigmaMinus = Li7DLine.D1.F1.sigmaPlus[pumpExcitedStateF - 1][mf - 1 + initGroundStateF];
    else
      f1SigmaMinus = 0.;



    // Decay back to targetGroundStateF
    if(-targetGroundStateF <= (mf + 1) && (mf + 1) <= targetGroundStateF)
      // probablity of emitting sigma+ photon, index refer to transitionStrength.h
      f2SigmaPlus = Li7DLine.D1.F2.sigmaMinus[pumpExcitedStateF - 1][mf + 1 + targetGroundStateF];
    else
      f2SigmaPlus = 0.;

    if(-targetGroundStateF <= mf && mf  <= targetGroundStateF)
      // probablity of emitting pi photon
      f2Pi = Li7DLine.D1.F2.pi[pumpExcitedStateF - 1][mf + targetGroundStateF];
    else
      f2Pi = 0.;

    if(-targetGroundStateF <= (mf - 1) && (mf -1)<= targetGroundStateF)
      // probabilty of emitting sigma- photon
      f2SigmaMinus = Li7DLine.D1.F2.sigmaPlus[pumpExcitedStateF - 1][mf - 1 + targetGroundStateF];
    else
      f2SigmaMinus = 0.;

    // Check if the probablities for spontaneous decay make sence
    // All probablities should add up to 1
    probSum = f1SigmaPlus+ f1SigmaMinus+ f1Pi+f2SigmaPlus+ f2SigmaMinus+ f2Pi;
    //std::cout << f1SigmaPlus << ","<< f1SigmaMinus << "," <<  f1Pi << "," << f2SigmaPlus << "," << f2SigmaMinus << "," << f2SigmaMinus << "," << f2Pi << std::endl;
    if(probSum != 1){
      std::cout << "------\nTransition strength value wrong(sum != 1)\n------" << std::endl;
      std::cout << "probSum = " << probSum << std::endl;
    }

    
    
    if (randNum <= f1SigmaPlus)
      {
	f = 1;
	l = 0;
	mf = mf + 1;
      }
    else if(randNum <= (f1SigmaPlus + f1Pi))
      {
	f = 1;
	l = 0;
	mf = mf;
      }
    else if(randNum <= (f1SigmaPlus + f1SigmaMinus + f1Pi))
      {
	f = 1;
	l = 0;
	mf = mf -1;
      }
    else if(randNum <= (f2SigmaPlus + f1SigmaPlus + f1SigmaMinus + f1Pi))
      {
	f = 2;
	l = 0;
	mf = mf  + 1;
      }
    else if (randNum <= (f2Pi + f2SigmaPlus + f1SigmaPlus + f1SigmaMinus + f1Pi))
      {
	f = 2;
	l = 0;
	mf = mf;
      }
    else
      {
	f = 2;
	l = 0;
	mf = mf -1;
      }
  }
}

