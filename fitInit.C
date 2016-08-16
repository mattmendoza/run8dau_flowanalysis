#include "fitTuningParsPos.C"
#include "fitTuningParsNeg.C"

struct parstruct {
  float ptrange[2];
  int   Nrebin;           
  int   kUseLogLowBins; 
  int   twogausfit;       
  int   threegausfit;     
  float protmeanvariance; 
  float protwidthvariance;
  float pionmeanrange[2]; 
  float kaonmeanrange[2]; 
  float protmeanrange[2]; 
  float pionwidthrange[2];
  float kaonwidthrange[2];
  float protwidthrange[2];
  float pionfitrange[2];  
  float kaonfitrange[2];  
  float protfitrange[2];  
  float tunepionheight[6];
  float tunepionwidth[6]; 
  float tunepionmean[6]; 
  float tunekaonheight[6];
  float tunekaonwidth[6]; 
  float tunekaonmean[6];  
  float tuneprotheight[6];
  float tuneprotwidth[6]; 
  float tuneprotmean[6];  
} fitTuning;

int isSumW2 = 1;  //plot histo as  sumw2
int hipTpeakfinder = 0; //combines all dphi bins to find peak of histos.

int fixfBinWidthpion = 0; //fixes first bin width for consecutive bins
int fixfBinWidthkaon = 0; //fixes first bin width for consecutive bins
int fixfBinWidthprot = 1; //fixes first bin width for consecutive bins

int whichsig = 2; //how many sigma for yield plots
float M_PI = 3.1415926;
//float ptrange[2] = {0.7,0.9}; //slice 2d hists to this range
//int Nrebin = 5; //rebin N bins to one
int kUseLogLowBins = 0; //use log Y axis for sharp pion peaks at low pT, 0 = no, 1 = yes

int drawDiagnosticFits = 1;

int delPointPion = 0; //omit specific point from fit of v2, 0 means none, 1-6 are specific points
int delPointKaon = 0; 
int delPointProt = 0; 

/*
int twogausfit = 1; //flag use of separate or combined gaussians
int threegausfit = 1; //flag use of separate or combined gaussians

float pionmeanrange[2] = {-0.1,0.05};
float kaonmeanrange[2] = {0.2,0.3};
float protmeanrange[2] = {0.8,0.9};

float pionwidthrange[2] = {0.01,0.2};
float kaonwidthrange[2] = {0.01,0.1};
float protwidthrange[2] = {0.01,0.3};

float pionfitrange[2] = {-0.3,0.05};
float kaonfitrange[2] = {0.1,0.4};
float protfitrange[2] = {0.6,1.2};
*/
float protmeanvariance = 0.05;  // percent variance +/- for consecutive fit iterations. "wiggle room" for better fit
float protwidthvariance = 0.05;

float combindedfitrange[2] = {-0.4,0.6};

int itof    = 1; //{"tofe","tofw","tofw+acc"}
int icent   = 0;
int ich   = 0;

float pionheightpercent;
float kaonheightpercent;
float protheightpercent;

float pionwidthpercent; 
float kaonwidthpercent; 
float protwidthpercent; 

float pionmeanshift;
float kaonmeanshift;
float protmeanshift;

int setTuning;

//pt bin reference
//ptbin ptlow pthigh
//0     0.5   0.7
//1     0.7   0.9
//2     0.9   1.1
//3     1.1   1.3
//4     1.3   1.5
//5     1.5   1.7
//6     1.7   1.9
//7     1.9   2.1
//8     2.1   2.3
//9     2.3   2.5
//10    2.5   2.7
//11    2.7   2.9
//12    2.9   3.1
//13    3.1   3.3
//14    3.3   3.5
//15    3.5   3.7
//16    3.7   3.9
//17    3.9   4.1
//18    4.1   4.3
//19    4.3   4.5
//20    4.5   4.7
//21    4.7   4.9
//22    4.9   5.1
  int ptbin = 3;

//manually override final fit params by visual


//now override final fits by bins in dphi
//heights and widths are modified by percents
//means are shifted by the addition of floats (make negative to shift over to the left)
//write and remove all modifications as necessary
//indicies are such that first bin is idphi = 0

void fitInit(int itof, int icent, int ich, int ptbin)
{
  setTuning = 0;
  //cout << "init Fits..." << endl;
  if(ich == 0) fitTuning = loadFitParamsNeg(ptbin); // flag to tell tuning function to initialize unity tuning or unique tunings for different bins
  if(ich == 1) fitTuning = loadFitParamsPos(ptbin); // flag to tell tuning function to initialize unity tuning or unique tunings for different bins

  //if(itof==0 && icent==0 && ich == 1) {
  //  if(ptrange[0] == 0.5) TOFEposcent0_pt0508();
  //  if(ptrange[0] == 0.8) TOFEposcent0_pt0811();  
  //  if(ptrange[0] == 3.0) TOFEposcent0_pt3035();
  //}
  //if(setTuning == 0) {  unityTuning();  }
  //override();

  return;
}

void override() {

  drawDiagnosticFits = 0;

  pionheightpercent = 1.05;
  kaonheightpercent = 0.7;
  protheightpercent = 0.85;
  
  pionwidthpercent = 0.95; 
  kaonwidthpercent = 0.3; 
  protwidthpercent = 0.65;

  pionmeanshift = -0.01;
  kaonmeanshift = -0.0;
  protmeanshift = 0.02;
  //setUniformTuning();

  tunepionheight[0] = 0.1;     tunepionheight[1] = 0.0;   tunepionheight[2] = 0.07;
  tunepionwidth[0]  = 0.05;     tunepionwidth[1]  = 0.05;   tunepionwidth[2]  = 0.03;
  tunepionmean[0]   = -0.02;     tunepionmean[1]   = -0.02;   tunepionmean[2]   = -0.06;
  tunekaonheight[0] = -0.13;     tunekaonheight[1] = -0.15;   tunekaonheight[2] = -0.1;
  tunekaonwidth[0]  = 0.2;     tunekaonwidth[1]  = 0.1;   tunekaonwidth[2]  = 0.1;
  tunekaonmean[0]   = 0.02;     tunekaonmean[1]   = 0;   tunekaonmean[2]   = 0;
  tuneprotheight[0] = -0.1;     tuneprotheight[1] = 0;   tuneprotheight[2] = -0.1;
  tuneprotwidth[0]  = 0.0;     tuneprotwidth[1]  = -0.15;   tuneprotwidth[2]  = -0.15;
  tuneprotmean[0]   = 0.02;     tuneprotmean[1]   = 0;   tuneprotmean[2]   = 0.02;

  tunepionheight[3] = 0.07;      tunepionheight[4] = 0.05;   tunepionheight[5] = 0.02;
  tunepionwidth[3]  = +0.01;     tunepionwidth[4]  = 0;      tunepionwidth[5]  = 0.05;
  tunepionmean[3]   = -0.03;     tunepionmean[4]   = -0.02;   tunepionmean[5]   = -0.02;
  tunekaonheight[3] = -0.1;         tunekaonheight[4] = -0.2;      tunekaonheight[5] = -0.05;
  tunekaonwidth[3]  = .15;     tunekaonwidth[4]  = 0.22;   tunekaonwidth[5]  = 0.3;
  tunekaonmean[3]   = 0.02;         tunekaonmean[4]   = 0.04;       tunekaonmean[5]   = 0.02;
  tuneprotheight[3] = -0.11;     tuneprotheight[4] = -0.1;       tuneprotheight[5] = -0.15;
  tuneprotwidth[3]  = -0.05;     tuneprotwidth[4]  = -0.05;   tuneprotwidth[5]  = 0.07;
  tuneprotmean[3]   = 0;         tuneprotmean[4]   = 0;       tuneprotmean[5]   = 0.0;




  tunepionheight[0] = pionheightpercent + tunepionheight[0];     tunepionheight[1] = tunepionheight[1] + pionheightpercent;   tunepionheight[2] = tunepionheight[2] + pionheightpercent;
  tunepionwidth[0]  = pionwidthpercent  + tunepionwidth[0] ;     tunepionwidth[1]  = tunepionwidth[1]  + pionwidthpercent ;   tunepionwidth[2]  = tunepionwidth[2]  + pionwidthpercent ;
  tunepionmean[0]   = pionmeanshift     + tunepionmean[0]  ;     tunepionmean[1]   = tunepionmean[1]   + pionmeanshift    ;   tunepionmean[2]   = tunepionmean[2]   + pionmeanshift    ;
  tunekaonheight[0] = kaonheightpercent + tunekaonheight[0];     tunekaonheight[1] = tunekaonheight[1] + kaonheightpercent;   tunekaonheight[2] = tunekaonheight[2] + kaonheightpercent;
  tunekaonwidth[0]  = kaonwidthpercent  + tunekaonwidth[0] ;     tunekaonwidth[1]  = tunekaonwidth[1]  + kaonwidthpercent ;   tunekaonwidth[2]  = tunekaonwidth[2]  + kaonwidthpercent ;
  tunekaonmean[0]   = kaonmeanshift     + tunekaonmean[0]  ;     tunekaonmean[1]   = tunekaonmean[1]   + kaonmeanshift    ;   tunekaonmean[2]   = tunekaonmean[2]   + kaonmeanshift    ;
  tuneprotheight[0] = protheightpercent + tuneprotheight[0];     tuneprotheight[1] = tuneprotheight[1] + protheightpercent;   tuneprotheight[2] = tuneprotheight[2] + protheightpercent;
  tuneprotwidth[0]  = protwidthpercent  + tuneprotwidth[0] ;     tuneprotwidth[1]  = tuneprotwidth[1]  + protwidthpercent ;   tuneprotwidth[2]  = tuneprotwidth[2]  + protwidthpercent ;
  tuneprotmean[0]   = protmeanshift     + tuneprotmean[0]  ;     tuneprotmean[1]   = tuneprotmean[1]   + protmeanshift    ;   tuneprotmean[2]   = tuneprotmean[2]   + protmeanshift    ;

  tunepionheight[3] = tunepionheight[3] + pionheightpercent;     tunepionheight[4] = tunepionheight[4] + pionheightpercent;   tunepionheight[5] = tunepionheight[5] + pionheightpercent;
  tunepionwidth[3]  = tunepionwidth[3]  + pionwidthpercent ;     tunepionwidth[4]  = tunepionwidth[4]  + pionwidthpercent ;   tunepionwidth[5]  = tunepionwidth[5]  + pionwidthpercent ;
  tunepionmean[3]   = tunepionmean[3]   + pionmeanshift    ;     tunepionmean[4]   = tunepionmean[4]   + pionmeanshift    ;   tunepionmean[5]   = tunepionmean[5]   + pionmeanshift    ;
  tunekaonheight[3] = tunekaonheight[3] + kaonheightpercent;     tunekaonheight[4] = tunekaonheight[4] + kaonheightpercent;   tunekaonheight[5] = tunekaonheight[5] + kaonheightpercent;
  tunekaonwidth[3]  = tunekaonwidth[3]  + kaonwidthpercent ;     tunekaonwidth[4]  = tunekaonwidth[4]  + kaonwidthpercent ;   tunekaonwidth[5]  = tunekaonwidth[5]  + kaonwidthpercent ;
  tunekaonmean[3]   = tunekaonmean[3]   + kaonmeanshift    ;     tunekaonmean[4]   = tunekaonmean[4]   + kaonmeanshift    ;   tunekaonmean[5]   = tunekaonmean[5]   + kaonmeanshift    ;
  tuneprotheight[3] = tuneprotheight[3] + protheightpercent;     tuneprotheight[4] = tuneprotheight[4] + protheightpercent;   tuneprotheight[5] = tuneprotheight[5] + protheightpercent;
  tuneprotwidth[3]  = tuneprotwidth[3]  + protwidthpercent ;     tuneprotwidth[4]  = tuneprotwidth[4]  + protwidthpercent ;   tuneprotwidth[5]  = tuneprotwidth[5]  + protwidthpercent ;
  tuneprotmean[3]   = tuneprotmean[3]   + protmeanshift    ;     tuneprotmean[4]   = tuneprotmean[4]   + protmeanshift    ;   tuneprotmean[5]   = tuneprotmean[5]   + protmeanshift    ;




}


void unityTuning() {
  cout << "running: unityTuning" << endl << endl; 

  pionheightpercent = 1.0;
  kaonheightpercent = 1.0;
  protheightpercent = 1.0;
  
  pionwidthpercent = 1.0; 
  kaonwidthpercent = 1.0; 
  protwidthpercent = 1.0; 
  
  pionmeanshift = 0;
  kaonmeanshift = 0;
  protmeanshift = 0;
  setUniformTuning();
  

}

void setUniformTuning() {
    for(int i=0; i<6; i++) { 
    tunepionheight[i] = pionheightpercent; 
    tunekaonheight[i] = kaonheightpercent;
    tuneprotheight[i] = protheightpercent;
    
    tunepionmean[i] = pionmeanshift;
    tunekaonmean[i] = kaonmeanshift;
    tuneprotmean[i] = protmeanshift;
    
    tunepionwidth[i] = pionwidthpercent; 
    tunekaonwidth[i] = kaonwidthpercent; 
    tuneprotwidth[i] = protwidthpercent; 
  }
  cout << "setting uniform tuning" << endl;
  setTuning++;
}

void writeFitTuning(int itof, int icent, int ich, float ptrange[])
{
  char filestr[128];
  sprintf(filestr,"chkparams/parbkup/v2Par_tof%i_cent%i_ch%i_pT-%g-%g.txt",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  cout << filestr << endl;

  ofstream file;
  file.open(filestr, std::ofstream::app);
  
  file << endl << endl << endl;
  file << "float ptrange[2] = {" << ptrange[0] <<","<< ptrange[1]<<"};" << endl;
  
  file << "int    Nrebin            = " << Nrebin             << ";" << endl;
  file << "int    kUseLogLowBins    = " << kUseLogLowBins     << ";" << endl;
  file << "int    twogausfit        = " << twogausfit         << ";" << endl;
  file << "int    threegausfit      = " << threegausfit       << ";" << endl;
  file << "float  protmeanvariance  = " << protmeanvariance   << ";" << endl;
  file << "float  protwidthvariance = " << protwidthvariance  << ";" << endl;
  
  file << "float  pionmeanrange[2]  = {" << pionmeanrange[0]  <<","<< pionmeanrange[1]  << "};" << endl;
  file << "float  kaonmeanrange[2]  = {" << kaonmeanrange[0]  <<","<< kaonmeanrange[1]  << "};" << endl;
  file << "float  protmeanrange[2]  = {" << protmeanrange[0]  <<","<< protmeanrange[1]  << "};" << endl;
  file << "float  pionwidthrange[2] = {" << pionwidthrange[0] <<","<< pionwidthrange[1] << "};" << endl;
  file << "float  kaonwidthrange[2] = {" << kaonwidthrange[0] <<","<< kaonwidthrange[1] << "};" << endl;
  file << "float  protwidthrange[2] = {" << protwidthrange[0] <<","<< protwidthrange[1] << "};" << endl;
  file << "float  pionfitrange[2]   = {" << pionfitrange[0]   <<","<< pionfitrange[1]   << "};" << endl;
  file << "float  kaonfitrange[2]   = {" << kaonfitrange[0]   <<","<< kaonfitrange[1]   << "};" << endl;
  file << "float  protfitrange[2]   = {" << protfitrange[0]   <<","<< protfitrange[1]   << "};" << endl;

  file << "float tunepionheight[6] = {" << tunepionheight[0]<<","<<tunepionheight[1]<<","<<tunepionheight[2]<<","<<tunepionheight[3]<<","<<tunepionheight[4]<<","<<tunepionheight[5]<<"};"<<endl; 
  file << "float tunepionwidth[6]  = {" << tunepionwidth[0] <<","<<tunepionwidth[1] <<","<<tunepionwidth[2] <<","<<tunepionwidth[3] <<","<<tunepionwidth[4] <<","<<tunepionwidth[5] <<"};"<<endl; 
  file << "float tunepionmean[6]   = {" << tunepionmean[0]  <<","<<tunepionmean[1]  <<","<<tunepionmean[2]  <<","<<tunepionmean[3]  <<","<<tunepionmean[4]  <<","<<tunepionmean[5]  <<"};"<<endl;   

  file << "float tunekaonheight[6] = {" << tunekaonheight[0]<<","<<tunekaonheight[1]<<","<<tunekaonheight[2]<<","<<tunekaonheight[3]<<","<<tunekaonheight[4]<<","<<tunekaonheight[5]<<"};"<<endl; 
  file << "float tunekaonwidth[6]  = {" << tunekaonwidth[0] <<","<<tunekaonwidth[1] <<","<<tunekaonwidth[2] <<","<<tunekaonwidth[3] <<","<<tunekaonwidth[4] <<","<<tunekaonwidth[5] <<"};"<<endl; 
  file << "float tunekaonmean[6]   = {" << tunekaonmean[0]  <<","<<tunekaonmean[1]  <<","<<tunekaonmean[2]  <<","<<tunekaonmean[3]  <<","<<tunekaonmean[4]  <<","<<tunekaonmean[5]  <<"};"<<endl;   

  file << "float tuneprotheight[6] = {" << tuneprotheight[0]<<","<<tuneprotheight[1]<<","<<tuneprotheight[2]<<","<<tuneprotheight[3]<<","<<tuneprotheight[4]<<","<<tuneprotheight[5]<<"};"<<endl; 
  file << "float tuneprotwidth[6]  = {" << tuneprotwidth[0] <<","<<tuneprotwidth[1] <<","<<tuneprotwidth[2] <<","<<tuneprotwidth[3] <<","<<tuneprotwidth[4] <<","<<tuneprotwidth[5] <<"};"<<endl; 
  file << "float tuneprotmean[6]   = {" << tuneprotmean[0]  <<","<<tuneprotmean[1]  <<","<<tuneprotmean[2]  <<","<<tuneprotmean[3]  <<","<<tuneprotmean[4]  <<","<<tuneprotmean[5]  <<"};"<<endl;   

  return;
}
