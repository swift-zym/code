#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
    int id,u,v,w,tag;
};
vector<edge>v;
bool by_id(edge a,edge b){
    return a.id<b.id;
}
bool by_val(edge a,edge b){
    if(a.w!=b.w)
    return a.w<b.w;
    if(a.tag)return 1;
    return 0;
}
int f[100001];
int gf(int now){return f[now]==now?now:f[now]=gf(f[now]);}
int n,m;
bool solve(int id){
    for(int i=1;i<=n;i++)f[i]=i;
    sort(v.begin(),v.end(),by_val);
    for(auto e:v){
        int x=gf(e.u),y=gf(e.v);
        if(x==y)continue;
        f[x]=y;
        if(e.id==id)return 1;
    }
    return 0;
}
bool check(int id,int val){;
    int bk=v[id].w;
    v[id].w=val;
    v[id].tag=1;
    bool tmp=solve(id);
    sort(v.begin(),v.end(),by_id);
    v[id].w=bk;
    v[id].tag=0;
    return tmp;
}
int main(){
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v.push_back({i-1,a,b,c});
    }
    for(int i=1;i<=m;i++){
        int l=0,r=1e9,ans;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(i-1,mid)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}