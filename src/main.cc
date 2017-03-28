#include<iostream>
//#include<main.h>
#include "atoms.h"
//#include "setValue.h"
//============Problem, transition prob doesn't sum up to 1=============
int main(){
  atoms atom[numOfAtoms];
  int numInitState[numOfCycles][2 * initGroundStateF + 1];
  int numTargetState[numOfCycles][2 * targetGroundStateF + 1];
  
  for(int i = 0; i < numOfCycles; i++){
    
      for(int j = 0; j < numOfAtoms; j++){
	if(i == 0){
	  atom[j].f = initGroundStateF;
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
	atom[j].pump(1);
	atom[j].emission();
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
}
