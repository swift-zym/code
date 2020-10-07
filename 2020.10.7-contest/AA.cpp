#include<bits/stdc++.h>
using namespace std;
int ans;
int np[1000001],val[1000001];
vector<int>prime;
int n;
int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        if(!np[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=n;j++){
            np[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=1;i<=n;i++){
        int num=0;
        for(auto j=prime.begin();j!=prime.end()&&(*j)<=i;j++){
            if(i%(*j)==0)num++;
        }
        ans+=(1<<num);
    }
    cout<<ans<<endl;
    return 0;
}