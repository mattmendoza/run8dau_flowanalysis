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


parstruct loadFitParamsNeg(int ptbin) {

  parstruct fitTuning;

  if(ptbin == 0) {
    cout << "Loading params for ptbin " << ptbin << "..." << endl;
    float ptrange[2]        = {0.5,0.7};
    int   Nrebin            = 1;
    int   kUseLogLowBins    = 1;
    int   twogausfit        = 0;
    int   threegausfit      = 0;
    float protmeanvariance  = 0.05;
    float protwidthvariance = 0.05;
    float pionmeanrange[2]  = {-0.1,0.05};
    float kaonmeanrange[2]  = {0.15,0.35};
    float protmeanrange[2]  = {0.7,0.9};
    float pionwidthrange[2] = {0.001,0.08};
    float kaonwidthrange[2] = {0.01,0.1};
    float protwidthrange[2] = {0.001,0.048};
    float pionfitrange[2]   = {-0.1,0.1};
    float kaonfitrange[2]   = {0.2,0.3};
    float protfitrange[2]   = {0.7,0.95};
    float tunepionheight[6] = {1.02,1.02,1.02,1.02,1.02,1.02};
    float tunepionwidth[6]  = {1.05,1,1,1,1,1};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {1.02,0.99,1,1,1,1};
    float tunekaonwidth[6]  = {0.85,0.78,0.78,0.78,0.78,0.78};
    float tunekaonmean[6]   = {0,0,0,0,0,0};
    float tuneprotheight[6] = {0.9,0.9,0.9,0.9,0.89,0.91};
    float tuneprotwidth[6]  = {0.78,0.81,0.8,0.76,0.78,0.77};
    float tuneprotmean[6]   = {-0.002,-0.002,-0.005,-0.005,-0.00,-0.002};
  }
  
  if(ptbin == 1) {
    cout << "Loading params for ptbin " << ptbin << "..." << endl;
    float ptrange[2] = {0.7,0.9};
    int    Nrebin            = 1;
    int    kUseLogLowBins    = 1;
    int    twogausfit        = 0;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.15,0.35};
    float  protmeanrange[2]  = {0.7,0.9};
    float  pionwidthrange[2] = {0.001,0.08};
    float  kaonwidthrange[2] = {0.01,0.1};
    float  protwidthrange[2] = {0.001,0.048};
    float  pionfitrange[2]   = {-0.1,0.1};
    float  kaonfitrange[2]   = {0.2,0.3};
    float  protfitrange[2]   = {0.7,0.95};
    float tunepionheight[6] = {1.1,1.09,1.09,1.1,1.1,1.1};
    float tunepionwidth[6]  = {1.05,0.93,0.948,0.95,0.95,0.952};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {0.965,0.955,0.97,0.968,0.98,0.97};
    float tunekaonwidth[6]  = {0.84,0.84,0.84,0.84,0.84,0.84};
    float tunekaonmean[6]   = {0,0,0,0,0,0};
    float tuneprotheight[6] = {0.92,0.93,0.925,0.92,0.93,0.92};
    float tuneprotwidth[6]  = {0.81,0.81,0.82,0.81,0.82,0.8};
    float tuneprotmean[6]   = {0,0,0,0,0,0};
  }
  
  if(ptbin == 2) {
    cout << "Loading params for ptbin " << ptbin << "..." << endl;
    float ptrange[2] = {0.9,1.1};
    int    Nrebin            = 1;
    int    kUseLogLowBins    = 1;
    int    twogausfit        = 0;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.15,0.35};
    float  protmeanrange[2]  = {0.7,0.9};
    float  pionwidthrange[2] = {0.001,0.08};
    float  kaonwidthrange[2] = {0.01,0.1};
    float  protwidthrange[2] = {0.001,0.048};
    float  pionfitrange[2]   = {-0.1,0.1};
    float  kaonfitrange[2]   = {0.2,0.3};
    float  protfitrange[2]   = {0.7,0.95};
    float tunepionheight[6] = {1.12,1.11,1.11,1.12,1.12,1.12};
    float tunepionwidth[6]  = {1.02,0.94,0.94,0.96,0.95,0.94};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {0.99,0.98,0.99,0.99,0.985,0.99};
    float tunekaonwidth[6]  = {0.9,0.9,0.9,0.9,0.9,0.9};
    float tunekaonmean[6]   = {0,0,0,0,0,0};
    float tuneprotheight[6] = {0.965,0.97,0.95,0.97,0.983,0.98};
    float tuneprotwidth[6]  = {0.87,0.86,0.85,0.88,0.88,0.87};
    float tuneprotmean[6]   = {0,0,0,0,0,0};

  } 

  if(ptbin == 3) {
    cout << "Loading params for ptbin " << ptbin << "..." << endl;
    float ptrange[2] = {1.1,1.3};
    int    Nrebin            = 2;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 0;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.15,0.35};
    float  protmeanrange[2]  = {0.7,0.9};
    float  pionwidthrange[2] = {0.001,0.08};
    float  kaonwidthrange[2] = {0.01,0.1};
    float  protwidthrange[2] = {0.001,0.048};
    float  pionfitrange[2]   = {-0.1,0.1};
    float  kaonfitrange[2]   = {0.2,0.3};
    float  protfitrange[2]   = {0.7,0.95};
    float tunepionheight[6] = {1.01,0.99,0.98,0.99,0.995,1.005};
    float tunepionwidth[6]  = {0.97,0.9,0.88,0.88,0.9,0.92};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {1.04,1,1.02,1.05,1.03,1.03};
    float tunekaonwidth[6]  = {0.98,0.98,1,1.03,1.01,1};
    float tunekaonmean[6]   = {0,0,0,0,0,0};
    float tuneprotheight[6] = {1.02,1.02,1.04,1.02,1,1.01};
    float tuneprotwidth[6]  = {1.1,1.02,1.06,1.02,1.02,1};
    float tuneprotmean[6]   = {0.005,0.005,0.005,0.005,0.005,0.002};
  }

  if(ptbin == 4) {
    cout << "Loading params for ptbin " << ptbin << "..." << endl;
    float ptrange[2] = {1.3,1.5};
    int    Nrebin            = 1;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.15,0.35};
    float  protmeanrange[2]  = {0.7,0.9};
    float  pionwidthrange[2] = {0.002,0.04};
    float  kaonwidthrange[2] = {0.001,0.01};
    float  protwidthrange[2] = {0.05,0.12};
    float  pionfitrange[2]   = {-0.05,0.05};
    float  kaonfitrange[2]   = {0.18,0.28};
    float  protfitrange[2]   = {0.8,0.9};
    float tunepionheight[6] = {1.03,1.02,1.02,1.03,1.03,1.03};
    float tunepionwidth[6]  = {0.92,0.92,0.92,0.92,0.92,0.91};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {1.02,1.02,1,1,1.01,1.04};
    float tunekaonwidth[6]  = {0.95,1,0.93,0.98,0.98,1};
    float tunekaonmean[6]   = {0.002,0,0,0,0,0};
    float tuneprotheight[6] = {1.1,1.02,1.03,1.03,1.01,1.04};
    float tuneprotwidth[6]  = {1.1,1.06,1.03,1.06,1.04,1.03};
    float tuneprotmean[6]   = {0,0,0,0,0,0};
  }

  if(ptbin == 5) {
    cout << "Loading params for ptbin " << ptbin << "..." << endl;    
    float ptrange[2] = {1.5,1.7};
    int    Nrebin            = 2;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.15,0.35};
    float  protmeanrange[2]  = {0.7,0.9};
    float  pionwidthrange[2] = {0.01,0.1};
    float  kaonwidthrange[2] = {0.001,0.009};
    float  protwidthrange[2] = {0.05,0.12};
    float  pionfitrange[2]   = {-0.05,0.05};
    float  kaonfitrange[2]   = {0.15,0.3};
    float  protfitrange[2]   = {0.8,1};
    float tunepionheight[6] = {1.00,1.00,1.00,1.01,1.0,1.0};
    float tunepionwidth[6]  = {0.9,0.91,0.90,0.90,0.91,0.89};
    float tunepionmean[6]   = {0,0,0,0,0,0};
    float tunekaonheight[6] = {1.08,1.05,1.01,1.02,1.05,1.05};
    float tunekaonwidth[6]  = {1.02,1.02,0.96,0.98,0.99,1.04};
    float tunekaonmean[6]   = {-0.01,-0.01,-0.01,-0.01,-0.01,-0.01};
    float tuneprotheight[6] = {0.97,1,0.99,0.98,0.99,0.98};
    float tuneprotwidth[6]  = {0.96,0.94,0.95,0.97,0.99,0.97};
    float tuneprotmean[6]   = {0,0,0,0,0,0};
  }

  if(ptbin == 6) {
    cout << "Loading params for ptbin " << ptbin << "..." << endl;    
    float ptrange[2] = {1.7,1.9};
    int    Nrebin            = 4;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.15,0.35};
    float  protmeanrange[2]  = {0.7,0.9};
    float  pionwidthrange[2] = {0.01,0.1};
    float  kaonwidthrange[2] = {0.001,0.009};
    float  protwidthrange[2] = {0.05,0.12};
    float  pionfitrange[2]   = {-0.05,0.05};
    float  kaonfitrange[2]   = {0.15,0.3};
    float  protfitrange[2]   = {0.7,1.0};
    float tunepionheight[6] = {0.93,0.93,0.96,0.93,0.98,0.98};
    float tunepionwidth[6]  = {0.85,0.87,0.86,0.85,0.86,0.87};
    float tunepionmean[6]   = {-0.01,-0.01,-0.01,-0.01,-0.01,-0.01};
    float tunekaonheight[6] = {1.13,1.1,1.08,1.1,1.13,1.11};
    float tunekaonwidth[6]  = {0.99,0.94,1,0.93,0.93,0.97};
    float tunekaonmean[6]   = {-0.03,-0.025,-0.02,-0.025,-0.025,-0.02};
    float tuneprotheight[6] = {1.04,1.02,1.0,0.98,1.0,1.07};
    float tuneprotwidth[6]  = {1.05,0.95,1,0.94,1.0,1.05};
    float tuneprotmean[6]   = {0,0,0.0,0,0.0,0};
    
  }

  if(ptbin == 7) {
    cout << "Loading params for ptbin " << ptbin << "..." << endl;    
    float ptrange[2] = {1.9,2.1};
    int    Nrebin            = 4;
    int    kUseLogLowBins    = 0;
    int    twogausfit        = 1;
    int    threegausfit      = 0;
    float  protmeanvariance  = 0.05;
    float  protwidthvariance = 0.05;
    float  pionmeanrange[2]  = {-0.1,0.05};
    float  kaonmeanrange[2]  = {0.15,0.35};
    float  protmeanrange[2]  = {0.7,0.9};
    float  pionwidthrange[2] = {0.01,0.1};
    float  kaonwidthrange[2] = {0.001,0.009};
    float  protwidthrange[2] = {0.05,0.12};
    float  pionfitrange[2]   = {-0.05,0.05};
    float  kaonfitrange[2]   = {0.15,0.3};
    float  protfitrange[2]   = {0.75,0.95};
    float tunepionheight[6] = {0.89,0.87,0.87,0.91,0.88,0.91};
    float tunepionwidth[6]  = {0.8,0.76,0.8,0.8,0.8,0.8};
    float tunepionmean[6]   = {-0.01,-0.01,-0.01,-0.01,-0.01,-0.01};
    float tunekaonheight[6] = {1.31,1.36,1.24,1.33,1.41,1.37};
    float tunekaonwidth[6]  = {1,0.96,0.92,0.97,1.05,1};
    float tunekaonmean[6]   = {-0.05,-0.055,-0.042,-0.05,-0.052,-0.05};
    float tuneprotheight[6] = {1.05,1.03,1.05,1.04,1.03,1.11};
    float tuneprotwidth[6]  = {1.04,1.0,1.04,1.02,1.04,1.1};
    float tuneprotmean[6]   = {0.001,0.001,0.001,0.001,0.001,0.001};
  }

  fitTuning.Nrebin = Nrebin;           
  fitTuning.kUseLogLowBins = kUseLogLowBins;   
  fitTuning.twogausfit = twogausfit;       
  fitTuning.threegausfit = threegausfit;     
  fitTuning.protmeanvariance = protmeanvariance; 
  fitTuning.protwidthvariance = protwidthvariance;

  for(int i=0; i<=1; i++) {
    fitTuning.ptrange[i] = ptrange[i];
    fitTuning.pionmeanrange[i]  = pionmeanrange[i]; 
    fitTuning.kaonmeanrange[i]  = kaonmeanrange[i]; 
    fitTuning.protmeanrange[i]  = protmeanrange[i]; 
    fitTuning.pionwidthrange[i] = pionwidthrange[i];
    fitTuning.kaonwidthrange[i] = kaonwidthrange[i];
    fitTuning.protwidthrange[i] = protwidthrange[i];
    fitTuning.pionfitrange[i]   = pionfitrange[i];  
    fitTuning.kaonfitrange[i]   = kaonfitrange[i];  
    fitTuning.protfitrange[i]   = protfitrange[i];  
  }

  for(int i=0; i<=5; i++) {
    fitTuning.tunepionheight[i] = tunepionheight[i];
    fitTuning.tunepionwidth[i]  = tunepionwidth[i]; 
    fitTuning.tunepionmean[i]   = tunepionmean[i];  
    fitTuning.tunekaonheight[i] = tunekaonheight[i];
    fitTuning.tunekaonwidth[i]  = tunekaonwidth[i]; 
    fitTuning.tunekaonmean[i]   = tunekaonmean[i];  
    fitTuning.tuneprotheight[i] = tuneprotheight[i];
    fitTuning.tuneprotwidth[i]  = tuneprotwidth[i]; 
    fitTuning.tuneprotmean[i]   = tuneprotmean[i];  
  }
  return fitTuning;
}