#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T;
int a[500000];
pair<int,pair<int,int> > work(int now){
    int x=0,y=0;
    for(int i=0;i<n;i++){
        switch(now){
            case 0:
                x+=a[i];
                break;
            case 1:
                y+=a[i];
                break;
            case 2:
                x-=a[i];
                break;
            default:
                y-=a[i];
                break;
        }
        now+=a[i];
        now%=4;
    }
    return make_pair(x,make_pair(y,now));
}
int mx[4],my[4],mw[4];
int main(){
    scanf("%lld%lld",&n,&T);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<=3;i++){
        pair<int,pair<int,int> >tmp=work(i);
        mx[i]=tmp.first;
        my[i]=tmp.second.first;
        mw[i]=tmp.second.second;
    }
    int x=0,y=0,now=0;
    for(int i=1;i<=T;i++){
        x+=mx[now];y+=my[now];
        now=mw[now];
    }
    printf("%lld\n",abs(x)+abs(y));
    return 0;
}