#include<bits/stdc++.h>
#define int long long
using namespace std;
struct block{
    int w,h;
    void Swap(){swap(w,h);}
    bool operator<(const block &t)const{
        return w<t.w;
    }
};
vector<block>v;
int n,ans;
signed main(){
    scanf("%lld",&n);
    srand(time(0));
    for(int i=1;i<=n;i++){
        int w,h;
        scanf("%lld%lld",&w,&h);
        v.push_back({w,h});
    }
    int num=1e6/v.size();
    for(int i=1;i<=num;i++){
        for(int i=0;i<n;i++)if(rand()%2)v[i].Swap();
        sort(v.begin(),v.end());
        int sum=v[0].h;
        bool flag=1;
        for(int j=1;j<v.size();j++){
            if(v[j].w==v[j-1].w){flag=0;break;}
            sum+=v[j].h;
        }
        if(flag)
        ans=max(sum,ans);
    }
    //git clone if exit
    printf("%lld\n",ans);
    return 0;
}