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
// Last-Updated: Tue Apr 25 13:41:42 2017 (-0500)
//           By: yulu
//     Update #: 39
// 

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>
//#include<main.h>
#include "setValue.h"

int main(){
  int numOfCycles = (int)(totTime / tStep);
  double groundStatesPop[numOfCycles][8] = 0;
  double excitedStatesPop[numOfCycles][2 * excitedStateF + 1] = 0;
  
  //double decayMatrix[2 * excitedStateF + 1][8]; // shape: (2F' + 1) x 8
  //double exciteMatrix[8][2 * exciteStateF + 1];
  
  // int **pumpMatrix; // shape 3 x (2F' + 1)
  // int **repumpMatrix; // shape 5 x (2F' + 1)
  // for(int i = 0; i < 3; i++) pumpMatrix[i] = new int[2 * excitedStateF + 1];
  // for(int i = 0; i < 5; i++) repumpMatrix[i]  = new int[2 * excitedStateF + 1];

  int (*pumpMatrix)[2 * excitedStateF + 1];
  int (*repumpMatrix)[2 * excitedStateF + 1];
  int (*decayMatrix)[2 * excitedStateF + 1];
  int exciteMatrix[8][2 * excitedStateF + 1];
  int decayMatrix_1D [2 * excitedStateF + 1];
  int exciteMatrix_1D [8];
  // Get decayMatrix [2F'+1][8]
  decayMatrix = calSpontEmission(excitedStateF);
  
  // Get pump and repump matrix [3][2F'+1] & [5][2F'+1] 
  if(excitedStateF == 1){
    pumpMatrix = D1Trans.F11;
    repumpMatrix = D1Trans.F21;
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

  
  // =================> Check here, not finished <=============================
  for(int i = 0; i < numOfCycles; i++){ // time loop

    for(int k = 0; k < (2 * excitedStateF + 1); k++){ // excited hpf states
      for(int j = 0; j < 8;j++){ // gound hpf states 
	  excitedStatePop[i + 1][k] = \ 
	    groundStatesPop[i][j] * exciteMatrix[j][k] * tStep \
	    - excitedStatePop[i][k] * decayMatrix[k][j];
	}
    }

    for(int j = 0; j < 8; j++){ // ground hpf states
      for(int k = 0; k < (2 * excitedStateF + 1); k++){ //excited hpf states
	groundStatesPop[i + 1][j] = \
	  - groundStatesPop[i][j] * exciteMatrix[j][k]	\
	  + excitedStatePop[i][k] * decayMatrix[k][j];
      }
    }
    
  }


  std::string path="../dat/";
  std::string fileName1="numInitState.csv";
  std::string fileName2="numTargetState.csv";

  std::ofstream file1;
  std::ofstream file2;

  file1.open(path + fileName1);
  file2.open(path + fileName2);

  for(int k = 0; k < numOfCycles; k++){
    file1 << numInitState[k][0] << ", " << numInitState[k][1] << ", " << numInitState[k][2] << std::endl;
    file2 << numTargetState[k][0] << ", " << numTargetState[k][1] << ", " << numTargetState[k][2] << ", " << numTargetState[k][3] << ", " << numTargetState[k][4] << ", " << numTargetState[k][0] << std::endl;
  }

  








  atoms atom[numOfAtoms];
  int numInitState[numOfCycles][2 * initGroundStateF + 1];
  int numTargetState[numOfCycles][2 * targetGroundStateF + 1];
  float randNum;
  srand(112);
  for(int i = 0; i < numOfCycles; i++){
    
      for(int j = 0; j < numOfAtoms; j++){
	if(i == 0){
	  atom[j].f = initGroundStateF;
	  atom[j].l = 0;
	  switch(j%3){
	  case 0 : atom[j].mf = -1;
	    break;
	  case 1 : atom[j].mf = 0;
	    break;
	  case 2 : atom[j].mf = 1;
	    break;
	  }
	 
	  //std::cout << "mf: " << atom[j].mf << std::endl;
	}
	
	randNum = rand()%1000 / 1000.0;
	atom[j].pump(1);
	atom[j].repump(1);
	atom[j].emission(randNum);
	if(atom[j].f == initGroundStateF){
	  switch(atom[j].mf){
	  case -1 : numInitState[i][0] += 1;
	    break;
	  case 0 : numInitState[i][1] += 1;
	    break;
	  case 1 : numInitState[i][2] += 1;
	    break;
	  }
	}
	else if(atom[j].f == targetGroundStateF){
	  switch(atom[j].mf){
	  case -2 : numTargetState[i][0] += 1;
	    break;
	  case -1 : numTargetState[i][1] += 1;
	    break;
	  case 0 : numTargetState[i][2] += 1;
	    break;
	  case 1 : numTargetState[i][3] += 1;
	    break;
	  case 2 : numTargetState[i][4] += 1;
	    break;
	  }
	}
      }
      //std::cout << "Cycle :" << i << std::endl;   
  }
  // Saving data to file

  std::string path="../dat/";
  std::string fileName1="numInitState.csv";
  std::string fileName2="numTargetState.csv";

  std::ofstream file1;
  std::ofstream file2;

  file1.open(path + fileName1);
  file2.open(path + fileName2);

  for(int k = 0; k < numOfCycles; k++){
    file1 << numInitState[k][0] << ", " << numInitState[k][1] << ", " << numInitState[k][2] << std::endl;
    file2 << numTargetState[k][0] << ", " << numTargetState[k][1] << ", " << numTargetState[k][2] << ", " << numTargetState[k][3] << ", " << numTargetState[k][4] << ", " << numTargetState[k][0] << std::endl;
  }
   
}
