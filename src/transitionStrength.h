// Li7 D line transition relative strength data [Nested Structure]

// To index a specific transition, e.g.:
// Li7DLine.D1.F1.sigmaPlus[i][j]
// i = F'; j = mF

struct D1FTrans1{
  /* For each light polorization: 
|mF  | m=-1 | m=0 | m=1 |
|F'=1|  To correspoing  |
|F'=2|     mF'          |
  */
  
  double sigmaPlus[2][3] = {{1./12, 1./12, 0.}, {1./12, 1./4, 1./2}};
  double pi[2][3] = {{1./12, 0., 1./12}, {1./4, 1./3, 1./4}};
  double sigmaMinus[2][3] = {{0., 1./12, 1./12}, {1./2, 1./4, 1./12}};
}F1;


struct D1FTrans2{
  /* For each light polorization: 
|mF  |m=-2|m=-1|m=0|m=1|m=2|
|F'=1|  To  correspoing    |
|F'=2|     mF'             |
  */
  
  double sigmaPlus[2][5] = {{1./2, 1./4, 1./12, 0., 0.}, {1./6, 1./4, 1./4, 1./6, 0.}};  // sigma + 
  double pi[2][5] = {{0., 1./4, 1./3, 1./4, 0.},{1./3, 1./12, 0, 1./12, 1./3}};  // sigma - 
  double sigmaMinus[2][5] = {{0., 0., 1./12, 1./4, 1./2}, {0., 1./6, 1./4, 1./4, 1./6}};  // pi
}F2;
  


struct D1line{
  int groundF[2] = {1,2};
  int excitedF[2] = {1,2};
  D1FTrans1 F1;    // gournd hpf state
  D1FTrans2 F2;    // ground hpf state
  }D1;

struct LiDLine{
  D1line D1;
  //D2line D2;
}Li7DLine;
