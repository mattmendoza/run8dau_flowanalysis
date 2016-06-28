
void TOFWposcent0_pt2530() {
  
  cout << "running: TOFEposcent0_pt0508" << endl << endl; 
  pionheightpercent = 0.95;
  kaonheightpercent = 0.7;
  protheightpercent = 1.2;
  
  pionwidthpercent = 0.75; 
  kaonwidthpercent = 0.5; 
  protwidthpercent = 1.2;

  pionmeanshift = -0.04;
  kaonmeanshift = 0.01;
  protmeanshift = 0;
  setUniformTuning();

  tunepionheight[0] = 0.9;
  tunepionmean[0] = -0.05;

  tuneprotmean[0] = 0.01;
  tuneprotheight[0] = 1.3;

  tuneprotwidth[2] = 0.8;
  tuneprotheight[2] = 0.85;
  tuneprotmean[2] = 0.03;


}

