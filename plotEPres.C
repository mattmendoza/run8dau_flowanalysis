#include "Style.h"
#include "graphStyles.h"

void plotEPres() {

  float BBC[4]    = {0.12821,0.19337,0.07522,0.08759};
  float MPC[4]    = {0.25551,0.10140,0.21927,0.18086};
  float RXNIN[4]  = {0.14250,0.05626,0.17503,0.10996};
  float RXNOUT[4] = {0.1691,0.10058,0.12035,0.02571};
  float RXNCMB[4] = {0.09907,0.08638,0.12153,0.02593};

  float BBCerr[4]    = {0.00309,0.00311,0.00311,0.00311};
  float MPCerr[4]    = {0.00310,0.00310,0.00310,0.00311};
  float RXNINerr[4]  = {0.00309,0.00310,0.00310,0.00310};
  float RXNOUTerr[4] = {0.00309,0.00310,0.00311,0.00311};
  float RXNCMBerr[4] = {0.00308,0.00310,0.00311,0.00310};

  float cent[4];
  float centerr[4];
  for(int i=0; i<=3; i++) {
    cent[i]   = i*5+2.5;
    centerr[i]= 2.5;
  }
  
  TGraphErrors *EPresBBC    = new TGraphErrors(4,cent,BBC   ,centerr,BBCerr);
  TGraphErrors *EPresMPC    = new TGraphErrors(4,cent,MPC   ,centerr,MPCerr);
  TGraphErrors *EPresRXNIN  = new TGraphErrors(4,cent,RXNIN ,centerr,RXNINerr);
  TGraphErrors *EPresRXNOUT = new TGraphErrors(4,cent,RXNOUT,centerr,RXNOUTerr);
  TGraphErrors *EPresRXNCMB = new TGraphErrors(4,cent,RXNCMB,centerr,RXNCMBerr);

  c1 = new TCanvas("c1","c1",2000,2000);
  c1->cd();
  TH1F * frame = drawFrame(0,0,20,0.3,"Centrality (%)","Res(#Psi_{2})");
  frame->GetYaxis()->SetLabelSize(0.02);
  frame->GetXaxis()->SetNdivisions(4);
  //drawTitle(.1,-.07,"Identified Particle Elliptic Flow (v_{2}), TOF.W + ACC",1,12,.03,0);
  drawTitle(.1,-.07,"Event Plane Resolution Corrections",1,12,.03,0);
  EPresBBC   ->SetLineStyle(2); EPresBBC   ->SetLineWidth(6); EPresBBC   ->SetLineColor(1); EPresBBC   ->SetMarkerColor(1);  EPresBBC   ->SetMarkerSize(5);  EPresBBC   ->SetMarkerStyle(20);  EPresBBC   ->Draw("P");    
  EPresMPC   ->SetLineStyle(3); EPresMPC   ->SetLineWidth(6); EPresMPC   ->SetLineColor(2); EPresMPC   ->SetMarkerColor(2);  EPresMPC   ->SetMarkerSize(5);  EPresMPC   ->SetMarkerStyle(20);  EPresMPC   ->Draw("P");    
  EPresRXNIN ->SetLineStyle(4); EPresRXNIN ->SetLineWidth(6); EPresRXNIN ->SetLineColor(3); EPresRXNIN ->SetMarkerColor(3);  EPresRXNIN ->SetMarkerSize(5);  EPresRXNIN ->SetMarkerStyle(20);  EPresRXNIN ->Draw("P");  
  EPresRXNOUT->SetLineStyle(5); EPresRXNOUT->SetLineWidth(6); EPresRXNOUT->SetLineColor(4); EPresRXNOUT->SetMarkerColor(4);  EPresRXNOUT->SetMarkerSize(5);  EPresRXNOUT->SetMarkerStyle(20);  EPresRXNOUT->Draw("P"); 
  EPresRXNCMB->SetLineStyle(6); EPresRXNCMB->SetLineWidth(6); EPresRXNCMB->SetLineColor(6); EPresRXNCMB->SetMarkerColor(6);  EPresRXNCMB->SetMarkerSize(5);  EPresRXNCMB->SetMarkerStyle(20);  EPresRXNCMB->Draw("P"); 

  legend = new TLegend(0.2,0.89,0.8,0.78,0);
  legend->SetNColumns(3);   legend->SetBorderSize(0);
  legend->AddEntry(EPresBBC   ,"#Psi_{2.BBC}"   ,"p");
  legend->AddEntry(EPresMPC   ,"#Psi_{2.MPC}"   ,"p");
  legend->AddEntry(EPresRXNIN ,"#Psi_{2.RXNIN}" ,"p");
  legend->AddEntry(EPresRXNOUT,"#Psi_{2.RXNOUT}","p");
  legend->AddEntry(EPresRXNCMB,"#Psi_{2.RXNCMB}","p");
  legend->Draw();

  c1->SaveAs("EPresr8da.jpg");
}
