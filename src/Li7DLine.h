// Li7DLine.h --- 
// 
// Filename: Li7D1Line.h
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sun Apr 30 16:56:30 2017 (-0500)
// Version: 
// Last-Updated: Thu May  4 15:21:29 2017 (-0500)
//           By: yulu
//     Update #: 17
// 

#ifndef LIDLINE_H
#define LIDLINE_H


struct Ground1Excited1{ // [mf'][mf]
  int sigmaPlus[3][3];// = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}};
  int sigmaMinus[3][3];// = {{0, 1, 0}, {0, 0, 1}, {0, 0, 0}}; 
  int pi[3][3];// = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
};

Ground1Excited1 G1E1 = {
  {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}}, //sigmaPlus
  {{0, 1, 0}, {0, 0, 1}, {0, 0, 0}}, //sigmaMinux
  {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}} //pi
};




struct Ground1Excited2{ // [mf'][mf]
  int sigmaPlus[5][3] ;// {{0, 0, 0}, {0, 0, 0}, {1, 0, 0}, {0, 3, 0}, {0, 0, 6}};
  int sigmaMinus[5][3] ;// {{6, 0, 0}, {0, 3, 0}, {0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
  int pi[5][3] ;// {{0, 0, 0}, {3, 0, 0}, {0, 4, 0}, {0, 0, 3}, {0, 0, 0}};
};

Ground1Excited2 G1E2 = {
  {{0, 0, 0}, {0, 0, 0}, {1, 0, 0}, {0, 3, 0}, {0, 0, 6}},
  {{6, 0, 0}, {0, 3, 0}, {0, 0, 1}, {0, 0, 0}, {0, 0, 0}},
  {{0, 0, 0}, {3, 0, 0}, {0, 4, 0}, {0, 0, 3}, {0, 0, 0}}
};




struct Ground2Excited1{ //[mf'][mf]
  int sigmaPlus[3][5] ;// {{6, 0, 0, 0, 0}, {0, 3, 0, 0, 0}, {0, 0, 1, 0, 0}};
  int sigmaMinus[3][5] ;// {{0, 0 ,1, 0, 0}, {0, 0, 0, 3, 0}, {0, 0, 0, 0, 6}};
  int pi[3][5] ;// {{0, 3, 0, 0, 0}, {0, 0, 4, 0, 0}, {0, 0, 0, 3, 0}};
};

Ground2Excited1 G2E1 = {
  {{6, 0, 0, 0, 0}, {0, 3, 0, 0, 0}, {0, 0, 1, 0, 0}},
  {{0, 0 ,1, 0, 0}, {0, 0, 0, 3, 0}, {0, 0, 0, 0, 6}},
  {{0, 3, 0, 0, 0}, {0, 0, 4, 0, 0}, {0, 0, 0, 3, 0}}
};





struct Ground2Exicted2{ //[mf'][mf]
  int sigmaPlus[5][5] ;// {{0, 0, 0, 0, 0}, {2, 0, 0, 0, 0}, {0, 3, 0, 0, 0}, {0, 0, 3, 0, 0}, {0, 0, 0, 2, 0}};
  int sigmaMinus[5][5] ;// {{0, 2, 0, 0 ,0}, {0, 0, 3, 0, 0}, {0, 0, 0, 3, 0}, {0, 0, 0, 0, 2}, {0, 0, 0, 0, 0}};
  int pi[5][5] ;// {{4, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 4}};
};
Ground2Exicted2 G2E2 = {
  {{0, 0, 0, 0, 0}, {2, 0, 0, 0, 0}, {0, 3, 0, 0, 0}, {0, 0, 3, 0, 0}, {0, 0, 0, 2, 0}},
  {{0, 2, 0, 0 ,0}, {0, 0, 3, 0, 0}, {0, 0, 0, 3, 0}, {0, 0, 0, 0, 2}, {0, 0, 0, 0, 0}},
  {{4, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 4}}
};

struct D1Line{
  Ground1Excited1 G1E1;
  Ground1Excited2 G1E2;
  Ground2Excited1 G2E1;
  Ground2Exicted2 G2E2;
};

D1Line D1 = {
  G1E1,
  G1E2,
  G2E1,
  G2E2
};
  
struct LiDLine{
  D1Line D1;
  //D2Line D2;
};

LiDLine DLine = {
  D1
};

#endif
