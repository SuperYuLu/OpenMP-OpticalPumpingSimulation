// Li7 D line transition relative strength data 
/*
Fij[l][m]:
    -i: Ground state hpf structure F value
    -j: Excited state hpf structure F' vlue
    -l: Ground state mf value, -F, -(F-1) ... (F-1), F
    -m: Excited state mf' value, -F', -(F'-1) ... (F'-1), F'
Array content: 
    -Relative transition strength, e.g. F11: 
|       |mf' = -1 | mf'= 0 | mf' = 1|
|mf = -1|         |        |        |
|mf = 0 |         |        |        |
|mf = 1 |         |        |        |
*/
//
;

struct Li7D1Trans{
  int F11[3][3] = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}};
  int F12[3][5] = {{6, 3, 1, 0, 0}, {0, 3, 4, 3, 0}, {0, 0, 1, 3, 6}};
  int F21[5][3] = {{6, 0, 0}, {3, 3, 0}, {1, 4, 1}, {0, 3, 4}, {0, 0, 6}};
  int F22[5][5] = {{4, 2, 0, 0, 0}, {2, 1, 3, 0, 0}, {0, 3, 0, 3, 0}, {0, 0, 3, 1, 2}, {0, 0, 0, 2, 4}};
}D1Trans;

