#include<bits/stdc++.h>
#define int long long
using namespace std;
int qpow(int a,int b,int p){
    if(b==0)return 1;
    int tmp=qpow(a,b/2,p);
    return b%2?tmp*tmp%p*a%p:tmp*tmp%p;
}
vector<int>prime;
int np[100000];
signed main(){
    vector<int>v;
    int p;
    cin>>p;
    int pp=sqrt(p);
    np[1]=1;
    for(int i=2;i<=pp;i++){
        if(!np[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=pp;i++){
            np[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=0;i<prime.size();i++){
        if((p-1)%prime[i]==0)v.push_back(prime[i]);
    }
    for(int i=2;i<=p-1;i++){
        bool flag=1;
        for(int j=0;j<v.size();j++){
            if(qpow(i,(p-1)/v[j],p)==1){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}