// test.cc --- 
// 
// Filename: test.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sat Apr 29 13:20:05 2017 (-0500)
// Version: 
// Last-Updated: Sun Apr 30 16:23:50 2017 (-0500)
//           By: yulu
//     Update #: 33
// 

#include<iostream>


int main(int argc, char* argv[]){
  int a[][2] = {{1,2},{2,3},{3,4}};
  int b[] = {1,2,4,5};
  int (*p)[2];
  p = a;
  std::cout << a << std::endl;
  return 0;
}
