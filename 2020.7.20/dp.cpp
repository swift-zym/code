//
//  main.cpp
//  On Mac
//
//  Created by 张一鸣 on 2020/7/18.
//
#include "bits/stdc++.h"
#define MOD 1000000007
#define int long long
using namespace std;
int dp[1010][1<<15];
int ans[100];
int go[1<<15][5];
int len;
string s,ACGT="$ACGT";
int m;
int a[100],b[100],num[1<<15];
void init(){
    memset(go, 0, sizeof(go));
    memset(ans, 0, sizeof(ans));
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(ans, 0, sizeof(ans));
}
void preWork(){
    for(int i=0;i<(1<<len);i++){
        for(int j=1;j<=len;j++){
            a[j]=a[j-1];
            if(i&(1<<(j-1))){
                a[j]++;
            }
            //cout<<a[j]<<endl;
        }
        num[i]=a[len];
        for(int j=1;j<=4;j++){
            for(int k=1;k<=len;k++){
                b[k]=max(b[k-1],a[k]);
                if (ACGT[j]==s[k]) {
                    b[k]=max(b[k], a[k-1]+1);
                }
                //cout<<k<<" "<<b[k]<<endl;
            }
            for(int k=1;k<=len;k++){
                if (b[k]-b[k-1]>0) {
                    //cout<<k<<endl;
                    go[i][j]|=(1<<(k-1));
                }
            }
        }
    }
    dp[0][0]=1;
}
void solve(){
    for(int i=0;i<m;i++)
        for(int j=0;j<(1<<len);j++){
            if(dp[i][j]){
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                for(int k=1;k<=4;k++){
                    //cout<<go[j][k]<<endl;
                    dp[i+1][go[j][k]]+=dp[i][j];
                    dp[i+1][go[j][k]]%=MOD;
                }
            }
        }
    for(int i=0;i<(1<<len);i++){
        ans[num[i]]+=dp[m][i];
        ans[num[i]]%=MOD;
    }
    for(int i=0;i<=len;i++){
        printf("%lld\n",ans[i]);
    }
}
signed main(){
    //ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>s>>m;
        s="$"+s;
        len=s.length()-1;
        init();
        preWork();
        solve();
    }
    return 0;
}
