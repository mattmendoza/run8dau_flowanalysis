#include "Style.h"
#include "graphStyles.h"

const float M_PI=3.1415926;
float v2pion[15];
float v2kaon[15];
float v2prot[15];
float v2allt[15];
float v2errpion[15];
float v2errkaon[15];
float v2errprot[15];
float v2errallt[15];
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
    v2pion[ipt] = resCorr_r8dA(v2pion[ipt],1,0);
    v2kaon[ipt] = resCorr_r8dA(v2kaon[ipt],1,0);
    v2prot[ipt] = resCorr_r8dA(v2prot[ipt],1,0);
    v2allt[ipt] = resCorr_r8dA(v2allt[ipt],1,0);
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


  TGraphErrors *gr_v2pion = new TGraphErrors(14,pt,v2pion,pterr,v2errpion);
  TGraphErrors *gr_v2kaon = new TGraphErrors(14,pt,v2kaon,pterr,v2errkaon);
  TGraphErrors *gr_v2prot = new TGraphErrors(14,pt,v2prot,pterr,v2errprot);
  TGraphErrors *gr_v2allt = new TGraphErrors(12,pt,v2allt,pterr,v2errallt);
  TGraphErrors *gr_v2rawt = new TGraphErrors(12,pt,v2rawt,pterr,v2rawterr);

  gr_v2pion->RemovePoint(12);
  c1 = new TCanvas("c1","c1",1200,1200);
  c1->cd();
  drawFrame(0,0,3,0.3,"Transverse Momentum (GeV/c)","elliptic flow (v_{2})");
  //drawTitle(.1,-.07,"Identified Particle Elliptic Flow (v_{2}), TOF.W + ACC",1,12,.03,0);
  drawTitle(.1,-.07,"Charged Track Elliptic Flow (v_{2})",1,12,.03,0);
  gr_v2pion->RemovePoint(13);
  gr_v2kaon->RemovePoint(13);
  gr_v2prot->RemovePoint(13);
  gr_v2rawt->RemovePoint(13);

  gr_v2pion->RemovePoint(12);
  gr_v2kaon->RemovePoint(12);
  gr_v2prot->RemovePoint(12);
  gr_v2rawt->RemovePoint(12);

  
  gr_v2pion->SetMarkerSize(2.5); gr_v2pion->SetMarkerColor(pioncolor);  gr_v2pion->SetLineColor(pioncolor); gr_v2pion->SetMarkerStyle(20); 
  gr_v2kaon->SetMarkerSize(2.5); gr_v2kaon->SetMarkerColor(kaoncolor);  gr_v2kaon->SetLineColor(kaoncolor); gr_v2kaon->SetMarkerStyle(20); 
  gr_v2prot->SetMarkerSize(2.5); gr_v2prot->SetMarkerColor(protcolor);  gr_v2prot->SetLineColor(protcolor); gr_v2prot->SetMarkerStyle(20); 
  gr_v2allt->SetMarkerSize(2.5); gr_v2allt->SetMarkerColor(6);  gr_v2allt->SetLineColor(6); gr_v2allt->SetMarkerStyle(29); 
  //gr_v2rawt->SetMarkerSize(2); gr_v2rawt->SetMarkerColor(1);  gr_v2rawt->SetLineWidth(2);  gr_v2rawt->SetLineColor(1); gr_v2rawt->SetMarkerStyle(22);  gr_v2rawt->Draw("P");

  gr_v2pion->SetLineStyle(7); gr_v2pion->SetLineWidth(3);   gr_v2pion->Draw("P");
  gr_v2kaon->SetLineStyle(7); gr_v2kaon->SetLineWidth(3);   gr_v2kaon->Draw("P");
  gr_v2prot->SetLineStyle(7); gr_v2prot->SetLineWidth(3);   gr_v2prot->Draw("P");
  gr_v2allt->SetLineStyle(7); gr_v2allt->SetLineWidth(3);   //gr_v2allt->Draw("CP");
  
  legend = new TLegend(0.2,0.9,0.7,0.8,0);
  legend->SetNColumns(3);   legend->SetBorderSize(0);
  legend->AddEntry(gr_v2pion,"#pi+","p");
  legend->AddEntry(gr_v2kaon,"K+","p");
  legend->AddEntry(gr_v2prot,"P+","p");
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
  }

v2allt[0] = 0.0110464;     v2errallt[0] = 5.2853e-006;
v2pion[0] = 0.0132701;     v2errpion[0] = 1.22079e-005;
v2kaon[0] = 0.0114359;     v2errkaon[0] = 4.3463e-005;
v2prot[0] = 0.00793591;    v2errprot[0] = 4.5693e-005;

v2allt[1] = 0.0141471;     v2errallt[1] = 1.21562e-005;
v2pion[1] = 0.0153329;     v2errpion[1] = 1.17157e-005;
v2kaon[1] = 0.0122723;     v2errkaon[1] = 3.74461e-005;
v2prot[1] = 0.00999403;    v2errprot[1] = 3.9436e-005;


v2allt[2] = 0.0151138;     v2errallt[2] = 0.00790503;
v2pion[2] = 0.021668;      v2errpion[2] = 1.4323e-005;
v2kaon[2] = 0.0197097;     v2errkaon[2] = 4.53486e-005;
v2prot[2] = 0.0143848;     v2errprot[2] = 3.50862e-005;

v2allt[3] = 0.0249594;     v2errallt[3] = 2.70961e-005;
v2pion[3] = 0.0267752;     v2errpion[3] = 2.96894e-005;
v2kaon[3] = 0.0235448;     v2errkaon[3] = 0.000122925;
v2prot[3] = 0.0205499;     v2errprot[3] = 5.73726e-005;

v2allt[4] = 0.0260824;     v2errallt[4] = 2.41934e-005;
v2pion[4] = 0.0279191;     v2errpion[4] = 2.72026e-005;
v2kaon[4] = 0.0263924;     v2errkaon[4] = 5.52452e-005;
v2prot[4] = 0.0237102;     v2errprot[4] = 4.35944e-005;

v2allt[5] = 0.0203671;     v2errallt[5] = 0.0635948;
v2pion[5] = 0.0262748;     v2errpion[5] = 8.90982e-005;
v2kaon[5] = 0.033035;      v2errkaon[5] = 0.000152661;
v2prot[5] = 0.0335092;     v2errprot[5] = 0.000208749;

v2allt[6] = 0.0347729;     v2errallt[6] = 0.00013244;
v2pion[6] = 0.0268752;     v2errpion[6] = 0.000141449;
v2kaon[6] = 0.0417866;     v2errkaon[6] = 0.000239009;
v2prot[6] = 0.0479764;     v2errprot[6] = 0.000297471;

v2allt[7] = 0.0355309;     v2errallt[7] = 0.000236224;
v2pion[7] = 0.0292939;     v2errpion[7] = 0.000318738;
v2kaon[7] = 0.0426542;     v2errkaon[7] = 0.000418053;
v2prot[7] = 0.047862;      v2errprot[7] = 0.0003126;

v2pion[8] = 0.0298951;     v2errpion[8] = 0.0004699;
v2kaon[8] = 0.0443421;     v2errkaon[8] = 0.000666894;
v2prot[8] = 0.0472266;     v2errprot[8] = 0.00062743;

v2pion[9] = 0.0275577;     v2errpion[9] = 0.000650622;
v2kaon[9] = 0.0369777;     v2errkaon[9] = 0.00081272;
v2prot[9] = 0.0476927;     v2errprot[9] = 0.000769387;

v2pion[10] = 0.0278351;      v2errpion[10] = 0.0211714;
v2kaon[10] = 0.03378;      v2errkaon[10] = 0.00169447;
v2prot[10] = 0.0456037;    v2errprot[10] = 0.00202961;

v2pion[11] = 0.0282585;      v2errpion[11] = 0.00244153;
v2kaon[11] = 0.0346992;      v2errkaon[11] = 0.00430782;
v2prot[11] = 0.0435877;    v2errprot[11] = 0.00491859;


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
