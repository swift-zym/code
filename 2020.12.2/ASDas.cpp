#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef unsigned long long ull;
int n,m,threshold;
ull k1,k2;
int siz,a[2000000],b[2000000],q[2000000];
namespace data{
    ull k1,k2;
    ull xorShift128Plus(){
        ull k3=k1,k4=k2;
        k1=k4;
        k3^=(k3<<23);
        k2=k3^k4^(k3>>17)^(k4>>26);
        return k2+k4;
    }
    void gen(int n,int m,int threshold,ull _k1,ull _k2){
        k1=_k1,k2=_k2;
        for(int i=1;i<=(1<<n);i++)a[i]=xorShift128Plus()%threshold+1;
        for(int i=1;i<=m;i++)q[i]=xorShift128Plus()%(n+1);
    }
}
int t[2000000],v[2000000][2],ans,val,idx[2000000];
int sum[2000000],mx;
void add(int x,int y){
    for(;x<=mx;x+=x&-x){
        t[x]+=y;
    }
}
int query(int x){
    int v=0;
    for(;x;x-=x&-x){
        v+=t[x];
    }
    return v;
}
signed main(){
    //freopen("data.in","r",stdin);
    //freopen("user.out","w",stdout);
    cin>>n>>m>>threshold>>k1>>k2;
    siz=1<<n;
    data::gen(n,m,threshold,k1,k2);
    memcpy(b,a,sizeof(a));
    sort(b+1,b+siz+1);
    mx=unique(b+1,b+siz+1)-b;
    for(int i=1;i<=siz;i++){
        a[i]=lower_bound(b+1,b+mx,a[i])-b;
        cout<<a[i]<<endl;
    }
    //cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
    for(int i=1;i<=n;i++){
        int now=1,len=1<<i,num=0;
        while(now<=siz){
            int mid=now+len/2-1,end=now+len-1;
            for(int j=mid+1;j<=end;j++){
                add(a[j],1);
                sum[a[j]]++;
            }
            for(int j=now;j<=mid;j++){
                num+=sum[a[j]];
                v[i][0]+=query(a[j]-1);
            }
            for(int j=mid+1;j<=end;j++){
                add(a[j],-1);
                sum[a[j]]--;
            }
            now+=len;
        }
        v[i][1]=(siz/len)*(len/2)*(len/2)-v[i][0]-num;
        ans+=v[i][0];
        cerr<<i<<" "<<v[i][0]<<" "<<num<<endl;
    }
    //cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
    for(int i=1;i<=m;i++){
        for(int j=q[i];j>=1;j--){
            ans-=v[j][idx[j]];
            idx[j]^=1;
            ans+=v[j][idx[j]];
        }
        val^=(ans*i);
    }
    //cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
    cout<<val<<endl;
    return 0;
}