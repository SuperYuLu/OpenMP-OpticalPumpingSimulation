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
// Last-Updated: Tue May  2 10:48:48 2017 (-0500)
//           By: yulu
//     Update #: 45
// 

#include <iostream>


template <size_t x, size_t y>
void  myfunc(int (&m)[x][y]){
  std::cout << x << y;
  m[1][1] = 1000;
  
}

int main(){
  int a[][2] = {{1,2},{3,4}, {5,6}};
  int b[3][2] = {{1,2},{3,4}, {5,6}};
  int *p;
  int **m;
  p = &(a[0][0]);
  myfunc(a);

  m = new int*[3];
  for (int i = 0; i < 3; i ++){
    m[i] = new int[2];
  }
  b = a;
  
}
