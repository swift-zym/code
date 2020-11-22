#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
using namespace std;
struct ta{
    int a[2001];
    int query(int x){
        int v=0;
        for(;x;x-=x&-x){
            v+=a[x];
        }
        return v;
    }
    void add(int x,int v){
        for(;x<=2000;x+=x&-x){
            a[x]+=v;
        }
    }
    int sum(int l,int r){
        return query(r)-query(l-1);
    }
}h[2001],l[2001];
int n,m,k;
int v[2001][2001];
int lastans;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        char c=getchar();
        while(c!='.'&&c!='#')c=getchar();
        if(c=='#'){
            h[i].add(j,1);
            l[j].add(i,1);
        }
    }
    for(int _=1;_<=k;_++){
        if(_!=1&&(n>500||m>500)){
            printf("%d\n",lastans);
            continue;
        }
        int x,y;
        scanf("%d%d",&x,&y);
        h[x].add(y,1);l[y].add(x,1);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            v[i][j]=1;
        }
        int ans=0;
        for(int i=2;i<=n;i++)
        for(int j=2;j<=m;j++){
            if(h[i].sum(j,j)!=0)continue;
            int tmp=v[i-1][j-1];
            int L=0,R=tmp,val;
            while(L<=R){
                int mid=(L+R)/2;
                if(h[i].sum(j-mid,j)==0&&l[j].sum(i-mid,i)==0){
                    L=mid+1;
                    val=mid;
                }
                else{
                    R=mid-1;
                }
            }
            v[i][j]=val+1;
            ans=max(ans,v[i][j]);
        }
        lastans=ans;
        printf("%d\n",ans);
    }
    return 0;
}