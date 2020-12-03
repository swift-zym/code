#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> pd;
#define mp make_pair
int n;
pd fix(double h,double m,double s){
    double a=m*6+s/60*6,b=h*30+m/60*30+s/60/60*30;
    if(a>=360)a-=360;if(b>=360)b-=360;
    return mp(a,b);
}
pd a[50001];
int T;
double val=1e9;
double check(double s){
    double h=floor(s/3600),m=floor((s-h*3600)/60);s=s-h*3600-m*60;
    auto tmp=fix(h,m,s);
    double mx=0;
    for(int i=1;i<=n;i++){
        T++;
        if(T==400000000){
            cout<<fixed<<setprecision(10)<<val<<endl;
            exit(0);
        }
        mx=max(mx,min(fabs(tmp.first-a[i].first),360.0-fabs(tmp.first-a[i].first)));
        mx=max(mx,min(fabs(tmp.second-a[i].second),360.0-fabs(tmp.second-a[i].second)));
    }
    return mx;
}
int cov(int h,int m,int s){
    return s+m*60+h*3600;
}
vector<int>v;
#define eps 1e-8
#define down 0.996
void sa(){
    int now=v[v.size()/2];
    double ans=check(now);
    double t=3000;
    while (t>eps) {
        double nxt=now+(rand()*2-RAND_MAX)/max(int(1000/(t/eps)),1);
        if(rand()%2){
            nxt+=rand()%2?0.5:-0.5;
        }
        if(nxt>=60*60*24)nxt-=60*60*24;
        if(nxt<0)nxt+=60*60*24;
        double newAns=check(nxt);
        if(newAns<ans){
            now=nxt;
            ans=newAns;
            //cout<<nxt<<" "<<newAns<<endl;
        }
        else if(exp(-newAns/t)*RAND_MAX>rand()){
            now=nxt;
        }
        t*=down;
        val=min(val,ans);
    }
}
void file(){
    freopen("unreal.in","r",stdin);
    freopen("unreal.out","w",stdout);
}
void file_debug(){
    freopen("unreal20.in","r",stdin);
    freopen("unreal20.txt","w",stdout);
}
int to_int(string s){
    return (s[0]-'0')*10+(s[1]-'0');
}
int main(){
    file();
    //ios::sync_with_stdio(false);
    //srand(time(0));
    cin>>n;
    for(int i=1;i<=n;i++){
        int h,m,s;char c;
        string str;
        cin>>str;
        h=to_int(str.substr(0,2));
        m=to_int(str.substr(3,2));
        s=to_int(str.substr(6,2));
        a[i]=fix(h,m,s);
        v.push_back(cov(h,m,s));
    }
    sort(v.begin(),v.end());
    sa();
    sa();
    sa();
    cout<<fixed<<setprecision(10)<<val<<endl;
    return 0;
}
/*
2
12:30:00
02:40:00
*/
/*
3
00:00:00
23:59:59
06:30:30
*/