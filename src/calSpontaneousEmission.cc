#include "transitionStrength.h"
#include<cstdio>
#include "setValue.h"
// Calculate spontaneous emission Einstein factor for hpf states
// Based on the relative transition strenght and the fact that
// sum(Aij, overj)  = Sigma (nature linewidth)
// ref:
// Jonathan Gillot, Alexandre Gauguet, Matthias B¨uchner, Jacques Vigu´e. Optical pumping
// of a lithium atomic beam for atom interferometry. The European Physical Journal D, EDP
// Sciences, 2013, 67, pp.263. .

double** calSpontEmission(int excitedF){
  int numExictedMf, mfExcited, mfGroundF1, mfGroundF2, sum, count;
  double **A; // dim :(2F' + 1) x 8
  numExictedMf = 2 * excitedF - 1;
  for(int i = 0; i < numExictedMf; i++){ // for each mf'
    A[i] = new double[8];
    mfExcited = -excitedF + i;  // mf' for excited states;
    
    sum = 0; //Sum up transition strength for mf' decay
    if(excitedF == 1){
      for(int k = 0; k < 3; k++){
	sum = sum + D1Trans.F11[k][-excitedF + i];
      }
      for(int k = 0; k < 5; k++){
	sum = sum + D1Trans.F21[k][-excitedF + i];
      }
    }

    if(excitedF == 2){
      for(int k = 0; k < 3; k++){
	sum = sum + D1Trans.F12[k][-excitedF + i];
      }
      for(int k = 0; k < 5; k++){
	sum = sum + D1Trans.F22[k][-excitedF + i];
      }
    }

    
    for(int j = 0; j < 8; j++){ // j for each ground state mf, 0~2 for F=1, 3~8 for F = 2
      if(excitedF == 1){ // decay from F' = 1
	if(j < 3 ) // decay to F=1 ground state
	  A[i][j] = (double)D1Trans.F11[j][-excitedF + i] / (double)sum * gamma;
	else // decay to F=2 ground state
	  A[i][j] = (double)D1Trans.F21[j-3][-excitedF + i] / (double)sum * gamma;
      }
      if(excitedF == 2){
	if(j < 3 ) // decay to F=1 ground state
	  A[i][j] = (double)D1Trans.F12[j][-excitedF + i] / (double)sum * gamma;
	else // decay to F=2 ground state
	  A[i][j] = (double)D1Trans.F22[j-3][-excitedF + i] / (double)sum * gamma;
      }
    }
  }
  return A; // A spontaneouse matrix, dimension mxn =  (2F' + 1) x 8
}
