#include<bits/stdc++.h>
using namespace std;
struct node{
    int sum,ans,pre,bak;
}a[4000000];
char s[4000000];
void pushup(node &tmp,const node &a,const node &b){
    tmp.sum=a.sum+b.sum;
    tmp.pre=max(a.pre,a.sum+b.pre);tmp.pre=max(tmp.pre,0);
    tmp.bak=max(b.bak,b.sum+a.bak);tmp.bak=max(tmp.bak,0);
    tmp.ans=max(a.ans,max(b.ans,a.bak+b.pre));tmp.ans=max(tmp.ans,0);
}
void build(int now,int l,int r){
    if(l==r){
        a[now].ans=a[now].pre=a[now].bak=s[l-1]=='C'?1:0;
        a[now].sum=s[l-1]=='C'?1:-1;
        return;
    }
    int mid=(l+r)/2;
    build(now*2,l,mid);build(now*2+1,mid+1,r);
    pushup(a[now],a[now*2],a[now*2+1]);
}
node query(int now,int l,int r,int L,int R){
    if(l==L&&r==R)return a[now];
    int mid=(l+r)/2;
    if(R<=mid)return query(now*2,l,mid,L,R);
    else if(L>mid)return query(now*2+1,mid+1,r,L,R);
    else {
        node tmp;
        pushup(tmp,query(now*2,l,mid,L,mid),query(now*2+1,mid+1,r,mid+1,R));
        return tmp;
    }
}
int n,q,sum[1000000];
int main(){
    freopen("elections.in","r",stdin);
    freopen("elections.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&q);
    build(1,1,n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(s[i-1]=='C'?1:-1);
    }
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        //cin>>l>>r;
        cout<<query(1,1,n,l,r).ans-sum[r]+sum[l-1]<<"\n";
    }
    return 0;
}