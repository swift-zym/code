#include<bits/stdc++.h>
using namespace std;
struct cow{
    int w,s;
    bool operator<(const cow &c)const{
        return s+w<c.s+c.w;
    }
}a[50001];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].w,&a[i].s);
    }
    sort(a+1,a+n+1);
    int sum=a[1].w,ans=-a[1].s;
    for(int i=2;i<=n;i++){
        ans=max(ans,sum-a[i].s);
        sum+=a[i].w;
    }
    printf("%d\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}