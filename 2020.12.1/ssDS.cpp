#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(s)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int n,a[100001],b[100001];
signed dp[9500][9500];
signed jc[1000001],inv[1000001];
int C(int x,int y){
    if(x<0||y<0||x<y)return 0;
    //cerr<<x<<" "<<y<<endl;
    return 1ll*jc[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int qpow(int a,int b){
    if(!b)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
int count(int sx,int sy,int ex,int ey){
    //cerr<<"("<<sx<<","<<sy<<")->("<<ex<<","<<ey<<"):"<<C(ex-sx+ey-sy,ex-sx)<<endl;
    return C(ex-sx +ey-sy,ex-sx);
}
vector<int>v;
signed main(){
    freopen("gift.in","r",stdin);
    freopen("gift.out","w",stdout);
    jc[0]=inv[0]=jc[1]=inv[1]=1;
    for(int i=2;i<=1000000;i++){
        jc[i]=1ll*jc[i-1]*i%MOD;
    }
    inv[1000000]=qpow(jc[1000000],MOD-2);
    for(int i=999999;i>=2;i--){
        inv[i]=1ll*inv[i+1]*(i+1)%MOD;
    }
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]);
    int siz=0,ans=0;
    for(int i=1;i<=n;i++)siz+=(a[i]+b[i]);
    //siz=sqrt(siz)/2;
    siz=9000;
    for(int i=1;i<=n;i++){
        if(a[i]<=siz&&b[i]<=siz){
            dp[-a[i]+siz][-b[i]+siz]++;
        }
    }

    for(int i=1;i<=2*siz;i++){
        dp[0][i]+=dp[0][i-1];
    }
    for(int i=1;i<=2*siz;i++){
        dp[i][0]+=dp[i-1][0];
    }
    for(int i=1;i<=2*siz;i++)
    for(int j=1;j<=2*siz;j++){
        dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%MOD;
        dp[i][j]%=MOD;
    }
    for(int i=1;i<=n;i++){
        if(a[i]<=siz&&b[i]<=siz){
            ans+=dp[a[i]+siz][b[i]+siz];ans%=MOD;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]>siz||b[i]>siz)continue;
        ans-=C(2*a[i]+2*b[i],2*a[i]);
        //cout<<C(2*a[i]+2*b[i],2*a[i])<<":"<<a[i]<<" "<<b[i]<<endl;
        ans=(ans+MOD)%MOD;
    }
    //cerr<<ans<<endl;
    memset(dp,0,sizeof(dp));
    for(int j=1;j<=n;j++){
        if(a[j]<=siz&&b[j]<=siz)continue;
        dp[0][0]+=count(-a[j],-b[j],0,0);dp[0][0]%=MOD;
        for(int i=1;i<=siz;i++){
            dp[0][i]+=count(-a[j],-b[j],0,i);dp[0][i]%=MOD;
        }
        for(int i=1;i<=siz;i++){
            dp[i][0]+=count(-a[j],-b[j],i,0);dp[i][0]%=MOD;
        }
    }
    for(int i=1;i<=siz;i++)
    for(int j=1;j<=siz;j++){
        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
    }
    int tmp=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=siz&&b[i]<=siz){
            tmp+=dp[a[i]][b[i]];tmp%=MOD;
        }
    }
    //cerr<<tmp<<endl;
    ans+=tmp*2;ans%=MOD;
    for(int i=1;i<=n;i++){
        if(a[i]>siz||b[i]>siz)v.push_back(i);
    }
    for(int i=0;i<v.size();i++)
    for(int j=0;j<v.size();j++){
        if(i==j)continue;
        ans+=C(a[v[i]]+b[v[i]]+a[v[j]]+b[v[j]],a[v[i]]+a[v[j]]);
        ans%=MOD;
    }
    //cerr<<">"<<v.size()<<endl;
    printf("%lld\n",ans);
    return 0;
}