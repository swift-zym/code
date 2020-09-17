//
// Created by swift on 2020/7/30.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int np[10000001],miu[10000001],sum[10000001],tmp[10000001];
inline void read(int&x)
{
    char c=getchar();x=0;
    while(c>'9'||c<'0') c=getchar();
    while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
}
int cnt;
int prime[10000001];
void preWork(){
    np[1]=1;
    miu[1]=1;
    for(int i=2;i<=10000000;i++){
        if(!np[i]){
            prime[++cnt]=i;
            miu[i]=-1;
        }
        for(int j=1;j<=cnt&&i*prime[j]<=10000000;j++){
            np[i*prime[j]]=1;
            if(i%prime[j]==0)break;
            else{
                miu[i*prime[j]]=-miu[i];
            }
        }
    }
    for(int i=1;i<=cnt;i++)
        for(int j=1;j*prime[i]<=10000000;j++){
            tmp[j*prime[i]]+=miu[j];
        }
    for(int i=1;i<=10000000;i++){
        sum[i]=sum[i-1]+tmp[i];
    }
}
int n,a,b;
signed main(){
    preWork();
    read(n);
    while(n--){
        read(a);read(b);
        if(a>b)swap(a,b);
        int ans=0;
        for(int i=1,j;i<=a;i=j+1){
            j=min(a/(a/i),b/(b/i));
            ans+=(sum[j]-sum[i-1])*(a/i)*(b/i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
 * 7448821a-c70a-41e7-94a3-47248159b51a
 * 9o7C0X6tnU_ge41~8_Vam96Ox~N533VVGU
 * GITHUB_TOEKN 440736cc77184eb5f6ed7dd75739f10d92b3d435
 */