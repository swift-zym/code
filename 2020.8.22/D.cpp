#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500001],x[500001];
bool flag=1;
bool flag1=1;
int b[11];
struct node{
    int v,x,y;
    bool operator <(const node &t)const{
        return v<t.v;
    }
};
vector<node>tmp;
vector<node>out;
int ans;
void dfs(int deep){
    cerr<<"deep="<<deep<<endl;
    for(int i=1;i<=n;i++){
        cerr<<b[i]<<" ";
    }
    cerr<<endl;
    if(deep==n+1){
        for(int i=1;i<=n;i++){
            if(b[i]==x[i])return;
        }
        tmp.clear();
        for(int i=1;i<=n;i++){
            cerr<<i<<" "<<b[i]<<endl;
            if(b[i]<i)continue;
            tmp.push_back({min(a[i],a[b[i]]),i,b[i]});
        }
        sort(tmp.begin(),tmp.end());
        int val=0;
        for(int i=1;i<=n/2;i++){
            val+=i*tmp[n/2-i].v;
        }
        cerr<<val<<endl;
        if(val<ans){
            ans=val;
            out=tmp;
        }
        return;
    }
    if(b[deep]){
        dfs(deep+1);
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==deep)continue;
        cerr<<">"<<deep<<" "<<i<<" "<<b[i]<<endl;
        if(!b[i]){
            b[i]=deep;
            b[deep]=i;
            dfs(deep+1);
        }
    }
    b[b[deep]]=0;
    b[deep]=0;
    cerr<<"clear "<<deep<<endl;
}
signed main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
    for(int i=1;i<=n;i++){
        if(x[i]!=-1)flag=0;
        if(i<n&&a[i+1]<a[i])flag1=0;
    }
    flag=0;
    if(flag){
        sort(a+1,a+n+1);
        int sum=0;
        for(int i=1;i<=n/2;i++)sum+=a[i]*(n/2-i+1);
        printf("%lld\n",sum);
        for(int i=n/2;i>=1;i--){
            printf("%lld %lld\n",i,n/2+i);
        }
    }
    /*else if(n==2){
        puts("-1");
    }*/
    else if(n<=10){
        ans=LLONG_MAX;
        dfs(1);
        if(ans==LLONG_MAX){
            puts("-1");
        }
        else{
            printf("%lld\n",ans);
            for(int i=n/2-1;i>=0;i--){
                printf("%lld %lld\n",out[i].x,out[i].y);
            }
        }
    }
    else{
        puts("-1");
    }
    return 0;
}