//
// Created by swift on 2020/8/9.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,z;
int x[100001],y[100001],q[100001],ans;
signed main(){
    scanf("%lld%lld%lld",&n,&m,&z);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&x[i],&y[i],&q[i]);
        ans+=q[i];
    }
    sort(x+1,x+m+1);
    sort(y+1,y+m+1);
    int ansX,ansY;
    if(m%2){
        ansX=x[m/2+1];
        ansY=y[m/2+1];
    }
    else{
        ansX=x[m/2];
        ansY=y[m/2];
    }
    for(int i=1;i<=m;i++){
        ans+=(abs(ansX-x[i])+abs(ansY-y[i]))*z;
    }
    printf("%lld\n",ans);
    printf("%lld %lld\n",ansX,ansY);
    return 0;
}