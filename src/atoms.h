#include<iostream>
#include<cstdlib>
#include<ctime>
#include "setValue.h"
#include "transitionStrength.h"
class atoms{
public:
  int f;
  int mf;
  void pump(int);
  void emission();
};

// polarization = -1, 0, 1 for sigma-, pi, sigma+ polarization
void atoms :: pump(int polarization){
  if(-pumpExcitedStateF < (mf + polarization) && (mf + polarization) < pumpExcitedStateF) //check if recieving state avaliable
    {
      f = pumpExcitedStateF;
      mf = mf + polarization;
    }
  
}

void atoms :: emission(){
  double f1SigmaPlus, f1SigmaMinus, f1Pi, f2SigmaPlus, f2SigmaMinus, f2Pi, probSum;
  //float randomGen();
  float randNum;
  srand(time(0));
  if(f == pumpExcitedStateF){ // Only excited states can decay
  
    
    // Decay is inverse of pumping.
    //first check if there is receiving ground state avaliable
    
    // Decay back to initial ground state F
    std::cout << mf << "," <<  initGroundStateF << "," << targetGroundStateF  << std::endl;
    
    if(-initGroundStateF <= (mf + 1) && (mf + 1) <= initGroundStateF){
      // probablity of emitting sigma+ photon, index refer to transitionStrength.h
      f1SigmaPlus = Li7DLine.D1.F1.sigmaMinus[pumpExcitedStateF - 1][mf + 1 + pumpExcitedStateF];
      std::cout << "===================\n" << f1SigmaPlus << std::endl;
    }
    else
      f1SigmaPlus = 0.;

    if(-initGroundStateF <= mf && mf <= initGroundStateF)
      // probablity of emitting pi photon
      f1Pi = Li7DLine.D1.F1.pi[pumpExcitedStateF - 1][mf + pumpExcitedStateF];
    else
      f1Pi = 0.;

    if(-initGroundStateF <= (mf - 1) && (mf - 1)<= initGroundStateF)
      // probabilty of emitting sigma- photon
      f1SigmaMinus = Li7DLine.D1.F1.sigmaPlus[pumpExcitedStateF - 1][mf - 1 + pumpExcitedStateF];
    else
      f1SigmaMinus = 0.;



    // Decay back to targetGroundStateF
    if(-targetGroundStateF <= (mf + 1) && (mf + 1) <= targetGroundStateF)
      // probablity of emitting sigma+ photon, index refer to transitionStrength.h
      f2SigmaPlus = Li7DLine.D1.F2.sigmaMinus[pumpExcitedStateF - 1][mf + 1 + pumpExcitedStateF];
    else
      f2SigmaPlus = 0.;

    if(-targetGroundStateF <= mf && mf  <= targetGroundStateF)
      // probablity of emitting pi photon
      f2Pi = Li7DLine.D1.F2.pi[pumpExcitedStateF - 1][mf + pumpExcitedStateF];
    else
      f2Pi = 0.;

    if(-targetGroundStateF <= (mf - 1) && (mf -1)<= targetGroundStateF)
      // probabilty of emitting sigma- photon
      f2SigmaMinus = Li7DLine.D1.F2.sigmaPlus[pumpExcitedStateF - 1][mf - 1 + pumpExcitedStateF];
    else
      f2SigmaMinus = 0.;

    // Check if the probablities for spontaneous decay make sence
    // All probablities should add up to 1
    probSum = f1SigmaPlus+ f1SigmaMinus+ f1Pi+f2SigmaPlus+ f2SigmaMinus+ f2Pi;
    std::cout << f1SigmaPlus << ","<< f1SigmaMinus << "," <<  f1Pi+f2SigmaPlus << "," << f2SigmaMinus << "," << f2SigmaMinus << "," << f2Pi << std::endl;
    if(probSum != 1){
      //std::cout << "------\nTransition strength value wrong(sum != 1)\n------" << std::endl;
      //std::cout << "probSum = " << probSum << std::endl;
    }

    randNum = rand()%1000 / 1000.0;
    if (randNum <= f1SigmaPlus)
      {
	f = 1;
	mf = mf + 1;
      }
    else if(randNum <= (f1SigmaPlus + f1Pi))
      {
	f = 1;
	mf = mf;
      }
    else if(randNum <= (f1SigmaPlus + f1SigmaMinus + f1Pi))
      {
	f = 1;
	mf = mf -1;
      }
    else if(randNum <= (f2SigmaPlus + f1SigmaPlus + f1SigmaMinus + f1Pi))
      {
	f = 2;
	mf = mf  + 1;
      }
    else if (randNum <= (f2Pi + f2SigmaPlus + f1SigmaPlus + f1SigmaMinus + f1Pi))
      {
	f = 2;
	mf = mf;
      }
    else
      {
	f = 2;
	mf = mf -1;
      }
  }
}
