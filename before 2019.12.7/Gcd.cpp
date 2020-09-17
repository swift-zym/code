//题目名：Gcd
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,p[10000001],cnt,phi[10000001],sum[10000001];
bool np[10000001];
#undef int
int main(){
    #define int long long
    memset(np,0,sizeof(np));
    cin>>n;
    np[1]=1;
    phi[1]=1;
    for(int i=2;i<=n;i++){
       if(!np[i]){
           p[cnt++]=i;
           phi[i]=i-1;
       }
       for(int j=0;j<cnt;j++){
        if(i*p[j]>n)break;
        np[i*p[j]]=1;
        if(i%p[j]==0){
            phi[i*p[j]]=p[j]*phi[i];
            break;
        }
        else{
            phi[i*p[j]]=(p[j]-1)*phi[i];
        }
        }
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+phi[i];
    }
    int ans=0;
    for(int i=0;i<cnt;i++){
    ans+=sum[n/p[i]];
    }
    printf("%lld\n",2*ans-cnt);
    #ifdef WIN32
    system("pause");
    #endif
}