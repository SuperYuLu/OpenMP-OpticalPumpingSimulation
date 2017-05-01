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
// Last-Updated: Mon May  1 00:00:53 2017 (-0500)
//           By: yulu
//     Update #: 64
//

#include <iostream>
#include "main.h"
#include "Li7DLine.h"
#include "setValues.h"
int main(int argc, char *argv[]){
  LiDLine DLine;
  int numExcitedMf = 2 * excitedF + 1;
  int numCycles = (int)(totTime / tStep);
  double popGroundF1[numCycles][3];
  double popGroundF2[numCycles][5];
  double popExcited[numCycles][numExcitedMf];
  int* pumpGroundF1_1D;
  int* pumpGroundF2_1D;
  int **decayMatrix;

  
  pumpGroundF1_1D  = reduceMatrix(DLine.D1.G1E2.sigmaPlus,0);
  pumpGroundF2_1D = reduceMatrix(DLine.D1.G2E2.sigmaPlus,1);
  decayMatrix = transMatrix(DLine.D1.G1E2.sigmaPlus);

  // asume F' = 2
  for(int n = 0; n < numCycles - 1; n++){
    if(n == 0) {
      for (int i = 0; i < 3; i++) popGroundF1[0][i] = 1.0 / 3.0;
      for (int i = 0; i < 5; i++){
	popGroundF2[0][i] = 0.0;
	popExcited[0][i] = 0.0;
      }
   
      
    }//initialize
    //=======================> Error Here <==============================
    popExcited[n+1] = \
      + matrixMulti(popGroundF1[n], transMatrix(DLine.D1.G1E2.sigmaPlus)) \
      ;/*
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
    */
  }
      
      
 
  return 0;
}


