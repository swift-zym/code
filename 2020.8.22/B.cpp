#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int num[1000001];
int ans=-1;
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        num[a]+=b;
    }
    if(k!=0){
        for(int i=0;i<=1000000-k;i++){
            int x=num[i],y=num[i+k];
            if(x==0||y==0)continue;
            ans=max(ans,(2*i+k)*min(x,y));
        }
    }
    else{
        for(int i=0;i<=1000000;i++){
            int x=num[i];
            if(x<=1)continue;
            ans=max(ans,x*i);
        }
    }
    if(ans==-1){
        puts("NO");
    }
    else{
        printf("%lld\n",ans);
    }
    return 0;
}