#include"testlib.h"
#include<iostream>
#include<cstdio>
using namespace std;
vector<string>base={
    "The Green Run series of tests began in January 2020, when the stage was delivered from NASA’s Michoud Assembly Facility in New Orleans and installed in the B-2 test stand at Stennis. The team completed the first of the eight tests in the Green Run series before standing down in March due to the ongoing coronavirus pandemic. After resuming work in May, the team worked through the remaining tests in the series, while also standing down periodically as six tropical storms or hurricanes affected the Gulf Coast. Each test built upon the previous test with increasing complexity to evaluate the stages’ sophisticated systems, and the hot fire test that lit up all four engines was the final test in the series",
    "In addition to analyzing the data, teams also will inspect the core stage and its four RS-25 engines before determining the next steps. Under the Artemis program, NASA is working to land the first woman and the next man on the Moon in 2024. SLS and the Orion spacecraft that will carry astronauts to space, along with the human landing system and the Gateway in orbit around the Moon, are NASA’s backbone for deep space exploration",
    "NASA conducted a hot fire Saturday of the core stage for the agency’s Space Launch System (SLS) rocket that will launch the Artemis I mission to the Moon. The hot fire is the final test of the Green Run series.",
    "The victim is a star that exploded long ago in the Small Magellanic Cloud, a satellite galaxy to our Milky Way. The doomed star left behind an expanding, gaseous corpse, a supernova remnant named 1E 0102.2-7219, which NASA's Einstein Observatory first discovered in X-rays. Like detectives, researchers sifted through archival images taken by Hubble, analyzing visible-light observations made 10 years apart.",
    "To calculate an accurate explosion age, the astronomers picked the 22 fastest moving ejecta clumps, or knots. The researchers determined that these targets were the least likely to have been slowed down by passage through interstellar material. They then traced the knots' motion backward until the ejecta coalesced at one point, identifying the explosion site. Once that was known, they could calculate how long it took the speedy knots to travel from the explosion center to their current location.",
    "Hubble also clocked the speed of a suspected neutron star—the crushed core of the doomed star—that was ejected from the blast. Based on their estimates, the neutron star must be moving at more than 2 million miles per hour from the center of the explosion to have arrived at its current position. The suspected neutron star was identified in observations with the European Southern Observatory's Very Large Telescope in Chile, in combination with data from NASA's Chandra X-ray Observatory.",
    "The Hubble Space Telescope is a project of international cooperation between NASA and ESA (European Space Agency). NASA's Goddard Space Flight Center in Greenbelt, Maryland, manages the telescope. The Space Telescope Science Institute (STScI) in Baltimore, Maryland, conducts Hubble science operations. STScI is operated for NASA by the Association of Universities for Research in Astronomy in Washington, D.C.",
    "Like intergalactic paparazzi, NASA's Hubble Space Telescope captured the quick, fading celebrity status of a supernova, the self-detonation of a star. The Hubble snapshots have been assembled into a telling movie of the titanic stellar blast disappearing into oblivion in the spiral galaxy NGC 2525, located 70 million light-years away.",
    "\"A prior study compared images taken years apart with two different cameras on Hubble, the Wide Field Planetary Camera 2 and the Advanced Camera for Surveys (ACS),\" Milisavljevic said. \"But our study compares data taken with the same camera, the ACS, making the comparison much more robust; the knots were much easier to track using the same instrument. It's a testament to the longevity of Hubble that we could do such a clean comparison of images taken 10 years apart.",
    "Credits: NASA, ESA, and J. Banovetz and D. Milisavljevic (Purdue University)"
};
int siz[10];
string reviewStr(string s){
    string cur="",fin="";
    int num=0;
    for(auto &&c:s){
        if(c>='A'&&c<='Z')c=c-'A'+'a';
        if(c==' '){
            if(cur.length()){
                if(fin.length())fin+=" ";
                fin+=cur;
                num++;
            }
            cur="";
        }
        if(c<'a'||c>'z')continue;
        cur+=c;
    }
    return fin;
}
int countStr(string s){
    int num=1;
    for(auto c:s)num+=(c==' ');
    return num;
}
string randStr(){
    string s=rnd.any(base);
    for(auto &&c:s)c=(c==' ')?'|':c;
    return rnd.next(s);
}
string makeArticle(){
    string now=rnd.any(base);
    while(true){
        string nxt=rnd.any(base);
        if(now.length()+nxt.length()<5000){
            now=now+" "+nxt;
        }
        else{
            break;
        }
    }
    return now;
}
int main(int argc,char *argv[]){
    registerGen(argc,argv,1);
    int cnt=0;
    for(auto &&s:base){
        s=reviewStr(s);
        ++cnt;
    }
    for(int i=4;i<=10;i++){
        startTest(i);
        int n=rnd.next(700,1000);
        cout<<n<<endl;
        for(int i=1;i<=n;i++){
            string art=makeArticle();
            cout<<countStr(art)<<" "<<art<<endl;
        }
        int m=rnd.next(7000,10000);
        cout<<m<<endl;
        for(int i=1;i<=m;i++){
            if(!rnd.next(30)){
                cout<<"accoder"<<endl;
            }
            else{
                cout<<randStr()<<endl;
            }
        }
    }
    return 0;
}