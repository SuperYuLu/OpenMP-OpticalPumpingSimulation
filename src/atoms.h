#include<iostream>
#include<cstdlib>
#include<ctime>
class atoms{
public:
  int f;
  int mf;
  void pump(int);
  void emission();
};

void atoms :: pump(int polarization){
  if(-pumpExcitedStateF < (mf + polarization) < pumpExciitedStateF) //check if recieving state avaliable
    {
      f = pumpExcitedStateF;
      mf = mf + polarization;
    }
  else continue;
}

void atoms :: emission(){
  double f1SigmaPlus, f1SigmaMinus, f1Pi, f2SigmaPlus, f2SigmaMinus, f2Pi;
  //float randomGen();
  float randNum;
  srand(time(0));
  if(f == pumpExcitedStateF){ // Only excited states can decay
  
    
    // Decay is inverse of pumping.
    //first check if there is receiving ground state avaliable
    
    // Decay back to initial ground state F
    if(-initGroundStateF < (mf + 1) < initGroundStateF)
      // probablity of emitting sigma+ photon, index refer to transitionStrength.h
      f2SigmaPlus = Li7DLine.D1.F1.sigmaMinus[pumpExcitedStateF - 1][mf + 1 + pumpExcitedStateF]
    else
      f2SigmaPlus = 0.;

    if(-initGroundStateF < mf < initGroundStateF)
      // probablity of emitting pi photon
      f2Pi = Li7DLine.D1.F1.pi[pumpExcitedStateF - 1][mf + pumpExcitedStateF];
    else
      f2Pi = 0.;

    if(-initGroundStateF < (mf - 1) < initGroundStateF)
      // probabilty of emitting sigma- photon
      f2SigmaMinus = Li7DLine.D1.F1.sigmaPlus[pumpExcitedStateF - 1][mf - 1 + pumpExcitedStateF];
    else
      f2SigmaMinus = 0.;



    // Decay back to targetGroundStateF
    if(-targetGroundStateF < (mf + 1) < targetGroundStateF)
      // probablity of emitting sigma+ photon, index refer to transitionStrength.h
      f2SigmaPlus = Li7DLine.D1.F2.sigmaMinus[pumpExcitedStateF - 1][mf + 1 + pumpExcitedStateF]
    else
      f2SigmaPlus = 0.;

    if(-targetGroundStateF < mf < targetGroundStateF)
      // probablity of emitting pi photon
      f2Pi = Li7DLine.D1.F2.pi[pumpExcitedStateF - 1][mf + pumpExcitedStateF];
    else
      f2Pi = 0.;

    if(-targetGroundStateF < (mf - 1) < targetGroundStateF)
      // probabilty of emitting sigma- photon
      f2SigmaMinus = Li7DLine.D1.F2.sigmaPlus[pumpExcitedStateF - 1][mf - 1 + pumpExcitedStateF];
    else
      f2SigmaMinus = 0.;

    // Check if the probablities for spontaneous decay make sence
    // All probablities should add up to 1
    if(f1SigmaPlus+ f1SigmaMinus+ f1Pi+f2SigmaPlus+ f2SigmaMinus+ f2Pi = 1)
      std::cout << "------\nTransition strength value wrong (sum != 1)\n------" << std::endl;

    randNum = rand()%1000 / 1000.0;
    if (randNum < f1SigmaPlus)
      {
	f = 1;
	mf = mf + 1;
      }
    else if(randNum < (f1SigmaPlus + f1Pi))
      {
	f = 1;
	mf = mf;
      }
    else if(randNum < (f1SigmaPlus + f1SigmaMinus + f1Pi))
      {
	f = 1;
	mf = mf -1;
      }
    else if(randNum < (f2SigmaPlus + f1SigmaPlus + f1SigmaMinus + f1Pi))
      {
	f = 2;
	mf = mf  + 1;
      }
    else if (randNum < (f2Pi + f2SigmaPlus + f1SigmaPlus + f1SigmaMinus + f1Pi))
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

  else continue;
}
      
	 
    
