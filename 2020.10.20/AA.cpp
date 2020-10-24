#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int x[101][101],y[101][101],ans[101][101],s[101][101];
signed main(){
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        scanf("%lld",&x[i][j]);
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        scanf("%lld",&y[i][j]);
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++){
        ans[i][j]+=x[i][k]*y[k][j];
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+ans[i][j];
    }
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        int aa=min(a,c),bb=min(b,d),cc=max(a,c),dd=max(b,d);
        aa--;bb--;
        printf("%lld\n",s[cc][dd]-s[cc][bb]-s[aa][dd]+s[aa][bb]);
    }
    return 0;
}