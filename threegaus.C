//#include "/phenix/hhj/mmendoza/Style.h"
#include "ana_idv2.h"
//#include "drawYield.C"
//#include "TString.h"
//#include "TH2F.h"
#include "Run8dA_pid.h"
#include "Style.h"

//TF1 *funmerge =new TF1("funmerge","[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)+[3]/([2]+[5])*exp(-0.5*pow((x-[4])/([2]+[5]),2))/sqrt(6.283)+(1-[0]/[2]-[3]/([2]+[5]))*exp(-0.5*pow((x-[7])/[8],2))/sqrt(6.283)",-0.4,1.5);// pion+kaon
//third frac (1-[0]/[2]-[3]/([2]+[5]))
TCanvas * fit_m2_threepeak(TH1D * h,int whichtof, int centbin, int charge, int idphi, float ptrange[])
{
  
  TF1 *Rgaus = new TF1("Rgaus","[0]/[2]*exp(-0.5*pow((x-[1])/[2],2))/sqrt(6.283)",-1,2);
  TF1 *funmerge =new TF1("funmerge","fun1+fun2+fun3",-0.4,1.4);
  int iptbin = 0;
  
  (TCanvas*)c_h->cd();
  //c_h->Clear();
    
  float par[6];
  
  //h->Draw();
  h->Sumw2(isSumW2);
  h->SetMarkerStyle(21);
  h->SetMarkerColor(15);
  h->SetMarkerSize(m2histMarkerSize);
  h->SetAxisRange(-0.5,2.0);

  fun_pion->SetParLimits(1,pionmeanrange[0], pionmeanrange[1]);
  fun_pion->SetParLimits(2,pionwidthrange[0],pionwidthrange[1]);

  fun_kaon->SetParLimits(1,kaonmeanrange[0], kaonmeanrange[1]);
  fun_kaon->SetParLimits(2,kaonwidthrange[0],kaonwidthrange[1]);

  fun_proton->SetParLimits(1,protmeanrange[0], protmeanrange[1]);
  fun_proton->SetParLimits(2,protwidthrange[0],protwidthrange[1]);



  fun_pion->SetLineColor(2);
  fun_kaon->SetLineColor(3);
  fun_proton->SetLineColor(4);

  c_h->SetLogy(kUseLogLowBins); 

  h->Draw(); gPad->Update();
  float pionhpeak = findpeak(h,-0.1,0.1);
  float kaonhpeak = findpeak(h,0.2,0.3);
  float prothpeak = findpeak(h,0.7,1.2);

  //cout << "pion peak: " << pionhpeak << "\t kaon peak: " << kaonhpeak << "\t prot peak:" << prothpeak << endl;
     
   //Trial fit for pion
  fun1->SetRange(pionfitrange[0],pionfitrange[1]);
  fun1->SetParameters(1,0.02,0.1);
  fun1->SetParLimits(1,pionmeanrange[0],pionmeanrange[1]); //mean
  fun1->SetParLimits(2,pionwidthrange[0],pionwidthrange[1]);  //width

  h->Fit("fun1","RQN0");
  
  //Trial fit for kaon
  fun2->SetRange(kaonfitrange[0],kaonfitrange[1]);
  fun2->SetParameters(1,0.25,0.3);
  fun2->SetParLimits(1,kaonmeanrange[0],kaonmeanrange[1]);
  fun2->SetParLimits(2,kaonwidthrange[0],kaonwidthrange[1]);

  h->Fit("fun2","RQN0");

  //Trial fit for proton
  fun3->SetRange(protfitrange[0],protfitrange[1]);
  fun3->SetParameters(1,0.8,0.6);
  fun3->SetParLimits(1,protmeanrange[0],protmeanrange[1]);
  fun3->SetParLimits(2,protwidthrange[0],protwidthrange[1]);
  h->Fit("fun3","RQN");

    //**********************************
    //Set initial parameters for the pion
    //**********************************
    for(int ipar=0; ipar<3; ipar++) {
      par[ipar] = fun1->GetParameter(ipar);
      fun1->SetParameter(ipar, par[ipar]); 
    }
    //fun1->SetRange(par[1]-2.0*par[2], par[1]+2.0*par[2]); 
    h->Fit("fun1","RQN0+");  

    //**********************************
    //Set initial parameters for the kaon   
    //**********************************
    for(int ipar=0; ipar<3; ipar++) {
      par[ipar] = fun2->GetParameter(ipar);
      fun2->SetParameter(ipar, par[ipar]); 
    }  
    fun2->SetParLimits(1,kaonmeanrange[0],kaonmeanrange[1]);
    fun2->SetParLimits(2,kaonwidthrange[0],kaonwidthrange[1]);
    h->Fit("fun2","RQN+"); 

    //**********************************
    //Set initial parameters for the proton   
    //**********************************
    for(int ipar=0; ipar<3; ipar++) {
      par[ipar] = fun3->GetParameter(ipar);
      fun3->SetParameter(ipar, par[ipar]); 
    }
    fun3->SetRange(protfitrange[0], protfitrange[1]); 
    fun3->SetParLimits(1,protmeanrange[0],protmeanrange[1]);
    fun3->SetParLimits(2,protwidthrange[0],protwidthrange[1]); 
    
    h->Fit("fun3","RQN+");   //unquiet this later

    //**********************************
    //Set parameters in individual pion, kaon, and proton functions
    //**********************************


    for(int ipar=0 ; ipar<3 ; ipar++) {
      fun_pion->SetParameter(ipar,   fun1->GetParameter(ipar));
      fun_pion->SetParError(ipar,    fun1->GetParError(ipar));
      fun_kaon->SetParameter(ipar,   fun2->GetParameter(ipar));
      fun_kaon->SetParError(ipar,    fun2->GetParError(ipar));
      fun_proton->SetParameter(ipar, fun3->GetParameter(ipar));
      fun_proton->SetParError(ipar,  fun3->GetParError(ipar)); 
    }

    //**********************************
    // Refit pion+kaon once they merge 
    //**********************************

    fun->SetParameter(0,fun1->GetParameter(0));
    fun->SetParameter(1,fun1->GetParameter(1)); //mean
    fun->SetParameter(2,fun1->GetParameter(2)); //sigma 
    fun->SetParameter(3,fun2->GetParameter(0));
    fun->SetParameter(4,fun2->GetParameter(1)); //mean
    fun->SetParameter(5,fun2->GetParameter(2)); // sigma
    h->Fit("fun","RQN+"); //unquiet this later

      //**********************************
      //Set initial parameters for pion+kaon   
      //**********************************
    for(int ipar=0; ipar<6; ipar++){
      //par[ipar] = fun->GetParameter(ipar);
      //fun->SetParameter(ipar, par[ipar]);
      if(ipar==1) { fun->FixParameter(ipar, fun1->GetParameter(1)); }//pion mean
      //if(ipar==1) { fun->SetParLimits(ipar, pionmeanrange[0],pionmeanrange[1]); }//pion width
      //if(ipar==2) { fun->SetParLimits(ipar, 0,0.2); }//pion width
      if(ipar==2) { fun->SetParLimits(ipar, pionwidthrange[0],pionwidthrange[1]); }//pion width
      if(ipar==3) { fun->SetParLimits(ipar, fun1->GetParameter(0)/4,fun1->GetParameter(0)/2); }//kaon height
      if(ipar==4) { fun->FixParameter(ipar, fun2->GetParameter(1)); }//kaon mean
      //if(ipar==4) { fun->SetParLimits(ipar, kaonmeanrange[0],kaonmeanrange[1]); }  //kaon width
      //if(ipar==5) { fun->FixParameter(ipar, fun1->GetParameter(2)); }  //kaon width
      if(ipar==5) { fun->SetParLimits(ipar, fun1->GetParameter(2)/5,fun1->GetParameter(2)*(2/3)); }  //kaon width
    } //par loop

    fun->SetRange(-0.4,0.7);
    fun->SetLineColor(1);
    fun->SetLineWidth(4);
    fun->SetLineStyle(9);
    h->Fit("fun","RQN+"); //unquiet this later

    if(drawDiagnosticFits == 1) fun->Draw("same");

    for(int ipar=0 ; ipar<3 ; ipar++) {
      fun_pion->SetParameter(ipar,  fun->GetParameter(ipar));
      fun_pion->SetParError(ipar,   fun->GetParError(ipar));
      fun_kaon->SetParameter(ipar,  fun->GetParameter(ipar+3));
      fun_kaon->SetParError(ipar,   fun->GetParError(ipar+3)); 
      fun_kaon->SetParameter(2,     fun->GetParameter(5)+fun->GetParameter(2));
      fun_kaon->SetParError(2,      fun->GetParError(5)+fun->GetParError(2)); 
      fun_proton->SetParameter(ipar,fun3->GetParameter(ipar));
      fun_proton->SetParError(ipar, fun3->GetParError(ipar)); 
    }

    funbulk->SetRange(-0.4,1.3);
    
    //funbulk->SetParameter(0,fun1->GetParameter(0));
    funbulk->SetParameter(1, findpeak(h,-0.2,0.4)); //mean
    //funbulk->SetParameter(4,fun3->GetParameter(1)); //mean
    //funbulk->SetParameter(5,fun3->GetParameter(2)); //sigma
    //h->Fit("funbulk","RQN+");
    //funbulk->FixParameter(2, fun->GetParameter(5)+fun->GetParameter(2)); //sigma
    //funbulk->FixParameter(3, fun3->GetParameter(0));
    funbulk->FixParameter(4, fun3->GetParameter(1)); //mean
    //funbulk->SetParLimits(4,fun3->GetParameter(1)*(1-protmeanvariance),fun3->GetParameter(1)*(1+protmeanvariance)); //mean
    //funbulk->SetParLimits(4, fun3->GetParameter(1)*(1-protmeanvariance),fun3->GetParameter(1)*(1+protmeanvariance)); //prot mean
    funbulk->FixParameter(5, fun3->GetParameter(2));  //prot width
    //funbulk->SetParLimits(5, fun3->GetParameter(2)*(1-protwidthvariance),fun3->GetParameter(2)*(1+protwidthvariance));  //prot width
    
    funbulk->SetLineWidth(4);
    funbulk->SetLineStyle(3);
    funbulk->SetLineColor(6);
    h->Fit("funbulk","RQBN+");
    
    
    for(int ipar=0 ; ipar<3 ; ipar++) {
      fun_proton->SetParameter(ipar,funbulk->GetParameter(ipar+3));
      fun_proton->SetParError(ipar, funbulk->GetParError(ipar+3)); 
    }
    
    fun_proton->SetParameter(2,funbulk->GetParameter(2)+fun->GetParameter(5));
    fun_proton->SetParError(2, funbulk->GetParError(2)+ fun->GetParError(5)); 
    //h->Fit("fun_proton","RQB+");
    //funbulk->FixParameter(3,fun_proton->GetParameter(0));
    funbulk->FixParameter(4,fun_proton->GetParameter(1));
    funbulk->FixParameter(5,fun_proton->GetParameter(2)*0.1);
    h->Fit("funbulk","RQBN+");
    if(drawDiagnosticFits == 1) funbulk->Draw("same");
    


    //for(int ipar=0 ; ipar<3 ; ipar++) {
    //  funbulk->SetParameter(ipar+3,fun_proton->GetParameter(ipar));
    //  funbulk->SetParError(ipar+3,fun_proton->GetParError(ipar));
    //}

    //fun_pion->Draw("same");
    //fun_kaon->Draw("same");
    //fun_proton->Draw("same");
    //Trial fit for pion+kaon+prot
    //funmerge->SetParameter(0,fun->GetParameter(0));
    funmerge->SetParameter(1,fun->GetParameter(1)); //mean
    funmerge->SetParameter(2,fun->GetParameter(2)); //sigma 
    //funmerge->SetParameter(3,fun->GetParameter(3));
    funmerge->SetParameter(4,fun->GetParameter(4)); //mean
    funmerge->SetParameter(5,fun->GetParameter(5)); // sigma
    //funmerge->SetParameter(6,funbulk->GetParameter(3));
    funmerge->SetParameter(7,funbulk->GetParameter(4)); //mean
    funmerge->SetParameter(8,funbulk->GetParameter(5)); //sigma
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~initial merged pi/k fit, cent: " 
    //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
   
      //**********************************
      //Set initial parameters for pion+kaon   
      //**********************************

    
    //funmerge->SetRange(par[1]-2.0*par[2], par[4]+2.0*(par[2]+par[5]));
    funmerge->SetRange(-0.4,1.5);
    //h->Fit("funmerge","RQN+"); //unquiet this later
    
      funmerge->FixParameter(0, fun_pion->GetParameter(0)  *tunepionheight[idphi] ); //pion height
      funmerge->FixParameter(1, fun_pion->GetParameter(1)  +tunepionmean[idphi]   ); //pion mean
      funmerge->FixParameter(2, fun_pion->GetParameter(2)  *tunepionwidth[idphi]  ); //pion width
      funmerge->FixParameter(3, fun_kaon->GetParameter(0)  *tunekaonheight[idphi] ); //kaon height
      funmerge->FixParameter(4, fun_kaon->GetParameter(1)  +tunekaonmean[idphi]   ); //kaon mean
      funmerge->FixParameter(5, fun_kaon->GetParameter(2)  *tunekaonwidth[idphi]  ); //kaon width      
      funmerge->FixParameter(6, fun_proton->GetParameter(0)*tuneprotheight[idphi] ); //prot height
      funmerge->FixParameter(7, fun_proton->GetParameter(1)+tuneprotmean[idphi]   ); //prot mean
      funmerge->FixParameter(8, fun_proton->GetParameter(2)*tuneprotwidth[idphi]  );   //prot width
      //funmerge->SetParLimits(7, fun_proton->GetParameter(1)*(1-protmeanvariance),fun_proton->GetParameter(1)*(1+protmeanvariance)); //prot mean
  
    
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~final merged pi/k fit, cent: " 
    //<< centbin << ", which tof: " << whichtof << ", charge: " << charge << ", ptbin: " << iptbin << "~~~~~~~~~~~~~~" << endl;
    funmerge->SetLineWidth(4);
    funmerge->SetLineStyle(9);
    //h->Fit("funmerge","RQB+","same"); //unquiet this later

  
      //**********************************
      //Set parameters in individual pion and kaon functions
      //**********************************

    for(int ipar=0 ; ipar<3 ; ipar++) {
    //  funmerge->SetParameter(ipar,  fun_pion->GetParameter(ipar));
    //  funmerge->SetParError(ipar,   fun_pion->GetParError(ipar) );
    //  funmerge->SetParameter(ipar+3,fun_kaon->GetParameter(ipar));
    //  funmerge->SetParError(ipar+3, fun_kaon->GetParError(ipar) ); 
    //  //funmerge->SetParameter(5,     fun->GetParameter(5)+fun->GetParameter(2));
    //  //funmerge->SetParError(5,      fun->GetParError(5) +fun->GetParError(2) ); 
    //  funmerge->SetParameter(ipar+6,fun_proton->GetParameter(ipar));
    //  //funmerge->SetParError(ipar+6, funbulk->GetParError(ipar+3) ); 
    //  funmerge->SetParameter(ipar+6,fun_proton->GetParameter(ipar));
    //  //funmerge->SetParError(8,      funbulk->GetParError(2) +funbulk->GetParError(5) ); 
    //
      fun_pion->SetParameter(ipar,  funmerge->GetParameter(ipar));
      fun_pion->SetParError(ipar,   funmerge->GetParError(ipar));
      fun_kaon->SetParameter(ipar,  funmerge->GetParameter(ipar+3));
      fun_kaon->SetParError(ipar,   funmerge->GetParError(ipar+3)); 
      //fun_kaon->SetParameter(2,     fun->GetParameter(5)+fun->GetParameter(2));
      //fun_kaon->SetParError(2,      fun->GetParError(5) +fun->GetParError(2)); 
      fun_proton->SetParameter(ipar,funmerge->GetParameter(ipar+6));
      fun_proton->SetParError(ipar, funmerge->GetParError(ipar+6) ); 
      //fun_proton->SetParameter(2,   funmerge->GetParameter(5));
      //fun_proton->SetParError(2,    funmerge->GetParError(5) ); 
    }

    //funmerge->FixParameter(0,fun->GetParameter());
    //funmerge->FixParameter(1,fun->GetParameter(1));
    //funmerge->FixParameter(2,fun->GetParameter(2));
    //funmerge->FixParameter(3,fun->GetParameter(3));
    //funmerge->FixParameter(4,fun->GetParameter(4));
    //funmerge->FixParameter(5,fun->GetParameter(5));
    ////funmerge->FixParameter(6,funbulk->GetParameter());
    //funmerge->FixParameter(7,fun3->GetParameter(1));
    //funmerge->FixParameter(8,fun3->GetParameter(2));

    h->Fit("funmerge","RQBN+","same"); //unquiet this later

    fun_pion->Draw("same");
    fun_kaon->Draw("same");
    fun_proton->Draw("same");
    
    //for(int ipar=0 ; ipar<3 ; ipar++) {
    //  fun_pion->SetParameter(ipar,  funmerge->GetParameter(ipar));
    //  fun_pion->SetParError(ipar,   funmerge->GetParError(ipar));
    //  fun_kaon->SetParameter(ipar,  funmerge->GetParameter(ipar+3));
    //  fun_kaon->SetParError(ipar,   funmerge->GetParError(ipar+3)); 
    //  //fun_kaon->SetParameter(2,     funmerge->GetParameter(5)+funmerge->GetParameter(2));
    //  //fun_kaon->SetParError(2,      funmerge->GetParError(5)+ funmerge->GetParError(2) ); 
    //  fun_proton->SetParameter(ipar,funmerge->GetParameter(ipar+6));
    //  fun_proton->SetParError(ipar, funmerge->GetParError(ipar+6) ); 
    //  //fun_proton->SetParameter(2,   funmerge->GetParameter(5)+funmerge->GetParameter(8));
    //  //fun_proton->SetParError(2,    funmerge->GetParError(5) +funmerge->GetParError(8) ); 
    //}

    /*



    //**********************************
    //This is the end of the fitting, just plotting now ...
    //**********************************

    setFunctionRanges(2.5);//sigma
    
    //drawFrame(gPad->GetFrame()->GetX1(),gPad->GetFrame()->GetY1(),gPad->GetFrame()->GetX2(),gPad->GetFrame()->GetY2(),"m^{2} [GeV^{2}/c^{4}]","Raw Counts");
    //char gifname[100];
    //sprintf(gifname,"%s%s%s%s%s%s%2.2f%s%2.2f","m2",whichtoflabel[whichtof].Data(),"_",chargelabel[charge].Data(),"_",centbinlabel[centbin].Data(),(iptbin)*0.1,"~",(iptbin+1)*0.1);
    //h->Draw("same");
    //fun->SetLineColor(6);
*/



    fun1->SetLineColor(9);
    fun2->SetLineColor(9);
    fun3->SetLineColor(9);     

    //fun1->Draw("same");
    //fun2->Draw("same");
    //fun3->Draw("same");    

    funmerge->Draw("same");

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

    }

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
    
    float pionmean  = fun_pion->GetParameter(1);    float pionmeanerr  = fun_pion->GetParError(1);
    float pionwidth = fun_pion->GetParameter(2);    float pionwidtherr = fun_pion->GetParError(2);
    float kaonmean  = fun_kaon->GetParameter(1);    float kaonmeanerr  = fun_kaon->GetParError(1);
    float kaonwidth = fun_kaon->GetParameter(2);    float kaonwidtherr = fun_kaon->GetParError(2);
    float protmean  = fun_proton->GetParameter(1);  float protmeanerr  = fun_proton->GetParError(1);
    float protwidth = fun_proton->GetParameter(2);  float protwidtherr = fun_proton->GetParError(2);

    //drawLabel(TString("rootbin=")+long(iptbin),1,0.03,0.975,0.35,32);
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
    return c_h;
}

//Double_t richardGaus(Double_t *x, Double_t *par) {
//  return par[0]/par[2]*exp(-0.5*pow((x[0]-par[1])/par[2],2))/sqrt(6.283);
//}
//
//Double_t triplePeakGaus(Double_t *x, Double_t *pionpar, Double_t *kaonpar, Double_t *protpar) {
//  return richardGaus(x,pionpar) + richardGaus(x,kaonpar) + richardGaus (x,protpar);
//}