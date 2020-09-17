#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1100000;
int n,mid,r,p[maxn<<1],cnt=1,ans,a[maxn<<1];
char s[maxn<<1];
inline void read(){
    cin>>n;
    scanf("%s",s+1);
    return;
}
void manachar()
{
    a[1]=1;a[0]=233;
    for (int i=1;i<=n;i++) a[i<<1]=(s[i]=='1')?2:0,a[i<<1|1]=1;
    n=n<<1|1;
    int id=0,mx=0;
    for (int i=1;i<n;i+=2)
    {
        if (mx>i) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        while (a[i-p[i]]+a[i+p[i]]==2&&i-p[i]>0&&i+p[i]<n) p[i]++;
        if (i+p[i]>mx) mx=i+p[i],id=i;
    }
}
signed main(){
    read();
    manachar();
    for(int i=1;i<=n;i+=2){
      ans+=p[i]>>1;
    }
    cout<<ans<<endl;
    return 0;
}
