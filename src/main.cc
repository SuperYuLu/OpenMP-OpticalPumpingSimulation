// main.cc --- 
// 
// Filename: main.cc
// Description: 
//     Main program to calculation the optical pumping process
//     for 7Li D1 Line
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sun Apr 23 22:28:03 2017 (-0500)
// Version: 0.1
// Last-Updated: Sun Apr 30 15:30:25 2017 (-0500)
//           By: yulu
//     Update #: 152
// 

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "main.h"
#include "setValue.h"
#include "transitionStrength.h"


int main(int argc, char *argv[]){
  int numOfCycles = (int)(totTime / tStep);  // Total num of simulatio cycles
  double groundStatesPop[numOfCycles][8] = {0.};  // Ground state population at each step
  double excitedStatesPop[numOfCycles][2 * excitedStateF + 1] = {0.};  //Excited state population
  Li7D1Trans D1Trans;  // Relative transition strength for D1 line

  
  //double decayMatrix[2 * excitedStatesF + 1][8]; // shape: (2F' + 1) x 8
  //double exciteMatrix[8][2 * exciteStateF + 1];
  
  // int **pumpMatrix; // shape 3 x (2F' + 1)
  // int **repumpMatrix; // shape 5 x (2F' + 1)
  // for(int i = 0; i < 3; i++) pumpMatrix[i] = new int[2 * excitedStateF + 1];
  // for(int i = 0; i < 5; i++) repumpMatrix[i]  = new int[2 * excitedStateF + 1];

  int (*pumpMatrix)[2 * excitedStateF + 1];  // pump Matrix 
  int (*repumpMatrix)[2 * excitedStateF + 1];  // repump matrix
  //double (*decayMatrix)[2 * excitedStateF + 1];
  double **decayMatrix;  // Matrix for decay transition
  int exciteMatrix[8][2 * excitedStateF + 1];  // combined matrix for pump and repump 
  double decayMatrix_1D [2 * excitedStateF + 1]; // reduced 1D decay matrix 
  int exciteMatrix_1D [8]; // Reduced 1d excite matrix 
  // Get decayMatrix [2F'+1][8]
  decayMatrix = calSpontEmission(excitedStateF, D1Trans);
  //std::cout << decayMatrix << std::endl;
  // Get pump and repump matrix [3][2F'+1] & [5][2F'+1] 
  if(excitedStateF == 1){
    //pumpMatrix = D1Trans.F11;
    //repumpMatrix = D1Trans.F21;
  }
  else{
    pumpMatrix = D1Trans.F12;
    repumpMatrix = D1Trans.F22;
  }

  //Combine the pump and repump matix in to one [8][2F'+1]
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 2 * excitedStateF + 1; j++){
      if(i < 3) exciteMatrix[i][j] = pumpMatrix[i][j];
      else exciteMatrix[i][j] = repumpMatrix[i][j];
    }
  }

  // Sum decay Matrix to [2F'+1][1]
  for(int i = 0; i < 2 * excitedStateF + 1; i ++){
    decayMatrix_1D[i] = 0;
    for(int j = 0; j < 8; j++)
      decayMatrix_1D[i] += decayMatrix[i][j];
  }
  

  // Sum excite matrix into [8][1]
  for(int i = 0; i < 8; i++){
    exciteMatrix_1D[i] = 0;
    for(int j = 0; j< 2 * excitedStateF + 1; j++)
      exciteMatrix_1D[i] += exciteMatrix[i][j];
  }
			    
  //initializeStates();
  for(int i = 0; i < 8; i++) groundStatesPop[0][i] = 0.125;

  
  
  for(int i = 0; i < numOfCycles; i++){ // time loop

    for(int k = 0; k < (2 * excitedStateF + 1); k++){ // excited hpf states
      for(int j = 0; j < 8;j++){ // gound hpf states 
	  excitedStatesPop[i + 1][k] = \
	    groundStatesPop[i][j] * exciteMatrix[j][k] * tStep	\
	    - excitedStatesPop[i][k] * decayMatrix[k][j];
	}
    }

    for(int j = 0; j < 8; j++){ // ground hpf states
      for(int k = 0; k < (2 * excitedStateF + 1); k++){ //excited hpf states
	groundStatesPop[i + 1][j] = \
	  - groundStatesPop[i][j] * exciteMatrix[j][k]	\
	  + excitedStatesPop[i][k] * decayMatrix[k][j];
      }
    }
    
  }

  
  
  //std::string savePath = "../dat/";
  //std::string fileName1 = "numInitState.csv";
  //std::string f1 = "numGroundF1.csv";
  //std::string f2 = "numGroundF1.csfdv";
  //std::string filename2 = "numTargetState.csv";

  
  std::cout << "test" <<std::endl;
  std::ofstream file1;
  std::ofstream file2;
  /*  
  file1.open("numInitState.txt", std::ios::in);
  file2.open("numTargetState.txt", std::ios::in);
  
  if(file1.is_open() && file2.is_open()){
    for(int k = 0; k < numOfCycles; k++){
      for(int i = 0; i < 8; i++)
	file1 << groundStatesPop[k][i] << " ";
      file1 << "\n";
      for(int j = 0; j < 2 * excitedStateF + 1; j++)
	file2 << excitedStatesPop[k][j] << " ";
      file2 << "\n";
    }
  }
  else
    printf("Cannot open file to save data\n");
  */
  
  return 0;
}

  
