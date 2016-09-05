#include "Style.h"
#include "graphStyles.h"

const float M_PI=3.1415926;
float v2pionpos[15];
float v2kaonpos[15];
float v2protpos[15];
float v2alltpos[15];
float v2errpionpos[15];
float v2errkaonpos[15];
float v2errprotpos[15];
float v2erralltpos[15];

float v2pionneg[15];
float v2kaonneg[15];
float v2protneg[15];
float v2alltneg[15];
float v2errpionneg[15];
float v2errkaonneg[15];
float v2errprotneg[15];
float v2erralltneg[15];
float pt[16];
float pterr[16];

void drawV2()
{
  //float v2pion[15] = {0.065344036, 0.095706341,0.074121629,0.097737244,0.11073904,  0.160831242, 0.138848861,  0.149438224,  0.154992883,  0.146361542,  0.135903757,  0.162946278,  0.130378936};
  //float v2kaon[15] = {0.068234845, 0.088567851,0.082106329,0.076054705,0.102435421, 0.146085179,0.140614163,  0.141599288,  0.169931667,  0.176307101,  0.170938804,  0.205085086,  0.183818803};
  //float v2prot[15] = {0.038813154, 0.061657887,0.087950558,0.108783463,0.125990384, 0.146233388,0.18779599 ,  0.20881917,  0.198700359,  0.202845809,  0.237306118,  0.305554659,  0.342471911};
  //float v2allt[12] = {0.053105786, 0.074034073,0.085216762,0.095314051,0.106477663, 0.212319936, 0.167691901, 0.118672869, 0.154175043, 0.123573549, 0.176613791, 0.217033276};
  //float v2errpion[15] = {0.070202161 , 0.0011956  , 0.00153213, 0.00292076,0.0026686 , 0.00430756,0.00629224, 0.00595989, 0.0073670 , 0.0078317 , 0.0109411 , 0.0129487}; 
  //float v2errkaon[15] = {0.088231813 , 0.00333713 , 0.00334462, 0.00467125,0.00459631, 0.00674828,0.00713508, 0.00685736, 0.0085217 , 0.0073558 , 0.0104899 , 0.0124554};
  //float v2errprot[15] = {0.091693447 , 0.0031351  , 0.00320363, 0.00524073,0.0044155 , 0.00663063,0.00951811, 0.00902409, 0.0108702 , 0.0113582 , 0.0158324 , 0.0173097};
  //float v2errallt[15] = {0.088978238 , 0.00111325, 0.00172712, 0.0024903, 0.00302129, 0.0053449, 0.00332785, 0.00142889, 0.00307024, 0.00686395, 0.00562647, 0.0109289};

  float v2rawt[12] = {0.054412765, 0.067165588, 0.080514672, 0.093017545, 0.101842096, 0.105409385, 0.100016631, 0.108548677, 0.119417338, 0.102892277, 0.148518644, 0.161019072};
  initParams();
  for(int ipt=0;ipt<=14;ipt++) {
    v2pionpos[ipt] = resCorr_r8dA(v2pionpos[ipt],1,0);
    v2kaonpos[ipt] = resCorr_r8dA(v2kaonpos[ipt],1,0);
    v2protpos[ipt] = resCorr_r8dA(v2protpos[ipt],1,0);
    v2alltpos[ipt] = resCorr_r8dA(v2alltpos[ipt],1,0);

    v2pionneg[ipt] = resCorr_r8dA(v2pionneg[ipt],1,0);
    v2kaonneg[ipt] = resCorr_r8dA(v2kaonneg[ipt],1,0);
    v2protneg[ipt] = resCorr_r8dA(v2protneg[ipt],1,0);
    v2alltneg[ipt] = resCorr_r8dA(v2alltneg[ipt],1,0);
  }



float v2rawterr[12];
v2rawterr[0]=7.76036e-005;
v2rawterr[1]=0.000108036;
v2rawterr[2]=0.000144733;
v2rawterr[3]=0.000218838;
v2rawterr[4]=0.000214715;
v2rawterr[5]=0.000273343;
v2rawterr[6]=0.000339524;
v2rawterr[7]=0.000411411;
v2rawterr[8]=0.000576471;
v2rawterr[9]=0.000527435;
v2rawterr[10]=0.000605382;
v2rawterr[11]=0.000681793;


  TGraphErrors *gr_v2pionpos = new TGraphErrors(8,pt,v2pionpos,pterr,v2errpionpos);
  TGraphErrors *gr_v2kaonpos = new TGraphErrors(8,pt,v2kaonpos,pterr,v2errkaonpos);
  TGraphErrors *gr_v2protpos = new TGraphErrors(8,pt,v2protpos,pterr,v2errprotpos);
  TGraphErrors *gr_v2alltpos = new TGraphErrors(12,pt,v2alltpos,pterr,v2erralltpos);

  TGraphErrors *gr_v2pionneg = new TGraphErrors(8,pt,v2pionneg,pterr,v2errpionneg);
  TGraphErrors *gr_v2kaonneg = new TGraphErrors(8,pt,v2kaonneg,pterr,v2errkaonneg);
  TGraphErrors *gr_v2protneg = new TGraphErrors(8,pt,v2protneg,pterr,v2errprotneg);
  TGraphErrors *gr_v2alltneg = new TGraphErrors(12,pt,v2alltneg,pterr,v2erralltneg);

  TGraphErrors *gr_v2rawt = new TGraphErrors(12,pt,v2rawt,pterr,v2rawterr);

  c1 = new TCanvas("c1","c1",2000,1500);
  c1->cd();
  drawFrame(0,0,5,0.5,"Transverse Momentum (GeV/c)","elliptic flow (v_{2})");
  //drawTitle(.1,-.07,"Identified Particle Elliptic Flow (v_{2}), TOF.W + ACC",1,12,.03,0);
  drawTitle(.1,-.07,"Charged Track Elliptic Flow (v_{2})",1,12,.03,0);
  //gr_v2pion->RemovePoint(13);
  //gr_v2kaonpos->RemovePoint(13);
  //gr_v2prot->RemovePoint(13);
  //gr_v2rawt->RemovePoint(13);

  //gr_v2pion->RemovePoint(12);
  //gr_v2kaonpos->RemovePoint(12);
  //gr_v2prot->RemovePoint(12);
  //gr_v2rawt->RemovePoint(12);

  
  gr_v2pionpos->SetMarkerSize(3.2); gr_v2pionpos->SetMarkerColor(pioncolor);  gr_v2pionpos->SetLineColor(pioncolor); gr_v2pionpos->SetMarkerStyle(20); 
  gr_v2kaonpos->SetMarkerSize(3.2); gr_v2kaonpos->SetMarkerColor(kaoncolor);  gr_v2kaonpos->SetLineColor(kaoncolor); gr_v2kaonpos->SetMarkerStyle(20); 
  gr_v2protpos->SetMarkerSize(3.2); gr_v2protpos->SetMarkerColor(protcolor);  gr_v2protpos->SetLineColor(protcolor); gr_v2protpos->SetMarkerStyle(20); 
  
  gr_v2pionneg->SetMarkerSize(3.8); gr_v2pionneg->SetMarkerColor(kGreen-9);  gr_v2pionneg->SetLineColor(pioncolor); gr_v2pionneg->SetMarkerStyle(22); 
  gr_v2kaonneg->SetMarkerSize(3.8); gr_v2kaonneg->SetMarkerColor(kBlue-9);   gr_v2kaonneg->SetLineColor(kaoncolor); gr_v2kaonneg->SetMarkerStyle(22); 
  gr_v2protneg->SetMarkerSize(3.8); gr_v2protneg->SetMarkerColor(kRed-9);    gr_v2protneg->SetLineColor(protcolor); gr_v2protneg->SetMarkerStyle(22); 
  //gr_v2allt->SetMarkerSize(2.1); gr_v2allt->SetMarkerColor(6);  gr_v2allt->SetLineColor(6); gr_v2allt->SetMarkerStyle(29); 
  //gr_v2rawt->SetMarkerSize(2); gr_v2rawt->SetMarkerColor(1);  gr_v2rawt->SetLineWidth(2);  gr_v2rawt->SetLineColor(1); gr_v2rawt->SetMarkerStyle(22);  gr_v2rawt->Draw("P");

  gr_v2pionneg->SetLineStyle(7); gr_v2pionneg->SetLineWidth(3);   gr_v2pionneg->Draw("P");
  gr_v2kaonneg->SetLineStyle(7); gr_v2kaonneg->SetLineWidth(3);   gr_v2kaonneg->Draw("P");
  gr_v2protneg->SetLineStyle(7); gr_v2protneg->SetLineWidth(3);   gr_v2protneg->Draw("P");

  gr_v2pionpos->SetLineStyle(7); gr_v2pionpos->SetLineWidth(3);   gr_v2pionpos->Draw("P");
  gr_v2kaonpos->SetLineStyle(7); gr_v2kaonpos->SetLineWidth(3);   gr_v2kaonpos->Draw("P");
  gr_v2protpos->SetLineStyle(7); gr_v2protpos->SetLineWidth(3);   gr_v2protpos->Draw("P");


  //gr_v2allt->SetLineStyle(7); gr_v2allt->SetLineWidth(3);   //gr_v2allt->Draw("CP");
  
  legend = new TLegend(0.2,0.9,0.6,0.8,0);
  legend->SetNColumns(3);   legend->SetBorderSize(0);
  legend->AddEntry(gr_v2pionpos,"#pi+","p");
  legend->AddEntry(gr_v2kaonpos,"K+","p");
  legend->AddEntry(gr_v2protpos,"P+","p");
  legend->AddEntry(gr_v2pionneg,"#pi-","p");
  legend->AddEntry(gr_v2kaonneg,"K-","p");
  legend->AddEntry(gr_v2protneg,"P-","p");
  //legend->AddEntry(gr_v2allt,"all ID tracks (sum of #pi+k+P)","p");
  //legend->AddEntry(gr_v2rawt,"all charged tracks","p");
  legend->Draw();

  c1->SaveAs("v2all.jpg");

}

void initParams()
{
  for(int i=0 ; i<=15 ; i++) {
    pt[i] = 0.5+i*0.2 +0.1;
    pterr[i] = 0.0;
    if(i>11) pt[i] = 3.0 +((i-12)*0.5)+0.25;
    if(i>=15) { pt[i] = 4.5+(i-14) + 0.5;  }
  }

v2alltpos[0] = 0.0131388;      v2erralltpos[0] = 1.26888e-005;
v2pionpos[0] = 0.0139944;      v2errpionpos[0] = 1.35303e-005;
v2kaonpos[0] = 0.0116669;      v2errkaonpos[0] = 4.9449e-005;
v2protpos[0] = 0.00452348;     v2errprotpos[0] = 5.29505e-005;

v2alltpos[1] = 0.014424;     v2erralltpos[1] = 1.10428e-005;
v2pionpos[1] = 0.0151749;      v2errpionpos[1] = 1.26266e-005;
v2kaonpos[1] = 0.013755;     v2errkaonpos[1] = 4.1153e-005;
v2protpos[1] = 0.010197;     v2errprotpos[1] = 4.12966e-005;

v2alltpos[2] = 0.00208193;     v2erralltpos[2] = 0.687642;
v2pionpos[2] = 0.0206842;      v2errpionpos[2] = 1.53471e-005;
v2kaonpos[2] = 0.0217392;      v2errkaonpos[2] = 4.76238e-005;
v2protpos[2] = 0.0160926;    v2errprotpos[2] = 3.70303e-005;

v2alltpos[3] = 0.0278941;      v2erralltpos[3] = 0.0430533;
v2pionpos[3] = 0.0264116;      v2errpionpos[3] = 3.26708e-005;
v2kaonpos[3] = 0.0330352;      v2errkaonpos[3] = 0.00012124;
v2protpos[3] = 0.0236456;    v2errprotpos[3] = 6.11545e-005;

v2alltpos[4] = 0.0270103;      v2erralltpos[4] = 0.0155533;
v2pionpos[4] = 0.0317765;      v2errpionpos[4] = 2.69951e-005;
v2kaonpos[4] = 0.0369021;      v2errkaonpos[4] = 6.07405e-005;
v2protpos[4] = 0.0309901;    v2errprotpos[4] = 5.05088e-005;

v2alltpos[5] = 0.0348183;      v2erralltpos[5] = 9.9283e-005;
v2pionpos[5] = 0.0323648;      v2errpionpos[5] = 9.6986e-005;
v2kaonpos[5] = 0.0396659;      v2errkaonpos[5] = 0.000174864;
v2protpos[5] = 0.0371596;    v2errprotpos[5] = 0.000317537;

v2alltpos[6] = 0.0376867;      v2erralltpos[6] = 0.000145551;
v2pionpos[6] = 0.0324613;      v2errpionpos[6] = 0.000163718;
v2kaonpos[6] = 0.0400783;      v2errkaonpos[6] = 0.0003155;
v2protpos[6] = 0.0452959;    v2errprotpos[6] = 0.000262236;

v2alltpos[7] = 0.0359183;      v2erralltpos[7] = 0.000266693;
v2pionpos[7] = 0.0336751;      v2errpionpos[7] = 0.000363713;
v2kaonpos[7] = 0.0393055;      v2errkaonpos[7] = 0.000551467;
v2protpos[7] = 0.046838;     v2errprotpos[7] = 0.000337257;

v2pionpos[8] = 0.0298951;     v2errpionpos[8] = 0.0004699;
v2kaonpos[8] = 0.0396922;     v2errkaonpos[8] = 0.000669895;
v2protpos[8] = 0.046966;      v2errprotpos[8] = 0.000632564;

v2pionpos[9] = 0.0275577;     v2errpionpos[9] = 0.000650622;
v2kaonpos[9] = 0.0369777;     v2errkaonpos[9] = 0.00081272;
v2protpos[9] = 0.0476927;     v2errprotpos[9] = 0.000769387;

v2pionpos[10] = 0.0278351;    v2errpionpos[10] = 0.0211714;
v2kaonpos[10] = 0.03378;      v2errkaonpos[10] = 0.00169447;
v2protpos[10] = 0.0456037;    v2errprotpos[10] = 0.00202961;

v2pionpos[11] = 0.0282585;    v2errpionpos[11] = 0.00244153;
v2kaonpos[11] = 0.0346992;    v2errkaonpos[11] = 0.00430782;
v2protpos[11] = 0.0435877;    v2errprotpos[11] = 0.00491859;

v2pionpos[12] = 0.0248839;    v2errpionpos[12] = 0.00473314;
v2kaonpos[12] = 0.0361253;    v2errkaonpos[12] = 0.0024278;
v2protpos[12] = 0.0434931;    v2errprotpos[12] = 0.00303396;

v2pionpos[13] = 0.030272;      v2errpionpos[13] = 0.00644539;
v2kaonpos[13] = 0.0890235;     v2errkaonpos[13] = 0.00970629;
v2protpos[13] = 0.0213572;     v2errprotpos[13] = 0.00357928;

v2pionpos[14] = 0.025759;     v2errpionpos[14] = 0.00888207;
v2kaonpos[14] = 0.0340744;    v2errkaonpos[14] = 0.00449614;
v2protpos[14] = 0.0631675;    v2errprotpos[14] = 0.006439;

///////////////////////////////////////////////////////////////////////////Neg v2s begin here///////////////////////////////////////////

v2alltneg[0] = 0.00993574;     v2erralltneg[0] = 7.24118e-006;
v2pionneg[0] = 0.013381;     v2errpionneg[0] = 1.37161e-005;
v2kaonneg[0] = 0.010324;     v2errkaonneg[0] = 5.23681e-005;
v2protneg[0] = 0.00466884;     v2errprotneg[0] = 7.97635e-005;

v2alltneg[1] = 0.015009;     v2erralltneg[1] = 1.20154e-005;
v2pionneg[1] = 0.0156552;      v2errpionneg[1] = 1.2805e-005;
v2kaonneg[1] = 0.0113971;      v2errkaonneg[1] = 4.48186e-005;
v2protneg[1] = 0.0110577;    v2errprotneg[1] = 5.18096e-005;

v2alltneg[2] = 0.0206733;      v2erralltneg[2] = 1.41132e-005;
v2pionneg[2] = 0.0213564;      v2errpionneg[2] = 1.5362e-005;
v2kaonneg[2] = 0.0218287;      v2errkaonneg[2] = 5.06469e-005;
v2protneg[2] = 0.014912;     v2errprotneg[2] = 4.5425e-005;

v2alltneg[3] = 0.028054;     v2erralltneg[3] = 6.20903e-005;
v2pionneg[3] = 0.0280355;      v2errpionneg[3] = 6.65019e-005;
v2kaonneg[3] = 0.0321181;      v2errkaonneg[3] = 0.000244299;
v2protneg[3] = 0.0238375;    v2errprotneg[3] = 0.000142362;

v2alltneg[4] = 0.0319019;      v2erralltneg[4] = 1.50299e-005;
v2pionneg[4] = 0.0303357;      v2errpionneg[4] = 2.86714e-005;
v2kaonneg[4] = 0.0365472;      v2errkaonneg[4] = 5.97541e-005;
v2protneg[4] = 0.0319782;    v2errprotneg[4] = 7.75184e-005;

v2alltneg[5] = 0.0323494;      v2erralltneg[5] = 9.6557e-005;
v2pionneg[5] = 0.0309382;      v2errpionneg[5] = 9.7712e-005;
v2kaonneg[5] = 0.039378;     v2errkaonneg[5] = 0.000187254;
v2protneg[5] = 0.0368732;    v2errprotneg[5] = 0.000338683;

v2alltneg[6] = 0.0330857;      v2erralltneg[6] = 0.000251937;
v2pionneg[6] = 0.03046;      v2errpionneg[6] = 0.000317745;
v2kaonneg[6] = 0.0273039;      v2errkaonneg[6] = 0.000610792;
v2protneg[6] = 0.0466697;    v2errprotneg[6] = 0.000553187;

v2alltneg[7] = 0.0403298;      v2erralltneg[7] = 0.000292584;
v2pionneg[7] = 0.0353522;      v2errpionneg[7] = 0.00034218;
v2kaonneg[7] = 0.0528272;      v2errkaonneg[7] = 0.000557646;
v2protneg[7] = 0.0380506;    v2errprotneg[7] = 0.00067613;

v2pionneg[8] = 0.0282388;      v2errpionneg[8] = 0.000504408;
v2kaonneg[8] = 0.0399862;     v2errkaonneg[8] = 0.000628708;
v2protneg[8] = 0.0508686;     v2errprotneg[8] = 0.000653833;

v2pionneg[9] = 0.0294254;      v2errpionneg[9] = 0.000733668;
v2kaonneg[9] = 0.0400348;      v2errkaonneg[9] = 0.000879399;
v2protneg[9] = 0.0472006;    v2errprotneg[9] = 0.000866769;

v2pionneg[10] = 0.0297185;     v2errpionneg[10] = 0.00161919;
v2kaonneg[10] = 0.0352589;     v2errkaonneg[10] = 0.00203679;
v2protneg[10] = 0.0464441;     v2errprotneg[10] = 0.00258222;

v2kaonneg[11] = 0.0331489;     v2errkaonneg[11] = 0.00440734;
v2protneg[11] = 0.0460766;     v2errprotneg[11] = 0.00596628;

v2kaonneg[12] = 0.0333368;     v2errkaonneg[12] = 0.00519813;
v2protneg[12] = 0.0469274;     v2errprotneg[12] = 0.0065295;

v2pionneg[13] = 0.0336624;     v2errpionneg[13] = 0.00204244;
v2kaonneg[13] = 0.065236;      v2errkaonneg[13] = 0.0159537;
v2protneg[13] = 0.075951;      v2errprotneg[13] = 0.00600602;

v2kaonneg[14] = 0.0346352;     v2errkaonneg[14] = 0.00414226;
v2protneg[14] = 0.0534996;     v2errprotneg[14] = 0.0085335;

float pt;


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
  return;
}

float resCorr_r8dA(float v2, int sysflag, int centbin)
{
  //sysflag flags which detector is used for RP 
  //1 - BBC
  //2 - SMD
  //3 - MPC

  sysflag = sysflag - 1;
  float res[6][4];
  float resErr[6][4];

  res[0][0] = 0.204441;     resErr[0][0] = 0.0819683;
  res[1][0] = 0.0019903;    resErr[1][0] = 0.00808764;
  res[2][0] = 0.273492;     resErr[2][0] = 0.0948057;

  res[0][1] = 0.202299;     resErr[0][1] = 0.0978059;
  res[1][1] = 0.00162359;   resErr[1][1] = 0.00876207;
  res[2][1] = 0.297775;     resErr[2][1] = 0.118662;

  res[0][2] = 0.221582;     resErr[0][2] = 0.131902;
  res[1][2] = 0.00120449;   resErr[1][2] = 0.00972486;
  res[2][2] = 0.285497;     resErr[2][2] = 0.149721;

  res[0][3] = 0.188814;     resErr[0][3] = 0.193319;
  res[1][3] = 0.000894145;  resErr[1][3] = 0.0133034;
  res[2][3] = 0.348711;     resErr[2][3] = 0.262719;

  return v2 / res[sysflag][centbin];

}
