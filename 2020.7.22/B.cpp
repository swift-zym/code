//
// Created by swift on 2020/7/22.
//

#include<bits/stdc++.h>
#define int long long
#define st set<node>::iterator
using namespace std;
int n,sum[400000];
struct node{
    int x,v;
    bool operator <(const node &t)const{
        if(v!=t.v)return v<t.v;
        return x<t.x;
    }
};
set<node>a,b;
int ans=1e18,l,r;
signed main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i - 1];
    }
    b.insert({0,0});
    for(int i=1;i<=n;i++){
        if(sum[i]%2==0){
            //cout<<sum[i]<<endl;
            st pos=a.lower_bound({(int)1e18,sum[i]});
            if(a.empty()==0&&pos!=a.begin()){
                //cout<<pos->x<<" "<<pos->v<<endl;
                pos--;
                if(sum[i]-pos->v<ans){
                    ans=sum[i]-pos->v;
                    l=pos->x+1;
                    r=i;
                }
                else if(sum[i]-pos->v==ans){
                    pos=a.lower_bound({-1,pos->v});
                    if(pos->x+1<l){
                        l=pos->x+1;
                        r=i;
                    }
                }
            }
            b.insert({i,sum[i]});
        }
        else{
            //cout<<sum[i]<<endl;
            st pos=b.lower_bound({(int)1e18,sum[i]});
            if(b.empty()==0&&pos!=b.begin()){
                pos--;
                //cout<<pos->x<<" "<<pos->v<<endl;
                if(sum[i]-pos->v<ans){
                    ans=sum[i]-pos->v;
                    l=pos->x+1;
                    r=i;
                }
                else if(sum[i]-pos->v==ans){
                    pos=b.lower_bound({-1,pos->v});
                    if(pos->x+1<l){
                        l=pos->x+1;
                        r=i;
                    }
                }
            }
            a.insert({i,sum[i]});
        }
    }
    if(ans==1e18){
        puts("-1");
    }
    else{
        printf("%lld %lld %lld\n",ans,l,r);
    }
    return 0;
}