//题目名：最多约数(http:///218.62.22.209:8080)/最多因子数(http://luogu.org)
#define LUOGU//若在209上运行，注释掉这一句
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool np[10006];
int p[10006];
ll l=1,u;
ll out,ans_out=-1;
ll qpow(ll a, ll b){
    if(!b)return 1;
    ll tmp=qpow(a,b/2);
    return b%2?tmp*tmp*a:tmp*tmp;
}
int cnt=0;
void getPrime(){
    memset(np,0,sizeof(np));
    for(int i=2;i<=sqrt(10005);i++){
        for(int j=2;j<=10005/i;j++){
           np[i*j]=1;
        }
    }
    np[1]=1; 
    for(int i=1;i<=10005;i++){
        if(!np[i]){
            p[++cnt]=i;
        }
    }
}
void dfs(int deep,ll now,ll ans_now,ll maxn){
    if(now>u)return;
    if((now>=l&&now<=u)&&(ans_now>ans_out||(ans_now==ans_out&&now<out))){
    ans_out=ans_now;
    out=now;
    }
    for(int i=1;i<=maxn;i++){
        ll tmp=qpow(p[deep],i)*now;
        if(tmp>u)break;
        dfs(deep+1,tmp,ans_now*(i+1),i);
    }
}
int main(){
    #ifdef LUOGU
    scanf("%lld",&l);
    #endif
    scanf("%lld",&u);
    if(u<l){
        swap(l,u);
    }
    getPrime();
    dfs(1,1,1,log(u));
    #ifndef LUOGU
    printf("%lld\n",out);
    #endif
    #ifdef LUOGU
    printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,out,ans_out);
    #endif
    #ifdef WIN32
	system("pause");
	#endif
    return 0;
}