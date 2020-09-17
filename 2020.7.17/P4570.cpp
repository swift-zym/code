//
// Created by swift on 2020/7/17.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[70];
bool ins(int x){
    for(int i=62;i>=0;i--){
        if(x&(1ll<<i)){
            if(!p[i]){
                p[i]=x;
                return 1;
            }
            x^=p[i];
        }
    }
    return 0;
}
struct stone{
    int number,magic;
    bool operator <(const stone &t)const{
        return magic>t.magic;
    }
}a[1001];
int n;
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].number,&a[i].magic);
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(ins(a[i].number)){
            ans+=a[i].magic;
        }
    }
    printf("%lld\n",ans);
    return 0;
}