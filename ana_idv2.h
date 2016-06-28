TString centbinlabel[6]   = {"minbias",  "0-5", "5-10", "10-15", "15-20", "20-25"};
TString centbinrelabel[6] = {    "_MB","_cent0","_cent1","_cent2","_cent3", "_cent4"};
TString whichtoflabel[4] = {"tofe","tofw","tofwveto","tofwfire"};
TString specieslabel[3] = {"pion","kaon","prot"};
TString dphilabel[6] = {    "_dphi0","_dphi1","_dphi2","_dphi3","_dphi4","_dphi5"};
//TString chargelabel[2] = {"neg","pos"};
TString chargelabel[2] = {"negative","positive"};
TString fPart[3] = {"pion","kaon","proton"};

TString fPar = "par/";
TString fRoot = "rootout/";

float pt;

///////////////////////////
// Fit Function Definitions
///////////////////////////
TF1 *polybg = new TF1("polybg","[0] + [1]*x + [2]*x*x",-0.4,1.4);
TF1 *fun1 =new TF1("fun1","[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)",-0.2,0.1);   // pion
TF1 *fun2 =new TF1("fun2","[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)",0.2,0.4);    // kaon

TF1 *fun     =new TF1("fun"    ,"[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)+[3]/([2]+[5])*exp(-0.5*pow((x-[4])/([2]+[5]),2))/sqrt(6.283)",-0.4,0.6);// pion+kaon
//TF1 *fun = new TF1("fun","fun1+fun2",-0.4,0.6);
TF1 *funbulk =new TF1("funbulk","[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)+[3]/([2]+[5])*exp(-0.5*pow((x-[4])/([2]+[5]),2))/sqrt(6.283)",-0.4,1.4);// pion+kaon
//TF1 *funbulk =new TF1("funbulk","fun1+fun2",-0.4,1.4);// pion+kaon
TF1 *fun3 =new TF1("fun3","[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)",0.72,1.1);   // proton

TF1 *fun_pion = new TF1("fun_pion","[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)",-1.0,2.0);
TF1 *fun_kaon = new TF1("fun_kaon","[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)",-1.0,2.0);
TF1 *fun_proton = new TF1("fun_proton","[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)",-1.0,2.0);  


///////////////////////////
// Diagnositic Histograms
///////////////////////////
TH1F *hNtracksvspT[2][2][3]; 
TGraphErrors *gTOFefficiencies[2][2][3];

float effcorr[2][2][3][31];
float effcorr_err[2][2][3][31];

float ntracks[2][2][3][31];

float pt[26];

double PionYield[4][2][5][26];  //which tof, charge, centrality, ptbin
double KaonYield[4][2][5][26];
double ProtYield[4][2][5][26];

Double_t ypi;
Double_t yka;
Double_t ypr;

TGraphErrors *gPionSpectra[4][2][3][5][8];//1,2,3 sigma
TGraphErrors *gKaonSpectra[4][2][3][5][8];//1,2,3 sigma
TGraphErrors *gProtSpectra[4][2][3][5][8];//1,2,3 sigma

TGraphErrors *gPionYield[4][2][3][5][8];//1,2,3 sigma
TGraphErrors *gPionYieldBC[4][2][3][5][8];//1,2,3 sigma
TGraphErrors *gPionMass[4][2][5][8];
TGraphErrors *gPionWidth[4][2][5][8];

TGraphErrors *gKaonYield[4][2][3][5][8];//1,2,3 sigma
TGraphErrors *gKaonYieldBC[4][2][3][5][8];//1,2,3 sigma
TGraphErrors *gKaonMass[4][2][5][8];
TGraphErrors *gKaonWidth[4][2][5][8];

TGraphErrors *gProtYield[4][2][3][5][8];//1,2,3 sigma
TGraphErrors *gProtYieldBC[4][2][3][5][8];//1,2,3 sigma
TGraphErrors *gProtMass[4][2][5][8];
TGraphErrors *gProtWidth[4][2][5][8];

TGraphErrors *gPionPhi;

float PionPosMean[50];  	float PionNegMean[50];
float PionPosMeanErr[50];	float PionNegMeanErr[50];
float PionPosWidth[50];  	float PionNegWidth[50];
float PionPosWidthErr[50]; 	float PionNegWidthErr[50];
float PionPosYield[50];  	float PionNegYield[50];
float PionPosYieldErr[50];  float PionNegYieldErr[50];

float KaonPosMean[50];  	float KaonNegMean[50];
float KaonPosMeanErr[50];	float KaonNegMeanErr[50];
float KaonPosWidth[50];  	float KaonNegWidth[50];
float KaonPosWidthErr[50]; 	float KaonNegWidthErr[50];
float KaonPosYield[50];  	float KaonNegYield[50];
float KaonPosYieldErr[50];  float KaonNegYieldErr[50];

float ProtPosMean[50];  	float ProtNegMean[50];
float ProtPosMeanErr[50];	float ProtNegMeanErr[50];
float ProtPosWidth[50];  	float ProtNegWidth[50];
float ProtPosWidthErr[50]; 	float ProtNegWidthErr[50];
float ProtPosYield[50];  	float ProtNegYield[50];
float ProtPosYieldErr[50];  float ProtNegYieldErr[50];