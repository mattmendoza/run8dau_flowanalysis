void setStyle()
{
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetTextFont(132);
  gStyle->SetNdivisions(505,"X");
  gStyle->SetNdivisions(505,"Y");
  gStyle->SetTitleFont(132,"X");
  gStyle->SetLabelFont(132,"X");
  gStyle->SetTitleFont(132,"Y");
  gStyle->SetLabelFont(132,"Y");
  gStyle->SetTitleFont(132,"Z");
  gStyle->SetLabelFont(132,"Z");
  gStyle->SetTitleSize(0.05,"X");
  gStyle->SetTitleOffset(1.6,"X");
  gStyle->SetLabelSize(0.05,"X");
  gStyle->SetTitleSize(0.05,"Y");
  gStyle->SetTitleOffset(1.8,"Y");
  gStyle->SetLabelSize(0.05,"Y");
  gStyle->SetTitleSize(0.05,"Z");
  gStyle->SetTitleOffset(1.8,"Z");
  gStyle->SetLabelSize(0.05,"Z");
  gStyle->SetOptStat(0);
  gStyle->SetOptDate(0);
  
  gStyle->SetPadLeftMargin(0.2);
  gStyle->SetPadBottomMargin(0.2);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
}

void setStyleWide()
{
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetTextFont(132);
  gStyle->SetNdivisions(505,"X");
  gStyle->SetNdivisions(505,"Y");
  gStyle->SetTitleFont(132,"X");
  gStyle->SetLabelFont(132,"X");
  gStyle->SetTitleFont(132,"Y");
  gStyle->SetLabelFont(132,"Y");
  gStyle->SetTitleSize(0.05,"X");
  gStyle->SetTitleOffset(1.2,"X");
  gStyle->SetLabelSize(0.05,"X");
  gStyle->SetTitleSize(0.05,"Y");
  gStyle->SetTitleOffset(0.9,"Y");
  gStyle->SetLabelSize(0.05,"Y");
  gStyle->SetOptStat(0);
  gStyle->SetOptDate(0);
  
  gStyle->SetPadLeftMargin(0.1);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetTickLength(0.015,"X");
  gStyle->SetTickLength(0.015,"Y");
}

TH1F *drawFrame(Float_t xlow, Float_t ylow, Float_t xhigh, Float_t yhigh,
               TString xTitle="", TString yTitle="")
{
  TH1F *hFrame;

  if(gPad->GetLogy()==0) {
    hFrame = gPad->DrawFrame(xlow,ylow,xhigh,yhigh);
    hFrame->GetXaxis()->SetTitle(xTitle);
    hFrame->GetYaxis()->SetTitle(yTitle); }
  else {
    hFrame = gPad->DrawFrame(xlow,pow(10,ylow),xhigh,pow(10,yhigh));
    hFrame->GetXaxis()->SetTitle(xTitle);
    hFrame->GetYaxis()->SetTitle(yTitle); }

  if(ylow*yhigh<0.) {
    TLine *l = new TLine(xlow,0,xhigh,0);
    l->SetLineStyle(2);
    l->Draw(); }
  
  return hFrame;
}

TH1F *newTH1F(TString hName, TString hTitle,
              Int_t nBinsX, Float_t xlow, Float_t xhigh,
              Int_t fColor=1, Int_t fSumw2=1,
              Int_t fMarkerStyle=7, Float_t fMarkerSize=1)
{
  TH1F *hDummy = new TH1F(hName,hTitle,nBinsX,xlow,xhigh);
  hDummy->SetLineColor(fColor);
  //hDummy->SetLineWidth(2);
  hDummy->SetMarkerColor(fColor);
  hDummy->SetMarkerStyle(fMarkerStyle);
  hDummy->SetMarkerSize(fMarkerSize);

  if(fSumw2) { hDummy->Sumw2(); }
  else       { hDummy->SetFillColor(fColor);}
  
  hDummy->SetStats(0);
  
  return hDummy;
}

TH1D *newTH1D(TString hName, TString hTitle,
              Int_t nBinsX, Float_t xlow, Float_t xhigh,
              Int_t fColor=1, Int_t fSumw2=1,
              Int_t fMarkerStyle=7, Float_t fMarkerSize=1)
{
  TH1D *hDummy = new TH1D(hName,hTitle,nBinsX,xlow,xhigh);
  hDummy->SetLineColor(fColor);
  //hDummy->SetLineWidth(2);
  hDummy->SetMarkerColor(fColor);
  hDummy->SetMarkerStyle(fMarkerStyle);
  hDummy->SetMarkerSize(fMarkerSize);

  if(fSumw2) { hDummy->Sumw2(); }
  else       { hDummy->SetFillColor(fColor);}
  
  hDummy->SetStats(0);
  
  return hDummy;
}

TProfile *newTProfile(TString hName, TString hTitle,
		      Int_t nBinsX, Float_t xlow, Float_t xhigh,
		      TString opt="s",
		      Int_t fColor=1, Int_t fSumw2=1,
		      Int_t fMarkerStyle=7, Float_t fMarkerSize=1)
{
  TProfile *hDummy = new TProfile(hName,hTitle,nBinsX,xlow,xhigh,opt);
  hDummy->SetLineColor(fColor);
  //hDummy->SetLineWidth(2);
  hDummy->SetMarkerColor(fColor);
  hDummy->SetMarkerStyle(fMarkerStyle);
  hDummy->SetMarkerSize(fMarkerSize);
  
  hDummy->SetStats(0);
  
  return hDummy;
}

TH2F *newTH2F(TString fName, TString fTitle, 
	      Int_t fNBinsX, Double_t fNXlow, Double_t fNXhigh,
	      Int_t fNBinsY, Double_t fNYlow, Double_t fNYhigh,
	      Int_t fColor=1, Int_t fMarkerStyle=7, Int_t fMarkerSize=1)
{
  TH2F *hDummy = new TH2F(fName,fTitle,fNBinsX,fNXlow,fNXhigh,
			  fNBinsY,fNYlow,fNYhigh);

  hDummy->SetLineColor(fColor);
  hDummy->SetMarkerColor(fColor);
  hDummy->SetMarkerStyle(fMarkerStyle);
  hDummy->SetMarkerSize(fMarkerSize);

  hDummy->SetStats(0);
  
  return hDummy;
}

void newTLatex(Float_t x, Float_t y, TString fText, Int_t fColor=1, 
	       Int_t fAlign=21, Float_t fSize, Float_t fAngle=0)
{
  TLatex *l = new TLatex(x,y,fText);
  
  l->SetTextColor(fColor);
  l->SetTextAlign(fAlign);
  l->SetTextSize(fSize);
  l->SetTextAngle(fAngle);

  l->Draw();  
}

void drawTitle(double xpos = 0.05, double ypos = 0.075, TString fTitle="",
	       int color=1,int align=12, double size=0.045, double angle=0)
{
  double x0 = gPad->GetFrame()->GetX1();
  double x1 = gPad->GetFrame()->GetX2();
  double y0 = gPad->GetFrame()->GetY1();
  double y1 = gPad->GetFrame()->GetY2();
  double dx = x1-x0;
  double dy = y1-y0;
  
  newTLatex(x0+xpos*dx,y1-ypos*dy,fTitle,color,align,size,angle);
}

void newTMarker(double xpos = 0.05, double ypos = 0.075, int style=7,
		int color=1, double size=1.0, double absolute = 0)
{
  double x0 = gPad->GetFrame()->GetX1();
  double x1 = gPad->GetFrame()->GetX2();
  double y0 = gPad->GetFrame()->GetY1();
  double y1 = gPad->GetFrame()->GetY2();
  double dx = x1-x0;
  double dy = y1-y0;
  
  if(!absolute) //default before Sept 2015
    {
      TMarker *m = new TMarker(x0+xpos*dx,y1-ypos*dy,style);
      m->SetMarkerColor(color);
      m->SetMarkerSize(size);
      m->Draw();
    }
  else 
    {
      TMarker *m = new TMarker(xpos,ypos,style);
      m->SetMarkerColor(color);
      m->SetMarkerSize(size);
      m->Draw();
    }
}

void newTBox(double xpos0 = 0.05, double ypos0 = 0.075,
	     double xpos1 = 0.05, double ypos1 = 0.075,
	     int lcolor=1, int fcolor=1, int style=7)
{
  double x0 = gPad->GetFrame()->GetX1();
  double x1 = gPad->GetFrame()->GetX2();
  double y0 = gPad->GetFrame()->GetY1();
  double y1 = gPad->GetFrame()->GetY2();
  double dx = x1-x0;
  double dy = y1-y0;
  
  TBox *b = new TBox(x0+xpos0*dx,y1-ypos0*dy,x0+xpos1*dx,y1-ypos1*dy);
  b->SetLineColor(lcolor);
  b->SetFillColor(fcolor);
  b->SetFillStyle(style);
  b->Draw();
}

bool progress(int iEvent, int total_events, int ndiv=10)
{
  if(iEvent%(total_events/ndiv)==0) {
    cout << "Progress: " << iEvent/(total_events/100)
         << "%     \r" << flush;
    if(gROOT->IsBatch()) { cout << endl; }
    return true;
  }
  return false;
}

void drawTGEOutline(TGraphErrors *gDummy)
{
  double x,y,ex,ey;
  TGraph *gDummy2 = new TGraphErrors();
  gDummy2->SetLineColor(gDummy->GetLineColor());
  gDummy2->SetLineWidth(gDummy->GetLineWidth());
  gDummy2->SetLineStyle(gDummy->GetLineStyle());
  
  int n = gDummy->GetN();
  for(int i=0 ; i<n ; i++) {
    gDummy->GetPoint(i,x,y);
    ex = gDummy->GetErrorX(i);
    ey = gDummy->GetErrorY(i);
    
    gDummy2->SetPoint(i,x-ex,y-ey);
    if(i==0) { gDummy2->SetPoint(2*n,x-ex,y-ey); }
    gDummy2->SetPoint(2*n-1-i,x+ex,y+ey);
  }
  
  gDummy2->Draw("L");
}

void drawTGEOutline(TGraphAsymmErrors *gDummy)
{
  double x,y,exl,eyl,exh,eyh;
  TGraph *gDummy2 = new TGraphErrors();
  gDummy2->SetLineColor(gDummy->GetLineColor());
  gDummy2->SetLineWidth(gDummy->GetLineWidth());
  gDummy2->SetLineStyle(gDummy->GetLineStyle());
  
  int n = gDummy->GetN();
  for(int i=0 ; i<n ; i++) {
    gDummy->GetPoint(i,x,y);
    exl = gDummy->GetErrorXlow(i);
    exh = gDummy->GetErrorXhigh(i);
    eyl = gDummy->GetErrorYlow(i);
    eyh = gDummy->GetErrorYhigh(i);
    
    gDummy2->SetPoint(i,x-exl,y-eyl);
    if(i==0) { gDummy2->SetPoint(2*n,x-exl,y-eyl); }
    gDummy2->SetPoint(2*n-1-i,x+exh,y+eyh);
  }
  
  gDummy2->Draw("L");
}


TGraphErrors *findTGERatio(TGraphErrors *gNum, TGraphErrors *gDenom,
			   bool kAddError = true)
{
  double xN,yN,exN,eyN;
  double xD,yD,exD,eyD;
  TGraphErrors *gReturn = new TGraphErrors();
  gReturn->SetLineColor(gNum->GetLineColor());
  gReturn->SetLineWidth(gNum->GetLineWidth());
  gReturn->SetFillColor(gNum->GetFillColor());
  gReturn->SetFillStyle(gNum->GetFillStyle());
  gReturn->SetMarkerColor(gNum->GetMarkerColor());
  gReturn->SetMarkerStyle(gNum->GetMarkerStyle());
  gReturn->SetMarkerSize(gNum->GetMarkerSize());
  
  int n = gNum->GetN();
  if(n!=gDenom->GetN()) {
    cout << "findTGERatio() Error!" << endl;
    return NULL; }
  
  for(int i=0 ; i<n ; i++) {
    gNum->GetPoint(i,xN,yN);
    exN = gNum->GetErrorX(i);
    eyN = gNum->GetErrorY(i);
    gDenom->GetPoint(i,xD,yD);
    exD = gDenom->GetErrorX(i);
    eyD = gDenom->GetErrorY(i);
    
    if(fabs(xN-xD)>0.001) { 
      cout << "findTGERatio() Error! (x's don't match: "
	   << xN-xD << ")" << endl; }
    
    gReturn->SetPoint(i,xN,yN/yD);
    if(!kAddError) {
      gReturn->SetPointError(i,TMath::Max(exN,exD),eyN/yD); }
    else {
      double error = pow(eyN/yN,2)+pow(eyD/yD,2);
      error = sqrt(error)*yN/yD;
      gReturn->SetPointError(i,TMath::Max(exN,exD),error); }
  }
  
  return gReturn;
}
