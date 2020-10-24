#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[2001][2001],b[2001][2001],s[2001][2001];
int suma[2001][2001],sumb[2001][2001];
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    scanf("%lld",&a[i][j]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    scanf("%lld",&b[i][j]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        suma[i][j]=suma[i-1][j]+suma[i][j-1]-suma[i-1][j-1]+a[i][j];
        sumb[i][j]=sumb[i-1][j]+sumb[i][j-1]-sumb[i-1][j-1]+b[i][j];
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        int tmp=s[i-1][j-1];
        s+=a[i-1][j]*sum[i-1][n];
    }
    return 0;
}
/**
 * ans(i,j)=a(i,x)*b(x,j)
 * ans(i,*)=a(i,x)*sum(x,*)
 * ans=a(1,x)*sum(x,*)+a(2,x)*sum(x,*)
 * ans=sum(x,*)*(a(1,x)+a(2,x)+a(3,x)+...)
 * ans=sumb(x,*)*suma(*,x)
 * ans(i,{j,k})=a(i,x)*b(x,{j,k});
 * ans({m,n},{j,k})=a({m,n},x)*b(x,{j,k})
 * ans({1,i-1},{1,j})=ans({1,i-1},1{j-1})+a({1,i-1},{1-n})*a[i-1][j]
 */
