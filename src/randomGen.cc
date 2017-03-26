#include<cstdlib>
#include<ctime>
float randomGen(){
  float randNum;
  srand(time(0));
  randNum = rand()%1000 / 1000.0;
  return (randNum);
}
