#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
namespace euler{
    int vv[5000001],np[5000001],sv[5000001];
    unordered_map<int,int>v;
    vector<int>prime;
    int tmp=5000000;
    void pre(){
        //tmp=pow(n,2.0/3.0);
        vv[1]=sv[1]=1;
        for(int i=2;i<=tmp;i++){
            if(!np[i]){
                prime.push_back(i);
                vv[i]=i-1;
            }
            for(int j=0;j<prime.size()&&i*prime[j]<=tmp;j++){
                np[i*prime[j]]=1;
                if(i%prime[j]==0){
                    vv[i*prime[j]]=vv[i]*(prime[j]);
                    break;
                }
                else{
                    vv[i*prime[j]]=vv[i]*(prime[j]-1);
                }
            }
            sv[i]=sv[i-1]+vv[i];
        }
    }
    int getsum(int m){
        if(m<=tmp)return sv[m];
        if(v[m])return v[m];
        int sum=m*(m+1)/2;
        for(int l=2,r;l<=m;l=r+1){
            r=(m/(m/l));
            sum-=(r-l+1)*getsum(m/l);
        }
        return v[m]=sum;
    }
    void solve(){
        //pre();
        printf("%lld ",getsum(n));
    }
}
namespace mobius{
    int vv[5000001],np[5000001],sv[5000001];
    unordered_map<int,int>v;
    vector<int>prime;
    int tmp=5000000;
    void pre(){
        //tmp=pow(n,2.0/3.0);
        vv[1]=sv[1]=1;
        for(int i=2;i<=tmp;i++){
            if(!np[i]){
                prime.push_back(i);
                vv[i]=-1;
            }
            for(int j=0;j<prime.size()&&i*prime[j]<=tmp;j++){
                np[i*prime[j]]=1;
                if(i%prime[j]==0){
                    vv[i*prime[j]]=0;
                    break;
                }
                else{
                    vv[i*prime[j]]=vv[i]*-1;
                }
            }
            sv[i]=sv[i-1]+vv[i];
        }
    }
    int getsum(int m){
        if(m<=tmp)return sv[m];
        if(v[m])return v[m];
        int sum=1;
        for(int l=2,r;l<=m;l=r+1){
            r=(m/(m/l));
            sum-=(r-l+1)*getsum(m/l);
        }
        return v[m]=sum;
    }
    void solve(){
        //pre();
        printf("%lld\n",getsum(n));
    }
}
signed main(){
    euler::pre();
    mobius::pre();
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        euler::solve();
        mobius::solve();
    }
    return 0;
}