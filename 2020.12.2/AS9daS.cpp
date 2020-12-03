#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef unsigned long long ull;
int n,m,threshold;
ull k1,k2;
int siz,bk[2000000],a[2000000],b[2000000],q[2000000];
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
int v[2000000][2],ans,val,idx[2000000];
int sum[2000000],mx;
void msort(int l,int r,int id){
    if(r-l+1>=2){
        int mid=(l+r)/2;
        msort(l,mid,id-1);msort(mid+1,r,id-1);
        int x=l,y=mid+1,cnt=l-1;
        while(x<=mid&&y<=r){
            if(a[x]<=a[y]){
                b[++cnt]=a[x++];
            }
            else{
                v[id][0]+=mid-x+1;
                b[++cnt]=a[y++];
            }
        }
        while(x<=mid)b[++cnt]=a[x++];
        while(y<=r)b[++cnt]=a[y++];
        for(int i=l;i<=r;i++){
            a[i]=b[i];
        }
    }
}
signed main(){
    freopen("inversions.in","r",stdin);
    freopen("inversions.out","w",stdout);
    cin>>n>>m>>threshold>>k1>>k2;
    siz=1<<n;
    data::gen(n,m,threshold,k1,k2);
    memcpy(bk,a,sizeof(a));
    msort(1,siz,n);
    memcpy(a,bk,sizeof(bk));
    sort(bk+1,bk+siz+1);
    int cnt=unique(bk+1,bk+siz+1)-bk;
    for(int i=1;i<=siz;i++){
        a[i]=lower_bound(bk+1,bk+cnt,a[i])-bk;
    }
    for(int i=1;i<=n;i++){
        int now=1,len=1<<i,num=0;
        while(now<=siz){
            int mid=now+len/2-1,elnd=now+len-1;
            for(int j=mid+1;j<=end;j++){
                sum[a[j]]++;
            }
            for(int j=now;j<=mid;j++){
                num+=sum[a[j]];
            }
            for(int j=mid+1;j<=end;j++){
                sum[a[j]]--;
            }
            now+=len;
        }
        v[i][1]=(siz/len)*(len/2)*(en/2)-v[i][0]-num;
        ans+=v[i][0];
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
    cout<<val<<endl;
    return 0;
}