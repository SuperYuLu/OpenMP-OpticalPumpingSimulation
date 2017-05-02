// main.cc --- 
// 
// Filename: main.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sun Apr 30 17:46:08 2017 (-0500)
// Version: 
// Last-Updated: Tue May  2 13:48:48 2017 (-0500)
//           By: yulu
//     Update #: 116
//

#include <iostream>
#include <fstream>
#include "main.h"
#include "Li7DLine.h"
#include "setValues.h"
int main(int argc, char *argv[]){
  LiDLine DLine;
  int numExcitedMf = 2 * excitedF + 1;
  int numCycles = (int)(totTime / tStep);
  // double popGroundF1[numCycles][3];
  // double popGroundF2[numCycles][5];
  // double popExcited[numCycles][numExcitedMf];

  int* pumpGroundF1_reduce_sigmaPlus;
  int* pumpGroundF1_reduce_sigmaMinus;
  int* pumpGroundF1_reduce_pi;

  int* pumpGroundF2_reduce_sigmaPlus;
  int* pumpGroundF2_reduce_sigmaMinus;
  int* pumpGroundF2_reduce_pi;

  int* decayGroundF1_reduce_sigmaPlus;
  int* decayGroundF1_reduce_sigmaMinus;
  int* decayGroundF1_reduce_pi;

  int* decayGroundF2_reduce_sigmaPlus;
  int* decayGroundF2_reduce_sigmaMinus;
  int* decayGroundF2_reduce_pi;
      
  double popGroundF1[3];
  double popGroundF2[5];
  double popExcited[numExcitedMf];

  double popGroundF1_last[3];
  double popGroundF2_last[5];
  double popExcited_last[numExcitedMf];

  int (*pumpGroundF1_sigmaPlus)[3];
  int (*pumpGroundF1_sigmaMinus)[3];
  int (*pumpGroundF1_pi)[3];

  int (*pumpGroundF2_sigmaPlus)[5];
  int (*pumpGroundF2_sigmaMinus)[5];
  int (*pumpGroundF2_pi)[5];


  
  std::ofstream fileG1;
  std::ofstream fileG2;
  std::ofstream fileE;
  fileG1.open("../dat/groundState_F1_population.csv");
  fileG2.open("../dat/groundState_F2_population.csv");
  fileE.open("../dat/excitedState_population.csv");
 
  if(excitedF == 2){
    pumpGroundF1_reduce_sigmaPlus  = reduceMatrix(DLine.D1.G1E2.sigmaPlus,1);
    pumpGroundF1_reduce_sigmaMinus  = reduceMatrix(DLine.D1.G1E2.sigmaMinus,1);
    pumpGroundF1_reduce_pi  = reduceMatrix(DLine.D1.G1E2.pi,1);
  
    pumpGroundF2_reduce_sigmaPlus  = reduceMatrix(DLine.D1.G2E2.sigmaPlus,1);
    pumpGroundF2_reduce_sigmaMinus  = reduceMatrix(DLine.D1.G2E2.sigmaMinus,1);
    pumpGroundF2_reduce_pi  = reduceMatrix(DLine.D1.G2E2.pi,1);

    decayGroundF1_reduce_sigmaPlus =  reduceMatrix(DLine.D1.G1E2.sigmaPlus,0);
    decayGroundF1_reduce_sigmaMinus =  reduceMatrix(DLine.D1.G1E2.sigmaMinus,0);
    decayGroundF1_reduce_pi =  reduceMatrix(DLine.D1.G1E2.pi,0);

    decayGroundF2_reduce_sigmaPlus =  reduceMatrix(DLine.D1.G2E2.sigmaPlus,0);
    decayGroundF2_reduce_sigmaMinus =  reduceMatrix(DLine.D1.G2E2.sigmaMinus,0);
    decayGroundF2_reduce_pi =  reduceMatrix(DLine.D1.G2E2.pi,0);

    pumpGroundF1_sigmaPlus  = DLine.D1.G1E2.sigmaPlus;
    pumpGroundF1_sigmaMinus  = DLine.D1.G1E2.sigmaMinus;
    pumpGroundF1_pi  = DLine.D1.G1E2.pi;
  
    pumpGroundF2_sigmaPlus  = DLine.D1.G2E2.sigmaPlus;
    pumpGroundF2_sigmaMinus  = DLine.D1.G2E2.sigmaMinus;
    pumpGroundF2_pi  = DLine.D1.G2E2.pi;
  }

  
  if(excitedF == 2){
    pumpGroundF1_reduce_sigmaPlus  = reduceMatrix(DLine.D1.G1E1.sigmaPlus,1);
    pumpGroundF1_reduce_sigmaMinus  = reduceMatrix(DLine.D1.G1E1.sigmaMinus,1);
    pumpGroundF1_reduce_pi  = reduceMatrix(DLine.D1.G1E1.pi,1);
  
    pumpGroundF2_reduce_sigmaPlus  = reduceMatrix(DLine.D1.G2E1.sigmaPlus,1);
    pumpGroundF2_reduce_sigmaMinus  = reduceMatrix(DLine.D1.G2E1.sigmaMinus,1);
    pumpGroundF2_reduce_pi  = reduceMatrix(DLine.D1.G2E1.pi,1);

    decayGroundF1_reduce_sigmaPlus =  reduceMatrix(DLine.D1.G1E1.sigmaPlus,0);
    decayGroundF1_reduce_sigmaMinus =  reduceMatrix(DLine.D1.G1E1.sigmaMinus,0);
    decayGroundF1_reduce_pi =  reduceMatrix(DLine.D1.G1E1.pi,0);

    decayGroundF2_reduce_sigmaPlus =  reduceMatrix(DLine.D1.G2E1.sigmaPlus,0);
    decayGroundF2_reduce_sigmaMinus =  reduceMatrix(DLine.D1.G2E1.sigmaMinus,0);
    decayGroundF2_reduce_pi =  reduceMatrix(DLine.D1.G2E1.pi,0);

    pumpGroundF1_sigmaPlus  = DLine.D1.G1E1.sigmaPlus;
    pumpGroundF1_sigmaMinus  = DLine.D1.G1E1.sigmaMinus;
    pumpGroundF1_pi  = DLine.D1.G1E1.pi;
  
    pumpGroundF2_sigmaPlus  = DLine.D1.G2E1.sigmaPlus;
    pumpGroundF2_sigmaMinus  = DLine.D1.G2E1.sigmaMinus;
    pumpGroundF2_pi  = DLine.D1.G2E1.pi;
  }
  // asume F' = 2
  for(int n = 0; n < numCycles - 1; n++){
    std::cout << "Cycle: " << n << std::endl;
    
    if(n == 0) {//initialize
      for (int i = 0; i < 3; i++){
	popGroundF1[i] = 1.0 / 3.0;
	popGroundF1_last[i] = popGroundF1[i];
      for (int i = 0; i < 5; i++){
	popGroundF2[i] = 0.0;
	popGroundF2_last[i] = popGroundF2[i];
      }
      for (int i = 0; i < numExcitedMf; i++){
	popExcited[i] = 0.0;
	popExcited_last[i] = popExcited[i];
      }    
      }
    }

    else{

      for(int i = 0; i < 3; i++){
	popGroundF1[i] = popGroundF1_last[i] - popGroundF1_last[i] * pumpGroundF1_reduce_sigmaPlus[i] * dipoleElement;
	for(int j = 0; j < numExcitedMf; j ++){
	  popGroundF1[i] += \
	    + popExcited[j] * pumpGroundF1_sigmaPlus[j][i]* tStep * dipoleElement	\
	    + popExcited[j] * pumpGroundF1_sigmaMinus[j][i] * tStep * dipoleElement	\
	    + popExcited[j] * pumpGroundF1_pi[j][i] * tStep * dipoleElement;
	}
      
      }

      for(int i = 0; i < 5; i++){
	popGroundF2[i] = popGroundF2_last[i] - popGroundF2_last[i] * pumpGroundF2_reduce_sigmaPlus[i] * tStep * dipoleElement;
	for(int j = 0; j < numExcitedMf; j ++){
	  popGroundF2[i] += \
	    + popExcited[j] * pumpGroundF2_sigmaPlus[j][i] * tStep * dipoleElement	\
	    + popExcited[j] * pumpGroundF2_sigmaMinus[j][i] * tStep * dipoleElement	\
	    + popExcited[j] * pumpGroundF2_pi[j][i] * tStep * dipoleElement;
	}
      }

      for(int i = 0; i < numExcitedMf; i++){
	for(int j = 0; j < 3; j++){
	  popExcited[i] = popExcited_last[i] + popGroundF1_last[j] * pumpGroundF1_sigmaPlus[i][j] * tStep * dipoleElement;
	}
	for(int j = 0; j < 5; j++){
	  popExcited[i] += popGroundF2_last[j] * pumpGroundF2_sigmaPlus[i][j] * tStep * dipoleElement;
	}

	popExcited[i] += popExcited_last[i] * tStep * dipoleElement *\
	  (decayGroundF1_reduce_sigmaPlus[i]\
	   + decayGroundF1_reduce_sigmaMinus[i]\
	   + decayGroundF1_reduce_pi[i]\
	   + decayGroundF2_reduce_sigmaPlus[i]\
	   + decayGroundF2_reduce_sigmaMinus[i]\
	   + decayGroundF2_reduce_pi[i]);	    
      }
    }	   

    // Write into files
    for(int i = 0; i < 3; i++){
      fileG1 << popGroundF1[i] << " ";
      popGroundF1_last[i] = popGroundF1[i];
    }
    fileG1 << "\n";

    for(int i = 0; i < 5; i++){
      fileG2 << popGroundF2[i] << " ";
      popGroundF2_last[i] = popGroundF2[i];
    }
    fileG2 << "\n";

    for(int i = 0; i < numExcitedMf; i++){
      fileE << popExcited[i] << " ";
      popExcited_last[i] = popExcited[i];
    }
    fileE << "\n";
  }

  fileG1.close();
  fileG2.close();
  fileE.close();
    

    /*


    
   
    //=======================> Error Here <==============================
    popExcited[n+1] = \  // << cannot assign array like this 
      + matrixMulti(popGroundF1[n], transMatrix(DLine.D1.G1E2.sigmaPlus),5 ) \
     
      - vectorMulti(popExcited[n], reduceMatrix(DLine.D1.G1E2.sigmaPlus, 0))\
      - vectorMulti(popExcited[n], reduceMatrix(DLine.D1.G1E2.sigmaMinus, 0))\
      - vectorMulti(popExcited[n], reduceMatrix(DLine.D1.G1E2.pi, 0))\
      
      + matrixMulti(popGroundF2[n], transMatrix(DLine.D1.G2E2.sigmaPlus))
      - vectorMulti(popExcited[n], reduceMatrix(DLine.D1.G2E2.sigmaPlus, 0))\
      - vectorMulti(popExcited[n], reduceMatrix(DLine.D1.G2E2.sigmaMinus, 0))\
      - vectorMulti(popExcited[n], reduceMatrix(DLine.D1.G2E2.pi, 0));

    popGroundF1[n+1] = \
      - vectorMulti(popExcited[n], reduceMatrix(DLine.D1.G1E2.sigmaPlus, 1))\
      + matrixMulti(popExcited[n], DLine.D1.G1E2.sigmaPlus)\
      + matrixMulti(popExcited[n], DLine.D1.G1E2.sigmaMinus)\
      + matrixMulti(popExcited[n], DLine.D1.G1E2.pi);

    popGroundF2[n+1] = \
      - vectorMulti(popGroundF2[n], reduceMatrix(DLine.D1.G2E2.sigmaPlus, 1))\
      + matrixMulti(popExcited[n], DLine.D1.G2E2.sigmaPlus)\
      + matrixMulti(popExcited[n], DLine.D1.G2E2.sigmaMinus)\
      + matrixMulti(popExcited[n], DLine.D1.G2E2.pi);

  }
    */      
      
 
  return 0;
}

