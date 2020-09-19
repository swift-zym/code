#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define MOD 1000000009
using namespace std;
int n,a[100001],tmp[100001];
int ans;
void dfs(int now){
    if(tmp[now]){
        ans+=tmp[now];
        ans%=MOD;
        return;
    }
    if(now>n){
        tmp[now]=1;
        ans=(ans+1)%MOD;
        return;
    }
    int sum1=0,sum2=0;
    for(int i=now;i<=n;i++){
        sum1+=a[i];
        if(sum1>=0)dfs(i+1),sum2+=tmp[i+1];
    }
    tmp[now]=sum2;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dfs(1);
    printf("%d\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}