#include "../../tunefits/Style.h"
#include "../../tunefits/graphStyles.h"

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

float v2pionpos[15];
float v2kaonpos[15];
float v2protpos[15];
float v2alltpos[15];
float v2errpionpos[15];
float v2errkaonpos[15];
float v2errprotpos[15];
float v2erralltpos[15];

float v2pionneg[15];
float v2kaonneg[15];
float v2protneg[15];
float v2alltneg[15];
float v2errpionneg[15];
float v2errkaonneg[15];
float v2errprotneg[15];
float v2erralltneg[15];

float v2allt[15];
float v2allterr[15];

float pt[16];
float pterr[16];

void sysErrCalc() {

  plotCentSys();

  return;
  v2pionnegdn[0] = 0.0150697;	 v2errpionnegdn[0] = 1.33888e-005;
  v2kaonnegdn[0] = 0.00920919;	 v2errkaonnegdn[0] = 5.09984e-005;
  v2protnegdn[0] = 0.00453759;	 v2errprotnegdn[0] = 7.69204e-005;
  v2pionposdn[0] = 0.00733804;	 v2errpionposdn[0] = 1.30074e-005;
  v2kaonposdn[0] = 0.0131675;	 v2errkaonposdn[0] = 4.79801e-005;
  v2protposdn[0] = 0;	 v2errprotposdn[0] = 2.84089e-007;
  v2pionnegdn[1] = 0.0195387;	 v2errpionnegdn[1] = 1.24818e-005;
  v2kaonnegdn[1] = 0.0146153;	 v2errkaonnegdn[1] = 4.35811e-005;
  v2protnegdn[1] = 0.0126996;	 v2errprotnegdn[1] = 5.03483e-005;
  v2pionposdn[1] = 0.0162357;	 v2errpionposdn[1] = 1.2289e-005;
  v2kaonposdn[1] = 0.0120187;	 v2errkaonposdn[1] = 3.99608e-005;
  v2protposdn[1] = 0.00505559;	 v2errprotposdn[1] = 4.02803e-005;
  v2pionnegdn[2] = 0.0237009;	 v2errpionnegdn[2] = 1.49602e-005;
  v2kaonnegdn[2] = 0.0245606;	 v2errkaonnegdn[2] = 4.93983e-005;
  v2protnegdn[2] = 0.0202174;	 v2errprotnegdn[2] = 4.39789e-005;
  v2pionposdn[2] = 0.0214961;	 v2errpionposdn[2] = 1.49369e-005;
  v2kaonposdn[2] = 0.0244096;	 v2errkaonposdn[2] = 4.67646e-005;
  v2protposdn[2] = 0.0177595;	 v2errprotposdn[2] = 3.59867e-005;
  v2pionnegdn[3] = 0.0326892;	 v2errpionnegdn[3] = 6.48967e-005;
  v2kaonnegdn[3] = 0.0239345;	 v2errkaonnegdn[3] = 0.000243339;
  v2protnegdn[3] = 0.0212885;	 v2errprotnegdn[3] = 0.000138137;
  v2pionposdn[3] = 0.0274668;	 v2errpionposdn[3] = 3.18497e-005;
  v2kaonposdn[3] = 0.0445484;	 v2errkaonposdn[3] = 0.000118175;
  v2protposdn[3] = 0.0299764;	 v2errprotposdn[3] = 5.94961e-005;
  v2pionnegdn[4] = 0.0319515;	 v2errpionnegdn[4] = 2.76598e-005;
  v2kaonnegdn[4] = 0.0398414;	 v2errkaonnegdn[4] = 5.74311e-005;
  v2protnegdn[4] = 0.014444;	 v2errprotnegdn[4] = 9.43155e-005;
  v2pionposdn[4] = 0.0264099;	 v2errpionposdn[4] = 2.62817e-005;
  v2kaonposdn[4] = 0.0357544;	 v2errkaonposdn[4] = 5.82557e-005;
  v2protposdn[4] = 0.0286837;	 v2errprotposdn[4] = 4.84381e-005;
  v2pionnegdn[5] = 0.0332945;	 v2errpionnegdn[5] = 9.59331e-005;
  v2kaonnegdn[5] = 0.0392577;	 v2errkaonnegdn[5] = 0.000187877;
  v2protnegdn[5] = 0.0555988;	 v2errprotnegdn[5] = 0.000330473;
  v2pionposdn[5] = 0.0300038;	 v2errpionposdn[5] = 9.58079e-005;
  v2kaonposdn[5] = 0.0375366;	 v2errkaonposdn[5] = 0.000174624;
  v2protposdn[5] = 0.0380819;	 v2errprotposdn[5] = 0.000263507;
  v2pionnegdn[6] = 0.0333546;	 v2errpionnegdn[6] = 0.000159246;
  v2kaonnegdn[6] = 0.0157326;	 v2errkaonnegdn[6] = 0.000306631;
  v2protnegdn[6] = 0.0486312;	 v2errprotnegdn[6] = 0.000272805;
  v2pionposdn[6] = 0.0375772;	 v2errpionposdn[6] = 0.00015684;
  v2kaonposdn[6] = 0.0247945;	 v2errkaonposdn[6] = 0.000297438;
  v2protposdn[6] = 0.0701346;	 v2errprotposdn[6] = 0.000256147;
  v2pionnegdn[7] = 0.0310358;	 v2errpionnegdn[7] = 0.000326618;
  v2kaonnegdn[7] = 0.0314218;	 v2errkaonnegdn[7] = 0.000528245;
  v2protnegdn[7] = 0.0382549;	 v2errprotnegdn[7] = 0.000667445;
  v2pionposdn[7] = 0.0344241;	 v2errpionposdn[7] = 0.000353938;
  v2kaonposdn[7] = 0.0421158;	 v2errkaonposdn[7] = 0.000542107;
  v2protposdn[7] = 0.00775044;	 v2errprotposdn[7] = 0.000655753;
  v2pionnegup[0] = 0.0139638;	 v2errpionnegup[0] = 1.05703e-005;
  v2kaonnegup[0] = 0.0105157;	 v2errkaonnegup[0] = 4.03379e-005;
  v2protnegup[0] = 0.00463242;	 v2errprotnegup[0] = 6.07244e-005;
  v2pionposup[0] = 0.0144171;	 v2errpionposup[0] = 1.04227e-005;
  v2kaonposup[0] = 0.0140224;	 v2errkaonposup[0] = 3.7995e-005;
  v2protposup[0] = 0.00335522;	 v2errprotposup[0] = 4.0625e-005;
  v2pionnegup[1] = 0.0177732;	 v2errpionnegup[1] = 9.85947e-006;
  v2kaonnegup[1] = 0.0107572;	 v2errkaonnegup[1] = 3.45185e-005;
  v2protnegup[1] = 0.0124603;	 v2errprotnegup[1] = 3.97707e-005;
  v2pionposup[1] = 0.015942;	 v2errpionposup[1] = 9.71911e-006;
  v2kaonposup[1] = 0.0109642;	 v2errkaonposup[1] = 3.16466e-005;
  v2protposup[1] = 0.00834204;	 v2errprotposup[1] = 3.18129e-005;
  v2pionnegup[2] = 0.0232385;	 v2errpionnegup[2] = 1.18286e-005;
  v2kaonnegup[2] = 0.0213315;	 v2errkaonnegup[2] = 3.9096e-005;
  v2protnegup[2] = 0.0235475;	 v2errprotnegup[2] = 3.47859e-005;
  v2pionposup[2] = 0.0216462;	 v2errpionposup[2] = 1.18143e-005;
  v2kaonposup[2] = 0.0275753;	 v2errkaonposup[2] = 3.67935e-005;
  v2protposup[2] = 0.0175231;	 v2errprotposup[2] = 2.84703e-005;
  v2pionnegup[3] = 0;	 v2errpionnegup[3] = 1.19573e-007;
  v2kaonnegup[3] = 0.0212747;	 v2errkaonnegup[3] = 0.000189621;
  v2protnegup[3] = 0.022584;	 v2errprotnegup[3] = 0.000109282;
  v2pionposup[3] = 0.026306;	 v2errpionposup[3] = 2.51847e-005;
  v2kaonposup[3] = 0.0430063;	 v2errkaonposup[3] = 9.24605e-005;
  v2protposup[3] = 0.027813;	 v2errprotposup[3] = 4.70711e-005;
  v2pionnegup[4] = 0.0305023;	 v2errpionnegup[4] = 2.20733e-005;
  v2kaonnegup[4] = 0.0410987;	 v2errkaonnegup[4] = 4.55088e-005;
  v2protnegup[4] = 0.0255841;	 v2errprotnegup[4] = 2.84036e-005;
  v2pionposup[4] = 0.0255358;	 v2errpionposup[4] = 2.07039e-005;
  v2kaonposup[4] = 0.0329652;	 v2errkaonposup[4] = 4.61643e-005;
  v2protposup[4] = 0.0381864;	 v2errprotposup[4] = 3.07393e-005;
  v2pionnegup[5] = 0.0318499;	 v2errpionnegup[5] = 7.58492e-005;
  v2kaonnegup[5] = 0.0327286;	 v2errkaonnegup[5] = 0.000144496;
  v2protnegup[5] = 0.0313964;	 v2errprotnegup[5] = 0.000255228;
  v2pionposup[5] = 0.0279178;	 v2errpionposup[5] = 7.46169e-005;
  v2kaonposup[5] = 0.0371083;	 v2errkaonposup[5] = 0.000135382;
  v2protposup[5] = 0.0411784;	 v2errprotposup[5] = 0.000247904;
  v2pionnegup[6] = 0.0332408;	 v2errpionnegup[6] = 0.000127991;
  v2kaonnegup[6] = 0.027235;	 v2errkaonnegup[6] = 0.000251177;
  v2protnegup[6] = 0.0414298;	 v2errprotnegup[6] = 0.000226377;
  v2pionposup[6] = 0.0312882;	 v2errpionposup[6] = 0.000126355;
  v2kaonposup[6] = 0.0204455;	 v2errkaonposup[6] = 0.00024543;
  v2protposup[6] = 0.0574986;	 v2errprotposup[6] = 0.00022458;
  v2pionnegup[7] = 0.0304708;	 v2errpionnegup[7] = 0.000261848;
  v2kaonnegup[7] = 0.0314013;	 v2errkaonnegup[7] = 0.000424337;
  v2protnegup[7] = 0.0440652;	 v2errprotnegup[7] = 0.000524108;
  v2pionposup[7] = 0.0341449;	 v2errpionposup[7] = 0.000273472;
  v2kaonposup[7] = 0.0309047;	 v2errkaonposup[7] = 0.000404753;
  v2protposup[7] = 0.0755506;	 v2errprotposup[7] = 0.000997967;

  v2alltpos[0] = 0.0131388;      v2erralltpos[0] = 1.26888e-005;
v2pionpos[0] = 0.0139944;      v2errpionpos[0] = 1.35303e-005;
v2kaonpos[0] = 0.0116669;      v2errkaonpos[0] = 4.9449e-005;
v2protpos[0] = 0.00452348;     v2errprotpos[0] = 5.29505e-005;

v2alltpos[1] = 0.014424;     v2erralltpos[1] = 1.10428e-005;
v2pionpos[1] = 0.0151749;      v2errpionpos[1] = 1.26266e-005;
v2kaonpos[1] = 0.013755;     v2errkaonpos[1] = 4.1153e-005;
v2protpos[1] = 0.010197;     v2errprotpos[1] = 4.12966e-005;

v2alltpos[2] = 0.00208193;     v2erralltpos[2] = 0.687642;
v2pionpos[2] = 0.0206842;      v2errpionpos[2] = 1.53471e-005;
v2kaonpos[2] = 0.0217392;      v2errkaonpos[2] = 4.76238e-005;
v2protpos[2] = 0.0160926;    v2errprotpos[2] = 3.70303e-005;

v2alltpos[3] = 0.0278941;      v2erralltpos[3] = 0.0430533;
v2pionpos[3] = 0.0264116;      v2errpionpos[3] = 3.26708e-005;
v2kaonpos[3] = 0.0330352;      v2errkaonpos[3] = 0.00012124;
v2protpos[3] = 0.0236456;    v2errprotpos[3] = 6.11545e-005;

v2alltpos[4] = 0.0270103;      v2erralltpos[4] = 0.0155533;
v2pionpos[4] = 0.0317765;      v2errpionpos[4] = 2.69951e-005;
v2kaonpos[4] = 0.0369021;      v2errkaonpos[4] = 6.07405e-005;
v2protpos[4] = 0.0309901;    v2errprotpos[4] = 5.05088e-005;

v2alltpos[5] = 0.0348183;      v2erralltpos[5] = 9.9283e-005;
v2pionpos[5] = 0.0323648;      v2errpionpos[5] = 9.6986e-005;
v2kaonpos[5] = 0.0396659;      v2errkaonpos[5] = 0.000174864;
v2protpos[5] = 0.0371596;    v2errprotpos[5] = 0.000317537;

v2alltpos[6] = 0.0376867;      v2erralltpos[6] = 0.000145551;
v2pionpos[6] = 0.0324613;      v2errpionpos[6] = 0.000163718;
v2kaonpos[6] = 0.0400783;      v2errkaonpos[6] = 0.0003155;
v2protpos[6] = 0.0452959;    v2errprotpos[6] = 0.000262236;

v2alltpos[7] = 0.0359183;      v2erralltpos[7] = 0.000266693;
v2pionpos[7] = 0.0336751;      v2errpionpos[7] = 0.000363713;
v2kaonpos[7] = 0.0393055;      v2errkaonpos[7] = 0.000551467;
v2protpos[7] = 0.046838;     v2errprotpos[7] = 0.000337257;

v2pionpos[8] = 0.0326042;      v2errpionpos[8] = 0.000468384;
v2kaonpos[8] = 0.0396922;      v2errkaonpos[8] = 0.000669895;
v2protpos[8] = 0.046966;     v2errprotpos[8] = 0.000632564;

v2pionpos[9] = 0.0326037;      v2errpionpos[9] = 0.000647512;
v2kaonpos[9] = 0.0360695;      v2errkaonpos[9] = 0.000810233;
v2protpos[9] = 0.047532;     v2errprotpos[9] = 0.000769459;

v2pionpos[10] = 0.0327988;     v2errpionpos[10] = 0.00184278;
v2kaonpos[10] = 0.03378;     v2errkaonpos[10] = 0.00169447;
v2protpos[10] = 0.0456037;     v2errprotpos[10] = 0.00202961;

v2pionpos[11] = 0.0335232;     v2errpionpos[11] = 0.00241892;
v2kaonpos[11] = 0.0341182;     v2errkaonpos[11] = 0.0043093;
v2protpos[11] = 0.0433872;     v2errprotpos[11] = 0.00491914;

v2pionpos[12] = 0.0329689;     v2errpionpos[12] = 0.00474479;
v2kaonpos[12] = 0.0339862;     v2errkaonpos[12] = 0.00242974;
v2protpos[12] = 0.043666;    v2errprotpos[12] = 0.003034;

v2pionpos[13] = 0.0316514;     v2errpionpos[13] = 0.00778246;
v2kaonpos[13] = 0.0344744;     v2errkaonpos[13] = 0.00809327;
v2protpos[13] = 0.0441567;     v2errprotpos[13] = 0.00361229;


v2pionpos[14] = 0.0317127;     v2errpionpos[14] = 0.00883035;
v2kaonpos[14] = 0.0342252;     v2errkaonpos[14] = 0.00824922;
v2protpos[14] = 0.0467843;     v2errprotpos[14] = 0.0043356;

///////////////////////////////////////////////////////////////////////////Neg v2s begin here///////////////////////////////////////////

v2alltneg[0] = 0.00993574;     v2erralltneg[0] = 7.24118e-006;
v2pionneg[0] = 0.013381;     v2errpionneg[0] = 1.37161e-005;
v2kaonneg[0] = 0.010324;     v2errkaonneg[0] = 5.23681e-005;
v2protneg[0] = 0.00466884;     v2errprotneg[0] = 7.97635e-005;

v2alltneg[1] = 0.015009;     v2erralltneg[1] = 1.20154e-005;
v2pionneg[1] = 0.0156552;      v2errpionneg[1] = 1.2805e-005;
v2kaonneg[1] = 0.0113971;      v2errkaonneg[1] = 4.48186e-005;
v2protneg[1] = 0.0110577;    v2errprotneg[1] = 5.18096e-005;

v2alltneg[2] = 0.0206733;      v2erralltneg[2] = 1.41132e-005;
v2pionneg[2] = 0.0213564;      v2errpionneg[2] = 1.5362e-005;
v2kaonneg[2] = 0.0218287;      v2errkaonneg[2] = 5.06469e-005;
v2protneg[2] = 0.014912;     v2errprotneg[2] = 4.5425e-005;

v2alltneg[3] = 0.028054;     v2erralltneg[3] = 6.20903e-005;
v2pionneg[3] = 0.0280355;      v2errpionneg[3] = 6.65019e-005;
v2kaonneg[3] = 0.0321181;      v2errkaonneg[3] = 0.000244299;
v2protneg[3] = 0.0238375;    v2errprotneg[3] = 0.000142362;

v2alltneg[4] = 0.0319019;      v2erralltneg[4] = 1.50299e-005;
v2pionneg[4] = 0.0303357;      v2errpionneg[4] = 2.86714e-005;
v2kaonneg[4] = 0.0365472;      v2errkaonneg[4] = 5.97541e-005;
v2protneg[4] = 0.0319782;    v2errprotneg[4] = 7.75184e-005;

v2alltneg[5] = 0.0323494;      v2erralltneg[5] = 9.6557e-005;
v2pionneg[5] = 0.0309382;      v2errpionneg[5] = 9.7712e-005;
v2kaonneg[5] = 0.039378;     v2errkaonneg[5] = 0.000187254;
v2protneg[5] = 0.0368732;    v2errprotneg[5] = 0.000338683;

v2alltneg[6] = 0.0366022;      v2erralltneg[6] = 7.68003e-005;
v2pionneg[6] = 0.0323751;      v2errpionneg[6] = 0.000162868;
v2kaonneg[6] = 0.0394184;      v2errkaonneg[6] = 0.000301149;
v2protneg[6] = 0.0465922;    v2errprotneg[6] = 0.00028577;

v2alltneg[7] = 0.0372947;      v2erralltneg[7] = 0.000293688;
v2pionneg[7] = 0.033127;     v2errpionneg[7] = 0.000343079;
v2kaonneg[7] = 0.0411851;      v2errkaonneg[7] = 0.000558054;
v2protneg[7] = 0.0464645;    v2errprotneg[7] = 0.000680168;

v2pionneg[8] = 0.0335825;      v2errpionneg[8] = 0.000504641;
v2kaonneg[8] = 0.0389648;      v2errkaonneg[8] = 0.000622305;
v2protneg[8] = 0.0472923;    v2errprotneg[8] = 0.00065327;

v2pionneg[9] = 0.0335367;      v2errpionneg[9] = 0.00073306;
v2kaonneg[9] = 0.0373682;      v2errkaonneg[9] = 0.000883844;
v2protneg[9] = 0.0472011;    v2errprotneg[9] = 0.000866766;

v2pionneg[10] = 0.033089;      v2errpionneg[10] = 0.00159797;
v2kaonneg[10] = 0.0356833;     v2errkaonneg[10] = 0.00193603;
v2protneg[10] = 0.0472947;     v2errprotneg[10] = 0.00244889;

v2pionneg[11] = 0.0321075;     v2errpionneg[11] = 0.00251042;
v2kaonneg[11] = 0.0337351;     v2errkaonneg[11] = 0.00439436;
v2protneg[11] = 0.0442228;     v2errprotneg[11] = 0.00595987;

v2pionneg[12] = 0.0321625;     v2errpionneg[12] = 0.00477656;
v2kaonneg[12] = 0.0333368;     v2errkaonneg[12] = 0.00519813;
v2protneg[12] = 0.0430611;     v2errprotneg[12] = 0.00652144;

v2pionneg[13] = 0.0339533;     v2errpionneg[13] = 0.00438491;
v2kaonneg[13] = 0.0356072;     v2errkaonneg[13] = 0.0162713;
v2protneg[13] = 0.0412724;     v2errprotneg[13] = 0.0049791;

v2pionneg[14] = 0.0324945;     v2errpionneg[14] = 0.00467284;
v2kaonneg[14] = 0.0342532;     v2errkaonneg[14] = 0.00725964;
v2protneg[14] = 0.043748;    v2errprotneg[14] = 0.00591164;
  
  for(int ptbin =0; ptbin <=7;ptbin++) {

    cout << ptbin << "\t" << anaSystematics(v2pionneg[ptbin],v2pionnegdn[ptbin]) << "\t" <<anaSystematics(v2pionneg[ptbin],v2pionnegup[ptbin]) << endl;
    cout << ptbin << "\t" << anaSystematics(v2kaonneg[ptbin],v2kaonnegdn[ptbin]) << "\t" <<anaSystematics(v2kaonneg[ptbin],v2kaonnegup[ptbin]) << endl;
    cout << ptbin << "\t" << anaSystematics(v2protneg[ptbin],v2protnegdn[ptbin]) << "\t" <<anaSystematics(v2protneg[ptbin],v2protnegup[ptbin]) << endl;

    cout << ptbin << "\t" << anaSystematics(v2pionpos[ptbin],v2pionposdn[ptbin]) << "\t" <<anaSystematics(v2pionpos[ptbin],v2pionposup[ptbin]) << endl;
    cout << ptbin << "\t" << anaSystematics(v2kaonpos[ptbin],v2kaonposdn[ptbin]) << "\t" <<anaSystematics(v2kaonpos[ptbin],v2kaonposup[ptbin]) << endl;
    cout << ptbin << "\t" << anaSystematics(v2protpos[ptbin],v2protposdn[ptbin]) << "\t" <<anaSystematics(v2protpos[ptbin],v2protposup[ptbin]) << endl;
  }

}

float anaSystematics(float origVal, float newVal) {
  return fabs((origVal- newVal)/origVal);
}

void plotCentSys() {
  float ipt[8] = {0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0};
  float pterr[8]={0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
  float sigma[8]={0.00780072,0.0561458,0.0227773,0.0525852,0.0054919,0.00305493,0.0267396,0.0516373};
  float sigma2[8] = {0.0302049,0.0505506,0.0392522,0.00399827,0.0311012,0.02482,0.0361385,0.013951};
  float err[8]={1.05703E-05,9.85947E-06,1.18286E-05,1.19573E-07,2.20733E-05,7.58492E-05,0.000127991,0.000261848};
  
  TGraphErrors * gr_centsys = new TGraphErrors(8,ipt,sigma,pterr,err);
  TGraphErrors * gr_centsys2= new TGraphErrors(8,ipt,sigma2,pterr,err);
  c1 = new TCanvas("c1","c1",3000,2000);
  TH1F *axis = drawFrame(0.3,-0.1,2.25,1,"p_{T} (GeV/c)","#left| #frac{v_{2}^{0-5%}-v_{2}^{0-4%(6%)}}{v_{2}^{0-5%}} #right|");
  drawTitle(.3,-.07,"Fractional Flow Deviation: #left| #frac{v_{2}^{0-5%}-v_{2}^{0-4%(6%)}}{v_{2}^{0-5%}} #right|",1,12,.03,0);
  
  axis->GetYaxis()->SetLabelSize(0.03);
  axis->GetXaxis()->SetLabelSize(0.03);
  gr_centsys->SetMarkerSize(2);
  gr_centsys->SetMarkerColor(2);
  gr_centsys->SetMarkerStyle(20);
  gr_centsys->SetLineWidth(2);
  gr_centsys->Draw("PE");

  gr_centsys2->SetMarkerSize(2);
  gr_centsys2->SetMarkerColor(4);
  gr_centsys2->SetMarkerStyle(20);
  gr_centsys2->SetLineWidth(2);
  gr_centsys2->Draw("PE");

  legend2 = new TLegend(0.12,0.88,0.3,0.79,0);
  legend2->SetNColumns(1);   legend2->SetBorderSize(0);

  legend2->AddEntry(gr_centsys, "0-4% centrality","p");
  legend2->AddEntry(gr_centsys2,"0-6% centrality","p");

  //legend->AddEntry(gr_v2alltpos,"all ID tracks (sum of #pi+k+P)","p");
  //legend->AddEntry(gr_v2alltneg,"all ID tracks (sum of #pi+k+P)","p");
  //legend->AddEntry(gr_v2toftrk,"all charged tracks in TOFW","p");
  //legend->AddEntry(gr_v2rawt,"all charged tracks","p");
  legend2->Draw();
  
  c1->SaveAs("CentSysErrs.jpg");

}
//{0.00780072,0.0561458,0.0227773,0.0525852,0.0054919,0.00305493,0.0267396,0.0516373};
//{0.0302049,0.0505506,0.0392522,0.00399827,0.0311012,0.02482,0.0361385,0.013951};