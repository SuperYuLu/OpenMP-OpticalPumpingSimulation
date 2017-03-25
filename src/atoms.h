class atoms{
public:
  int f;
  int mf;
  void pump(int);
  void emmision();
};

void atoms :: pump(int polarization){
  if(-pumpExcitedStateF < (mf + polarization) < pumpExciitedStateF) //check if recieving state avaliable
    {
      f = pumpExcitedStateF;
      mf = mf + polarization;
    }
  else continue;
}

void atoms :: emmision(){
  if(f == pumpExcitedStateF){
    //first check if there is receiving ground state avaliable
    
    // probabilty of emitting sigma+ light
    f1SigmaPlus = Li7DLine.D1.F1.sigmaMinus[pumpExcitedStateF - 1][mf + 1 + 1];
    // probabilty of emitting sigma- light
    f1SigmaMinus = Li7DLine.D1.F1.sigmaPlus[pumpExcitedStateF - 1][mf - 1 + 1];
