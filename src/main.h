// main.h --- 
// 
// Filename: main.h
// Description:
//            Reduce (sum) matrix to row/column
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sun Apr 30 21:32:11 2017 (-0500)
// Version: 
// Last-Updated: Wed May  3 23:36:48 2017 (-0500)
//           By: yulu
//     Update #: 86
//



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



  
	
  
