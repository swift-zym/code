#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;
int n;
struct trie{
    struct node{
        int son[41],val,ans,fa;
    }a[100000];
    int cnt;
    void insert(int *tmp,int val){
        //cout<<"insert ";
        //for(int i=1;i<=n;i++)cout<<tmp[i]<<" ";
        //cout<<endl;
        int now=0;
        for(int i=1;i<=n;i++){
            if(!a[now].son[tmp[i]]){
                a[now].son[tmp[i]]=++cnt;
                a[cnt].val=tmp[i];
                a[cnt].ans=0;
                a[cnt].fa=now;
            }
            now=a[now].son[tmp[i]];
        }
        a[now].ans+=val;
        a[now].ans%=MOD;
    }
    int query(int *tmp){
        int now=0;
        for(int i=1;i<=n;i++){
            now=a[now].son[tmp[i]];
        }
        return a[now].ans;
    }
}tree[2];
int mp[2000],x;
ll qpow(ll a,ll b){
    if(!b)return 1;
    ll tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
int tmp[2000],trans[100];
int main(){
    freopen("tree20.in","r",stdin);
    //freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int v;
        scanf("%d",&v);
        mp[v]=1;
    }
    fill(tmp+1,tmp+n+1,1);
    tree[x].insert(tmp,1);
    for(int i=1;i<=n*(n-1)/2;i++){
        for(int j=1;j<=tree[x].cnt;j++){
            if(tree[x].a[j].ans){
                int tmp[21];
                for(int now=j,k=n;k>=1;k--){
                    //cout<<now<<" "<<k<<endl;
                    tmp[k]=tree[x].a[now].val;
                    now=tree[x].a[now].fa;
                }
                if(mp[i]){
                    for(int ii=1;ii<=n;ii++)
                    for(int jj=ii+1;jj<=n;jj++){
                        if(tmp[ii]==0||tmp[jj]==0)continue;
                        cout<<ii<<" "<<jj<<" start"<<endl;
                        cout<<x<<" "<<j<<endl;
                        cout<<tree[0].a[1].ans<<endl;
                        cout<<tree[x].a[j].ans<<endl;
                        int val=1ll*tree[x].a[j].ans*tmp[ii]%MOD*tmp[jj]%MOD;
                        memcpy(trans,tmp,sizeof(tmp));
                        trans[ii]+=trans[jj];
                        trans[jj]=0;
                        sort(trans+1,trans+n+1);
                        tree[x^1].insert(trans,val);
                        cout<<ii<<" "<<jj<<" finish"<<endl;
                    }
                }
                else{
                    ll sum=0;
                    for(int ii=1;ii<=n;ii++){
                        if(tmp[ii]==0)continue;
                        sum+=1ll*tmp[ii]*(tmp[ii]-1)%MOD*qpow(2,MOD-2)%MOD;
                        sum%=MOD;
                    }
                    sum=(sum-(i-1)+MOD)%MOD;
                    sum=(sum*tree[x].a[j].ans)%MOD;
                    tree[x^1].insert(tmp,sum);
                }
            }
        }
        tree[x].cnt=0;
        x^=1;
    }
    fill(tmp+1,tmp+n+1,0);
    tmp[n]=n;
    printf("%d\n",tree[x].query(tmp));
    return 0;
}