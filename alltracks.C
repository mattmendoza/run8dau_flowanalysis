#include "math.h"
#include "Style.h"
#include "Run8dA_pidEP.C"



const float M_PI = 3.1415926;
TCanvas *canvasflowfit;
TCanvas *c1;
TF1 *v2fit = new TF1("v2fit","[1]*(1+[0]*cos(2*x))",0,M_PI);


ofstream parout("alltrackflow.dat");
//TGraphErrors *yieldvsdphi;
//TF1 *v2fit = new TF1("v2fit","[1]*(1+[0]*cos(2*x))",0,M_PI);
void alltracks()
{

  canvasflowfit = new TCanvas ("canvasflowfit","canvasflowfit",800,800);
  cPS = new TCanvas("cPS","cPS",4000,3000);
  cPS->Draw();
  cPS->Divide(4,3);
  parout << "SumOfAllTofs!!!" << endl;
  for(int ipt = 0;ipt<=11;ipt++)
  {
    float ptlo = 0.5+0.2*ipt;
    float pthi = ptlo+0.2;
    TCanvas *ctmp = SumOfAllTofs(ptlo,pthi)->Clone();
    cPS->cd(ipt+1);
    ctmp->DrawClonePad();
    cPS->Update();
  }
  cPS->SaveAs("alltracksyieldvsdphi.jpg");

  //return;



  float dphi[6];
  for(int idphi=0 ; idphi<=5 ; idphi++) {
    dphi[idphi] = idphi*M_PI / 6 + M_PI/12;
  }


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


  //float allTrkYield2123[6] = {13947	,13509	,13283	,13108	,13611	,13925	};
  //float allTrkYield2325[6] = {14629	,13963	,14083	,13827	,14261	,14525	};
  //float allTrkYield2527[6] = {7365	,7052	,6883	,7003	,7167	,7415	          };
  //float allTrkYield2729[6] = {5503  ,5244 ,5138 ,4908 ,5245 ,5347           };
  //float allTrkYield3035[6] = {5503  ,5244 ,5138 ,4908 ,5245 ,5347           };
  //float allTrkYield3540[6] = {5503  ,5244 ,5138 ,4908 ,5245 ,5347           };
  //float allTrkYield4045[6] = {5503	,5244	,5138	,4908	,5245	,5347	          };

  cmain = new TCanvas("cmain","cmain",3000,5000);

  cmain->Divide(3,5);
  cmain->Draw();
  canvasflowfit = new TCanvas ("canvasflowfit","canvasflowfit",800,800);
  parout << "SumOfAllTRACKS!!!" << endl;

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

  cmain->SaveAs("alltrackflow_TOFW.jpg");


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


  parout << "v2all[] = " << v2fit->GetParameter(0) << ";\t\t v2allerr[] = " << v2fit->GetParError(0) << ";" << endl;
  return canvasflowfit;


}

TCanvas * SumOfAllTofs(float ptlo, float pthi)
//generates all track v2 by taking all entries in all tof plots
{	
  
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

    //Ntrkseastneg[idphi] = (h2ineastneg->ProjectionX("hteastneg",lobin,hibin))->GetEntries();  //eastneg
    Ntrkswestneg[idphi] = (h2inwestneg->ProjectionX("htwestneg",lobin,hibin))->GetEntries();  //westneg
    //Ntrkseastpos[idphi] = (h2ineastpos->ProjectionX("hteastpos",lobin,hibin))->GetEntries();  //eastpos
    Ntrkswestpos[idphi] = (h2inwestpos->ProjectionX("htwestpos",lobin,hibin))->GetEntries();  //westpos
    Ntotal[idphi] = Ntrkswestneg[idphi] + Ntrkswestpos[idphi];
    //Ntotal[idphi] = Ntrkseastneg[idphi] + Ntrkswestneg[idphi] + Ntrkseastpos[idphi] + Ntrkswestpos[idphi];
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
  parout << "v2all[] = " << v2fit->GetParameter(0) << ";\t\t v2allerr[] = " << v2fit->GetParError(0) << ";" << endl;

  return c1;

}