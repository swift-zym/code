#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
    int x,y;
    bool operator <(const node &t)const{
        if(x!=t.x)return x<t.x;
        return y<t.y;
    }
    bool operator <=(const node &t)const{
        return x<=t.x&&y<=t.y;
    }
};
node p[100001];
node a[200001],b[200001];
int t[100001];
void add(int x,int v){
    for(;x<=n;x+=x&-x){
        t[x]+=v;
    }
}
int query(int x){
    int v=0;
    for(;x;x-=x&-x){
        v+=t[x];
    }
    return v;
}
namespace subtaskA{
    int bel[100001],tmp[200001];
    struct que{
        int id,l,r;
        bool operator <(const que &t)const{
            if(bel[l]!=bel[t.l]){
                return bel[l]<bel[t.l];
            }
            return r<t.r;
        }
    }q[200001];
    int cnt;
    int l=1,r=1,ans;
    void solve(){
        for(int i=1;i<=n;i++){
            bel[i]=i/sqrt(n);
        }
        for(int i=1;i<=m;i++){
            que newQue;
            newQue.id=i;
            newQue.l=a[i].x;
            newQue.r=b[i].x;
            q[++cnt]=newQue;
        }
        add(p[1].y,1);
        sort(q+1,q+m+1);
        for(int i=1;i<=m;i++){
            //cerr<<q[i].l<<" "<<q[i].r<<endl;
            for(;r > q[i].r;r--)
		 {
		 	ans -= r - l + 1 - query(p[r].y);
		 	add(p[r].y,-1);
		 }
		 for(r++;r <= q[i].r;r++)
		 {
		 	ans += r - l - query(p[r].y);
		 	add(p[r].y,1);
		 }
		 r = q[i].r;
		 for(;l < q[i].l;l++)
		 {
		 	ans -= query(p[l].y-1);
		 	add(p[l].y,-1);
		 }
	     for(l--;l >= q[i].l;l--)
	     {
		  	ans += query(p[l].y-1);
			add(p[l].y,1);   
		 }
        l = q[i].l;
            tmp[q[i].id]=(r-l+1)*(r-l)/2-ans;
        }
        for(int i=1;i<=m;i++){
            printf("%lld\n",tmp[i]);
        }
    }
}
signed main(){
    freopen("tears.in","r",stdin);
    freopen("tears.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        p[i].x=i;
        scanf("%lld",&p[i].y);
    }
    bool flag=1;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld%lld",&a[i].x,&b[i].x,&a[i].y,&b[i].y);
        if(a[i].y!=1||b[i].y!=n)flag=0;
    }
    sort(p+1,p+n+1);
    if(flag){
        subtaskA::solve();
        return 0;
    }
    //cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
    for(int i=1;i<=m;i++){
        memset(t,0,sizeof(t));
        int ans=0;
        for(int j=1;j<=n;j++){
            if(a[i]<=p[j]&&p[j]<=b[i]){
                //cout<<">"<<p[j].x<<" "<<p[j].y<<endl;
                ans+=query(p[j].y);
                add(p[j].y,1);
            }
        }
        printf("%lld\n",ans);
    }
    //cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}