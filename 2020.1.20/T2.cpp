#include<bits/stdc++.h>
#define IT set<node>::iterator
using namespace std;
struct node{
  int l,r,v;
  bool operator <(const node &t)const{
    return r<t.r;
  }
};
set<node>st;
IT split(int now){
  IT tmp=st.lower_bound({0,now,0});
  if(tmp==st.end()){
    return tmp;
  }
  int L=tmp->l,R=tmp->r,V=tmp->v;
  st.erase(tmp);
  if(L<=now-1)
  st.insert({L,now-1,V});
  return st.insert({now,R,V}).first;
}
void mem(int l,int r,int v){
  IT tmp1=split(l),tmp2=split(r+1);
  st.erase(tmp1,tmp2);
  st.insert({l,r,v});
}
int s,q;
int main(){
  freopen("T2.in","r",stdin);
  freopen("T2.ans","w",stdout);
  scanf("%d",&s);
  st.insert({1,s,0});
  scanf("%d",&q);
  for(int i=1;i<=q;i++){
    int opt;
    scanf("%d",&opt);
    if(opt==1){
      int l,r;
      scanf("%d%d",&l,&r);
      mem(l,r,1);
    }
    else if(opt==2){
      int l,r;
      scanf("%d%d",&l,&r);
      mem(l,r,0);
    }
    else{
      /*for(IT j=st.begin();j!=st.end();j++){
        printf("%d %d %d\n",j->l,j->r,j->v);
      }*/
      int x;
      scanf("%d",&x);
      IT tmp=st.lower_bound({0,x,0});
      if(tmp->v){
        puts("0");
        continue;
      }
      int ans=0;
      ans+=tmp->r-tmp->l+1;
      tmp++;
      bool flag=1;
      for(IT j=tmp;j!=st.end();j++){
        if(j->v){
          flag=0;
          break;
        }
        ans+=j->r-j->l+1;
      }
      tmp--;
      if(flag){
        puts("INF");
        continue;
      }
      flag=1;
      if(tmp!=st.begin()){
      tmp--;
      for(IT j=tmp;;j--){
        if(j->v){
          flag=0;
          break;
        }
        ans+=j->r-j->l+1;
        if(j==st.begin())break;
      }
      }
      if(flag){
        puts("INF");
        continue;
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}
