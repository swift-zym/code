//
// Created by swift on 2020/7/19.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct flower{
    int a,b;
    bool operator <(const flower &t)const{
        if(a!=t.a)
        return a<t.a;
        else return b<t.b;
    }
}a[200000];
int T;
signed main(){
    scanf("%lld",&T);
    while(T--){
        int n,m;
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%lld%lld",&a[i].a,&a[i].b);
        }
        sort(a+1,a+m+1);
        int mx=-1,id;
        for(int i=1;i<=m;i++){
            if(a[i].b>mx){
                mx=a[i].b;
                id=i;
            }
        }
        int sum=0,now=m+1,mxtmp=-1;
        for(int i=m;i>=1;i--){
            if(!n)break;
            if(a[i].a>=mx){
                mxtmp=max(mxtmp,a[i].b);
                sum+=a[i].a;
                n--;
                now=i;
            }
            else{
                break;
            }
        }
        //unlock+n*vale
        int mxans=-1;
        for(int i=1;i<=m;i++){
            if(i>=now){
                mxans=max(mxans,n*a[i].b);
            }
            else{
                mxans=max(mxans,a[i].a+(n-1)*a[i].b);
            }
        }
        sum+=mxans;
        printf("%lld\n",sum);
        //
        //unlock + n*vaule
    }
    return 0;
}
/*
 *
 */