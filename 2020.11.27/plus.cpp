#include<iostream>
using namespace std;
int biao[]={0,0,0,0,0,0,0,0,1,4,6,8,13,16,22,24,22,32,34,40,47,48,56,68,70,76,90,84,111,112,126,120,144,120,176,140,184,148,226,168,264,184,262,196,313,192,352,208,366,256,418,240,473,260,496,324,536,300,616,308,634,348,670,348,772,364,786,412,855,420,956,388,952,472,1032,456,1131,424,1170,580,1234,516,1356,504,1416,640,1442,564,1602,584,1678,708,1675,648,1908,644,1954,780,1958,744,2200,612,2208,832,2242,804,2484,688,2574,952,2558,840,2782,752,2944,1024,2867,936,3164,892,3360,1116,3210,1044,3637,988,3766,1176,3614,1128,4044,952,4144,1288,4088,1224,4472,964,4650,1392,4478,1212,4828,1004,5152,1480,4882,1308,5337,1176,5706,1536,5278,1392,5900,1264,6210,1552,5772,1560,6460,1252,6730,1720,6393,1644,6976,1248,7320,1804,6878,1560,7405,1396,8016,2028,7448,1692,8048,1472,8686,1980,7866,1848,8792,1616,9340,2056,8505,2064,9564,1584,9990,2208,9304,2100,10110,1552,10686,2320,9952,2148,10720,1772,11680,2452,10590,2148,11374,1872,12438,2520,11147,2304,12356,2080,13264,2668,11990,2544,13292,1912,13990,2796,12898,2664,13996,1908,14940,2920,13718,2628,14728,2032,16044,2968,14339,2544,15396,2204,16972,3048,15008,2892,16623,2428,17988,3028,15814,3108,17584,2380,18796,3324,17096,3180,18474,2356,19890,3564,18214,3156,19296,2452,21126,3600,18870,3192,20231,2648,22420,3648,19650,3480,21604,2776,23412,3640,20570,3708,22790,2736,24438,3952,22115,3876,23780,2776,25830,4084,23292,3756,24571,2992,27328,4344,24230,3684,25752,3172,28764,4380,25130,3984,27320,3280,29794,4392,26168,4344,28872,3208,31114,4648,27852,4440,29933,3172,32502,4864,29236,4344,30992,3368,34360,4920,30212,4308,32210,3652,36022,4824,31007,4584,33816,3768,37158,4972,32406,4824,35502,3640,38320,5452,34336,5040,36744,3576,39990,5604,35906,4956,37978,3808,42228,5704,36925,4884,39368,4000,44004,5616,37774,5292,41420,4084,45318,5520,39156,5604,43056,4128,46794,5932,41284,5628,44150,4032,48600,6232,43200,5424,45468,4444,50842,6544,44358,5400,47197,4528,52878,6276,45218,5976,49572,4700,54322,6348,46866,6336,51600,4488,55758,6700,49185,6396,52812,4348,57816,6900,51164,6348,54117,4864,60748,7024,52286,6048,55560,5056,62938,6984,53520,6564,58292,5284,64182,7072,55375,6972,60548,4980,65706,7488,57912,7176,61869,4888,68112,7912,60298,7032,63524,5196,71202,7888,61200,6768,65302,5600,73930,7776,62449,7476,68316,5852,75592,7476,64258,7704,70366,5616,76998,8284,67550,7860,71988,5608,79422,8692,70274,7716,73550,5888,82696,8772,71294,7716,75800,6096,85956,8916,72734,8292,79244,6244,87354,8472,74546,8640,81920,6124,89428,9112,78064,8928,83268,6004,92388,9252,80746,8544,84468,6460,95884,9640,82294,8316,87045,6748,99192,9708,83736,8820,90396,7108,100596,9408,85878,9468,93912,6724,102856,10152,89557,9708,95504,6460,105516,10396,92502,9384,97460,7092,109992,10416,93938,9288,99580,7312,113818,10224,95242,9732,103038,7636,115366,10144,97893,10056,106764,7500,117132,11020,102128,10284,108045,7116,120066,11208,105420,10116,110296,7468,124680,11460,106570,9924,112880,7708,128406,11400,108012,10452,117188,8132,130582,10852,110340,10992,120616,7972,132856,11488,114600,11124,121784,7584,136074,11976,118430,10896,124040,8276,140392,12336,120045,10356,126452,8408,144418,12180,121628,11340,131081,8692,146496,11836,123772,11856,135564,8292,148494,12700,128372,11988,137096,8196,152346,12928,132584,12072,139080,8908,157794,12892,133810,11400,141449,9084,162426,13140,135980,12168,146300,9604,163882,12964,138774,12492,150750,9072,166104,13764,143706,12924,152456,8752,170124,14140,147940,12816,155297,9316,175416,14268,148960,12300,158396,9820,180936,14136,151264,13392,163336,10156,183090,13420,153597,13836,167636,9844,185878,14616,159512,13920,169470,9588,189414,15280,164730,13476,171728,10208,194806,15408,166040,13248,175352,10568,201004,15408,167893,14364,181336,10500,202368,14728,170558,14856,186666,10516,205858,15792,176788,15240,187980,10132,210552,15972,181562,14736,189838,10860,216900,16384,183411,13728,193620,11596,222760,16452,185530,14904,199487,11516,223792,15780,188960,15744,205700,11112,227100,16900,194740,16176,207352,10464,231246,17176,200216,15672,210288,11484,238500,17548,201728,15096,213576,11992,245802,16980,203070,16092,219228,12172,247408,16708,207152,16632,225754,12144,249966,17956,214275,16692,226792,11464,254034,18216,220598,16632,230039,12112,261580,18904,221262,16104,234176,12604,268818,18408,222910,16896,241350,12960,270792,17604,226577,18072,247544,12736,274474,18424,233272,17952,248357,12036,279090,19188,240640,17592,251240,13168,286182,19740,242302,16596,254794,13336,293512,19488,244190,18300,262676,13412,295612,18640,247532,19008,269866,13020,298194,20028,254566,18996,271636,12484,303690,20152,262116,18900,273820,13700,312412,20188,262450,17988,277096,13992,321180,20520,265094,19212,285061,14768,322054,19800,269956,19500,292140,14044,324634,21132,277664,20388,294218,13428,330732,21592,285060,19992,297832,14344,338442,21808,285538,18792,302130,14572,348150,21576,288038,20508,309584,15312,350094,20220,291244,21192,317200,14860,354034,22156,300786,21132,318352,14428,358506,22996,309626,20472,321419,15112,366720,23040,310406,20340,326376,15456,377574,23136,312310,21732,335168,15672,378120,21840,315735,22068,344344,15396,382272,23488,325532,22452,344569,14956,388842,23388,332644,21912,347324,16024,398824,23956,334326,21012,352292,16740,407814,24528,337861,22308,360448,16640,408556,22680,342114,23484,370726,16288,412804,24832,350910,23784,371840,15268,418530,25068,359492,22716,375816,16724,428680,25176,360381,22392,380252,17176,440286,24504,362098,23712,387537,17640,441888,23940,367956,24408,398632,17328,444330,26056,378432,24132,397922,16168,449958,26244,387778,23952,402756,17656,461628,26508,387030,23100,408422,17560,471888,26304,389246,24624,418272,18436,472930,25036,394852,26028,428666};
int main(){
    freopen("plus.in","r",stdin);
    freopen("plus.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        printf("%d\n",biao[n]);
    }
    return 0;
}