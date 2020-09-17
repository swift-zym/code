#include<bits/stdc++.h>
using namespace std;
int np[10000001],sum[10000001];
vector<int>prime;
void pre(){
    np[1]=1;
    for(int i=2;i<=10000000;i++){
        if(!np[i]){
            sum[i]++;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=10000000;j++){
            np[i*prime[j]]=1;
            if(!np[i]){
                sum[i*prime[j]]++;
            }
            if(i%prime[j]==0)break;
        }
        sum[i]+=sum[i-1];
    }
}
int main(){
    pre();
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);
    }
    return 0;
}