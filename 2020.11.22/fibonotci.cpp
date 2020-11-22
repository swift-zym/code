#include<iostream>
#include<climits>
#define int long long
using namespace std;
int k,P;
int n;
int s[1000001],f[1000001];
int m;
signed main(){
    cout<<LLONG_MAX<<endl;
    scanf("%lld%lld",&k,&P);
    scanf("%lld",&n);
    for(int i=0;i<n;i++)scanf("%lld",&s[i]);
    for(int i=n;i<=k;i++){
        s[i]=s[i%n];
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        if(x>k)continue;
        s[x]=y;
    }
    f[0]=0;f[1]=1;
    for(int i=2;i<=k;i++){
        f[i]=(s[i-1]*f[i-1]%P+s[i-2]*f[i-2]%P)%P;
    }
    printf("%lld\n",f[k]);
    return 0;
}