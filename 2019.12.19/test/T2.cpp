//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[210000],t[11][210000];
int a[200001],nxt[200001];
struct node{
  int l,r,vis;
};
struct node2{
  int v,id,num;
  bool operator <(const node2 &t)const{
    if(num!=t.num)
    return num>t.num;
    return v<t.v;
  }
}b[200001];
vector<node>v;
void KMP(){
  for(int k=1;k<=m;k++){
  memset(nxt,0,sizeof(nxt));
  nxt[0]=-1;
  int len=strlen(t[k]);
  for(int i=1,j=-1;i<len;i++){
    while(j!=-1&&t[k][j+1]!=t[k][i])j=nxt[j];
    if(t[k][j+1]==t[k][i])j++;
    nxt[i]=j;
  }
  for(int i=0,j=-1;i<n;i++){
    while(j!=-1&&t[k][j+1]!=s[i])j=nxt[j];
    if(t[k][j+1]==s[i])j++;
    if(j==len-1){
      v.push_back({i-len+1,i});
      j=nxt[j];
    }
  }
  }
}
int main(){
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<=m;i++)scanf("%s",t[i]);
  KMP();
  for(int i=1;i<=n;i++)b[i]={a[i],i-1,0};
  int siz=v.size();
  for(int i=1;i<=n;i++){
    for(int j=0;j<siz;j++){
        if(v[j].l<=b[i].id&&v[j].r>=b[i].id){
          b[i].num++;
        }
    }
  }
  sort(b+1,b+n+1);
  int ans=0;
  for(int i=1;i<=n;i++){
    bool flag=0;
    for(int j=0;j<siz;j++){
        if(v[j].l<=b[i].id&&v[j].r>=b[i].id&&v[j].vis==0){
          flag=1;
          v[j].vis=flag;
        }
    }
    if(flag){
      ans+=b[i].v;
    }
  }
  printf("%d\n",ans);
  return 0;
}
