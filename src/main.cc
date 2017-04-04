#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>
//#include<main.h>
#include "atoms.h"
//#include "setValue.h"
//============Problem, transition prob doesn't sum up to 1=============
int main(){
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
