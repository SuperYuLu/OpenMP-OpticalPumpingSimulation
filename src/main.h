// main.h --- 
// 
// Filename: main.h
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sun Apr 30 21:32:11 2017 (-0500)
// Version: 
// Last-Updated: Sun Apr 30 23:28:15 2017 (-0500)
//           By: yulu
//     Update #: 79
//
#include <iostream>

// Reduce (sum) matrix to row/column
template<int nRow, int nCol>
int*  reduceMatrix(int (&mIn)[nRow][nCol], int direction){
  int sum;
  int* mOut;
  if (direction == 0) mOut = new int[nRow];
  if (direction == 1) mOut = new int[nCol];

  if (direction == 0){
    for(int i = 0; i < nRow; i ++){
    sum = 0;
    for(int j = 0; j < nCol; j ++) sum += mIn[i][j];
    mOut[i] = sum;
    }
  }
    
  else if(direction == 1){
    for(int j = 0; j < nCol; j ++){
      sum = 0;
      for(int i = 0; i < nRow; i ++) sum += mIn[i][j];
      mOut[j] = sum;
    }
  }
  return mOut;
}


// Transpose Matrix
template <int m, int n>
int **transMatrix(int (&mIn)[m][n]){
  int **mTrans = 0;
  mTrans = new int*[n];
  for(int i = 0; i < n; i++){
    mTrans[i] = new int[m];
    for(int j = 0; j < m; j++)  mTrans[i][j] = mIn[j][i];
  }
  return mTrans;
}
      
// Matrix multiply
template <int m, int n, int s>
double* matrixMulti(double (& pop)[m], int (& trans)[n][s]){
  double* res = new double [s];
  if(m == n){
    for(int j = 0; j < s; j++){
      for(int i = 0; i < m; i ++){
      	res[j] = pop[i] * (double)trans[i][j];
      }
    }
  }
  return res;
}

// Vector multiply
template <int m, int n>
double* vectorMulti(double (& pop)[m], int (& trans1D)[n]){
  double* res = new double[m];
  if (m == n){
    for (int i = 0; i < m; i ++){
      res[i] = pop[i] * trans1D[i];
    }
  }

  return res;
}
  
	
  
