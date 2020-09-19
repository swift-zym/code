#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0,np[2000001],prime[2000001],cnt;
main(){
    for(int i=2;i<2000000;i++){
        if(!np[i]){
            ans+=i;
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt&&i*prime[j]<2000000;j++){
            np[i*prime[j]]=1;
            if(prime[j]%i==0)break;
        }
    }    
    printf("%lld\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}