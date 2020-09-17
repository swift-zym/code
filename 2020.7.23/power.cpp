//
// Created by swift on 2020/7/23.
//

#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int dp[100001][51],sum[100001][51];
int n,a,b,l,px,py,x,y,nx,ny,nxy;
int qpow(int a,int b){
    if(b==0)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
struct matrix{
    int a[60][60];
    matrix operator *(matrix &t){
        matrix sol;
        memset(sol.a,0,sizeof(sol.a));
        for(int i=0;i<=l+1;i++)
            for(int j=0;j<=l+1;j++)
                for(int k=0;k<=l+1;k++){
                    sol.a[i][j]+=a[i][k]*t.a[k][j]%MOD;
                    sol.a[i][j]%=MOD;
                }
        return sol;
    }
}bas,ans;
void qpow(int b){
    while(b){
        if(b&1)ans=ans*bas;
        bas=bas*bas;
        b>>=1;
    }
}
signed main(){
    dp[0][0]=1;
    cin>>n>>a>>b>>l;
    cin>>px>>py;
    x=px*qpow(100,MOD-2)%MOD;
    y=py*qpow(100,MOD-2)%MOD;
    nx=(100-px)*qpow(100,MOD-2)%MOD;
    ny=(100-py)*qpow(100,MOD-2)%MOD;
    nxy=(100-px-py)*qpow(100,MOD-2)%MOD;
    /*
 * dp0 dp1 dp2 ...dpl sum
 */
    /*
 * nx x ... 0  b
 * y nxy ... 0 a+b
 * 0  y ... 0  2a+b
 * 0  0 ... 0  ...
 * ...  ... x  ...
 * 0  0 ... ny 0
 */
    ans.a[0][0]=1;
    bas.a[0][0]=nx;
    bas.a[1][0]=y;
    for(int i=1;i<l;i++){
        bas.a[i-1][i]=x;
        bas.a[i][i]=nxy;
        bas.a[i+1][i]=y;
    }
    bas.a[l][l]=ny;
    bas.a[l-1][l]=x;
    for(int i=0;i<=l;i++){
        bas.a[i][l+1]=(a*i%MOD+b)%MOD;
    }
    bas.a[l+1][l+1]=1;
    ans=ans*bas;
    ans.a[0][l+1]=0;
    qpow(n);
    /*for(int i=2;i<=n+1;i++){
        ans=ans*bas;
        for(int j=0;j<=l+1;j++){
            cout<<i<<" "<<j<<" "<<ans.a[0][j]<<endl;
        }
    }*/
    //qpow(n+1);
    printf("%lld\n",ans.a[0][l+1]);
    return 0;
}
