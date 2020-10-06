#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int c[200001];
struct node{
    int a,b;
    bool operator <(const node &t)const{return a<t.a;}
}a[2000000];
int sc[2000000],sa[2000000];
int s[2000000],tp;
int ans;
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&a[i].a,&a[i].b);
    }
    sort(a+1,a+m+1);
    for(int i=1,j=1;i<=m&&j<=1000000;i++){
        for(int k=1;k<=(a[i].b==-1?1000000:a[i].b);k++){
            sa[j++]=a[i].a;
            if(j>1000000)break;
        }
    }
    for(int i=1;i<=n;i++){
        sc[i]=sc[i-1]+c[i];
    }
    for(int i=1;i<=1000000;i++){
        sa[i]=sa[i-1]+sa[i];
    }
    for(int i=1;i<=n;i++){
        while(tp>0&&(sc[i]-sc[s[tp]])*(s[tp]-s[tp-1])>(sc[s[tp]]-sc[s[tp-1]])*(i-s[tp]))tp--;
        s[++tp]=i;
    }
    for(int i=1;i<=tp;i++){
        int x=s[i]-s[i-1],y=sc[s[i]]-sc[s[i-1]];
        ans+=(y%x)*sa[y/x+1]+(x-y%x)*sa[y/x];
    }
    printf("%lld\n",ans);
    return 0;
}