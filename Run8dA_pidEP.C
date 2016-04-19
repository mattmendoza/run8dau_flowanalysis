//#include "/phenix/hhj/mmendoza/Style.h"
#include "ana_idv2.h"
//#include "drawYield.C"
//#include "TString.h"
//#include "TH2F.h"
#include "Run8dA_pid.h"
#include "Style.h"
#include "threegaus.C"


float fBinWidthPion;  //define width for first bin of fits and hold width constant for all bins of dphi in same pT and centrality
float fBinWidthKaon;
float fBinWidthProt;

int isSumW2 = 1;  //plot histo as  sumw2

float M_PI = 3.1415926;
float ptrange[2] = {3.5,4.0}; //slice 2d hists to this range
float Nrebin = 8; //rebin N bins to one
int kUseLogLowBins = 0; //use log Y axis for sharp pion peaks at low pT, 0 = no, 1 = yes
int hipTpeakfinder = 0; //combines all dphi bins to find peak of histos.

int delPointPion = 0; //omit specific point from fit of v2, 0 means none, 1-6 are specific points
int delPointKaon = 0; 
int delPointProt = 0; 

int fixfBinWidthpion = 1; //fixes first bin width for consecutive bins
int fixfBinWidthkaon = 1; //fixes first bin width for consecutive bins
int fixfBinWidthprot = 1; //fixes first bin width for consecutive bins

int twogausfit = 1; //flag use of separate or combined gaussians
int whichsig = 2; //how many sigma for yield plots


float pionmeanrange[2] = {-0.05,0.1};
float kaonmeanrange[2] = {0.15,0.25};
float protmeanrange[2] = {0.75,1.1};

float pionwidthrange[2] = {0.05,0.1};
float kaonwidthrange[2] = {0.1,0.3};
float protwidthrange[2] = {0.1,0.15};

float pionfitrange[2] = {-0.2,0.1};
float kaonfitrange[2] = {0.2,0.6};
float protfitrange[2] = {0.6,1.4};

float combindedfitrange[2] = {-0.4,0.6};

int itof  	= 0;
int icent 	= 0;
int ich 	= 0;

float chkpionmean[6];    float chkpionwidth[6];    float chkpionyield[6]; 
float chkpionmeanerr[6]; float chkpionwidtherr[6]; float chkpionyielderr[6]; 

float chkkaonmean[6];    float chkkaonwidth[6];    float chkkaonyield[6]; 
float chkkaonmeanerr[6]; float chkkaonwidtherr[6]; float chkkaonyielderr[6]; 

float chkprotmean[6];    float chkprotwidth[6];    float chkprotyield[6]; 
float chkprotmeanerr[6]; float chkprotwidtherr[6]; float chkprotyielderr[6]; 

void Run8dA_pidEP() 
{


  runBySubBin(itof,icent,0,ptrange); //itof, icent, ich, ptrange[]
  //runBySubBin(0,icent,1,ptrange);

  
}

void findPeakCenter_hipT(TH2D * h2in, int itof, int icent, int ich, float ptrange[])  //function to add all dphi bins together and find bin center for higher pT bins
{
  int lobin=h2in->GetYaxis()->FindBin(ptrange[0]);
  int hibin=h2in->GetYaxis()->FindBin(ptrange[1]);
  //cout << lobin << "\t"  << hibin << endl;

  h2in->ProjectionX("ht",lobin,hibin);
  
  //cout << h->GetNbinsX() << endl;
  h = (TH1D *) ht->Rebin(Nrebin,"h");
  
  char histtitle[64];
  sprintf(histtitle,"m2, %g<pT<%g",ptrange[0],ptrange[1]);
  h->SetTitle(histtitle);
  hipTpeakfinder=2;
  c1 = fit_m2_2gaus(h,itof,icent,ich,0,ptrange);
  hipTpeakfinder=1;
  c1->DrawClonePad();
  char outfilestring[128];
  sprintf(outfilestring,"summed2dhists/m2_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);

  c1->SaveAs(outfilestring);
  

}


void runBySubBin(int itof, int icent, int ich, float ptrange[])  
//sub bin refers to charge, centrality, and tof bins, all dphi bins are run over in this step
{
  char outfilestring[128];
 
  for(int idphi=0 ; idphi<=5 ; idphi++) {
  	h2_m2tofvspt_v2_temp[itof][ich][icent][idphi] = loadHist(itof, icent, idphi, ich);
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
  	sprintf(outfilestring,"summed2dhists/m2vspt_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  	csum->SaveAs(outfilestring);
    findPeakCenter_hipT(h2_alldPhi, itof, icent, ich, ptrange);
  }


  ctemp = new TCanvas("ctemp","ctemp",2400,1600);
  ctemp->Divide(3,2);
  for(int idphi=0 ; idphi<=5 ; idphi++) {
    ctemp->cd(idphi+1);
    SlicetoEP(h2_m2tofvspt_v2_temp[itof][ich][icent][idphi], itof, icent, idphi, ich, ptrange);	 // input hist, itof, cent, idphi, charge

  }

  sprintf(outfilestring,"chkparams/yieldvsdphi_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  ctemp->SaveAs(outfilestring);
  //writeIndiv(itof,icent,ich);
  CheckFitsEP(itof, icent, ich, ptrange);

  return;
}

void CheckFitsEP(int itof, int icent, int ich, float ptrange[])
{
  float dphi[6]; 
  char titlestring[128];
  for(int idphi=0 ; idphi<=5 ; idphi++) {
    dphi[idphi] = idphi*M_PI / 6 + M_PI/12;
  }

  sprintf(titlestring,"chkparams/parbkup/v2Par_tof%i_cent%i_ch%i_pT-%g-%g.txt",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  cout << "Writing v2 parameters to: " << titlestring << endl;
  ofstream parfile(titlestring);

  TF1 *v2fit = new TF1("v2fit","[1]*(1+[0]*cos(2*x))",0,M_PI);
  v2fit->SetParLimits(0,0,1);

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
  sprintf(titlestring,"Fit Mean (GeV/c^{2}), itof%i, icent%i, ich%i, %g<pT<%g",itof,icent,ich,ptrange[0],ptrange[1]);
  drawFrame(0,-0.2,3.5,1.1,"d#phi","Mean (GeV/c^2)");
  drawTitle(.1,-.07,titlestring,1,12,.03,0);
  gr_pionmass->SetMarkerStyle(21);    gr_pionmass->SetMarkerColor(1);   gr_pionmass->Draw("P");
  gr_kaonmass->SetMarkerStyle(21);    gr_kaonmass->SetMarkerColor(2);   gr_kaonmass->Draw("P");
  gr_protmass->SetMarkerStyle(21);    gr_protmass->SetMarkerColor(3);   gr_protmass->Draw("P");

  sprintf(titlestring,"Fit Width (GeV/c^{2}), itof%i, icent%i, ich%i, %g<pT<%g",itof,icent,ich,ptrange[0],ptrange[1]);
  c_top->cd(2);  
  drawFrame(0,-0.2,3.5,0.5,"d#phi","width (GeV/c^2)");
  drawTitle(.1,-.07,titlestring,1,12,.03,0);
  gr_pionwidth->SetMarkerStyle(21);    gr_pionwidth->SetMarkerColor(1);   gr_pionwidth->Draw("P");
  gr_kaonwidth->SetMarkerStyle(21);    gr_kaonwidth->SetMarkerColor(2);   gr_kaonwidth->Draw("P");
  gr_protwidth->SetMarkerStyle(21);    gr_protwidth->SetMarkerColor(3);   gr_protwidth->Draw("P");

  sprintf(titlestring,"chkparams/fitMassWidth_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  c_top->SaveAs(titlestring);

  c_yield = new TCanvas("c_yield","c_yield",2400,800);
  c_yield->Divide(3,1);
  c_yield->cd(1);
  float min = TMath::MinElement(6,gr_pionyield->GetY());
  float max = TMath::MaxElement(6,gr_pionyield->GetY());
  float delta = max-min;
  drawFrame(-1*M_PI/4,min-delta,5*M_PI/4,max+delta,"d#phi","Raw Yield");
  sprintf(titlestring,"Pion Yield (GeV/c^{2}), itof%i, icent%i, ich%i, %g<pT<%g",itof,icent,ich,ptrange[0],ptrange[1]);
  drawTitle(.1,-.07,titlestring,1,12,.03,0);
  if(delPointPion>0) gr_pionyield->RemovePoint(delPointPion-1);
  gr_pionyield->SetMarkerStyle(21);   gr_pionyield->SetMarkerColor(1);    gr_pionyield->Draw("P");
  gr_pionyield->Fit("v2fit","Q","",0.05,M_PI-0.05);
  parfile << "pion v2: " << v2fit->GetParameter(0) << " error: " << v2fit->GetParError(0) << endl;

  
  c_yield->cd(2);
  float min = TMath::MinElement(6,gr_kaonyield->GetY());
  float max = TMath::MaxElement(6,gr_kaonyield->GetY());
  float delta = max-min;
  drawFrame(-1*M_PI/4,min-delta,5*M_PI/4,max+delta,"d#phi","Raw Yield");
  sprintf(titlestring,"Kaon Yield (GeV/c^{2}), itof%i, icent%i, ich%i, %g<pT<%g",itof,icent,ich,ptrange[0],ptrange[1]);
  drawTitle(.1,-.07,titlestring,1,12,.03,0);
  if(delPointKaon>0) gr_kaonyield->RemovePoint(delPointKaon-1);
  gr_kaonyield->SetMarkerStyle(21);   gr_kaonyield->SetMarkerColor(2);    gr_kaonyield->Draw("P");
  gr_kaonyield->Fit("v2fit","Q","",0.05,M_PI-0.05);
  parfile << "kaon v2: " << v2fit->GetParameter(0) << " error: " << v2fit->GetParError(0) << endl;

  c_yield->cd(3);
  float min = TMath::MinElement(6,gr_protyield->GetY());
  float max = TMath::MaxElement(6,gr_protyield->GetY());
  float delta = max-min;
  drawFrame(-1*M_PI/4,min-delta,5*M_PI/4,max+delta,"d#phi","Raw Yield");
  sprintf(titlestring,"Proton Yield (GeV/c^{2}), itof%i, icent%i, ich%i, %g<pT<%g",itof,icent,ich,ptrange[0],ptrange[1]);
  drawTitle(.1,-.07,titlestring,1,12,.03,0);
  if(delPointProt>0) gr_protyield->RemovePoint(delPointProt-1);
  gr_protyield->SetMarkerStyle(21);   gr_protyield->SetMarkerColor(3);    gr_protyield->Draw("P");
  gr_protyield->Fit("v2fit","Q","",0.05,M_PI-0.05);
  parfile << "prot v2: " << v2fit->GetParameter(0) << " error: " << v2fit->GetParError(0) << endl;

  sprintf(titlestring,"chkparams/fitYield_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  c_yield->SaveAs(titlestring);


  TCanvas *c_check = new TCanvas("c_check","c_check",3000,2000);
  c_check->Divide(1,2);
  c_check->Draw();
  c_check->cd(1); c_top->DrawClonePad();
  c_check->cd(2); c_yield->DrawClonePad();
  c_check->Update();

  sprintf(titlestring,"chkparams/fitParams_tof%i_cent%i_ch%i_pT-%g-%g.jpg",itof,icent,ich,ptrange[0]*10,ptrange[1]*10);
  c_check->SaveAs(titlestring);

  parfile.close();


}

TH2F *loadHist(int itof, int icent, int idphi, int ich)
{
  TH2F *h2load;
  char histgrab[128]; 
  //for(long iphi=0 ; iphi<=5 ; iphi++) {
  if(itof == 0)	{	sprintf(histgrab,"h_m2tofEraw_cent%i_idphi%i_ich%i",icent+1,idphi,ich);   	} //icent+1 because hists saved in previous step 1 - 5 
  if(itof == 1)	{	sprintf(histgrab,"h_m2tofWraw_cent%i_idphi%i_ich%i",icent+1,idphi,ich);   	}
  if(itof == 2)	{	sprintf(histgrab,"h_m2tofnoacc_cent%i_idphi%i_ich%i",icent+1,idphi,ich);  	}
  if(itof == 3)	{	sprintf(histgrab,"h_m2tofwacc_cent%i_idphi%i_ich%i",icent+1,idphi,ich);   	}
  cout << "now loading: " << endl;
  cout << "\t" << histgrab << endl;
  h2load = (TH2F)infile.Get(histgrab);
  //}
  return h2load;
}


TCanvas * SlicetoEP(TH2F *h2in,int itof, int cent,int idphi, int charge, float ptrange[])
{
  TF1 *f_pi;
  TF1 *f_k;
  TF1 *f_pr;
  TF1 *f_all;
  //cPS = new TCanvas("cPS","cPS",800,800);
  char gifname[64];



  setupIndiv(itof,cent,charge,idphi);
  char histtitle[64];
  cout << "fitting on pT range: ";

  int lobin=h2in->GetYaxis()->FindBin(ptrange[0]);
  int hibin=h2in->GetYaxis()->FindBin(ptrange[1]);
  //cout << lobin << "\t"  << hibin << endl;

  h2in->ProjectionX("ht",lobin,hibin);
  
  //cout << h->GetNbinsX() << endl;
  h = (TH1D *) ht->Rebin(Nrebin,"h");

  sprintf(histtitle,"m2, %g<pT<%g",ptrange[0],ptrange[1]);
  h->SetTitle(histtitle);
  c1 = fit_m2_threepeak(h,itof,cent,charge,idphi,ptrange);

  c1->DrawClonePad();


  sprintf(gifname,"PSgifs/indiv/%s.jpg",h2in->GetName());
  c1->SaveAs(gifname);
 
  ctemp->cd(idphi+1);
  c1->DrawClonePad();
  //delete c;
  //delete c1;
  //delete cPS;
  
  //cout << endl;

  return c1;
}

TCanvas * fit_m2_2gaus(TH1D * h,int whichtof, int centbin, int charge, int idphi, float ptrange[])
{
  //ofstream fm2pion(fPar+whichtoflabel[whichtof]+"_"+fPart[0]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin]+".dat");
  //ofstream fm2kaon(fPar+whichtoflabel[whichtof]+"_"+fPart[1]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin]+".dat");
  //ofstream fm2proton(fPar+whichtoflabel[whichtof]+"_"+fPart[2]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin]+".dat");
  int iptbin = 0;
  
  (TCanvas*)c_h->cd();
  //c_h->Clear();
    
  float par[6];
  
  
  //h->Draw();
  h->Sumw2();
  h->SetAxisRange(-0.5,2.0);
  fun_pion->SetLineColor(kCyan+1);
  fun_kaon->SetLineColor(kCyan+2);
  fun_proton->SetLineColor(kCyan+3);

  c_h->SetLogy(kUseLogLowBins); 

  h->Draw(); gPad->Update();
  float pionhpeak = findpeak(h,-0.1,0.1);
  float kaonhpeak = findpeak(h,0.2,0.3);
  float prothpeak = findpeak(h,0.7,1.2);

  
  //cout << "pion peak: " << pionhpeak << "\t kaon peak: " << kaonhpeak << "\t prot peak:" << prothpeak << endl;
     
   //Trial fit for pion
  fun1->SetRange(pionfitrange[0],pionfitrange[1]);
  fun1->SetParameters(1,0.02,0.02);
  fun1->SetParameters(1,pionhpeak,0.02);
  fun1->SetParLimits(1,pionhpeak-0.01,pionhpeak+0.02); //mean
  fun1->SetParLimits(2,pionwidthrange[0],pionwidthrange[1]);  //width

  h->Fit("fun1","RQ0N","same");
  
    //Trial fit for kaon
  //fun2->SetRange(0.2,0.3);
  fun2->SetRange(kaonhpeak-0.02,kaonhpeak+0.04);
  fun2->SetRange(kaonfitrange[0],kaonfitrange[1]);
  fun2->SetParameters(1,kaonhpeak,0.05);
  //fun2->SetParLimits(1,kaonhpeak-0.05,kaonhpeak+0.05);
  fun2->SetParLimits(1,kaonmeanrange[0],kaonmeanrange[1]);
  if(ptrange[0]>=3) fun2->SetParLimits(1,0.19,0.21);
  fun2->SetParLimits(2,kaonwidthrange[0],kaonwidthrange[1]);
  if(fixfBinWidthkaon==1) fun2->SetParLimits(2,fBinWidthKaon*0.95,fBinWidthKaon*1.05);


    h->Fit("fun2","RQ0N","same");

        //Trial fit for proton
    fun3->SetRange(0.72,1.1);
    fun3->SetParameters(1,prothpeak,0.02);
    fun3->SetParLimits(2,protwidthrange[0],protwidthrange[1]);
    h->Fit("fun3","RQN+");

    //**********************************
    //Set initial parameters for the pion
    //**********************************
    for(int ipar=0; ipar<3; ipar++) {
      par[ipar] = fun1->GetParameter(ipar);
      fun1->SetParameter(ipar, par[ipar]); 
    }
    if(idphi > 0) {  fun1->SetParLimits(2,fBinWidthPion,fBinWidthPion);  } 
    
    fun1->SetRange(par[1]-2.0*par[2], par[1]+2.0*par[2]); 
      //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~initial pion fit, cent: " 
      //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
    h->Fit("fun1","RQN","same");  

    //**********************************
    //Set initial parameters for the kaon   
    //**********************************
    for(int ipar=0; ipar<3; ipar++) {
      par[ipar] = fun2->GetParameter(ipar);
      fun2->SetParameter(ipar, par[ipar]); 
    }  
    if(idphi == 0) {  fun2->SetParLimits(2,kaonwidthrange[0],kaonwidthrange[1]);  } 
    if(idphi > 0 && fixfBinWidthkaon == 1) {  fun2->SetParLimits(2,fBinWidthKaon,fBinWidthKaon);  } 

    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~initial kaon fit, cent: " 
  //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
    h->Fit("fun2","RQN","same"); 

    //**********************************
    //Set initial parameters for the proton   
    //**********************************
    for(int ipar=0; ipar<3; ipar++) {
      par[ipar] = fun3->GetParameter(ipar);
      fun3->SetParameter(ipar, par[ipar]); }
    //fun3->SetRange(par[1]-2.0*par[2], par[1]+2.0*par[2]);
    fun3->SetRange(prothpeak-0.1, prothpeak+0.1); 
    fun3->SetRange(protfitrange[0], protfitrange[1]); 
    //if(ptrange[0]>=3) { fun3->SetRange(0.8, par[1]+1.5*par[2]); }
    if(ptrange[0]>=4.5) fun3->SetRange(protfitrange[0], protfitrange[1]); 
    //if(iptbin>=7) fun3->SetRange(prothpeak-0.07, prothpeak+0.2); 
    fun3->SetParLimits(1,protmeanrange[0],protmeanrange[1]);

    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~initial proton fit, cent: " 
  //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
    if(idphi > 0) {  fun3->SetParLimits(2,protwidthrange[0],protwidthrange[1]);  } 
    if(idphi > 0 && fixfBinWidthprot == 1) {  fun3->SetParLimits(2,fBinWidthProt*0.9,fBinWidthProt*1.15);  } 
    //else fun3->SetParLimits(2,protwidthrange[0],protwidthrange[1]); 
    
    h->Fit("fun3","RQN+","same");   //unquiet this later

    //**********************************
    //Set parameters in individual pion, kaon, and proton functions
    //**********************************


    for(int ipar=0 ; ipar<3 ; ipar++) {
      fun_pion->SetParameter(ipar,   fun1->GetParameter(ipar));
      fun_pion->SetParError(ipar,    fun1->GetParError(ipar));
      fun_kaon->SetParameter(ipar,   fun2->GetParameter(ipar));
      fun_kaon->SetParError(ipar,    fun2->GetParError(ipar));
      fun_proton->SetParameter(ipar, fun3->GetParameter(ipar));
      fun_proton->SetParError(ipar,  fun3->GetParError(ipar)); }

    //cout << fun_proton->GetParameter(0) << endl;
          
    if(idphi==0) {
      fBinWidthPion = fun1->GetParameter(2);
      fBinWidthKaon = fun2->GetParameter(2);
      fBinWidthProt = fun3->GetParameter(2);
    }
    //**********************************
    // Refit pion+kaon once they merge 
    //**********************************
    if(twogausfit == 1) {//18
      //Trial fit for pion+kaon
      fun->SetParameter(0,fun1->GetParameter(0));
      fun->SetParameter(1,fun1->GetParameter(1)); //mean
      fun->SetParameter(2,fun1->GetParameter(2)); //sigma 
      fun->SetParameter(3,fun2->GetParameter(0));
      fun->SetParameter(4,fun2->GetParameter(1)); 
      fun->SetParameter(5,fun2->GetParameter(2));
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~initial merged pi/k fit, cent: " 
    //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
      //h->Fit("fun","RQ","same"); //unquiet this later
   
      //**********************************
      //Set initial parameters for pion+kaon   
      //**********************************
    
    for(int ipar=0; ipar<6; ipar++){
    par[ipar] = fun->GetParameter(ipar);
    fun->SetParameter(ipar, par[ipar]);
    if(iptbin < 5 && ipar==1) { fun->SetParLimits(ipar, 0.01,0.09); }//pion mean
    if(ptrange[0] >=3.5 && ipar==1) { fun->SetParLimits(ipar, pionmeanrange[0],pionmeanrange[1]); }//pion mean
    
    if(ipar==2) { fun->SetParLimits(ipar, pionwidthrange[0], pionwidthrange[1]); }//pion width
    if(ipar==2 && fixfBinWidthpion == 1) { fun->SetParLimits(ipar, fBinWidthPion*0.98, fBinWidthPion*1.05); }//pion width
    
    if(ipar==4) { fun->SetParLimits(ipar,  kaonhpeak-0.2, kaonhpeak+0.1); }//kaon mean
    if(ipar==4 && ptrange[0]>=2) { fun->SetParLimits(ipar,  kaonmeanrange[0], kaonmeanrange[1]); }//kaon mean
  
    if(ipar==5) { fun->SetParLimits(ipar, kaonwidthrange[0],kaonwidthrange[1]); }  //kaon width
    if(ipar==5 && fixfBinWidthkaon == 1) { fun->SetParLimits(ipar, fBinWidthKaon*0.95,fBinWidthKaon*1.05); }  //kaon width
    //if(iptbin>18) {
    //  if(ipar==5) { fun->SetParLimits(ipar, -0.02, +0.02); } }
    }
    
    //fun->SetRange(par[1]-2.0*par[2], par[4]+2.0*(par[2]+par[5]));
    fun->SetRange(-0.4,0.5);
    fun->SetRange(combindedfitrange[0],combindedfitrange[1]);
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~final merged pi/k fit, cent: " 
    //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
    h->Fit("fun","RQN+","same"); //unquiet this later
    h->Fit("fun","RQN+","same"); //unquiet this later
    h->Fit("fun","RQN+","same"); //unquiet this later
  
      //**********************************
      //Set parameters in individual pion and kaon functions
      //**********************************
    for(int ipar=0 ; ipar<3 ; ipar++) {
      fun_pion->SetParameter(ipar, fun->GetParameter(ipar));
      fun_pion->SetParError(ipar, fun->GetParError(ipar));
      fun_kaon->SetParameter(ipar, fun->GetParameter(ipar+3));
      fun_kaon->SetParError(ipar, fun->GetParError(ipar+3)); }
      fun_kaon->SetParameter(2, fun->GetParameter(2)+fun->GetParameter(5));
      fun_kaon->SetParError(2,  fun->GetParError(2)+fun->GetParError(5)); 
      
    }//End conditional: iptbin>18


    //**********************************
    //This is the end of the fitting, just plotting now ...
    //**********************************

    setFunctionRanges(2.5);//sigma
    
    //drawFrame(gPad->GetFrame()->GetX1(),gPad->GetFrame()->GetY1(),gPad->GetFrame()->GetX2(),gPad->GetFrame()->GetY2(),"m^{2} [GeV^{2}/c^{4}]","Raw Counts");
    //char gifname[100];
    //sprintf(gifname,"%s%s%s%s%s%s%2.2f%s%2.2f","m2",whichtoflabel[whichtof].Data(),"_",chargelabel[charge].Data(),"_",centbinlabel[centbin].Data(),(iptbin)*0.1,"~",(iptbin+1)*0.1);
    //h->Draw("same");

    fun_pion->Draw("same");
    fun_kaon->Draw("same");
    fun->Draw("same");
    fun_proton->Draw("same");
    char text[100];
    sprintf(text,"%s%4.3f#pm%4.3f%s","m^{2}_{#pi}(fit) = ",fun_pion->GetParameter(1),fun_pion->GetParError(1), " GeV^{2}/c^{4}");
    drawLabel(text,fun_pion->GetLineColor(),0.03,0.65,0.075);
    sprintf(text,"%s%4.3f#pm%4.3f%s","#sigma(m^{2}_{#pi}(fit)) = ",fun_pion->GetParameter(2),fun_pion->GetParError(2), " GeV^{2}/c^{4}");
    drawLabel(text,fun_pion->GetLineColor(),0.03,0.70,0.125);

    sprintf(text,"%s%4.3f#pm%4.3f%s","m^{2}_{k}(fit) = ",fun_kaon->GetParameter(1), fun_kaon->GetParError(1), " GeV^{2}/c^{4}");
    drawLabel(text,fun_kaon->GetLineColor(),0.03,0.65,0.185);
    sprintf(text,"%s%4.3f#pm%4.3f%s","#sigma(m^{2}_{k}(fit)) = ",fun_kaon->GetParameter(2), fun_kaon->GetParError(2), " GeV^{2}/c^{4}");
    drawLabel(text,fun_kaon->GetLineColor(),0.03,0.70,0.235);

    sprintf(text,"%s%4.3f#pm%4.3f%s","m^{2}_{p}(fit) = ",fun_proton->GetParameter(1), fun_proton->GetParError(1), " GeV^{2}/c^{4}");
    drawLabel(text,fun_proton->GetLineColor(),0.03,0.65,0.295+0.5*(iptbin>5&&iptbin<9)*kUseLogLowBins);
    sprintf(text,"%s%4.3f#pm%4.3f%s","#sigma(m^{2}_{p}(fit)) = ",fun_proton->GetParameter(2), fun_proton->GetParError(2), " GeV^{2}/c^{4}");
    drawLabel(text,fun_proton->GetLineColor(),0.03,0.70,0.345+0.5*(iptbin>5&&iptbin<9)*kUseLogLowBins);
    
    drawLabel(TString("rootbin=")+long(iptbin),1,0.03,0.975,0.35,32);
    if(hipTpeakfinder == 2 ) return c_h;
    //**********************************
    // Spit out the parameters
    //**********************************
    float pionyield[4]; float pionyielderr[4];
    float kaonyield[4]; float kaonyielderr[4];
    float protyield[4]; float protyielderr[4];

    for(int isig=0 ; isig<3 ; isig++) {
      //Individual Pions
      gPionYield[whichtof][charge][isig][centbin][idphi]->SetPoint(gPionYield[whichtof][charge][isig][centbin][idphi]->GetN(),pt,fun_pion->GetParameter(0)/h->GetBinWidth(0));
      gPionYield[whichtof][charge][isig][centbin][idphi]->SetPointError(gPionYield[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,fun_pion->GetParError(0)/h->GetBinWidth(0));
      double bc = h->Integral(h->FindBin(fun_pion->GetParameter(1)-fun_pion->GetParameter(2)*(1+isig)),
            h->FindBin(fun_pion->GetParameter(1)+fun_pion->GetParameter(2)*(1+isig)));
      gPionYieldBC[whichtof][charge][isig][centbin][idphi]->SetPoint(gPionYieldBC[whichtof][charge][isig][centbin][idphi]->GetN(),pt,bc);
      gPionYieldBC[whichtof][charge][isig][centbin][idphi]->SetPointError(gPionYieldBC[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,sqrt(bc));

      pionyield[isig+1] = bc;                                          pionyielderr[isig+1] = sqrt(bc);
      pionyield[0] = fun_pion->GetParameter(0)/h->GetBinWidth(0);      pionyielderr[0] = fun_pion->GetParError(0)/h->GetBinWidth(0);

      
      //Individual Kaons
      gKaonYield[whichtof][charge][isig][centbin][idphi]->SetPoint(gKaonYield[whichtof][charge][isig][centbin][idphi]->GetN(),pt,fun_kaon->GetParameter(0)/h->GetBinWidth(0));
      gKaonYield[whichtof][charge][isig][centbin][idphi]->SetPointError(gKaonYield[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,fun_kaon->GetParError(0)/h->GetBinWidth(0));
      bc = h->Integral(h->FindBin(fun_kaon->GetParameter(1)-fun_kaon->GetParameter(2)*(1+isig)),
           h->FindBin(fun_kaon->GetParameter(1)+fun_kaon->GetParameter(2)*(1+isig)));
      gKaonYieldBC[whichtof][charge][isig][centbin][idphi]->SetPoint(gKaonYieldBC[whichtof][charge][isig][centbin][idphi]->GetN(),pt,bc);
      gKaonYieldBC[whichtof][charge][isig][centbin][idphi]->SetPointError(gKaonYieldBC[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,sqrt(bc));
      
      kaonyield[isig+1] = bc;                                          kaonyielderr[isig+1] = sqrt(bc);
      kaonyield[0] = fun_kaon->GetParameter(0)/h->GetBinWidth(0);      kaonyielderr[0] = fun_kaon->GetParError(0)/h->GetBinWidth(0);
      

      //Individual Kaons
      gProtYield[whichtof][charge][isig][centbin][idphi]->SetPoint(gProtYield[whichtof][charge][isig][centbin][idphi]->GetN(),pt,fun_proton->GetParameter(0)/h->GetBinWidth(0));
      gProtYield[whichtof][charge][isig][centbin][idphi]->SetPointError(gProtYield[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,fun_proton->GetParError(0)/h->GetBinWidth(0));
      bc = h->Integral(h->FindBin(fun_proton->GetParameter(1)-fun_proton->GetParameter(2)*(1+isig)),
           h->FindBin(fun_proton->GetParameter(1)+fun_proton->GetParameter(2)*(1+isig))); 
      gProtYieldBC[whichtof][charge][isig][centbin][idphi]->SetPoint(gProtYieldBC[whichtof][charge][isig][centbin][idphi]->GetN(),pt,bc);
      gProtYieldBC[whichtof][charge][isig][centbin][idphi]->SetPointError(gProtYieldBC[whichtof][charge][isig][centbin][idphi]->GetN()-1,0,sqrt(bc));

      protyield[isig+1] = bc;                                          protyielderr[isig+1] = sqrt(bc);
      protyield[0] = fun_proton->GetParameter(0)/h->GetBinWidth(0);    protyielderr[0] = fun_proton->GetParError(0)/h->GetBinWidth(0);
  

    char sigbin[8];
    sprintf(sigbin,"%d",isig);
     
      //ofstream fpionyield(fPar+whichtoflabel[whichtof]+"_"+fPart[0]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin][idphi]+"_sig_"+sigbin+"yields.dat");
      //ofstream fkaonyield(fPar+whichtoflabel[whichtof]+"_"+fPart[1]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin][idphi]+"_sig_"+sigbin+"yields.dat");
      //ofstream fprotyield(fPar+whichtoflabel[whichtof]+"_"+fPart[2]+"_"+chargelabel[charge]+"_cent_"+centbinlabel[centbin][idphi]+"_sig_"+sigbin+"yields.dat");

    }

  
    gPionMass[whichtof][charge][centbin][idphi]->SetPoint(gPionMass[whichtof][charge][centbin][idphi]->GetN(),pt,fun_pion->GetParameter(1));
    gPionMass[whichtof][charge][centbin][idphi]->SetPointError(gPionMass[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_pion->GetParError(1));
    gPionWidth[whichtof][charge][centbin][idphi]->SetPoint(gPionWidth[whichtof][charge][centbin][idphi]->GetN(),pt,fun_pion->GetParameter(2));
    gPionWidth[whichtof][charge][centbin][idphi]->SetPointError(gPionWidth[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_pion->GetParError(2));
    
    gKaonMass[whichtof][charge][centbin][idphi]->SetPoint(gKaonMass[whichtof][charge][centbin][idphi]->GetN(),pt,fun_kaon->GetParameter(1));
    gKaonMass[whichtof][charge][centbin][idphi]->SetPointError(gKaonMass[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_kaon->GetParError(1));
    gKaonWidth[whichtof][charge][centbin][idphi]->SetPoint(gKaonWidth[whichtof][charge][centbin][idphi]->GetN(),pt,fun_kaon->GetParameter(2));
    gKaonWidth[whichtof][charge][centbin][idphi]->SetPointError(gKaonWidth[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_kaon->GetParError(2));
    
    gProtMass[whichtof][charge][centbin][idphi]->SetPoint(gProtMass[whichtof][charge][centbin][idphi]->GetN(),pt,fun_proton->GetParameter(1));
    gProtMass[whichtof][charge][centbin][idphi]->SetPointError(gProtMass[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_proton->GetParError(1));
    gProtWidth[whichtof][charge][centbin][idphi]->SetPoint(gProtWidth[whichtof][charge][centbin][idphi]->GetN(),pt,fun_proton->GetParameter(2));
    gProtWidth[whichtof][charge][centbin][idphi]->SetPointError(gProtWidth[whichtof][charge][centbin][idphi]->GetN()-1,0,fun_proton->GetParError(2));

    if(twogausfit == 0) {

      float pionmean = fun1->GetParameter(1);   float pionmeanerr = fun1->GetParError(1);
      float pionwidth = fun1->GetParameter(2);  float pionwidtherr = fun1->GetParError(2);
      float kaonmean = fun2->GetParameter(1);   float kaonmeanerr = fun2->GetParError(1);
      float kaonwidth = fun2->GetParameter(2);  float kaonwidtherr = fun2->GetParError(2);
    }
    else {
      float pionmean = fun->GetParameter(1);  float pionmeanerr = fun->GetParError(1);
      float pionwidth = fun->GetParameter(2); float pionwidtherr = fun->GetParError(2);
      float kaonmean = fun->GetParameter(4);  float kaonmeanerr = fun->GetParError(4);
      float kaonwidth = fun->GetParameter(5); float kaonwidtherr = fun->GetParError(5);
    }
    float protmean =  fun3->GetParameter(1);  float protmeanerr = fun3->GetParError(1);
    float protwidth = fun3->GetParameter(2);  float protwidtherr = fun3->GetParError(2);

    float pionParams[12];
    float kaonParams[12];
    float protParams[12];
    float ptrange[2];

    //ptrange[0] = ptmin;
    //ptrange[1] = ptmax;

    pionParams[0] = pionmean;      pionParams[1] = pionmeanerr;
    pionParams[2] = pionwidth;     pionParams[3] = pionwidtherr;
    pionParams[4] = pionyield[0];  pionParams[5] = pionyielderr[0]; // yield from bin sums
    pionParams[6] = pionyield[1];  pionParams[7] = pionyielderr[1]; // yield 1 sigma
    pionParams[8] = pionyield[2];  pionParams[9] = pionyielderr[2]; // yield 2 sigma
    pionParams[10]= pionyield[3];  pionParams[11]= pionyielderr[3]; // yield 3 sigma

    kaonParams[0] = kaonmean;      kaonParams[1] = kaonmeanerr;
    kaonParams[2] = kaonwidth;     kaonParams[3] = kaonwidtherr;
    kaonParams[4] = kaonyield[0];  kaonParams[5] = kaonyielderr[0]; // yield from bin sums
    kaonParams[6] = kaonyield[1];  kaonParams[7] = kaonyielderr[1]; // yield 1 sigma
    kaonParams[8] = kaonyield[2];  kaonParams[9] = kaonyielderr[2]; // yield 2 sigma
    kaonParams[10]= kaonyield[3];  kaonParams[11]= kaonyielderr[3]; // yield 3 sigma

    protParams[0] = protmean;      protParams[1] = protmeanerr;
    protParams[2] = protwidth;     protParams[3] = protwidtherr;
    protParams[4] = protyield[0];  protParams[5] = protyielderr[0]; // yield from bin sums
    protParams[6] = protyield[1];  protParams[7] = protyielderr[1]; // yield 1 sigma
    protParams[8] = protyield[2];  protParams[9] = protyielderr[2]; // yield 2 sigma
    protParams[10]= protyield[3];  protParams[11]= protyielderr[3]; // yield 3 sigma

    saveParameters(whichtof,centbin, charge, idphi, ptrange, pionParams, kaonParams, protParams, iptbin);

    pionmeanset[iptbin]  = pionmean;    pionmeanseterr[iptbin]  = pionmeanerr;
    pionwidthset[iptbin] = pionwidth;   pionwidthseterr[iptbin] = pionwidtherr;

    kaonmeanset[iptbin]  = kaonmean;    kaonmeanseterr[iptbin]  = kaonmeanerr;
    kaonwidthset[iptbin] = kaonwidth;   kaonwidthseterr[iptbin] = kaonwidtherr;

    protmeanset[iptbin]  = protmean;    protmeanseterr[iptbin]  = protmeanerr;
    protwidthset[iptbin] = protwidth;   protwidthseterr[iptbin] = protwidtherr;

    chkpionmean[idphi]  = pionmean;    chkpionmeanerr[idphi]  = pionmeanerr;
    chkpionwidth[idphi] = pionwidth;   chkpionwidtherr[idphi] = pionwidtherr;
    chkpionyield[idphi] = pionyield[whichsig];   chkpionyielderr[idphi] = pionyielderr[whichsig];

    chkkaonmean[idphi]  = kaonmean;    chkkaonmeanerr[idphi]  = kaonmeanerr;
    chkkaonwidth[idphi] = kaonwidth;   chkkaonwidtherr[idphi] = kaonwidtherr;
    chkkaonyield[idphi] = kaonyield[whichsig];   chkkaonyielderr[idphi] = kaonyielderr[whichsig];

    chkprotmean[idphi]  = protmean;    chkprotmeanerr[idphi]  = protmeanerr;
    chkprotwidth[idphi] = protwidth;   chkprotwidtherr[idphi] = protwidtherr;
    chkprotyield[idphi] = protyield[whichsig];   chkprotyielderr[idphi] = protyielderr[whichsig];
    //fm2pion.close();
  //fm2kaon.close();
  //fm2proton.close();

  //write();

    return c_h;
}

void saveParameters(int whichtof, int centbin, int charge, int idphi, float ptrange[], float pionParams[], float kaonParams[], float protParams[],int iptbin) {
  //char filepath[64];
  char filename[128];
  ofstream parfile;
  //sprintf(filepath,"par/%s/%s/",whichtoflabel[whichtof],centbinrelabel[centbin+1]);
  
  if(isCoarseBin==0) {	sprintf(filename, "fitParameters_%s%s_idphi%i", whichtoflabel[whichtof], centbinrelabel[centbin+1], idphi);	}
  if(isCoarseBin==1) {	sprintf(filename, "fitParametersCoarse_%s%s_idphi%i", whichtoflabel[whichtof], centbinrelabel[centbin+1], idphi);	}
  //cout << "\t" << fPar << whichtoflabel[whichtof] << "/"<< centbinrelabel[centbin+1] << "/fitParameters_" << whichtoflabel[whichtof] << centbinrelabel[centbin+1] << "_idphi" << (int)idphi << ".dat" << endl;
  
  
  if(ptrange[0] <= 0.5) { 
    if(isCoarseBin==0) {	ofstream parfile(fPar+whichtoflabel[whichtof]+"/fitParameters_"+whichtoflabel[whichtof]+centbinrelabel[centbin+1]+dphilabel[idphi]+"_"+chargelabel[charge]+".dat");	}
    if(isCoarseBin==1) {	ofstream parfile(fPar+whichtoflabel[whichtof]+"/fitParametersCoarse_"+whichtoflabel[whichtof]+centbinrelabel[centbin+1]+dphilabel[idphi]+"_"+chargelabel[charge]+".dat");	}
  }
  else {
  	//fexists.close();
    if(isCoarseBin==0) {	ofstream parfile(fPar+whichtoflabel[whichtof]+"/fitParameters_"+whichtoflabel[whichtof]+centbinrelabel[centbin+1]+dphilabel[idphi]+"_"+chargelabel[charge]+".dat", ios::app);	}
    if(isCoarseBin==1) {	ofstream parfile(fPar+whichtoflabel[whichtof]+"/fitParametersCoarse_"+whichtoflabel[whichtof]+centbinrelabel[centbin+1]+dphilabel[idphi]+"_"+chargelabel[charge]+".dat", ios::app);	}
  	parfile << endl << endl; 
  }
  

  //cout << "\t writing to: " << whichtoflabel[whichtof] << centbinrelabel[centbin+1] << ".dat" << endl;
  //parfile.open(filename);
  parfile << "ptlo[" << iptbin <<"]=" << ptrange[0] << ";\t" << "pthi[" << iptbin <<"]=" << ptrange[1] << endl; 

  if(charge == 0) {
    parfile << "PionNegMean[" << iptbin <<"]="      << pionParams[0]  << ";\t\t" << "PionNegMeanErr[" << iptbin <<"]="      << pionParams[1] << endl;
    parfile << "PionNegWidth[" << iptbin <<"]="     << pionParams[2]  << ";\t\t" << "PionNegWidthErr[" << iptbin <<"]="     << pionParams[3] << endl;
    parfile << "PionNegYieldHist[" << iptbin <<"]=" << pionParams[4]  << ";\t\t" << "PionNegYieldErrHist[" << iptbin <<"]=" << pionParams[5] << endl;
    parfile << "PionNegYield1sig[" << iptbin <<"]=" << pionParams[6]  << ";\t\t" << "PionNegYieldErr1sig[" << iptbin <<"]=" << pionParams[7] << endl;
    parfile << "PionNegYield2sig[" << iptbin <<"]=" << pionParams[8]  << ";\t\t" << "PionNegYieldErr2sig[" << iptbin <<"]=" << pionParams[9] << endl;
    parfile << "PionNegYield3sig[" << iptbin <<"]=" << pionParams[10] << ";\t\t" << "PionNegYieldErr3sig[" << iptbin <<"]=" << pionParams[11] << endl;

    parfile << "KaonNegMean[" << iptbin <<"]="      << kaonParams[0]  << ";\t\t" << "KaonNegMeanErr[" << iptbin <<"]="      << kaonParams[1] << endl;
    parfile << "KaonNegWidth[" << iptbin <<"]="     << kaonParams[2]  << ";\t\t" << "KaonNegWidthErr[" << iptbin <<"]="     << kaonParams[3] << endl;
    parfile << "KaonNegYieldHist[" << iptbin <<"]=" << kaonParams[4]  << ";\t\t" << "KaonNegYieldErrHist[" << iptbin <<"]=" << kaonParams[5] << endl;
    parfile << "KaonNegYield1sig[" << iptbin <<"]=" << kaonParams[6]  << ";\t\t" << "KaonNegYieldErr1sig[" << iptbin <<"]=" << kaonParams[7] << endl;
    parfile << "KaonNegYield2sig[" << iptbin <<"]=" << kaonParams[8]  << ";\t\t" << "KaonNegYieldErr2sig[" << iptbin <<"]=" << kaonParams[9] << endl;
    parfile << "KaonNegYield3sig[" << iptbin <<"]=" << kaonParams[10] << ";\t\t" << "KaonNegYieldErr3sig[" << iptbin <<"]=" << kaonParams[11] << endl;

    parfile << "ProtNegMean[" << iptbin <<"]="      << protParams[0]  << ";\t\t" << "protNegMeanErr[" << iptbin <<"]="      << protParams[1] << endl;
    parfile << "ProtNegWidth[" << iptbin <<"]="     << protParams[2]  << ";\t\t" << "protNegWidthErr[" << iptbin <<"]="     << protParams[3] << endl;
    parfile << "ProtNegYieldHist[" << iptbin <<"]=" << protParams[4]  << ";\t\t" << "protNegYieldErrHist[" << iptbin <<"]=" << protParams[5] << endl;
    parfile << "ProtNegYield1sig[" << iptbin <<"]=" << protParams[6]  << ";\t\t" << "protNegYieldErr1sig[" << iptbin <<"]=" << protParams[7] << endl;
    parfile << "ProtNegYield2sig[" << iptbin <<"]=" << protParams[8]  << ";\t\t" << "protNegYieldErr2sig[" << iptbin <<"]=" << protParams[9] << endl;
    parfile << "ProtNegYield3sig[" << iptbin <<"]=" << protParams[10] << ";\t\t" << "protNegYieldErr3sig[" << iptbin <<"]=" << protParams[11] << endl;
  }

  if(charge == 1) {
    parfile << "PionPosMean[" << iptbin <<"]="      << pionParams[0]  << ";\t\t" << "PionPosMeanErr[" << iptbin <<"]="      << pionParams[1] << endl;
    parfile << "PionPosWidth[" << iptbin <<"]="     << pionParams[2]  << ";\t\t" << "PionPosWidthErr[" << iptbin <<"]="     << pionParams[3] << endl;
    parfile << "PionPosYieldHist[" << iptbin <<"]=" << pionParams[4]  << ";\t\t" << "PionPosYieldErrHist[" << iptbin <<"]=" << pionParams[5] << endl;
    parfile << "PionPosYield1sig[" << iptbin <<"]=" << pionParams[6]  << ";\t\t" << "PionPosYieldErr1sig[" << iptbin <<"]=" << pionParams[7] << endl;
    parfile << "PionPosYield2sig[" << iptbin <<"]=" << pionParams[8]  << ";\t\t" << "PionPosYieldErr2sig[" << iptbin <<"]=" << pionParams[9] << endl;
    parfile << "PionPosYield3sig[" << iptbin <<"]=" << pionParams[10] << ";\t\t" << "PionPosYieldErr3sig[" << iptbin <<"]=" << pionParams[11] << endl;

    parfile << "KaonPosMean[" << iptbin <<"]="      << kaonParams[0]  << ";\t\t" << "KaonPosMeanErr[" << iptbin <<"]="      << kaonParams[1] << endl;
    parfile << "KaonPosWidth[" << iptbin <<"]="     << kaonParams[2]  << ";\t\t" << "KaonPosWidthErr[" << iptbin <<"]="     << kaonParams[3] << endl;
    parfile << "KaonPosYieldHist[" << iptbin <<"]=" << kaonParams[4]  << ";\t\t" << "KaonPosYieldErrHist[" << iptbin <<"]=" << kaonParams[5] << endl;
    parfile << "KaonPosYield1sig[" << iptbin <<"]=" << kaonParams[6]  << ";\t\t" << "KaonPosYieldErr1sig[" << iptbin <<"]=" << kaonParams[7] << endl;
    parfile << "KaonPosYield2sig[" << iptbin <<"]=" << kaonParams[8]  << ";\t\t" << "KaonPosYieldErr2sig[" << iptbin <<"]=" << kaonParams[9] << endl;
    parfile << "KaonPosYield3sig[" << iptbin <<"]=" << kaonParams[10] << ";\t\t" << "KaonPosYieldErr3sig[" << iptbin <<"]=" << kaonParams[11] << endl;

    parfile << "ProtPosMean[" << iptbin <<"]="      << protParams[0]  << ";\t\t" << "protPosMeanErr[" << iptbin <<"]="      << protParams[1] << endl;
    parfile << "ProtPosWidth[" << iptbin <<"]="     << protParams[2]  << ";\t\t" << "protPosWidthErr[" << iptbin <<"]="     << protParams[3] << endl;
    parfile << "ProtPosYieldHist[" << iptbin <<"]=" << protParams[4]  << ";\t\t" << "protPosYieldErrHist[" << iptbin <<"]=" << protParams[5] << endl;
    parfile << "ProtPosYield1sig[" << iptbin <<"]=" << protParams[6]  << ";\t\t" << "protPosYieldErr1sig[" << iptbin <<"]=" << protParams[7] << endl;
    parfile << "ProtPosYield2sig[" << iptbin <<"]=" << protParams[8]  << ";\t\t" << "protPosYieldErr2sig[" << iptbin <<"]=" << protParams[9] << endl;
    parfile << "ProtPosYield3sig[" << iptbin <<"]=" << protParams[10] << ";\t\t" << "protPosYieldErr3sig[" << iptbin <<"]=" << protParams[11] << endl;
  }
  parfile.close();

}


float findpeak(TH1D* inputhist, float lowbound, float highbound) {
//c1 = new TCanvas("c1","",0,0,800,500);
  /*
  float xlow = inputhist->FindBin(lowbound);
  float xhigh= inputhist->FindBin(highbound);  
  
  cout << "xlow: " << xlow << "\t xhigh: " << xhigh  << endl;
  
  inputhist->GetXaxis()->SetRange(xlow,xhigh);
  */
  
  inputhist->GetXaxis()->SetRangeUser(lowbound,highbound);
  float peakloc = inputhist->GetBinCenter(inputhist->GetMaximumBin());
  
  inputhist->GetXaxis()->UnZoom();
  
  return peakloc;
  
}


void setupIndiv(int itof, int centbin, int ich, int idphi)
{
  //setStyleWide();

  cout << "setting up (tof, cent, charge, dphi):" << "(" << itof << "," << centbin << "," << ich << "," << idphi << ")" << endl; 
  Canvas->Draw();
  Canvas->Update();
  Canvas->cd();

  TString g = "g";
  
  fun_pion->SetLineColor(kCyan+1);
  fun_kaon->SetLineColor(kCyan+2);
  fun_proton->SetLineColor(kCyan+3); 
  
  for(long isig=0 ; isig<3 ; isig++) {

	gPionYield[itof][ich][isig][centbin][idphi] = new TGraphErrors();
	gPionYield[itof][ich][isig][centbin][idphi]->SetName(g+"PionYield_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(Long_t)(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+(Long_t)idphi);
	gPionYield[itof][ich][isig][centbin][idphi]->SetMarkerStyle(20+4*ich);
	gPionYield[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));
	gPionYieldBC[itof][ich][isig][centbin][idphi] = new TGraphErrors();
	gPionYieldBC[itof][ich][isig][centbin][idphi]->SetName(g+"PionYieldBC_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(Long_t)(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+(Long_t)idphi);
	gPionYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerStyle(7);
	gPionYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));

	gKaonYield[itof][ich][isig][centbin][idphi] = new TGraphErrors();
	gKaonYield[itof][ich][isig][centbin][idphi]->SetName(g+"KaonYield_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(Long_t)(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+(Long_t)idphi);
	gKaonYield[itof][ich][isig][centbin][idphi]->SetMarkerStyle(21+4*ich);
	gKaonYield[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));
	gKaonYieldBC[itof][ich][isig][centbin][idphi] = new TGraphErrors();
	gKaonYieldBC[itof][ich][isig][centbin][idphi]->SetName(g+"KaonYieldBC_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(Long_t)(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+(Long_t)idphi);
	gKaonYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerStyle(7);
	gKaonYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));

	gProtYield[itof][ich][isig][centbin][idphi] = new TGraphErrors();
	gProtYield[itof][ich][isig][centbin][idphi]->SetName(g+"ProtYield_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(Long_t)(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+(Long_t)idphi);
	gProtYield[itof][ich][isig][centbin][idphi]->SetMarkerStyle(22+4*ich);
	gProtYield[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));
	gProtYieldBC[itof][ich][isig][centbin][idphi] = new TGraphErrors();
	gProtYieldBC[itof][ich][isig][centbin][idphi]->SetName(g+"ProtYieldBC_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(Long_t)(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+(Long_t)idphi);
	gProtYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerStyle(7);
	gProtYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));

	  
	gPionMass[itof][ich][centbin][idphi] = new TGraphErrors();
	gPionMass[itof][ich][centbin][idphi]->SetName(g+"PionMass_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_dphi"+(Long_t)idphi);
	gPionMass[itof][ich][centbin][idphi]->SetMarkerStyle(20+4*ich);
	gPionMass[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
	gPionWidth[itof][ich][centbin][idphi] = new TGraphErrors();
	gPionWidth[itof][ich][centbin][idphi]->SetName(g+"PionWidth_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_cent"+centbinlabel[centbin]+"_dphi"+(Long_t)idphi);
	gPionWidth[itof][ich][centbin][idphi]->SetMarkerStyle(20+4*ich);
	gPionWidth[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
	
	gKaonMass[itof][ich][centbin][idphi] = new TGraphErrors();
	gKaonMass[itof][ich][centbin][idphi]->SetName(g+"KaonMass_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_dphi"+(Long_t)idphi);
	gKaonMass[itof][ich][centbin][idphi]->SetMarkerStyle(21+4*ich);
	gKaonMass[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
	gKaonWidth[itof][ich][centbin][idphi] = new TGraphErrors();
	gKaonWidth[itof][ich][centbin][idphi]->SetName(g+"KaonWidth_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_cent"+centbinlabel[centbin]+"_dphi"+(Long_t)idphi);
	gKaonWidth[itof][ich][centbin][idphi]->SetMarkerStyle(21+4*ich);
	gKaonWidth[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
	
	gProtMass[itof][ich][centbin][idphi] = new TGraphErrors();
	gProtMass[itof][ich][centbin][idphi]->SetName(g+"ProtMass_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_dphi"+(Long_t)idphi);
	gProtMass[itof][ich][centbin][idphi]->SetMarkerStyle(22+4*ich);
	gProtMass[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
	gProtWidth[itof][ich][centbin][idphi] = new TGraphErrors(); 
	gProtWidth[itof][ich][centbin][idphi]->SetName(g+"ProtWidth_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_cent"+centbinlabel[centbin]+"_dphi"+(Long_t)idphi);
	gProtWidth[itof][ich][centbin][idphi]->SetMarkerStyle(22+4*ich);
	gProtWidth[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));  
  }
}



void writeIndiv(int itof, int centbin, int ich)
{
  cout << endl;  
  cout << "~~~~~~~~~~~~~~~now write output~~~~~~~~~~~~~~~~" << endl;  
  cout << endl;  
  //fOutFile.cd();
  char writestring[128];
  TFile *fout;
  if(isCoarseBin==0) {	sprintf(writestring,"rootout/fittingoutput_itof%i_cent%i_ich%i.root",itof,centbin,ich);	}
  if(isCoarseBin==1) {	sprintf(writestring,"rootout/fittingoutputCoarse_itof%i_cent%i_ich%i.root",itof,centbin,ich);	}
  fout = new TFile(writestring,"RECREATE");
  fout->cd();
  for(long idphi=0 ; idphi<6 ; idphi++) {
    for(long isig=0 ; isig<3 ; isig++) {
	    //cout << isig << "\t" << idphi << endl;
		gPionYield[itof][ich][isig][centbin][idphi]->Write();
	  gPionYieldBC[itof][ich][isig][centbin][idphi]->Write();
	    
		gKaonYield[itof][ich][isig][centbin][idphi]->Write();
		gKaonYieldBC[itof][ich][isig][centbin][idphi]->Write();
		    
		gProtYield[itof][ich][isig][centbin][idphi]->Write();
		gProtYieldBC[itof][ich][isig][centbin][idphi]->Write();

		

	  //gProtYieldBC[itof][ich][isig][centbin][idphi]->Draw();
	  //c2->Update();
	  //sprintf(writestring,"checkfits/tof%i/charge%i/ProtYieldBC_sig%i_cent%i_dphi%i.jpg",itof,ich,isig,centbin,idphi);
		//c2->SaveAs(writestring);
  
    }  //isigma 

    gPionMass[itof][ich][centbin][idphi]->Write();
    gPionWidth[itof][ich][centbin][idphi]->Write();
    
    gKaonMass[itof][ich][centbin][idphi]->Write();
    gKaonWidth[itof][ich][centbin][idphi]->Write();
    
    gProtMass[itof][ich][centbin][idphi]->Write();
    gProtWidth[itof][ich][centbin][idphi]->Write();


  }

  fout->Close();
}



  
void drawLabel(char *title, int color, double size, double x, double y, int pos=12)
{
  double x0 = gPad->GetFrame()->GetX1();
  double x1 = gPad->GetFrame()->GetX2();
  double y0 = gPad->GetFrame()->GetY1();
  double y1 = gPad->GetFrame()->GetY2();
  
  double dx = x1-x0;
  double dy = y1-y0;
  
  double xtitle=0,ytitle=0;
    
  if(gPad->GetLogy()==0) {
    xtitle = x0+x*dx;
    ytitle = y1-y*dy; }
  else {
    xtitle = x0+x*dx;
    y0 = pow(10.,y0);
    y1 = pow(10.,y1);
    ytitle = pow(10,log10(y1)-log10(y1/y0)*y); }
  
  //newTLatex(xtitle,ytitle,title,color,pos,size,0);
}

void setFunctionRanges(double nsigma=2.5)
{
  fun_pion->SetRange(fun_pion->GetParameter(1)-nsigma*fun_pion->GetParameter(2),
		     fun_pion->GetParameter(1)+nsigma*fun_pion->GetParameter(2));
  
  fun_kaon->SetRange(fun_kaon->GetParameter(1)-nsigma*fun_kaon->GetParameter(2),
		     fun_kaon->GetParameter(1)+nsigma*fun_kaon->GetParameter(2));
  
  fun_proton->SetRange(fun_proton->GetParameter(1)-nsigma*fun_proton->GetParameter(2),
		       fun_proton->GetParameter(1)+nsigma*fun_proton->GetParameter(2));
}


void write()
{
  cout << "now write output." << endl;  
  
  //fOutFile.cd();
  char writestring[128];
  TFile *fout[4][2][5][6];
  for(long itof=0 ; itof<4 ; itof++) {
    for(long ich=0 ; ich<2 ; ich++) {
      for(long isig=0 ; isig<3 ; isig++) {
        for(long centbin=0 ; centbin<=4 ; centbin++) {
        for(long idphi=0 ; idphi<=5 ; idphi++) {

          sprintf(writestring,"rootout/fittingoutput_itof%i_cent%i_idphi%i_ich%i.root",itof,centbin,idphi,ich);
            fout[itof][ich][centbin][idphi] = new TFile(writestring,"RECREATE");
            fout[itof][ich][centbin][idphi]->cd();
            gPionYield[itof][ich][isig][centbin][idphi]->Write();
            gPionYieldBC[itof][ich][isig][centbin][idphi]->Write();
            
            gKaonYield[itof][ich][isig][centbin][idphi]->Write();
            gKaonYieldBC[itof][ich][isig][centbin][idphi]->Write();
            
            gProtYield[itof][ich][isig][centbin][idphi]->Write();
            gProtYieldBC[itof][ich][isig][centbin][idphi]->Write();

            gPionMass[itof][ich][centbin][idphi]->Write();
            gPionWidth[itof][ich][centbin][idphi]->Write();
            
            gKaonMass[itof][ich][centbin][idphi]->Write();
            gKaonWidth[itof][ich][centbin][idphi]->Write();
            
            gProtMass[itof][ich][centbin][idphi]->Write();
            gProtWidth[itof][ich][centbin][idphi]->Write();
            fout[itof][ich][centbin][idphi]->Close();
          } 
        } 
      }
    }
  }
}


void setup()
{
  //setStyleWide();
  Canvas = new TCanvas("Canvas","",0,0,800,500);
  Canvas->Draw();
  Canvas->Update();
  Canvas->cd();

  TString g = "g";
  
  fun_pion->SetLineColor(kCyan+1);
  fun_kaon->SetLineColor(kCyan+2);
  fun_proton->SetLineColor(kCyan+3); 
  
  for(long itof=0 ; itof<4 ; itof++) {
    for(long ich=0 ; ich<2 ; ich++) {
      for(long isig=0 ; isig<3 ; isig++) {
    for(int centbin=0; centbin<=4; centbin++) {
          for(long idphi=0 ; idphi<6 ; idphi++) {
            gPionYield[itof][ich][isig][centbin][idphi] = new TGraphErrors();
            gPionYield[itof][ich][isig][centbin][idphi]->SetName(g+"PionYield_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gPionYield[itof][ich][isig][centbin][idphi]->SetMarkerStyle(20+4*ich);
            gPionYield[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));
            gPionYieldBC[itof][ich][isig][centbin][idphi] = new TGraphErrors();
            gPionYieldBC[itof][ich][isig][centbin][idphi]->SetName(g+"PionYieldBC_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gPionYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerStyle(7);
            gPionYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));

            gKaonYield[itof][ich][isig][centbin][idphi] = new TGraphErrors();
            gKaonYield[itof][ich][isig][centbin][idphi]->SetName(g+"KaonYield_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gKaonYield[itof][ich][isig][centbin][idphi]->SetMarkerStyle(21+4*ich);
            gKaonYield[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));
            gKaonYieldBC[itof][ich][isig][centbin][idphi] = new TGraphErrors();
            gKaonYieldBC[itof][ich][isig][centbin][idphi]->SetName(g+"KaonYieldBC_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gKaonYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerStyle(7);
            gKaonYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));

            gProtYield[itof][ich][isig][centbin][idphi] = new TGraphErrors();
            gProtYield[itof][ich][isig][centbin][idphi]->SetName(g+"ProtYield_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gProtYield[itof][ich][isig][centbin][idphi]->SetMarkerStyle(22+4*ich);
            gProtYield[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));
            gProtYieldBC[itof][ich][isig][centbin][idphi] = new TGraphErrors();
            gProtYieldBC[itof][ich][isig][centbin][idphi]->SetName(g+"ProtYieldBC_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_nsig"+(isig+1)+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gProtYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerStyle(7);
            gProtYieldBC[itof][ich][isig][centbin][idphi]->SetMarkerColor((itof==0?2:4));

              
            gPionMass[itof][ich][centbin][idphi] = new TGraphErrors();
            gPionMass[itof][ich][centbin][idphi]->SetName(g+"PionMass_"+whichtoflabel[itof]+"_"+chargelabel[ich]);
            gPionMass[itof][ich][centbin][idphi]->SetMarkerStyle(20+4*ich);
            gPionMass[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
            gPionWidth[itof][ich][centbin][idphi] = new TGraphErrors();
            gPionWidth[itof][ich][centbin][idphi]->SetName(g+"PionWidth_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gPionWidth[itof][ich][centbin][idphi]->SetMarkerStyle(20+4*ich);
            gPionWidth[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));

            gKaonMass[itof][ich][centbin][idphi] = new TGraphErrors();
            gKaonMass[itof][ich][centbin][idphi]->SetName(g+"KaonMass_"+whichtoflabel[itof]+"_"+chargelabel[ich]);
            gKaonMass[itof][ich][centbin][idphi]->SetMarkerStyle(21+4*ich);
            gKaonMass[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
            gKaonWidth[itof][ich][centbin][idphi] = new TGraphErrors();
            gKaonWidth[itof][ich][centbin][idphi]->SetName(g+"KaonWidth_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gKaonWidth[itof][ich][centbin][idphi]->SetMarkerStyle(21+4*ich);
            gKaonWidth[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));

            gProtMass[itof][ich][centbin][idphi] = new TGraphErrors();
            gProtMass[itof][ich][centbin][idphi]->SetName(g+"ProtMass_"+whichtoflabel[itof]+"_"+chargelabel[ich]);
            gProtMass[itof][ich][centbin][idphi]->SetMarkerStyle(22+4*ich);
            gProtMass[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
            gProtWidth[itof][ich][centbin][idphi] = new TGraphErrors(); 
            gProtWidth[itof][ich][centbin][idphi]->SetName(g+"ProtWidth_"+whichtoflabel[itof]+"_"+chargelabel[ich]+"_cent"+centbinlabel[centbin]+"_dphi"+idphi);
            gProtWidth[itof][ich][centbin][idphi]->SetMarkerStyle(22+4*ich);
            gProtWidth[itof][ich][centbin][idphi]->SetMarkerColor((itof==0?2:4));
          }  
        } 
      }
    }
  }
}


TF1 * fit_m2pi(TH1D *h)
{
  //h->Sumw2();
    h->SetAxisRange(-0.5,2.0);
    int iptbin=3;
    //if(iptbin<=8)     { Canvas->SetLogy(kUseLogLowBins); }
    //else if(iptbin>8)   { Canvas->SetLogy(0); }
    
    //h->Draw(); gPad->Update();

  TH1D *hclone = (TH1D *)h->Clone("hclone");

  float pionhpeak = findpeak(hclone,-0.1,0.1);
  
  cout << "pion peak: " << pionhpeak << "\t";
    
   

    //Trial fit for pion
    fun1->SetRange(-0.05,0.05);
    fun1->SetParameters(1,0.02,0.02);
  //fun1->SetParameters(1,h->GetBinCenter(h->GetMaximumBin()),0.01);
  //cout << "maximum:                                " << h->GetBinCenter(h->GetMaximumBin()) << " or " << findpeak(h,0.2,0.3) << endl;
  //fun1->SetParLimits(1,-0.03,0.03);
  //fun1->SetParLimits(2,0.007,0.05);
  if(iptbin<8) {
    fun1->SetParameters(1,pionhpeak,0.02);
    fun1->SetParLimits(1,-0.03,0.09);
    fun1->SetParLimits(2,0.009,0.1);
  }
  
    h->Fit("fun1","RQ0N","same");

    return fun1;
}

TF1 * fit_m2k(TH1D * h)
{
    //h->Sumw2();
    h->SetAxisRange(-0.5,2.0);
    int iptbin=3;
    //if(iptbin<=8)     { Canvas->SetLogy(kUseLogLowBins); }
    //else if(iptbin>8)   { Canvas->SetLogy(0); }
    
    //h->Draw(); gPad->Update();

  TH1D *hclone = (TH1D *)h->Clone("hclone");
  float kaonhpeak = findpeak(hclone,0.2,0.4);

  cout << "kaon peak: " << kaonhpeak << "\t";
    //Trial fit for kaon
    fun2->SetRange(0.15,0.3);
    //fun2->SetParameters(1,0.25,0.02);
  fun2->SetParameters(1,kaonhpeak,0.02);
  fun2->SetParLimits(2,0.01,0.02);
  /*
  if(iptbin<5) {
    //fun2->SetParLimits(1,0.2,0.3);
    fun2->SetParameters(1,findpeak(hclone,0.2,0.3),0.02);
    fun2->SetParLimits(2,0.001,0.03);
  }
  if(iptbin<8) {
    //fun2->SetParLimits(1,0.2,0.3);
    fun2->SetParLimits(2,0.001,0.04);
  }
  if(iptbin>8) {
    //fun2->SetParLimits(1,0.2,0.3);
    fun2->SetParLimits(2,0.001,0.06);
  }
  */
    h->Fit("fun2","RQ0N","same");

    return fun2; 

}

TF1 * fit_m2prot(TH1D * h)
{
  float prothpeak = findpeak(hclone,0.5,1.5);
  
  cout << "prot peak:" << prothpeak << endl;

  //Trial fit for proton
  fun3->SetRange(0.72,1.3);
  fun3->SetParameters(1,prothpeak,0.02);
  fun3->SetParLimits(2,0.01,0.04);
  h->Fit("fun3","RQN+");
  
  return fun3;

}

void plotWidth(int itof)
{
      //save jpgs of the fit params for quick checking
  cout << endl;  
  c2 = new TCanvas("c2","c2",500,500);
  float ptmax = 7;
  //fOutFile.cd();
  char writestring[128];
  for(int centbin=0;centbin<=4;centbin++)
  {
    for(long idphi=0 ; idphi<6 ; idphi++) 
    {
      for(int ich=0; ich<=1; ich++)
      {
      drawFrame(0,0,ptmax,0.3,"p_{T} Bin","fit width");
      gPionWidth[itof][ich][centbin][idphi]->Draw("P");
      c2->Update();
        //sprintf(writestring,"checkfits/tof%i/charge%i/PionWidth_cent%i_dphi%i.jpg",itof,ich,isig,centbin,idphi);
      //c2->SaveAs(writestring);
      gKaonWidth[itof][ich][centbin][idphi]->Draw("P");
      c2->Update();
      //sprintf(writestring,"checkfits/tof%i/charge%i/KaonWidth_cent%i_dphi%i.jpg",itof,ich,isig,centbin,idphi);
      //c2->SaveAs(writestring);
      gProtWidth[itof][ich][centbin][idphi]->Draw("P");
      c2->Update();
      }
    }
  }
  sprintf(writestring,"checkfits/tof%i/charge%i/fitWidth_cent%i_dphi%i.jpg",itof,ich,centbin,idphi);
  c2->SaveAs(writestring);
  c2->Clear();


}

void plotYield(int itof)
{
  c2 = new TCanvas("c2","c2",500,500);
  TGraphErrors* tempPionY,tempKaonY,tempProtY;
  
  for(int ich=0;ich<=1;ich++)
  {
    for(int centbin=0;centbin<=4;centbin++)
    {
      for(int idphi=0;idphi<=5;idphi++)
      {
        c2->cd();
        drawFrame(0,0,ptmax,10E7,"p_{T} Bin","Raw Pion Yield");
        gPionYieldBC[itof][ich][isig][centbin][idphi]->Draw("P");
        c2->Update();
        c2->SetLogy();
        c2->Update();
        sprintf(writestring,"checkfits/tof%i/charge%i/PionYield_sig%i_cent%i_dphi%i.jpg",itof,ich,isig,centbin,idphi);
        c2->SaveAs(writestring);
        c2->Clear();

        //gPionYieldBC[itof][ich][isig][centbin][idphi]->Draw();
        //c2->Update();
        //sprintf(writestring,"checkfits/tof%i/charge%i/PionYieldBC_sig%i_cent%i_dphi%i.jpg",itof,ich,isig,centbin,idphi);
        //c2->SaveAs(writestring);

        c2->cd();
        //c2->SetLogy();
        drawFrame(0,0,ptmax,10E7,"p_{T} Bin","Raw Kaon Yield");
        gKaonYieldBC[itof][ich][isig][centbin][idphi]->Draw("P");
        c2->Update();
        sprintf(writestring,"checkfits/tof%i/charge%i/KaonYield_sig%i_cent%i_dphi%i.jpg",itof,ich,isig,centbin,idphi);
        c2->SaveAs(writestring);
        c2->Clear();

        //gKaonYieldBC[itof][ich][isig][centbin][idphi]->Draw();
        //c2->Update();
        //sprintf(writestring,"checkfits/tof%i/charge%i/KaonYieldBC_sig%i_cent%i_dphi%i.jpg",itof,ich,isig,centbin,idphi);
        //c2->SaveAs(writestring);
          
        c2->cd();
        //c2->SetLogy();
        drawFrame(0,0,ptmax,10E7,"p_{T} Bin","Raw Proton Yield");
        gProtYieldBC[itof][ich][isig][centbin][idphi]->Draw("P");
        c2->Update();
        sprintf(writestring,"checkfits/tof%i/charge%i/ProtYield_sig%i_cent%i_dphi%i.jpg",itof,ich,isig,centbin,idphi);
        c2->SaveAs(writestring);
        c2->Clear();
      }
    }
  }

}

void setupfits()
{
  for(int itof = 0; itof<=4 ; itof++) {
   for(int ich = 0; ich<=1 ; ich++) {
   
   
    f_pionsigma[itof][ich]= new TF1("f_pionsigma","[0]+[1]/x+[2]/(x*x)+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.4,20);//put to 20 to use nsigma for pions, actualy valid up to 4
    f_kaonsigma[itof][ich]= new TF1("f_kaonsigma","[0]+[1]/x+[2]/(x*x)+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.6,6);
    f_protsigma[itof][ich]= new TF1("f_protsigma","[0]+[1]/x+[2]/(x*x)+[3]*exp(sqrt(x))+[4]*sqrt(x)",0.4,20);
	  
    f_pionsigma[itof][ich]->SetLineColor(2*itof+2);
    f_kaonsigma[itof][ich]->SetLineColor(2*itof+2);
    f_protsigma[itof][ich]->SetLineColor(2*itof+2);
	
	f_pionsigma[itof][ich]->SetLineWidth(1);
    f_kaonsigma[itof][ich]->SetLineWidth(1);
    f_protsigma[itof][ich]->SetLineWidth(1);
   
   }
  }
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

