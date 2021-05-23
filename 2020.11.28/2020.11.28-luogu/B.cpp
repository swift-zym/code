#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
int n,m,k,p;
signed main(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
    int v=min(m,k/p),num=k-p*v;
    if(num<=(n-p)*(v-1)){
        puts("YES");
        for(int i=1;i<=p;i++){
            printf("%lld %lld\n",v,m-v);
        }
        for(int i=p+1;i<=n;i++){
            if(num){
                if(num>=v){
                    printf("%lld %lld\n",v-1,m-v+1);
                    num-=(v-1);
                }
                else{
                    printf("%lld %lld\n",num,m-num);
                    num=0;
                }
            }
            else{
                printf("%lld %lld\n",0,m);
            }
        }
    }
    else{
        puts("NO");
    }
    return 0;
}