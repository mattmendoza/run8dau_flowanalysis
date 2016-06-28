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

  return;



  float dphi[6];
  for(int idphi=0 ; idphi<=5 ; idphi++) {
    dphi[idphi] = idphi*M_PI / 6 + M_PI/12;
  }


  float allTrkYield0507[6] = {297893,293361	,289905	,290438	,293891	,297078	};
  float allTrkYield0709[6] = {302443,296815	,292693	,292992	,296974	,300988	};
  float allTrkYield0911[6] = {216756,213406	,209786	,209073	,212012	,215913	};
  float allTrkYield1113[6] = {68056	,66490	,65638	,65472	,66176	,67645	};
  float allTrkYield1315[6] = {81810	,79975	,78246	,78023	,79073	,81309	};
  float allTrkYield1517[6] = {34135	,33443	,32097	,31910	,32839	,33640	};
  float allTrkYield1719[6] = {19315	,18635	,18077	,18042	,18620	,19015	};
  float allTrkYield1921[6] = {21401	,20930	,20482	,20463	,20997	,21303	};
  float allTrkYield2123[6] = {13947	,13509	,13283	,13108	,13611	,13925	};
  float allTrkYield2325[6] = {14629	,13963	,14083	,13827	,14261	,14525	};
  float allTrkYield2527[6] = {7365	,7052	,6883	,7003	,7167	,7415	};
  float allTrkYield2729[6] = {5503	,5244	,5138	,4908	,5245	,5347	};

  cmain = new TCanvas("cmain","cmain",4000,3000);

  cmain->Divide(4,3);
  cmain->Draw();
  canvasflowfit = new TCanvas ("canvasflowfit","canvasflowfit",800,800);

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
  cmain->cd(12);	c11->DrawClonePad();

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
  parout << "v2all[] = " << v2fit->GetParameter(0) << ";\t\t v2allerr[] = " << v2fit->GetParError(0) << ";" << endl;

  return c1;

}