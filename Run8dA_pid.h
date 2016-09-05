#ifndef RUN8DA_PID_H
#define RUN8DA_PID_H

TCanvas * fit_m2_2gaus(TH1D * h,int whichtof, int centbin, int charge, int idphi, int iptbin, float ptmin, float ptmax);
void SlicetoPS(TH2F *h2in,int itof, int cent,int idphi, int charge);
TH2F *loadHist(int itof, int icent, int idphi, int ich);
void runBySubBin(int itof, int icent, int ich);  
void setupIndiv(int itof, int centbin, int ich, int idphi);
float findpeak(TH1D* inputhist, float lowbound, float highbound);
void writeIndiv(int itof, int centbin, int ich);

int isCoarseBin = 0;

float pionmeanset[20];   float pionmeanseterr[20];
float pionwidthset[20];  float pionwidthseterr[20];

float kaonmeanset[20];   float kaonmeanseterr[20];
float kaonwidthset[20];  float kaonwidthseterr[20];

float protmeanset[20];   float protmeanseterr[20];
float protwidthset[20];  float protwidthseterr[20];

float initialpion;
float initialkaon;
float initialprot;

int minptbin=0;
int maxptbin=9;  //40
float ptstepsize = .3;
int ptbinsplit = 0;
ofstream fm2mean;
ofstream fm2width;
ofstream fm2yield;
TCanvas *c_h = new TCanvas("c_h","c_h",1000,1000);
TCanvas *canvas = new TCanvas("canvas","canvas",1500,1500);
TCanvas *Canvas = new TCanvas("Canvas","",0,0,800,500);
TCanvas *c1 = new TCanvas("c1","c1",1000,1000);
TH1F * h_m2vspt_allphi;
  TH1D *h;  
TFile infile("anaacc2698_new.root");

TF1 *f_pionsigma, *f_kaonsigma, *f_protsigma;

TH2F *h2_m2tofvspt_v2_temp[4][2][5][6];  // [tof] [charge] [centrality] [dphi]

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

#endif