#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
#define MOD 1000000007
using namespace std;
int qpow(int a,int b){
    if(b==0)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
vector<int>v;
int t[100];
int N;
void add(int x,int v){
    for(;x<=N;x+=x&-x){
        t[x]+=v;
    }
}
int sum(int x){
    int v=0;
    for(;x;x-=x&-x){
        v+=t[x];
    }
    return v;
}
int solve(int n,int k){
    if(k>n*(n-1)/2){
        return 0;
    }
    if(k==0){
        return 1;
    }
    else if(k==1){
        return n-1;
    }
    else if(k==2){
        return(n*(n-1)/2-1)%MOD;
    }
    else if(k==3){
        int ans=1;
        for(int i=3;i<n;i++){
            ans+=(i*(i+1)/2-1)%MOD;
            ans%=MOD;
        }
        return ans;
    }
    else{
        int ans=0;
        v.clear();
        for(int i=1;i<=n;i++)v.push_back(i);
        do{
            int val=0;
            for(int i=1;i<=n;i++)t[i]=0;
            for(int i=1;i<=n;i++){
                val+=(i-1)-sum(v[i-1]);
                add(v[i-1],1);
            }
            ans+=(val==k);
        }while(next_permutation(v.begin(),v.end()));
        return ans;
    }
}
signed main(){
    int n,k,ans=0;
    cin>>n>>k;
    N=n;
    for(int i=0;i<=k;i++){
        ans+=solve(n,i);
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}