#include<bits/stdc++.h>
using namespace std;
struct sge{
  struct node{
    int s,m,l,r,ls,rs;
  };
  vector<node>a;
  void build(int maxn){
    a.push_back(node{0,0,0,0,0,0});
    a.push_back(node{0,0,1,maxn,0,0});
  }
  void pushup(int now){
    if(a[now].ls){
      a[now].m=a[a[now].ls].m;
      a[now].s=a[a[now].ls].s;
    }
    if(a[now].rs){
      a[now].m=max(a[now].m,a[a[now].rs].m);
      a[now].s+=a[a[now].rs].s;
    }
  }
  void change(int now,int pos,int v){
    if(a[now].l==a[now].r){
      a[now].s=v;
      a[now].m=v;
      return;
    }
    int mid=(a[now].l+a[now].r)/2;
    if(pos<=mid){
      if(!a[now].ls){
        a.push_back({0,0,a[now].l,mid,0,0});
        a[now].ls=a.size()-1;
      }
      change(a[now].ls,pos,v);
    }
    else{
      if(!a[now].rs){
        a.push_back({0,0,mid+1,a[now].r,0,0});
        a[now].rs=a.size()-1;
      }
      change(a[now].rs,pos,v);
    }
    pushup(now);
  }
  int ask1(int now,int l,int r){
    if(a[now].l==l&&a[now].r==r){
      return a[now].s;
    }
    int mid=(a[now].l+a[now].r)/2;
    if(r<=mid){
      if(!a[now].ls){
        a.push_back({0,0,a[now].l,mid,0,0});
        a[now].ls=a.size()-1;
      }
      return ask1(a[now].ls,l,r);
    }
    else if(l>mid){
      if(!a[now].rs){
        a.push_back({0,0,mid+1,a[now].r,0,0});
        a[now].rs=a.size()-1;
      }
      return ask1(a[now].rs,l,r);
    }
    else{
      if(!a[now].ls){
        a.push_back({0,0,a[now].l,mid,0,0});
        a[now].ls=a.size()-1;
      }
      if(!a[now].rs){
        a.push_back({0,0,mid+1,a[now].r,0,0});
        a[now].rs=a.size()-1;
      }
      return ask1(a[now].ls,l,mid)+ask1(a[now].rs,mid+1,r);
    }
    pushup(now);
  }
  int ask2(int now,int l,int r){
    if(a[now].l==l&&a[now].r==r){
      return a[now].m;
    }
    int mid=(a[now].l+a[now].r)/2;
    if(r<=mid){
      if(!a[now].ls){
        a.push_back({0,0,a[now].l,mid,0,0});
        a[now].ls=a.size()-1;
      }
      return ask2(a[now].ls,l,r);
    }
    else if(l>mid){
      if(!a[now].rs){
        a.push_back({0,0,mid+1,a[now].r,0,0});
        a[now].rs=a.size()-1;
      }
      return ask2(a[now].rs,l,r);
    }
    else{
      if(!a[now].ls){
        a.push_back({0,0,a[now].l,mid,0,0});
        a[now].ls=a.size()-1;
      }
      if(!a[now].rs){
        a.push_back({0,0,mid+1,a[now].r,0,0});
        a[now].rs=a.size()-1;
      }
      return max(ask2(a[now].ls,l,mid),ask2(a[now].rs,mid+1,r));
    }
    pushup(now);
  }
}tmp[100001];
int n,m,d[100001],f[100001],a[100001],b[100001],head[100001],to[200001],nxt[200001],s[100001],cnt,T,top[100001];
int x[100001],y[100001];
int c[100001],w[100001];
int dfs1(int now,int fa,int deep){
    f[now]=fa;
    d[now]=deep;
    int siz=1,id=-1,mx=0;
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa)continue;
        int v=dfs1(to[i],now,deep+1);
        siz+=v;
        if(v>mx){
            id=to[i];
            mx=v;
        }
    }
    if(id!=-1)
    s[now]=id;
    return siz;
}
void dfs2(int now,int fa,int tp){
    top[now]=tp;
    a[now]=++T;
    b[T]=now;
    if(s[now])
    dfs2(s[now],now,tp);
    for(int i=head[now];i;i=nxt[i]){
        if(to[i]==fa||to[i]==s[now])continue;
        dfs2(to[i],now,to[i]);
    }
}
void add(int a,int b){
  nxt[++cnt]=head[a];
  head[a]=cnt;
  to[cnt]=b;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=100000;i++)tmp[i].build(n);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&w[i],&c[i]);
  }
  for(int i=1;i<n;i++){
    int X,Y;
    scanf("%d%d",&X,&Y);
    add(X,Y);
    add(Y,X);
  }
  dfs1(1,1,1);
  dfs2(1,1,1);
  for(int i=1;i<=n;i++){
    tmp[c[i]].change(1,a[i],w[i]);
  }
  for(int i=1;i<=m;i++){
    char s[101];
    int X,Y;
    scanf("%s %d %d",s,&X,&Y);
    if(strcmp(s,"CC")==0){
      tmp[c[X]].change(1,a[X],0);
      c[X]=Y;
      tmp[c[X]].change(1,a[X],w[X]);
    }
    else if(strcmp(s,"CW")==0){
      tmp[c[X]].change(1,a[X],Y);
      w[X]=Y;
    }
    else if(strcmp(s,"QS")==0){
      int cc=c[X];
      int ans=0;
      while(top[X]!=top[Y]){
          if(d[top[X]]<d[top[Y]])swap(X,Y);
          ans+=tmp[cc].ask1(1,a[top[X]],a[X]);
          X=f[top[X]];
      }
      if(d[X]>d[Y])swap(X,Y);
      ans+=tmp[cc].ask1(1,a[X],a[Y]);
      printf("%d\n",ans);
    }
    else{
      int cc=c[X];
      int ans=0;
      while(top[X]!=top[Y]){
          if(d[top[X]]<d[top[Y]])swap(X,Y);
          ans=max(ans,tmp[cc].ask2(1,a[top[X]],a[X]));
          X=f[top[X]];
      }
      if(d[X]>d[Y])swap(X,Y);
      ans=max(ans,tmp[cc].ask2(1,a[X],a[Y]));
      printf("%d\n",ans);
    }
  }
  return 0;
}
