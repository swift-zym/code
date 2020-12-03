#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define add 50000
#define r signed
using namespace std;
int n,m,dp[add*10],s0,s1,ans;
struct node{
    int w,v;
    bool operator <(const node &t)const{
        return rand()%2==0;
    }
}a[10001],b[10001];
int id[10001];
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld%lld",&n,&m);int siz=n+m;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].w,&a[i].v);
    }
    for(int i=n+1;i<=siz;i++){
        scanf("%lld%lld",&a[i].w,&a[i].v);
        a[i].w=-a[i].w;
    }
    memset(dp,0xef,sizeof(dp));
    dp[add]=0;
    for(int i=1;i<=1000000;i++){
        int x=rand()%siz+1,y=rand()%siz+1;
        swap(a[x],a[y]);
    }
    for(r int i=1;i<=siz;i++){
        if(a[i].w>0){
            for(r int j=add;j>=-add;j--){
               if(j-a[i].w+add<0||j-a[i].w+add>=2*add)continue;
               dp[j+add]=max(dp[j+add],dp[j-a[i].w+add]+a[i].v); 
            }
        }
        else{
            for(r int j=-add;j<=add;j++){
                if(j-a[i].w+add<0||j-a[i].w+add>=2*add)continue;
                dp[j+add]=max(dp[j+add],dp[j-a[i].w+add]+a[i].v);
            }
        }
    }
    printf("%lld\n",dp[add]);
    return 0;
}
/*
3 4
4 7
3 8
2 2
1 4
5 8
1 3
4 4
*/