#include <iostream>
#include "Run8dA_pidEP.C"

int ptbin;
int ich;

float v2pionnegup[8];	float v2errpionnegup[8];
float v2kaonnegup[8];	float v2errkaonnegup[8];
float v2protnegup[8];	float v2errprotnegup[8];
float v2pionposup[8];	float v2errpionposup[8];
float v2kaonposup[8];	float v2errkaonposup[8];
float v2protposup[8];	float v2errprotposup[8];

float v2pionnegdn[8];	float v2errpionnegdn[8];
float v2kaonnegdn[8];	float v2errkaonnegdn[8];
float v2protnegdn[8];	float v2errprotnegdn[8];
float v2pionposdn[8];	float v2errpionposdn[8];
float v2kaonposdn[8];	float v2errkaonposdn[8];
float v2protposdn[8];	float v2errprotposdn[8];

int centupdown =1;  
//int centupdown =1;  

void anaCentSys() {
  if(centupdown == 0) {	ofstream systFile("centsys/centsystematicsdn.txt");	}
  if(centupdown == 1) {	ofstream systFile("centsys/centsystematicsup.txt");	}
  for(int ptbin=0; ptbin <=7; ptbin++) {
    for(int ich=0; ich<=1; ich++) {
      fitInit(itof,icent,ich,ptbin);
      importfromStruct(fitTuning);
      runBySubBin_centsys(itof,icent,ich,ptrange,ptbin); //itof, icent, ich, ptrange[]
      //cout<< "////////////////////////////////////////////////////running on pt,ch:  " << ptbin << "\t" << ich << endl;
  	}
  }

}

void runBySubBin_centsys(int itof, int icent, int ich, float ptrange[], int ptbin)  
//sub bin refers to charge, centrality, and tof bins, all dphi bins are run over in this step
{
  char outfilestring[128];
 
  for(int idphi=0 ; idphi<=5 ; idphi++) {
  	if(itof <2 || itof == 3) h2_m2tofvspt_v2_temp[itof][ich][icent][idphi] = loadHist_centsys(itof, icent, idphi, ich);
    if(itof==2) 
    {
        TCanvas *c5 = new TCanvas("c5","c5",800,2400);
        c5->Divide(1,3);
        
        h2_m2tofvspt_v2_temp[1][ich][icent][idphi] = loadHist_centsys(1, icent, idphi, ich);
        h2_m2tofvspt_v2_temp[1][ich][icent][idphi]->SetTitle("TOFW RAW;m^{2} (GeV/c^{2});p_{T} (GeV/c)");
        c5->cd(1);
        gPad->SetLogz();
        h2_m2tofvspt_v2_temp[1][ich][icent][idphi]->DrawCopy("colz");

        h2_m2tofvspt_v2_temp[3][ich][icent][idphi] = loadHist_centsys(3, icent, idphi, ich);
        c5->cd(2);
        gPad->SetLogz();
        h2_m2tofvspt_v2_temp[3][ich][icent][idphi]->SetTitle("TOFW ACCFIRE;m^{2} (GeV/c^{2});p_{T} (GeV/c)");
        h2_m2tofvspt_v2_temp[3][ich][icent][idphi]->DrawCopy("colz");

        h2_m2tofvspt_v2_temp[2][ich][icent][idphi] = loadHist_centsys(2, icent, idphi, ich);
        //h2_m2tofvspt_v2_temp[2][ich][icent][idphi]->Add(h2_m2tofvspt_v2_temp[3][ich][icent][idphi],-15);
        c5->cd(3);
        gPad->SetLogz();
        h2_m2tofvspt_v2_temp[2][ich][icent][idphi]->SetTitle("TOFW VETO;m^{2} (GeV/c^{2});p_{T} (GeV/c)");
        h2_m2tofvspt_v2_temp[2][ich][icent][idphi]->Draw("COLZ");

        c5->SaveAs("tofwveto2dh.jpg");
    }

  }

  if(hipTpeakfinder==1) {
  	h2_alldPhi = new TH2D();
  	h2_alldPhi = (TH2D*)h2_m2tofvspt_v2_temp[itof][ich][icent][0]->Clone("h2_all");
  	h2_alldPhi->Add(h2_m2tofvspt_v2_temp[itof][ich][icent][1]);
  	h2_alldPhi->Add(h2_m2tofvspt_v2_temp[itof][ich][icent][2]);
  	h2_alldPhi->Add(h2_m2tofvspt_v2_temp[itof][ich][icent][3]);
  	h2_alldPhi->Add(h2_m2tofvspt_v2_temp[itof][ich][icent][4]);
  	h2_alldPhi->Add(h2_m2tofvspt_v2_temp[itof][ich][icent][5]);
  	csum = new TCanvas("csum","csum",800,800);
  	csum->cd();
  	h2_alldPhi->Draw("colz");
  	csum->SetLogz();
  	//sprintf(outfilestring,"summed2dhists/m2vspt_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  	//csum->SaveAs(outfilestring);
    findPeakCenter_hipT(h2_alldPhi, itof, icent, ich, ptrange);
  }


  ctemp = new TCanvas("ctemp","ctemp",6000,4000);
  ctemp->Divide(3,2);
  for(int idphi=0 ; idphi<=5 ; idphi++) {
    ctemp->cd(idphi+1);
    SlicetoEP(h2_m2tofvspt_v2_temp[itof][ich][icent][idphi], itof, icent, idphi, ich, ptrange);	 // input hist, itof, cent, idphi, charge

  }

  sprintf(outfilestring,"centsys/yieldvsdphi_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  ctemp->SaveAs(outfilestring);
  //writeIndiv(itof,icent,ich);
  CheckFitsEP_centsys(itof, icent, ich, ptrange, ptbin);

  return;
}

void CheckFitsEP_centsys(int itof, int icent, int ich, float ptrange[],int ptbin)
{

  cout<< "////////////////////////////////////////////////////plotting diagnostics for pt,ch:  " << ptbin << "\t" << ich << endl;
  float dphi[6]; 
  char titlestring[128];

  TString tofstring;
  if(itof == 0)	{	tofstring = "TOF.E";	}
  if(itof == 1)	{	tofstring = "TOF.W";	}
  if(itof == 2)	{	tofstring = "TOF.E ACCveto";	}
  if(itof == 3)	{	tofstring = "TOF.E ACCfire";	}

  TString centrality = "% centrality";
  TString lcomma = ", ";
  TString tracks = " tracks";

  //sprintf(titlestring,"chkparams/parbkup/meansandsigmas/meansandsigmas_tof%i_cent%i_ch%i_pT-%g-%g.txt",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  //cout << "Writing mean and sigma parameters to: " << titlestring << endl;
  //ofstream pidparsfile(titlestring);


  sprintf(titlestring,"centsys/v2Par_tof%i_cent%i_ch%i_pT-%g-%g.txt",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  cout << "Writing v2 and fit parameters to: " << titlestring << endl;
  ofstream parfile(titlestring);

  float allIDyield[6];
  float allIDyielderr[6];
  
  for(int idphi=0 ; idphi<=5 ; idphi++) {
    dphi[idphi] = idphi*M_PI / 6 + M_PI/12;

    parfile << "PIONS  | \t idphi: \t" << idphi << "\t mean:\t" << chkpionmean[idphi] << "\t mean err:\t" << chkpionmeanerr[idphi] << "\t width:\t" << chkpionwidth[idphi] << "\t width err: \t"<< chkpionwidtherr[idphi] << "\t yield:\t" << chkpionyield[idphi] << "\t yield err:\t" << chkpionyielderr[idphi] << endl;
    parfile << "KAONS  | \t idphi: \t" << idphi << "\t mean:\t" << chkkaonmean[idphi] << "\t mean err:\t" << chkkaonmeanerr[idphi] << "\t width:\t" << chkkaonwidth[idphi] << "\t width err: \t"<< chkkaonwidtherr[idphi] << "\t yield:\t" << chkkaonyield[idphi] << "\t yield err:\t" << chkkaonyielderr[idphi] << endl;
    parfile << "PROTONS| \t idphi: \t" << idphi << "\t mean:\t" << chkprotmean[idphi] << "\t mean err:\t" << chkprotmeanerr[idphi] << "\t width:\t" << chkprotwidth[idphi] << "\t width err: \t"<< chkprotwidtherr[idphi] << "\t yield:\t" << chkprotyield[idphi] << "\t yield err:\t" << chkprotyielderr[idphi] << endl;
    
    allIDyield[idphi] = chkpionyield[idphi] + chkkaonyield[idphi] + chkprotyield[idphi]; 
    allIDyielderr[idphi] = sqrt(pow(chkpionyielderr[idphi],2) + pow(chkkaonyielderr[idphi],2) + pow(chkprotyielderr[idphi],2)); 
    
    parfile << endl;

    parfile << "ALL ID TRACKS| \t idphi: \t" << idphi << "\t yield:\t" << allIDyield[idphi] << "\t yield err:\t" << allIDyielderr[idphi] << endl;
  }
  parfile << endl << endl << endl;

  TF1 *v2fit = new TF1("v2fit","[1]*(1+[0]*cos(2*x))",0,M_PI);
  v2fit->SetParLimits(0,0,1);

  TGraphErrors *gr_allIDyield = new TGraphErrors(6,dphi,allIDyield,0,allIDyielderr);
  float min = TMath::MinElement(6,gr_allIDyield->GetY());
  float max = TMath::MaxElement(6,gr_allIDyield->GetY());
  float delta = max-min;
  c_allT = new TCanvas("c_allT","c_allT",800,800);
  c_allT->cd();
  drawFrame(-1*M_PI/4,min-delta,5*M_PI/4,max+delta,"d#phi","Raw Yield");
  sprintf(titlestring,"All ID Particle Yield (GeV/c^{2}), %g<pT<%g",ptrange[0],ptrange[1]);
  drawTitle(.1,-.07,titlestring+lcomma+tofstring+lcomma+centbinlabel[icent+1]+centrality+lcomma+chargelabel[ich]+tracks,1,12,.03,0);
  gr_allIDyield->SetMarkerSize(YieldMarkerSize); gr_allIDyield->SetMarkerStyle(21);   gr_allIDyield->SetMarkerColor(1);    gr_allIDyield->Draw("P");
  gr_allIDyield->Fit("v2fit","Q","",0.05,M_PI-0.05);  gStyle->SetOptFit();
  
  if(ich==0) parfile << "v2alltneg[" << ptbin << "] = " << v2fit->GetParameter(0) << "; \t\t v2erralltneg[" << ptbin << "] = " << v2fit->GetParError(0) << ";" << endl;
  if(ich==1) parfile << "v2alltpos[" << ptbin << "] = " << v2fit->GetParameter(0) << "; \t\t v2erralltpos[" << ptbin << "] = " << v2fit->GetParError(0) << ";" << endl;
  sprintf(titlestring,"yieldvsdphi_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  c_allT->SaveAs(titlestring);



  TGraphErrors *gr_pionmass = new TGraphErrors(6,dphi,chkpionmean,0,chkpionmeanerr);
  TGraphErrors *gr_kaonmass = new TGraphErrors(6,dphi,chkkaonmean,0,chkkaonmeanerr);
  TGraphErrors *gr_protmass = new TGraphErrors(6,dphi,chkprotmean,0,chkprotmeanerr);

  TGraphErrors *gr_pionwidth = new TGraphErrors(6,dphi,chkpionwidth,0,chkpionwidtherr);
  TGraphErrors *gr_kaonwidth = new TGraphErrors(6,dphi,chkkaonwidth,0,chkkaonwidtherr);
  TGraphErrors *gr_protwidth = new TGraphErrors(6,dphi,chkprotwidth,0,chkprotwidtherr);

  TGraphErrors *gr_pionyield = new TGraphErrors(6,dphi,chkpionyield,0,chkpionyielderr);
  TGraphErrors *gr_kaonyield = new TGraphErrors(6,dphi,chkkaonyield,0,chkkaonyielderr);
  TGraphErrors *gr_protyield = new TGraphErrors(6,dphi,chkprotyield,0,chkprotyielderr);


  TCanvas *c_top = new TCanvas("c_top","c_top",1600,800);
  c_top->Divide(2,1);

  c_top->cd(1);  
  sprintf(titlestring,"Fit Mean (GeV/c^{2}), %g<pT<%g",ptrange[0],ptrange[1]);
  drawFrame(0,-0.2,3.5,1.1,"d#phi","Mean (GeV/c^2)");
  drawTitle(.1,-.07,titlestring+lcomma+tofstring+lcomma+centbinlabel[icent+1]+centrality+lcomma+chargelabel[ich]+tracks,1,12,.03,0);
  gr_pionmass->SetMarkerSize(MeanMarkerSize);	gr_pionmass->SetMarkerStyle(21);    gr_pionmass->SetMarkerColor(pioncolor);   gr_pionmass->Draw("P");
  gr_kaonmass->SetMarkerSize(MeanMarkerSize);	gr_kaonmass->SetMarkerStyle(21);    gr_kaonmass->SetMarkerColor(kaoncolor);   gr_kaonmass->Draw("P");
  gr_protmass->SetMarkerSize(MeanMarkerSize);	gr_protmass->SetMarkerStyle(21);    gr_protmass->SetMarkerColor(protcolor);   gr_protmass->Draw("P");

  sprintf(titlestring,"Fit Width (GeV/c^{2}), %g<pT<%g",ptrange[0],ptrange[1]);
  c_top->cd(2);  
  drawFrame(0,-0.2,3.5,0.9,"d#phi","width (GeV/c^2)");
  drawTitle(.1,-.07,titlestring+lcomma+tofstring+lcomma+centbinlabel[icent+1]+centrality+lcomma+chargelabel[ich]+tracks,1,12,.03,0);
  gr_pionwidth->SetMarkerSize(WidthMarkerSize);  gr_pionwidth->SetMarkerStyle(21);    gr_pionwidth->SetMarkerColor(pioncolor);   gr_pionwidth->Draw("P");
  gr_kaonwidth->SetMarkerSize(WidthMarkerSize);  gr_kaonwidth->SetMarkerStyle(21);    gr_kaonwidth->SetMarkerColor(kaoncolor);   gr_kaonwidth->Draw("P");
  gr_protwidth->SetMarkerSize(WidthMarkerSize);  gr_protwidth->SetMarkerStyle(21);    gr_protwidth->SetMarkerColor(protcolor);   gr_protwidth->Draw("P");

  sprintf(titlestring,"centsys/fitMassWidth_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  //c_top->SaveAs(titlestring);

  c_yield = new TCanvas("c_yield","c_yield",2400,800);
  c_yield->Divide(3,1);
  c_yield->cd(1);
  float min = TMath::MinElement(6,gr_pionyield->GetY());
  float max = TMath::MaxElement(6,gr_pionyield->GetY());
  float delta = max-min;
  drawFrame(-1*M_PI/4,min-delta,5*M_PI/4,max+delta,"d#phi","Raw Yield");
  sprintf(titlestring,"Pion Yield (GeV/c^{2}), %g<pT<%g",ptrange[0],ptrange[1]);
  drawTitle(.1,-.07,titlestring+lcomma+tofstring+lcomma+centbinlabel[icent+1]+centrality+lcomma+chargelabel[ich]+tracks,1,12,.03,0);
  if(delPointPion>0) gr_pionyield->RemovePoint(delPointPion-1);
  gr_pionyield->SetMarkerSize(YieldMarkerSize); gr_pionyield->SetMarkerStyle(21);   gr_pionyield->SetMarkerColor(pioncolor);    gr_pionyield->Draw("P");
  v2fit->SetLineColor(pioncolor);	v2fit->SetLineWidth(4);
  gr_pionyield->Fit("v2fit","Q","",0.05,M_PI-0.05);
  gStyle->SetOptFit();
  if(ich==0) parfile << "v2pionneg[" << ptbin << "] = " << v2fit->GetParameter(0) << "; \t\t v2errpionneg[" << ptbin << "] = " << v2fit->GetParError(0) << ";" << endl;
  if(ich==1) parfile << "v2pionpos[" << ptbin << "] = " << v2fit->GetParameter(0) << "; \t\t v2errpionpos[" << ptbin << "] = " << v2fit->GetParError(0) << ";" << endl;
  saveSystematics(v2fit->GetParameter(0),v2fit->GetParError(0),"pion",ich,ptbin,centupdown);

  
  c_yield->cd(2);
  float min = TMath::MinElement(6,gr_kaonyield->GetY());
  float max = TMath::MaxElement(6,gr_kaonyield->GetY());
  float delta = max-min;
  drawFrame(-1*M_PI/4,min-delta,5*M_PI/4,max+delta,"d#phi","Raw Yield");
  sprintf(titlestring,"Kaon Yield (GeV/c^{2}), %g<pT<%g",ptrange[0],ptrange[1]);
  drawTitle(.1,-.07,titlestring+lcomma+tofstring+lcomma+centbinlabel[icent+1]+centrality+lcomma+chargelabel[ich]+tracks,1,12,.03,0);
  if(delPointKaon>0) gr_kaonyield->RemovePoint(delPointKaon-1);
  gr_kaonyield->SetMarkerSize(YieldMarkerSize); gr_kaonyield->SetMarkerStyle(21);   gr_kaonyield->SetMarkerColor(kaoncolor);    gr_kaonyield->Draw("P");
  v2fit->SetLineColor(kaoncolor);	v2fit->SetLineWidth(4);
  gr_kaonyield->Fit("v2fit","Q","",0.05,M_PI-0.05);
  if(ich==0) parfile << "v2kaonneg[" << ptbin << "] = " << v2fit->GetParameter(0) << "; \t\t v2errkaonneg[" << ptbin << "] = " << v2fit->GetParError(0) << ";" << endl;
  if(ich==1) parfile << "v2kaonpos[" << ptbin << "] = " << v2fit->GetParameter(0) << "; \t\t v2errkaonpos[" << ptbin << "] = " << v2fit->GetParError(0) << ";" << endl;
  saveSystematics(v2fit->GetParameter(0),v2fit->GetParError(0),"kaon",ich,ptbin,centupdown);

  c_yield->cd(3);
  float min = TMath::MinElement(6,gr_protyield->GetY());
  float max = TMath::MaxElement(6,gr_protyield->GetY());
  float delta = max-min;
  drawFrame(-1*M_PI/4,min-delta,5*M_PI/4,max+delta,"d#phi","Raw Yield");
  sprintf(titlestring,"Proton Yield (GeV/c^{2}), %g<pT<%g",ptrange[0],ptrange[1]);
  drawTitle(.1,-.07,titlestring+lcomma+tofstring+lcomma+centbinlabel[icent+1]+centrality+lcomma+chargelabel[ich]+tracks,1,12,.03,0);
  if(delPointProt>0) gr_protyield->RemovePoint(delPointProt-1);
  gr_protyield->SetMarkerSize(YieldMarkerSize); gr_protyield->SetMarkerStyle(21);   gr_protyield->SetMarkerColor(protcolor);    gr_protyield->Draw("P");
  v2fit->SetLineColor(protcolor);	v2fit->SetLineWidth(4);
  gr_protyield->Fit("v2fit","Q","",0.05,M_PI-0.05);
  if(ich==0) parfile << "v2protneg[" << ptbin << "] = " << v2fit->GetParameter(0) << ";\t\t v2errprotneg[" << ptbin << "] = " << v2fit->GetParError(0) << ";" << endl;
  if(ich==1) parfile << "v2protpos[" << ptbin << "] = " << v2fit->GetParameter(0) << ";\t\t v2errprotpos[" << ptbin << "] = " << v2fit->GetParError(0) << ";" << endl;
  saveSystematics(v2fit->GetParameter(0),v2fit->GetParError(0),"prot",ich,ptbin,centupdown);

  //c_yield->SaveAs(titlestring);


  TCanvas *c_check = new TCanvas("c_check","c_check",3000,2000);
  c_check->Divide(1,2);
  c_check->Draw();
  c_check->cd(1); c_top->DrawClonePad();
  c_check->cd(2); c_yield->DrawClonePad();
  c_check->Update();


  writeFitTuning(itof, icent, ich, ptrange);

  sprintf(titlestring,"centsys/fitParams_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  c_check->SaveAs(titlestring);

  parfile.close(); 

  return;
}

void saveSystematics(float v2, float v2err, string species, int ich, int ptbin, int centupdown) {
  //cout<< "////////////////////////////////////////////////////saving pars for pt,ch:  " << ptbin << "\t" << ich << endl;
  
  //char filename[64];
  //sprintf(filename,"centsys/centsystematics%i.txt",centupdown);
  if(centupdown == 0) {	ofstream systFile("centsys/centsystematicsdn.txt",fstream::app | fstream::ate);	}
  if(centupdown == 1) {	ofstream systFile("centsys/centsystematicsup.txt",fstream::app | fstream::ate);	}

  if(centupdown == 1) {
  	if(ich==0) {	
      systFile << "v2" << species << "negup" << "[" << ptbin << "] = " << v2 << ";\t v2err" << species << "negup" << "[" << ptbin << "] = " << v2err << ";" << endl;
  	  if(species == "pion") {	v2pionnegup[ptbin] = v2; v2errpionnegup[ptbin] = v2err;	}
  	  if(species == "kaon") {	v2kaonnegup[ptbin] = v2; v2errkaonnegup[ptbin] = v2err;	}
  	  if(species == "prot") {	v2protnegup[ptbin] = v2; v2errprotnegup[ptbin] = v2err;	}
  	}
  	else if(ich==1) {
      systFile << "v2" << species << "posup" << "[" << ptbin << "] = " << v2 << ";\t v2err" << species << "posup" << "[" << ptbin << "] = " << v2err << ";" << endl;
  	  if(species == "pion") {	v2pionposup[ptbin] = v2; v2errpionposup[ptbin] = v2err;	}
  	  if(species == "kaon") {	v2kaonposup[ptbin] = v2; v2errkaonposup[ptbin] = v2err;	}
  	  if(species == "prot") {	v2protposup[ptbin] = v2; v2errprotposup[ptbin] = v2err;	}
  	}
  }

  if(centupdown == 0) {
  	if(ich==0) {	
      systFile << "v2" << species << "negdn" << "[" << ptbin << "] = " << v2 << ";\t v2err" << species << "negdn" << "[" << ptbin << "] = " << v2err << ";" << endl;
  	  if(species == "pion") {	v2pionnegdn[ptbin] = v2; v2errpionnegdn[ptbin] = v2err;	}
  	  if(species == "kaon") {	v2kaonnegdn[ptbin] = v2; v2errkaonnegdn[ptbin] = v2err;	}
  	  if(species == "prot") {	v2protnegdn[ptbin] = v2; v2errprotnegdn[ptbin] = v2err;	}
  	}
  	else if(ich==1) {
      systFile << "v2" << species << "posdn" << "[" << ptbin << "] = " << v2 << ";\t v2err" << species << "posdn" << "[" << ptbin << "] = " << v2err << ";" << endl;
  	  if(species == "pion") {	v2pionposdn[ptbin] = v2; v2errpionposdn[ptbin] = v2err;	}
  	  if(species == "kaon") {	v2kaonposdn[ptbin] = v2; v2errkaonposdn[ptbin] = v2err;	}
  	  if(species == "prot") {	v2protposdn[ptbin] = v2; v2errprotposdn[ptbin] = v2err;	}
  	}
  }
  
  //systFile.close();
  return;
}

float anaSystematics(float origVal, float newVal) {
  return fabs((origVal- newVal)/origVal);
}

TH2F *loadHist_centsys(int itof, int icent, int idphi, int ich)
{
  TH2F *h2load;
  char histgrab[128]; 
  //for(long iphi=0 ; iphi<=5 ; iphi++) {
  if(itof == 1 && centupdown ==0)	{	sprintf(histgrab,"h_m2tofWrawsysminus_cent%i_idphi%i_ich%i",icent+1,idphi,ich);   	}
  if(itof == 1 && centupdown ==1)	{	sprintf(histgrab,"h_m2tofWrawsysplus_cent%i_idphi%i_ich%i",icent+1,idphi,ich);   	}
  cout << "now loading: " << endl;
  cout << "\t" << histgrab << endl;
  h2load = (TH2F)infile.Get(histgrab);
  //}
  return h2load;
}