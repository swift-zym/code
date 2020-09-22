#include<bits/stdc++.h>
using namespace std;
struct tree{
  struct message{
      int pre,sum,suf;
      message operator+(const message &t)const{
          return {max(pre,sum+t.pre),sum+t.sum,max(t.suf,suf+t.sum)};
      }
      void set(int x){
          pre=sum=suf=x;
      }
  };
  struct node{
      message m;
      int l,r,ls,rs;
  }a[6000000];
  int tot=-1;
  int newNode(int from){
      a[++tot]=a[from];
      return tot;
  }
  int newNode(int l,int r){
      a[++tot].l=l;a[tot].r=r;
      return tot;
  }
  void pushup(int now){
      a[now].m=a[a[now].ls].m+a[a[now].rs].m;
  }
  int build(int now){
      if(a[now].l==a[now].r){
          a[now].m.set(1);
          return now;
      }
      int mid=(a[now].l+a[now].r)/2;
      a[now].ls=build(newNode(a[now].l,mid));
      a[now].rs=build(newNode(mid+1,a[now].r));
      pushup(now);
      return now;
  }
  void build(int l,int r){
      int idx=newNode(l,r);
      build(idx);
  }
  int add(int now,int pos,int v){
      now=newNode(now);
      if(a[now].l==a[now].r){
          a[now].m.set(v);
          return now;
      }
      int mid=(a[now].l+a[now].r)/2;
      if(pos<=mid){
          a[now].ls=add(a[now].ls,pos,v);
      }
      else{
          a[now].rs=add(a[now].rs,pos,v);
      }
      pushup(now);
      return now;
  }
  message query(int now,int l,int r){
      int L=a[now].l,R=a[now].r;
      if(L==l&&R==r){
          return a[now].m;
      }
      int mid=(L+R)/2;
      if(r<=mid){
          return query(a[now].ls,l,r);
      }
      else if(l>mid){
          return query(a[now].rs,l,r);
      }
      else{
          return query(a[now].ls,l,mid)+query(a[now].rs,mid+1,r);
      }
  }
}base;
int roots[20001];
int check(int a,int b,int c,int d,int x){
    int lv=base.query(roots[x-1],a,b).suf;
    int mv=b+1>c-1?0:base.query(roots[x-1],b+1,c-1).sum;
    int rv=base.query(roots[x-1],c,d).pre;
    //cout<<x<<" "<<lv<<" "<<mv<<" "<<rv<<endl;
    return lv+mv+rv>=0;
}
int n;
int a[20001];
int b[20001];
int tmp[20001];
int x;
void solve(vector<int>q){
    sort(q.begin(),q.end());
    //cout<<q[0]<<" "<<q[1]<<" "<<q[2]<<" "<<q[3]<<endl;
    int l=1,r=n,ans;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(q[0],q[1],q[2],q[3],mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    printf("%d\n",x=tmp[ans]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memcpy(tmp,a,sizeof(a));
    sort(tmp+1,tmp+n+1);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(tmp+1,tmp+n+1,a[i])-tmp;
        b[a[i]]=i;
    }
    base.build(1,n);
    for(int i=1;i<=n;i++){
        roots[i]=base.tot+1;
        base.add(roots[i-1],b[i],-1);
        //cout<<base.query(roots[i],1,n).sum<<endl;
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int q1,q2,q3,q4;
        scanf("%d%d%d%d",&q1,&q2,&q3,&q4);
        q1=(q1+x)%n;q1++;
        q2=(q2+x)%n;q2++;
        q3=(q3+x)%n;q3++;
        q4=(q4+x)%n;q4++;
        solve({q1,q2,q3,q4});
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}