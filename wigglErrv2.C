#include "math.h"
#include "Style.h"
#include "Run8dA_pidEP.C"


float v2allt[15];
float v2allterr[15];

int ipt=0;

const float M_PI = 3.1415926;
TCanvas *canvasflowfit;
TCanvas *c1;
TF1 *v2fit = new TF1("v2fit","[1]*(1+[0]*cos(2*x))",0,M_PI);

//ofstream parout("alltrackflow.dat");
//TGraphErrors *yieldvsdphi;
//TF1 *v2fit = new TF1("v2fit","[1]*(1+[0]*cos(2*x))",0,M_PI);
void wigglErrv2()
{

  int whichPhi = 2;
  float sysPercent = 2;
  string plusminus = "plus";

  float dphi[6];
  for(int idphi=0 ; idphi<=5 ; idphi++) {
    dphi[idphi] = idphi*M_PI / 6 + M_PI/12;
  }
  setBaseV2();

  float allTrkYield0507[6] = {426131  ,420909  ,416635  ,416147  ,420275  ,425595};
  float allTrkYield0709[6] = {483025  ,470456  ,471888  ,471714  ,478319  ,485048};
  float allTrkYield0911[6] = {353047  ,348209  ,342192  ,341032  ,347291  ,354713};
  float allTrkYield1113[6] = {97927.6 ,95949.7 ,93550.9 ,93454.6 ,95819.1 ,98143.3};
  float allTrkYield1315[6] = {128213.6,124835.4,120983.8,121328.2,124201.7,127949.8};
  float allTrkYield1517[6] = {51003   ,49831.7 ,48133.4 ,48288.9 ,49942.5 ,51180.3};
  float allTrkYield1719[6] = {23216.1 ,22535.1 ,21765.8 ,21902.3 ,22532.8 ,23326.9};
  float allTrkYield1921[6] = {25502.2 ,24663.4 ,23881.8 ,23811.8 ,24355.8 ,25407.1};
  float allTrkYield2123[6] = {10213.9 ,9814.4  ,9592.74 ,9585.85 ,9969      ,10274.7 };
  float allTrkYield2325[6] = {6693.2  ,6513.964,6298.442,6238.288,6444.611  ,6687.868};
  float allTrkYield2527[6] = {4933.719,4755.667,4626.862,4635.468,4734.004  ,4938.964};
  float allTrkYield2729[6] = {3681.681,3545.79 ,3460.461,3465.392,3580.476  ,3691.451};
  float allTrkYield3035[6] = {2619.115,2528.73 ,2463.142,2478.33 ,2536      ,2638.526};
  float allTrkYield3540[6] = {1602.69 ,1555.569,1492.359,1513.497,1555.067  ,1611.553};
  float allTrkYield4045[6] = {1317.69 ,1299.588,1222.193,1271.106,1251.564  ,1322.579};
  
  
  allTrkYield0507[whichPhi] = wiggleize(allTrkYield0507[whichPhi],sysPercent,plusminus);
  allTrkYield0709[whichPhi] = wiggleize(allTrkYield0709[whichPhi],sysPercent,plusminus);
  allTrkYield0911[whichPhi] = wiggleize(allTrkYield0911[whichPhi],sysPercent,plusminus);
  allTrkYield1113[whichPhi] = wiggleize(allTrkYield1113[whichPhi],sysPercent,plusminus);
  allTrkYield1315[whichPhi] = wiggleize(allTrkYield1315[whichPhi],sysPercent,plusminus);
  allTrkYield1517[whichPhi] = wiggleize(allTrkYield1517[whichPhi],sysPercent,plusminus);
  allTrkYield1719[whichPhi] = wiggleize(allTrkYield1719[whichPhi],sysPercent,plusminus);
  allTrkYield1921[whichPhi] = wiggleize(allTrkYield1921[whichPhi],sysPercent,plusminus);
  allTrkYield2123[whichPhi] = wiggleize(allTrkYield2123[whichPhi],sysPercent,plusminus);
  allTrkYield2325[whichPhi] = wiggleize(allTrkYield2325[whichPhi],sysPercent,plusminus);
  allTrkYield2527[whichPhi] = wiggleize(allTrkYield2527[whichPhi],sysPercent,plusminus);
  allTrkYield2729[whichPhi] = wiggleize(allTrkYield2729[whichPhi],sysPercent,plusminus);
  allTrkYield3035[whichPhi] = wiggleize(allTrkYield3035[whichPhi],sysPercent,plusminus);
  allTrkYield3540[whichPhi] = wiggleize(allTrkYield3540[whichPhi],sysPercent,plusminus);
  allTrkYield4045[whichPhi] = wiggleize(allTrkYield4045[whichPhi],sysPercent,plusminus);


  cmain = new TCanvas("cmain","cmain",3000,5000);

  cmain->Divide(3,5);
  cmain->Draw();
  canvasflowfit = new TCanvas ("canvasflowfit","canvasflowfit",800,800);
  //parout << "SumOfAllTRACKS!!!" << endl;

  TCanvas *c0  =  plot4flowfit(dphi,allTrkYield0507,0.5,0.7)->Clone();
  TCanvas *c1  =  plot4flowfit(dphi,allTrkYield0709,0.7,0.9)->Clone();
  TCanvas *c2  =  plot4flowfit(dphi,allTrkYield0911,0.9,1.1)->Clone();
  TCanvas *c3  =  plot4flowfit(dphi,allTrkYield1113,1.1,1.3)->Clone();
  TCanvas *c4  =  plot4flowfit(dphi,allTrkYield1315,1.3,1.5)->Clone();
  TCanvas *c5  =  plot4flowfit(dphi,allTrkYield1517,1.5,1.7)->Clone();
  TCanvas *c6  =  plot4flowfit(dphi,allTrkYield1719,1.7,1.9)->Clone();
  TCanvas *c7  =  plot4flowfit(dphi,allTrkYield1921,1.9,2.1)->Clone();
  TCanvas *c8  =  plot4flowfit(dphi,allTrkYield2123,2.1,2.3)->Clone();
  TCanvas *c9  =  plot4flowfit(dphi,allTrkYield2325,2.3,2.5)->Clone();
  TCanvas *c10 =  plot4flowfit(dphi,allTrkYield2527,2.5,2.7)->Clone();
  TCanvas *c11 =  plot4flowfit(dphi,allTrkYield2729,2.7,2.9)->Clone();
  TCanvas *c12 =  plot4flowfit(dphi,allTrkYield3035,30,35)->Clone();
  TCanvas *c13 =  plot4flowfit(dphi,allTrkYield3540,35,40)->Clone();
  TCanvas *c14 =  plot4flowfit(dphi,allTrkYield4045,40,45)->Clone();

  cmain->cd(1 );	c0 ->DrawClonePad();
  cmain->cd(2 );	c1 ->DrawClonePad();
  cmain->cd(3 );	c2 ->DrawClonePad();
  cmain->cd(4 );	c3 ->DrawClonePad();
  cmain->cd(5 );	c4 ->DrawClonePad();
  cmain->cd(6 );	c5 ->DrawClonePad();
  cmain->cd(7 );	c6 ->DrawClonePad();
  cmain->cd(8 );	c7 ->DrawClonePad();
  cmain->cd(9 );	c8 ->DrawClonePad();
  cmain->cd(10);	c9 ->DrawClonePad();
  cmain->cd(11);	c10->DrawClonePad();
  cmain->cd(12);  c11->DrawClonePad();
  cmain->cd(12);  c12->DrawClonePad();
  cmain->cd(13);  c13->DrawClonePad();
  cmain->cd(14);	c14->DrawClonePad();

  //for(int i = 0; i<=11; i++) {	cmain->cd(i+1);	ctemp[i]->DrawClonePad();	}
  cmain->Update();
  char savestring[64];
  sprintf(savestring,"sysstudyflow_dphi%i.jpg",idphi);
  cmain->SaveAs(savestring);


}

TCanvas * plot4flowfit(float dphi[], float yieldset[], float ptlo, float pthi)
{

  char titlestring[64];
  TF1 *v2fit = new TF1("v2fit","[1]*(1+[0]*cos(2*x))",0,M_PI);

  yieldvsdphi = new TGraphErrors(6,dphi,yieldset,0,0);

  canvasflowfit->cd();

  float min = TMath::MinElement(6,yieldvsdphi->GetY());
  float max = TMath::MaxElement(6,yieldvsdphi->GetY());
  float delta = max-min;
  drawFrame(-1*M_PI/4,min-delta,5*M_PI/4,max+delta,"d#phi","Raw Yield");


  sprintf(titlestring,"All Track Yield (GeV/c^{2}), %g<pT<%g",ptlo,pthi);
  drawTitle(.1,-.07,titlestring,1,12,.03,0);
  yieldvsdphi->SetMarkerSize(2); yieldvsdphi->SetMarkerStyle(21);   yieldvsdphi->SetMarkerColor(6);    yieldvsdphi->Draw("P");
  v2fit->SetLineColor(2);	v2fit->SetLineWidth(4);

  yieldvsdphi->Fit(v2fit,"Q","",0.05,M_PI-0.05);

  float v2new = resCorr_r8dA(v2fit->GetParameter(0),1,0);
  float v2old = resCorr_r8dA(v2allt[ipt],1,0);
  float deltaPercent = fabs(resCorr_r8dA(v2allt[ipt],1,0)-resCorr_r8dA(v2fit->GetParameter(0),1,0)) / resCorr_r8dA(v2allt[ipt],1,0);

  cout << "v2compare NEW: " << v2new << endl;
  cout << "v2compare OLD: " << v2old << endl;
  cout << "Represents a : " << deltaPercent << " variance from original values" << endl;

  ipt++;
  return canvasflowfit;


}

TCanvas * SumOfAllTofs(float ptlo, float pthi)
//generates all track v2 by taking all entries in all tof plots
{	
  cout << "SumOfAllTofs!!!" << endl;
  char titlestring[64];
  float dphi[6];
  float Ntrkseastneg[6];
  float Ntrkswestneg[6];
  float Ntrkseastpos[6];
  float Ntrkswestpos[6];


  float Ntotal[6];
  for(int idphi=0 ; idphi<=5 ; idphi++) {
    dphi[idphi] = idphi*M_PI / 6 + M_PI/12;


    TH2F *h2ineastneg = loadHist(0, icent, idphi, 0);
    TH2F *h2inwestneg = loadHist(1, icent, idphi, 0);
    TH2F *h2ineastpos = loadHist(0, icent, idphi, 1);
    TH2F *h2inwestpos = loadHist(1, icent, idphi, 1);
    
    int lobin=h2ineastneg->GetYaxis()->FindBin(ptlo);
    int hibin=h2ineastneg->GetYaxis()->FindBin(pthi);
    int icent = 0;

    Ntrkseastneg[idphi] = (h2ineastneg->ProjectionX("hteastneg",lobin,hibin))->GetEntries();  //eastneg
    Ntrkswestneg[idphi] = (h2inwestneg->ProjectionX("htwestneg",lobin,hibin))->GetEntries();  //westneg
    Ntrkseastpos[idphi] = (h2ineastpos->ProjectionX("hteastpos",lobin,hibin))->GetEntries();  //eastpos
    Ntrkswestpos[idphi] = (h2inwestpos->ProjectionX("htwestpos",lobin,hibin))->GetEntries();  //westpos
    Ntotal[idphi] = Ntrkseastneg[idphi] + Ntrkswestneg[idphi] + Ntrkseastpos[idphi] + Ntrkswestpos[idphi];
    //cout << Ntotal[idphi] << endl;
  }

  gr_v2all = new TGraphErrors(6,dphi,Ntotal,0);
  gr_v2all->SetMarkerSize(2);	gr_v2all->SetMarkerStyle(21);	

  float min = TMath::MinElement(6,gr_v2all->GetY());
  float max = TMath::MaxElement(6,gr_v2all->GetY());
  float delta = max-min;
  
  c1->cd();
  drawFrame(-1*M_PI/4,min-delta,5*M_PI/4,max+delta,"d#phi","Raw Yield");
  sprintf(titlestring,"All Track Yield (GeV/c^{2}), %g<pT<%g",ptlo,pthi);
  drawTitle(.1,-.07,titlestring,1,12,.03,0);
  gr_v2all->Draw("p");

  gr_v2all->Fit("v2fit","Q","",0.05,M_PI-0.05);
  //c1->SaveAs("blah.jpg");
  cout << "v2all[] = " << resCorr_r8dA(v2fit->GetParameter(0),1,0); << ";\t\t v2allerr[] = " << resCorr_r8dA(v2fit->GetParError(0),1,0) << ";" << endl;

  return c1;

}

float wiggleize(float yieldval, float sysPercent, string plusminus ="plus") {
  if(plusminus == "minus") { return yieldval*(1 - sysPercent/100);  }
  if(plusminus == "plus")  { return yieldval*(1 + sysPercent/100);  }
}

float resCorr_r8dA(float v2, int sysflag, int centbin)
{
  //sysflag flags which detector is used for RP 
// 0- BBC
// 1- MPC
// 2- RXNIN
// 3- RXNOUT
// 4- RXNCMB

  //sysflag = sysflag + 1;
  float res[6][4];
  float resErr[6][4];

  //cout << sysflag << "\t" << centbin << endl;

res[0][0] =   0.12821  ; resErr[0][0] =   0.00536457;
res[1][0] =   0.183482 ; resErr[1][0] =   0.00537042;
res[2][0] =   0.1425   ; resErr[2][0] =   0.00536553;
res[3][0] =   0.0169146; resErr[3][0] =   0.00536335;
res[4][0] =   0.0990726; resErr[4][0] =   0.00535798;
      
//centbin: 2    centbin: 2  
res[0][1] =   0.193376 ; resErr[0][1] =   0.00538797;
res[1][1] =   0.312562 ; resErr[1][1] =   0.00537477;
res[2][1] =   0.0562682; resErr[2][1] =   0.00538001;
res[3][1] =   0.100585 ; resErr[3][1] =   0.00538992;
res[4][1] =   0.0863826; resErr[4][1] =   0.00538704;
      
//centbin: 3    centbin: 3  
res[0][2] =   0.0752232; resErr[0][2] =   0.00538196;
res[1][2] =   0.458582 ; resErr[1][2] =   0.0053765;
res[2][2] =   0.175037 ; resErr[2][2] =   0.00538112;
res[3][2] =   0.120356 ; resErr[3][2] =   0.00539901;
res[4][2] =   0.121532 ; resErr[4][2] =   0.00539664;
      
//centbin: 4    centbin: 4  
res[0][3] =   0.0875941 ; resErr[0][3] =   0.00538681;
res[1][3] =   0.452428  ; resErr[1][3] =   0.00538587;
res[2][3] =   0.109962  ; resErr[2][3] =   0.00538293;
res[3][3] =   0.025718  ; resErr[3][3] =   0.00538809;
res[4][3] =   0.0259343 ; resErr[4][3] =   0.00538723;


  //res[1][0]=0.1134;  res[1][1]=0.0905;  res[1][2]=0.0664;  res[1][3]=0.0664;
  //res[2][0]=0.1591;  res[2][1]=0.1104;  res[2][2]=0.1095;  res[2][3]=0.0979;
  //res[3][0]=0.1250;  res[3][1]=0.0886;  res[3][2]=0.0985;  res[3][3]=0.0967;
  //res[4][0]=0.0937;  res[4][1]=0.1012;  res[4][2]=0.0573;  res[4][3]=0.0572;
  //res[5][0]=0.1282;  res[5][1]=0.1238;  res[5][2]=0.0991;  res[5][3]=0.0919;
/*
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
*/
  cout << v2 / res[sysflag][centbin] << endl;;
  return v2 / res[sysflag][centbin];

}


void setBaseV2() {
  v2allt[0] = 0.0129913;    v2allterr[0] = 0.000630539;
  v2allt[1] = 0.0148176;    v2allterr[1] = 0.00426477;
  v2allt[2] = 0.020368;     v2allterr[2] = 0.00130794;
  v2allt[3] = 0.0273147;    v2allterr[3] = 0.0007013;
  v2allt[4] = 0.0320949;    v2allterr[4] = 0.00128689;
  v2allt[5] = 0.0334418;    v2allterr[5] = 0.00190837;
  v2allt[6] = 0.0368089;    v2allterr[6] = 0.00161652;
  v2allt[7] = 0.0377298;    v2allterr[7] = 0.00333707;
  v2allt[8] = 0.0381662;    v2allterr[8] = 0.00352911;
  v2allt[9] = 0.0376176;    v2allterr[9] = 0.00289812;
  v2allt[10] = 0.0369319;   v2allterr[10] = 0.00290598;
  v2allt[11] = 0.0361587;   v2allterr[11] = 0.00234554;
  v2allt[12] = 0.035877;    v2allterr[12] = 0.00307623;
  v2allt[13] = 0.0386827;   v2allterr[13] = 0.00301108;
  v2allt[14] = 0.0331255;   v2allterr[14] = 0.0111428;
}
