// test.cc --- 
// 
// Filename: test.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sun Apr 30 19:31:03 2017 (-0500)
// Version: 
// Last-Updated: Sun Apr 30 22:49:17 2017 (-0500)
//           By: yulu
//     Update #: 35
// 

#include <iostream>


template <size_t x, size_t y>
void  myfunc(int (&m)[x][y]){
  std::cout << x << y;
  m[1][1] = 1000;
  
}

int main(){
  int a[][2] = {{1,2},{3,4}, {5,6}};
  int b[3][2];
  int *p;
  int **m;
  p = &(a[0][0]);
  myfunc(a);

  m = new int*[3];
  for (int i = 0; i < 3; i ++){
    m[i] = new int[2];
    for (int j = 0; j < 2; j ++){
      m[i][j] = i + j;
    }
  }
}
