#include "Style.h"

void anaWiggles() {

float  WigglErrOUT_dphi0percent1plus[15]=	{0.222877,0.195368,0.14196,0.106139,0.090692,0.0866735,0.0789024,0.0774436,0.0761199,0.0774175,0.0789738,0.080457,0.080983,0.0750632,0.0877926};
float  WigglErrOUT_dphi0percent2plus[15]=	{0.445007,0.390079,0.283438,0.211919,0.181075,0.173052,0.157536,0.154621,0.151979,0.154568,0.157676,0.160637,0.16169,0.149869,0.175285};
float  WigglErrOUT_dphi0percent4plus[15]=	{0.887032,0.777541,0.564969,0.422402,0.360917,0.344929,0.313998,0.308181,0.302919,0.308079,0.314273,0.320178,0.32228,0.298713,0.349375};
float  WigglErrOUT_dphi0percent5plus[15]=	{1.10694,0.970298,0.705025,0.527111,0.450379,0.430431,0.391829,0.384567,0.378004,0.384441,0.392171,0.39954,0.402168,0.372755,0.435975};
float  WigglErrOUT_dphi0percent7plus[15]=	{1.54454,1.35388,0.983733,0.73547,0.628393,0.600568,0.5467,0.536556,0.527409,0.536387,0.54717,0.557459,0.561123,0.520084,0.608294};
float  WigglErrOUT_dphi0percent10plus[15]=	{2.19551,1.92448,1.39832,1.04539,0.893164,0.853629,0.777047,0.762604,0.749623,0.762374,0.777699,0.792332,0.797547,0.739218,0.864594};

float  WigglErrOUT_dphi0percent1minus[15]=	{0.223634,0.196029,0.142436,0.106501,0.0910048,0.0869715,0.0791741,0.0777122,0.0763802,0.0776831,0.0792477,0.0807329,0.0812608,0.0753205,0.0880933};
float  WigglErrOUT_dphi0percent2minus[15]=	{0.448023,0.392722,0.285359,0.213367,0.182323,0.17424,0.158621,0.155694,0.153025,0.155635,0.158768,0.161742,0.162804,0.150902,0.17649};
float  WigglErrOUT_dphi0percent4minus[15]=	{0.89909,0.788116,0.572664,0.428197,0.365905,0.34968,0.318339,0.312471,0.30711,0.31235,0.318636,0.324608,0.326735,0.302848,0.3542};
float  WigglErrOUT_dphi0percent5minus[15]=	{1.12577,0.986822,0.717052,0.536167,0.458172,0.437853,0.398612,0.391269,0.384553,0.391115,0.398989,0.406464,0.409126,0.379216,0.443516};
float  WigglErrOUT_dphi0percent7minus[15]=	{1.58146,1.38627,1.00731,0.753221,0.643668,0.615115,0.559996,0.549692,0.540246,0.54947,0.560534,0.57103,0.574767,0.532749,0.623076};
float  WigglErrOUT_dphi0percent10minus[15]=	{2.27086,1.99059,1.44645,1.08163,0.924339,0.88332,0.804184,0.789416,0.775829,0.789084,0.804977,0.820037,0.825395,0.765059,0.894768};

float  WigglErrOUT_dphi1percent1plus[15]=	{0.00166532,0.00164177,0.00166393,0.00166593,0.00166771,0.00166794,0.00166332,0.00166815,0.00164722,0.00167203,0.0016592,0.00165171,0.00165513,0.00166384,0.0016878};
float  WigglErrOUT_dphi1percent2plus[15]=	{0.00332346,0.00327832,0.00332447,0.00332675,0.00332938,0.00332963,0.00332078,0.00333056,0.00328994,0.00333921,0.00331234,0.00329848,0.00330362,0.00332267,0.00337042};
float  WigglErrOUT_dphi1percent4plus[15]=	{0.00662334,0.00653546,0.00662909,0.00663181,0.00663625,0.00663654,0.00661939,0.00663871,0.00655919,0.00665683,0.00660219,0.00657574,0.00658428,0.00662387,0.00671869};
float  WigglErrOUT_dphi1percent5plus[15]=	{0.00826515,0.00815605,0.00827317,0.0082762,0.00828144,0.00828186,0.00826055,0.00828454,0.00818572,0.00830747,0.00823899,0.00820634,0.00821647,0.00826624,0.00838433};
float  WigglErrOUT_dphi1percent7plus[15]=	{0.0115325,0.0113814,0.0115451,0.0115486,0.0115555,0.011556,0.0115266,0.01156,0.011423,0.0115921,0.0114966,0.0114515,0.0114649,0.0115348,0.011699};
float  WigglErrOUT_dphi1percent10plus[15]=	{0.0163932,0.0161804,0.0164126,0.0164169,0.0164263,0.0164269,0.0163855,0.0164327,0.0162395,0.0164787,0.0163428,0.0162796,0.0162979,0.0163975,0.0166297};

float  WigglErrOUT_dphi1percent1minus[15]=	{0.00166768,0.00164761,0.0016738,0.00167234,0.00167224,0.00167228,0.00166838,0.00167328,0.00165444,0.00167906,0.00166353,0.00165821,0.00165825,0.00167049,0.00169443};
float  WigglErrOUT_dphi1percent2minus[15]=	{0.00334253,0.00330045,0.00335108,0.0033498,0.00335062,0.00335069,0.00334254,0.00335238,0.00331356,0.00336308,0.00333322,0.00332136,0.00332314,0.00334598,0.00339415};
float  WigglErrOUT_dphi1percent4minus[15]=	{0.00670908,0.00662245,0.00672246,0.00672176,0.00672435,0.00672454,0.00670775,0.00672758,0.00664821,0.00674814,0.00668934,0.00666445,0.00666964,0.00671391,0.00681102};
float  WigglErrOUT_dphi1percent5minus[15]=	{0.00840085,0.00829175,0.00841665,0.00841626,0.0084198,0.00842,0.0083988,0.00842366,0.00832383,0.00844928,0.00837587,0.00834429,0.00835135,0.00840636,0.00852817};
float  WigglErrOUT_dphi1percent7minus[15]=	{0.0118015,0.011647,0.0118223,0.0118225,0.0118278,0.0118282,0.011798,0.0118331,0.0116919,0.0118688,0.0117659,0.011721,0.0117315,0.0118084,0.0119801};
float  WigglErrOUT_dphi1percent10minus[15]=	{0.0169457,0.016722,0.016974,0.016975,0.0169831,0.0169837,0.0169401,0.0169907,0.0167865,0.0170418,0.0168939,0.0168285,0.0168445,0.0169547,0.0172027};

float  WigglErrOUT_dphi2percent1plus[15]=	{0.221215,0.194165,0.140872,0.104652,0.0888192,0.0850273,0.0771949,0.0757618,0.0747189,0.0760923,0.0772982,0.078854,0.0793893,0.073097,0.0846152};
float  WigglErrOUT_dphi2percent2plus[15]=	{0.441702,0.387691,0.281287,0.208965,0.177352,0.16978,0.154142,0.151279,0.149197,0.15194,0.154347,0.157455,0.158527,0.145961,0.168962};
float  WigglErrOUT_dphi2percent4plus[15]=	{0.880508,0.772842,0.560742,0.41658,0.353562,0.33847,0.307298,0.301585,0.29744,0.302902,0.3077,0.313899,0.316038,0.290996,0.336857};
float  WigglErrOUT_dphi2percent5plus[15]=	{1.09883,0.964471,0.699787,0.519885,0.441242,0.422411,0.383508,0.376376,0.371204,0.378017,0.384009,0.391745,0.394416,0.363167,0.420407};
float  WigglErrOUT_dphi2percent7plus[15]=	{1.53335,1.34586,0.976526,0.725496,0.615762,0.589488,0.535203,0.525241,0.518028,0.527531,0.535895,0.546693,0.55042,0.506826,0.586722};
float  WigglErrOUT_dphi2percent10plus[15]=	{2.17983,1.91329,1.38829,1.03144,0.875456,0.838115,0.760944,0.74676,0.736516,0.750012,0.761911,0.777267,0.782568,0.720618,0.834234};

float  WigglErrOUT_dphi2percent1minus[15]=	{0.221943,0.194807,0.141339,0.104994,0.089106,0.0853008,0.0774431,0.0760069,0.0749622,0.0763407,0.0775472,0.0791101,0.0796467,0.0733322,0.0848856};
float  WigglErrOUT_dphi2percent2minus[15]=	{0.444623,0.390258,0.283142,0.210331,0.178503,0.170878,0.155137,0.152261,0.150165,0.152929,0.155347,0.158477,0.159553,0.146899,0.170042};
float  WigglErrOUT_dphi2percent4minus[15]=	{0.892202,0.78311,0.568152,0.42204,0.358168,0.342866,0.311278,0.305513,0.301306,0.306854,0.311706,0.317984,0.320143,0.294742,0.341171};
float  WigglErrOUT_dphi2percent5minus[15]=	{1.11711,0.980515,0.711363,0.528416,0.448441,0.42928,0.389728,0.382514,0.377244,0.384194,0.390267,0.398126,0.400835,0.36902,0.427146};
float  WigglErrOUT_dphi2percent7minus[15]=	{1.56917,1.3773,0.999213,0.742217,0.629873,0.602952,0.547396,0.537273,0.529867,0.539636,0.548161,0.559199,0.562997,0.518298,0.599926};
float  WigglErrOUT_dphi2percent10minus[15]=	{2.25295,1.97748,1.43459,1.06557,0.90426,0.865598,0.785831,0.771318,0.760676,0.774716,0.786948,0.802789,0.808238,0.744041,0.86119};

float  WigglErrOUT_dphi3percent1plus[15]=	{0.220957,0.194093,0.140395,0.104545,0.0890717,0.0853015,0.0776783,0.0755398,0.0746649,0.0753667,0.0774415,0.0789662,0.079878,0.0741309,0.087996};
float  WigglErrOUT_dphi3percent2plus[15]=	{0.441187,0.387549,0.280335,0.208751,0.177855,0.170326,0.155106,0.150837,0.149091,0.150493,0.154633,0.157679,0.159501,0.148022,0.175702};
float  WigglErrOUT_dphi3percent4plus[15]=	{0.879483,0.772558,0.558853,0.416154,0.354562,0.339557,0.309212,0.300707,0.297227,0.300028,0.308269,0.314343,0.317975,0.295091,0.35025};
float  WigglErrOUT_dphi3percent5plus[15]=	{1.09756,0.964118,0.697434,0.519353,0.442488,0.423765,0.385895,0.375282,0.37094,0.374436,0.384718,0.392299,0.396828,0.36827,0.437094};
float  WigglErrOUT_dphi3percent7plus[15]=	{1.53157,1.34536,0.973254,0.724757,0.617496,0.591371,0.538522,0.523718,0.51766,0.522548,0.536881,0.547464,0.553776,0.513925,0.60993};
float  WigglErrOUT_dphi3percent10plus[15]=	{2.17732,1.9126,1.38365,1.0304,0.87791,0.84078,0.765641,0.744606,0.735995,0.742962,0.763306,0.778357,0.787317,0.730662,0.867075};

float  WigglErrOUT_dphi3percent1minus[15]=	{0.221683,0.194734,0.140859,0.104886,0.0893602,0.0855768,0.0779297,0.0757833,0.074908,0.0756104,0.0776916,0.0792231,0.0801384,0.0743727,0.0882884};
float  WigglErrOUT_dphi3percent2minus[15]=	{0.444101,0.390114,0.282179,0.210114,0.179012,0.171431,0.156113,0.151813,0.150057,0.151464,0.155637,0.158703,0.16054,0.148986,0.176869};
float  WigglErrOUT_dphi3percent4minus[15]=	{0.89115,0.782819,0.566213,0.421603,0.359194,0.34398,0.313243,0.304612,0.301088,0.303905,0.312289,0.31844,0.322131,0.298944,0.354916};
float  WigglErrOUT_dphi3percent5minus[15]=	{1.11579,0.98015,0.708932,0.527867,0.449728,0.430678,0.392193,0.381384,0.376972,0.380496,0.390998,0.398698,0.403326,0.37429,0.444384};
float  WigglErrOUT_dphi3percent7minus[15]=	{1.56731,1.37679,0.995787,0.741444,0.631687,0.604922,0.550868,0.53568,0.529482,0.534424,0.549193,0.560005,0.566509,0.525724,0.624217};
float  WigglErrOUT_dphi3percent10minus[15]=	{2.25027,1.97674,1.42964,1.06446,0.906877,0.86844,0.790841,0.769021,0.76012,0.767196,0.788434,0.803952,0.813304,0.754753,0.896234};

float  WigglErrOUT_dphi4percent1plus[15]=	{0.00166281,0.00166917,0.00165954,0.00166368,0.00165935,0.00167161,0.00166312,0.00164741,0.00167318,0.00165421,0.00165163,0.00166789,0.00165991,0.00166326,0.00162561};
float  WigglErrOUT_dphi4percent2plus[15]=	{0.00331852,0.003333,0.00331578,0.00332225,0.00331255,0.00333699,0.00332048,0.00328909,0.00334158,0.00330376,0.00329731,0.00333063,0.00331307,0.00332161,0.00324627};
float  WigglErrOUT_dphi4percent4plus[15]=	{0.00661352,0.00664407,0.00661171,0.00662288,0.00660282,0.00665125,0.00661879,0.00655647,0.00666178,0.00658652,0.00657243,0.00663972,0.00660308,0.00662175,0.00647195};
float  WigglErrOUT_dphi4percent5plus[15]=	{0.00825289,0.00829131,0.00825159,0.00826501,0.00823977,0.00830013,0.00825974,0.00818206,0.00831368,0.00821973,0.00820187,0.00828598,0.00823993,0.00826364,0.00807698};
float  WigglErrOUT_dphi4percent7plus[15]=	{0.0115154,0.0115696,0.0115151,0.0115331,0.0114975,0.0115814,0.0115255,0.0114174,0.0116009,0.0114702,0.0114448,0.0115622,0.0114976,0.0115311,0.0112715};
float  WigglErrOUT_dphi4percent10plus[15]=	{0.0163691,0.0164465,0.0163701,0.016395,0.0163443,0.0164629,0.0163839,0.0162312,0.0164911,0.0163062,0.0162697,0.0164363,0.0163441,0.0163923,0.016025};

float  WigglErrOUT_dphi4percent1minus[15]=	{0.00166517,0.00167521,0.00166941,0.00167002,0.00166376,0.00167596,0.00166818,0.00165235,0.0016806,0.00166124,0.00165597,0.00167448,0.00166302,0.00167,0.00163179};
float  WigglErrOUT_dphi4percent2minus[15]=	{0.00333751,0.00335576,0.00334221,0.0033453,0.00333356,0.00335815,0.00334223,0.00331042,0.00336588,0.00332723,0.00331799,0.00335402,0.00333269,0.00334492,0.00326842};
float  WigglErrOUT_dphi4percent4minus[15]=	{0.00669897,0.00673395,0.00670472,0.00671262,0.00668999,0.00673958,0.00670704,0.00664306,0.00675363,0.00667585,0.00665878,0.00673008,0.00668895,0.0067117,0.00655776};
float  WigglErrOUT_dphi4percent5minus[15]=	{0.00838816,0.00843159,0.00839443,0.00840474,0.00837674,0.00843893,0.00839799,0.00831772,0.00845609,0.00835857,0.00833744,0.00842661,0.00837554,0.00840366,0.00821047};
float  WigglErrOUT_dphi4percent7minus[15]=	{0.0117836,0.0118441,0.0117909,0.0118062,0.0117671,0.0118548,0.0117969,0.0116838,0.0118783,0.011741,0.0117117,0.011837,0.0117657,0.0118045,0.0115324};
float  WigglErrOUT_dphi4percent10minus[15]=	{0.0169199,0.0170064,0.0169287,0.0169516,0.0168955,0.0170221,0.0169384,0.0167753,0.0170555,0.0168574,0.0168157,0.016996,0.0168939,0.0169491,0.0165566};

float  WigglErrOUT_dphi5percent1plus[15]=	{0.222597,0.196185,0.142628,0.106373,0.0905061,0.0869744,0.0792788,0.0771553,0.0765725,0.0773561,0.0790572,0.0806701,0.0815822,0.0754776,0.0881182};
float  WigglErrOUT_dphi5percent2plus[15]=	{0.444449,0.391708,0.284771,0.212384,0.180704,0.173651,0.158285,0.154047,0.15288,0.154446,0.157843,0.161062,0.162884,0.150695,0.175933};
float  WigglErrOUT_dphi5percent4plus[15]=	{0.885924,0.780775,0.567617,0.423326,0.360179,0.34612,0.315486,0.30704,0.30471,0.307835,0.314605,0.321022,0.324652,0.300354,0.350662};
float  WigglErrOUT_dphi5percent5plus[15]=	{1.10555,0.974328,0.708325,0.528262,0.44946,0.431915,0.393683,0.383145,0.380235,0.384137,0.392584,0.400591,0.405123,0.374799,0.437579};
float  WigglErrOUT_dphi5percent7plus[15]=	{1.54262,1.35949,0.988321,0.737071,0.627116,0.602631,0.549278,0.534579,0.530512,0.535965,0.547745,0.55892,0.565232,0.522926,0.610524};
float  WigglErrOUT_dphi5percent10plus[15]=	{2.19279,1.93241,1.40481,1.04766,0.891357,0.856546,0.780693,0.759808,0.754009,0.761777,0.778511,0.794398,0.803356,0.743236,0.867747};

float  WigglErrOUT_dphi5percent1minus[15]=	{0.223351,0.196851,0.14311,0.106736,0.0908176,0.0872745,0.0795532,0.0774218,0.0768359,0.0776212,0.0793317,0.0809474,0.081864,0.0757377,0.0884211};
float  WigglErrOUT_dphi5percent2minus[15]=	{0.447458,0.394373,0.28671,0.213838,0.181946,0.174848,0.159381,0.155111,0.153939,0.155511,0.158938,0.162173,0.164015,0.151739,0.177147};
float  WigglErrOUT_dphi5percent4minus[15]=	{0.897951,0.791438,0.575386,0.429147,0.365146,0.350904,0.319869,0.311297,0.308951,0.312099,0.318978,0.325475,0.329173,0.304535,0.355523};
float  WigglErrOUT_dphi5percent5minus[15]=	{1.12434,0.990991,0.720465,0.537357,0.457221,0.439388,0.400531,0.389797,0.386862,0.390801,0.399417,0.407552,0.412185,0.381331,0.445175};
float  WigglErrOUT_dphi5percent7minus[15]=	{1.57945,1.39215,1.01212,0.754901,0.642327,0.617279,0.562701,0.547617,0.543502,0.549028,0.561137,0.572564,0.579079,0.53573,0.625417};
float  WigglErrOUT_dphi5percent10minus[15]=	{2.26796,1.99908,1.45339,1.08405,0.922404,0.886444,0.80809,0.78642,0.780528,0.788444,0.805847,0.82225,0.83162,0.769363,0.898145};

float pt[15];
float pterr[15];
for(int i=0 ; i<=15 ; i++) {
  pt[i] = 0.5+i*0.2 +0.1;
  pterr[i] = 0.0;
  if(i>11) pt[i] = 3.0 +((i-12)*0.5)+0.25;
  if(i>=15) { pt[i] = 4.5+(i-14) + 0.5;  }
}

TGraph * gr_dphi0percent1plus=	new TGraph(15,pt,WigglErrOUT_dphi0percent1plus);	
TGraph * gr_dphi0percent2plus=	new TGraph(15,pt,WigglErrOUT_dphi0percent2plus);	
TGraph * gr_dphi0percent4plus=	new TGraph(15,pt,WigglErrOUT_dphi0percent4plus);	
TGraph * gr_dphi0percent5plus=	new TGraph(15,pt,WigglErrOUT_dphi0percent5plus);	
TGraph * gr_dphi0percent7plus=	new TGraph(15,pt,WigglErrOUT_dphi0percent7plus);	
TGraph * gr_dphi0percent10plus=	new TGraph(15,pt,WigglErrOUT_dphi0percent10plus);	
TGraph * gr_dphi0percent1minus=	new TGraph(15,pt,WigglErrOUT_dphi0percent1minus);	
TGraph * gr_dphi0percent2minus=	new TGraph(15,pt,WigglErrOUT_dphi0percent2minus);	
TGraph * gr_dphi0percent4minus=	new TGraph(15,pt,WigglErrOUT_dphi0percent4minus);	
TGraph * gr_dphi0percent5minus=	new TGraph(15,pt,WigglErrOUT_dphi0percent5minus);	
TGraph * gr_dphi0percent7minus=	new TGraph(15,pt,WigglErrOUT_dphi0percent7minus);	
TGraph * gr_dphi0percent10minus=	new TGraph(15,pt,WigglErrOUT_dphi0percent10minus);	
TGraph * gr_dphi1percent1plus=	new TGraph(15,pt,WigglErrOUT_dphi1percent1plus);	
TGraph * gr_dphi1percent2plus=	new TGraph(15,pt,WigglErrOUT_dphi1percent2plus);	
TGraph * gr_dphi1percent4plus=	new TGraph(15,pt,WigglErrOUT_dphi1percent4plus);	
TGraph * gr_dphi1percent5plus=	new TGraph(15,pt,WigglErrOUT_dphi1percent5plus);	
TGraph * gr_dphi1percent7plus=	new TGraph(15,pt,WigglErrOUT_dphi1percent7plus);	
TGraph * gr_dphi1percent10plus=	new TGraph(15,pt,WigglErrOUT_dphi1percent10plus);	
TGraph * gr_dphi1percent1minus=	new TGraph(15,pt,WigglErrOUT_dphi1percent1minus);	
TGraph * gr_dphi1percent2minus=	new TGraph(15,pt,WigglErrOUT_dphi1percent2minus);	
TGraph * gr_dphi1percent4minus=	new TGraph(15,pt,WigglErrOUT_dphi1percent4minus);	
TGraph * gr_dphi1percent5minus=	new TGraph(15,pt,WigglErrOUT_dphi1percent5minus);	
TGraph * gr_dphi1percent7minus=	new TGraph(15,pt,WigglErrOUT_dphi1percent7minus);	
TGraph * gr_dphi1percent10minus=	new TGraph(15,pt,WigglErrOUT_dphi1percent10minus);	
TGraph * gr_dphi2percent1plus=	new TGraph(15,pt,WigglErrOUT_dphi2percent1plus);	
TGraph * gr_dphi2percent2plus=	new TGraph(15,pt,WigglErrOUT_dphi2percent2plus);	
TGraph * gr_dphi2percent4plus=	new TGraph(15,pt,WigglErrOUT_dphi2percent4plus);	
TGraph * gr_dphi2percent5plus=	new TGraph(15,pt,WigglErrOUT_dphi2percent5plus);	
TGraph * gr_dphi2percent7plus=	new TGraph(15,pt,WigglErrOUT_dphi2percent7plus);	
TGraph * gr_dphi2percent10plus=	new TGraph(15,pt,WigglErrOUT_dphi2percent10plus);	
TGraph * gr_dphi2percent1minus=	new TGraph(15,pt,WigglErrOUT_dphi2percent1minus);	
TGraph * gr_dphi2percent2minus=	new TGraph(15,pt,WigglErrOUT_dphi2percent2minus);	
TGraph * gr_dphi2percent4minus=	new TGraph(15,pt,WigglErrOUT_dphi2percent4minus);	
TGraph * gr_dphi2percent5minus=	new TGraph(15,pt,WigglErrOUT_dphi2percent5minus);	
TGraph * gr_dphi2percent7minus=	new TGraph(15,pt,WigglErrOUT_dphi2percent7minus);	
TGraph * gr_dphi2percent10minus=	new TGraph(15,pt,WigglErrOUT_dphi2percent10minus);	
TGraph * gr_dphi3percent1plus=	new TGraph(15,pt,WigglErrOUT_dphi3percent1plus);	
TGraph * gr_dphi3percent2plus=	new TGraph(15,pt,WigglErrOUT_dphi3percent2plus);	
TGraph * gr_dphi3percent4plus=	new TGraph(15,pt,WigglErrOUT_dphi3percent4plus);	
TGraph * gr_dphi3percent5plus=	new TGraph(15,pt,WigglErrOUT_dphi3percent5plus);	
TGraph * gr_dphi3percent7plus=	new TGraph(15,pt,WigglErrOUT_dphi3percent7plus);	
TGraph * gr_dphi3percent10plus=	new TGraph(15,pt,WigglErrOUT_dphi3percent10plus);	
TGraph * gr_dphi3percent1minus=	new TGraph(15,pt,WigglErrOUT_dphi3percent1minus);	
TGraph * gr_dphi3percent2minus=	new TGraph(15,pt,WigglErrOUT_dphi3percent2minus);	
TGraph * gr_dphi3percent4minus=	new TGraph(15,pt,WigglErrOUT_dphi3percent4minus);	
TGraph * gr_dphi3percent5minus=	new TGraph(15,pt,WigglErrOUT_dphi3percent5minus);	
TGraph * gr_dphi3percent7minus=	new TGraph(15,pt,WigglErrOUT_dphi3percent7minus);	
TGraph * gr_dphi3percent10minus=	new TGraph(15,pt,WigglErrOUT_dphi3percent10minus);	
TGraph * gr_dphi4percent1plus=	new TGraph(15,pt,WigglErrOUT_dphi4percent1plus);	
TGraph * gr_dphi4percent2plus=	new TGraph(15,pt,WigglErrOUT_dphi4percent2plus);	
TGraph * gr_dphi4percent4plus=	new TGraph(15,pt,WigglErrOUT_dphi4percent4plus);	
TGraph * gr_dphi4percent5plus=	new TGraph(15,pt,WigglErrOUT_dphi4percent5plus);	
TGraph * gr_dphi4percent7plus=	new TGraph(15,pt,WigglErrOUT_dphi4percent7plus);	
TGraph * gr_dphi4percent10plus=	new TGraph(15,pt,WigglErrOUT_dphi4percent10plus);	
TGraph * gr_dphi4percent1minus=	new TGraph(15,pt,WigglErrOUT_dphi4percent1minus);	
TGraph * gr_dphi4percent2minus=	new TGraph(15,pt,WigglErrOUT_dphi4percent2minus);	
TGraph * gr_dphi4percent4minus=	new TGraph(15,pt,WigglErrOUT_dphi4percent4minus);	
TGraph * gr_dphi4percent5minus=	new TGraph(15,pt,WigglErrOUT_dphi4percent5minus);	
TGraph * gr_dphi4percent7minus=	new TGraph(15,pt,WigglErrOUT_dphi4percent7minus);	
TGraph * gr_dphi4percent10minus=	new TGraph(15,pt,WigglErrOUT_dphi4percent10minus);	
TGraph * gr_dphi5percent1plus=	new TGraph(15,pt,WigglErrOUT_dphi5percent1plus);	
TGraph * gr_dphi5percent2plus=	new TGraph(15,pt,WigglErrOUT_dphi5percent2plus);	
TGraph * gr_dphi5percent4plus=	new TGraph(15,pt,WigglErrOUT_dphi5percent4plus);	
TGraph * gr_dphi5percent5plus=	new TGraph(15,pt,WigglErrOUT_dphi5percent5plus);	
TGraph * gr_dphi5percent7plus=	new TGraph(15,pt,WigglErrOUT_dphi5percent7plus);	
TGraph * gr_dphi5percent10plus=	new TGraph(15,pt,WigglErrOUT_dphi5percent10plus);	
TGraph * gr_dphi5percent1minus=	new TGraph(15,pt,WigglErrOUT_dphi5percent1minus);	
TGraph * gr_dphi5percent2minus=	new TGraph(15,pt,WigglErrOUT_dphi5percent2minus);	
TGraph * gr_dphi5percent4minus=	new TGraph(15,pt,WigglErrOUT_dphi5percent4minus);	
TGraph * gr_dphi5percent5minus=	new TGraph(15,pt,WigglErrOUT_dphi5percent5minus);	
TGraph * gr_dphi5percent7minus=	new TGraph(15,pt,WigglErrOUT_dphi5percent7minus);	
TGraph * gr_dphi5percent10minus=	new TGraph(15,pt,WigglErrOUT_dphi5percent10minus);	

int msize=1;

cplusminus = new TCanvas("cplusminus","cplusminus",4000,6000);
cplusminus->Divide(2,3);

cplusminus->cd(1);
TH1F *axis = drawFrame(0.0,0,4.5,1.7,"p_{T} GeV/c","v_{2} variance");
drawTitle(.3,-.07,"v_{2} variance, d#phi0 perturbations",1,12,.03,0);
gr_dphi0percent1plus->SetMarkerColor(1);	gr_dphi0percent1plus->SetMarkerStyle(20);	gr_dphi0percent1plus->SetMarkerSize(msize);		gr_dphi0percent1plus->Draw("PC");	
gr_dphi0percent1minus->SetMarkerColor(1);	gr_dphi0percent1minus->SetMarkerStyle(24);	gr_dphi0percent1minus->SetMarkerSize(msize);	gr_dphi0percent1minus->Draw("PC");	
gr_dphi0percent2plus->SetMarkerColor(1);	gr_dphi0percent2plus->SetMarkerStyle(20);	gr_dphi0percent2plus->SetMarkerSize(msize);		gr_dphi0percent2plus->Draw("PC");	
gr_dphi0percent2minus->SetMarkerColor(1);	gr_dphi0percent2minus->SetMarkerStyle(24);	gr_dphi0percent2minus->SetMarkerSize(msize);	gr_dphi0percent2minus->Draw("PC");	
gr_dphi0percent4plus->SetMarkerColor(1);	gr_dphi0percent4plus->SetMarkerStyle(20);	gr_dphi0percent4plus->SetMarkerSize(msize);		gr_dphi0percent4plus->Draw("PC");	
gr_dphi0percent4minus->SetMarkerColor(1);	gr_dphi0percent4minus->SetMarkerStyle(24);	gr_dphi0percent4minus->SetMarkerSize(msize);	gr_dphi0percent5minus->Draw("PC");	
gr_dphi0percent5plus->SetMarkerColor(1);	gr_dphi0percent5plus->SetMarkerStyle(20);	gr_dphi0percent5plus->SetMarkerSize(msize);		gr_dphi0percent5plus->Draw("PC");	
gr_dphi0percent5minus->SetMarkerColor(1);	gr_dphi0percent5minus->SetMarkerStyle(24);	gr_dphi0percent5minus->SetMarkerSize(msize);	gr_dphi0percent1minus->Draw("PC");	
gr_dphi0percent7plus->SetMarkerColor(1);	gr_dphi0percent7plus->SetMarkerStyle(20);	gr_dphi0percent7plus->SetMarkerSize(msize);		gr_dphi0percent7plus->Draw("PC");	
gr_dphi0percent7minus->SetMarkerColor(1);	gr_dphi0percent7minus->SetMarkerStyle(24);	gr_dphi0percent7minus->SetMarkerSize(msize);	gr_dphi0percent7minus->Draw("PC");	


cplusminus->cd(2);
TH1F *axis = drawFrame(0.0,0,4.5,0.02,"p_{T} GeV/c","v_{2} variance");
drawTitle(.3,-.07,"v_{2} variance, d#phi1 perturbations",1,12,.03,0);
gr_dphi1percent1plus->SetMarkerColor(1);	gr_dphi1percent1plus->SetMarkerStyle(20);	gr_dphi1percent1plus->SetMarkerSize(msize);		gr_dphi1percent1plus->Draw("PC");	
gr_dphi1percent1minus->SetMarkerColor(1);	gr_dphi1percent1minus->SetMarkerStyle(24);	gr_dphi1percent1minus->SetMarkerSize(msize);	gr_dphi1percent1minus->Draw("PC");	
gr_dphi1percent2plus->SetMarkerColor(1);	gr_dphi1percent2plus->SetMarkerStyle(20);	gr_dphi1percent2plus->SetMarkerSize(msize);		gr_dphi1percent2plus->Draw("PC");	
gr_dphi1percent2minus->SetMarkerColor(1);	gr_dphi1percent2minus->SetMarkerStyle(24);	gr_dphi1percent2minus->SetMarkerSize(msize);	gr_dphi1percent2minus->Draw("PC");	
gr_dphi1percent4plus->SetMarkerColor(1);	gr_dphi1percent4plus->SetMarkerStyle(20);	gr_dphi1percent4plus->SetMarkerSize(msize);		gr_dphi1percent4plus->Draw("PC");	
gr_dphi1percent4minus->SetMarkerColor(1);	gr_dphi1percent4minus->SetMarkerStyle(24);	gr_dphi1percent4minus->SetMarkerSize(msize);	gr_dphi1percent5minus->Draw("PC");	
gr_dphi1percent5plus->SetMarkerColor(1);	gr_dphi1percent5plus->SetMarkerStyle(20);	gr_dphi1percent5plus->SetMarkerSize(msize);		gr_dphi1percent5plus->Draw("PC");	
gr_dphi1percent5minus->SetMarkerColor(1);	gr_dphi1percent5minus->SetMarkerStyle(24);	gr_dphi1percent5minus->SetMarkerSize(msize);	gr_dphi1percent1minus->Draw("PC");	
gr_dphi1percent7plus->SetMarkerColor(1);	gr_dphi1percent7plus->SetMarkerStyle(20);	gr_dphi1percent7plus->SetMarkerSize(msize);		gr_dphi1percent7plus->Draw("PC");	
gr_dphi1percent7minus->SetMarkerColor(1);	gr_dphi1percent7minus->SetMarkerStyle(24);	gr_dphi1percent7minus->SetMarkerSize(msize);	gr_dphi1percent7minus->Draw("PC");	

cplusminus->cd(3);
TH1F *axis = drawFrame(0.0,0,4.5,1.7,"p_{T} GeV/c","v_{2} variance");
drawTitle(.3,-.07,"v_{2} variance, d#phi2 perturbations",1,12,.03,0);
gr_dphi2percent1plus->SetMarkerColor(1);	gr_dphi2percent1plus->SetMarkerStyle(20);	gr_dphi2percent1plus->SetMarkerSize(msize);		gr_dphi2percent1plus->Draw("PC");	
gr_dphi2percent1minus->SetMarkerColor(1);	gr_dphi2percent1minus->SetMarkerStyle(24);	gr_dphi2percent1minus->SetMarkerSize(msize);	gr_dphi2percent1minus->Draw("PC");	
gr_dphi2percent2plus->SetMarkerColor(1);	gr_dphi2percent2plus->SetMarkerStyle(20);	gr_dphi2percent2plus->SetMarkerSize(msize);		gr_dphi2percent2plus->Draw("PC");	
gr_dphi2percent2minus->SetMarkerColor(1);	gr_dphi2percent2minus->SetMarkerStyle(24);	gr_dphi2percent2minus->SetMarkerSize(msize);	gr_dphi2percent2minus->Draw("PC");	
gr_dphi2percent4plus->SetMarkerColor(1);	gr_dphi2percent4plus->SetMarkerStyle(20);	gr_dphi2percent4plus->SetMarkerSize(msize);		gr_dphi2percent4plus->Draw("PC");	
gr_dphi2percent4minus->SetMarkerColor(1);	gr_dphi2percent4minus->SetMarkerStyle(24);	gr_dphi2percent4minus->SetMarkerSize(msize);	gr_dphi2percent5minus->Draw("PC");	
gr_dphi2percent5plus->SetMarkerColor(1);	gr_dphi2percent5plus->SetMarkerStyle(20);	gr_dphi2percent5plus->SetMarkerSize(msize);		gr_dphi2percent5plus->Draw("PC");	
gr_dphi2percent5minus->SetMarkerColor(1);	gr_dphi2percent5minus->SetMarkerStyle(24);	gr_dphi2percent5minus->SetMarkerSize(msize);	gr_dphi2percent1minus->Draw("PC");	
gr_dphi2percent7plus->SetMarkerColor(1);	gr_dphi2percent7plus->SetMarkerStyle(20);	gr_dphi2percent7plus->SetMarkerSize(msize);		gr_dphi2percent7plus->Draw("PC");	
gr_dphi2percent7minus->SetMarkerColor(1);	gr_dphi2percent7minus->SetMarkerStyle(24);	gr_dphi2percent7minus->SetMarkerSize(msize);	gr_dphi2percent7minus->Draw("PC");	

cplusminus->cd(4);
TH1F *axis = drawFrame(0.0,0,4.5,1.7,"p_{T} GeV/c","v_{2} variance");
drawTitle(.3,-.07,"v_{2} variance, d#phi3 pertubations",1,12,.03,0);
gr_dphi3percent1plus->SetMarkerColor(1);	gr_dphi3percent1plus->SetMarkerStyle(20);	gr_dphi3percent1plus->SetMarkerSize(msize);		gr_dphi3percent1plus->Draw("PC");	
gr_dphi3percent1minus->SetMarkerColor(1);	gr_dphi3percent1minus->SetMarkerStyle(24);	gr_dphi3percent1minus->SetMarkerSize(msize);	gr_dphi3percent1minus->Draw("PC");	
gr_dphi3percent2plus->SetMarkerColor(1);	gr_dphi3percent2plus->SetMarkerStyle(20);	gr_dphi3percent2plus->SetMarkerSize(msize);		gr_dphi3percent2plus->Draw("PC");	
gr_dphi3percent2minus->SetMarkerColor(1);	gr_dphi3percent2minus->SetMarkerStyle(24);	gr_dphi3percent2minus->SetMarkerSize(msize);	gr_dphi3percent2minus->Draw("PC");	
gr_dphi3percent4plus->SetMarkerColor(1);	gr_dphi3percent4plus->SetMarkerStyle(20);	gr_dphi3percent4plus->SetMarkerSize(msize);		gr_dphi3percent4plus->Draw("PC");	
gr_dphi3percent4minus->SetMarkerColor(1);	gr_dphi3percent4minus->SetMarkerStyle(24);	gr_dphi3percent4minus->SetMarkerSize(msize);	gr_dphi3percent5minus->Draw("PC");	
gr_dphi3percent5plus->SetMarkerColor(1);	gr_dphi3percent5plus->SetMarkerStyle(20);	gr_dphi3percent5plus->SetMarkerSize(msize);		gr_dphi3percent5plus->Draw("PC");	
gr_dphi3percent5minus->SetMarkerColor(1);	gr_dphi3percent5minus->SetMarkerStyle(24);	gr_dphi3percent5minus->SetMarkerSize(msize);	gr_dphi3percent1minus->Draw("PC");	
gr_dphi3percent7plus->SetMarkerColor(1);	gr_dphi3percent7plus->SetMarkerStyle(20);	gr_dphi3percent7plus->SetMarkerSize(msize);		gr_dphi3percent7plus->Draw("PC");	
gr_dphi3percent7minus->SetMarkerColor(1);	gr_dphi3percent7minus->SetMarkerStyle(24);	gr_dphi3percent7minus->SetMarkerSize(msize);	gr_dphi3percent7minus->Draw("PC");	

cplusminus->cd(5);
TH1F *axis = drawFrame(0.0,0,4.5,0.02,"p_{T} GeV/c","v_{2} variance");
drawTitle(.3,-.07,"v_{2} variance, d#phi4 perturbations",1,12,.03,0);
gr_dphi4percent1plus->SetMarkerColor(1);	gr_dphi4percent1plus->SetMarkerStyle(20);	gr_dphi4percent1plus->SetMarkerSize(msize);		gr_dphi4percent1plus->Draw("PC");	
gr_dphi4percent1minus->SetMarkerColor(1);	gr_dphi4percent1minus->SetMarkerStyle(24);	gr_dphi4percent1minus->SetMarkerSize(msize);	gr_dphi4percent1minus->Draw("PC");	
gr_dphi4percent2plus->SetMarkerColor(1);	gr_dphi4percent2plus->SetMarkerStyle(20);	gr_dphi4percent2plus->SetMarkerSize(msize);		gr_dphi4percent2plus->Draw("PC");	
gr_dphi4percent2minus->SetMarkerColor(1);	gr_dphi4percent2minus->SetMarkerStyle(24);	gr_dphi4percent2minus->SetMarkerSize(msize);	gr_dphi4percent2minus->Draw("PC");	
gr_dphi4percent4plus->SetMarkerColor(1);	gr_dphi4percent4plus->SetMarkerStyle(20);	gr_dphi4percent4plus->SetMarkerSize(msize);		gr_dphi4percent4plus->Draw("PC");	
gr_dphi4percent4minus->SetMarkerColor(1);	gr_dphi4percent4minus->SetMarkerStyle(24);	gr_dphi4percent4minus->SetMarkerSize(msize);	gr_dphi4percent5minus->Draw("PC");	
gr_dphi4percent5plus->SetMarkerColor(1);	gr_dphi4percent5plus->SetMarkerStyle(20);	gr_dphi4percent5plus->SetMarkerSize(msize);		gr_dphi4percent5plus->Draw("PC");	
gr_dphi4percent5minus->SetMarkerColor(1);	gr_dphi4percent5minus->SetMarkerStyle(24);	gr_dphi4percent5minus->SetMarkerSize(msize);	gr_dphi4percent1minus->Draw("PC");	
gr_dphi4percent7plus->SetMarkerColor(1);	gr_dphi4percent7plus->SetMarkerStyle(20);	gr_dphi4percent7plus->SetMarkerSize(msize);		gr_dphi4percent7plus->Draw("PC");	
gr_dphi4percent7minus->SetMarkerColor(1);	gr_dphi4percent7minus->SetMarkerStyle(24);	gr_dphi4percent7minus->SetMarkerSize(msize);	gr_dphi4percent7minus->Draw("PC");	

cplusminus->cd(6);
TH1F *axis = drawFrame(0.0,0,4.5,1.7,"p_{T} GeV/c","v_{2} variance");
drawTitle(.3,-.07,"v_{2} variance, d#phi5 perturbations",1,12,.03,0);
gr_dphi5percent1plus->SetMarkerColor(1);	gr_dphi5percent1plus->SetMarkerStyle(20);	gr_dphi5percent1plus->SetMarkerSize(msize);		gr_dphi5percent1plus->Draw("PC");	
gr_dphi5percent1minus->SetMarkerColor(1);	gr_dphi5percent1minus->SetMarkerStyle(24);	gr_dphi5percent1minus->SetMarkerSize(msize);	gr_dphi5percent1minus->Draw("PC");	
gr_dphi5percent2plus->SetMarkerColor(1);	gr_dphi5percent2plus->SetMarkerStyle(20);	gr_dphi5percent2plus->SetMarkerSize(msize);		gr_dphi5percent2plus->Draw("PC");	
gr_dphi5percent2minus->SetMarkerColor(1);	gr_dphi5percent2minus->SetMarkerStyle(24);	gr_dphi5percent2minus->SetMarkerSize(msize);	gr_dphi5percent2minus->Draw("PC");	
gr_dphi5percent4plus->SetMarkerColor(1);	gr_dphi5percent4plus->SetMarkerStyle(20);	gr_dphi5percent4plus->SetMarkerSize(msize);		gr_dphi5percent4plus->Draw("PC");	
gr_dphi5percent4minus->SetMarkerColor(1);	gr_dphi5percent4minus->SetMarkerStyle(24);	gr_dphi5percent4minus->SetMarkerSize(msize);	gr_dphi5percent5minus->Draw("PC");	
gr_dphi5percent5plus->SetMarkerColor(1);	gr_dphi5percent5plus->SetMarkerStyle(20);	gr_dphi5percent5plus->SetMarkerSize(msize);		gr_dphi5percent5plus->Draw("PC");	
gr_dphi5percent5minus->SetMarkerColor(1);	gr_dphi5percent5minus->SetMarkerStyle(24);	gr_dphi5percent5minus->SetMarkerSize(msize);	gr_dphi5percent1minus->Draw("PC");	
gr_dphi5percent7plus->SetMarkerColor(1);	gr_dphi5percent7plus->SetMarkerStyle(20);	gr_dphi5percent7plus->SetMarkerSize(msize);		gr_dphi5percent7plus->Draw("PC");	
gr_dphi5percent7minus->SetMarkerColor(1);	gr_dphi5percent7minus->SetMarkerStyle(24);	gr_dphi5percent7minus->SetMarkerSize(msize);	gr_dphi5percent7minus->Draw("PC");	


cplusminus->SaveAs("plusminusstudy.jpg");


}

