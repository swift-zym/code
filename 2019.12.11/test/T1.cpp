#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[1100],t[1100];
int a[1100],b[1100],c[1100],ans[1100],mlen=1e8;
bool cmp(int len){
  if(!len)return 0;
  bool flag=1;
  for(int i=1;i<=n-len+1;i++){
    int pos=i,fin=1;
    for(int j=1;j<=len;j++){
      while(pos<=n&&a[pos]!=c[j])pos++;
      if(a[pos]!=c[j]){
      fin=0;
      break;
      }
      if(j!=len&&pos==n){
      fin=0;
      break;
      }
      pos++;
    }
    if(fin){
      flag=0;
      break;
    }
  }
  if(!flag)return 0;
  for(int i=1;i<=m-len+1;i++){
    int pos=i,fin=1;
    for(int j=1;j<=len;j++){
      while(pos<=m&&b[pos]!=c[j])pos++;
      if(b[pos]!=c[j]){
        fin=0;
        break;
      }
      if(j!=len&&pos==m){
        fin=0;
        break;
      }
      pos++;
    }
    if(fin){
      flag=0;
      break;
    }
  }
  if(!flag)return 0;
  return 1;
}
void dfs(int deep){
  if(deep-1>=mlen)return;
  if(cmp(deep-1)){
    for(int i=1;i<deep;i++)ans[i]=c[i];
    mlen=deep-1;
    return;
  }
  if(deep>max(n,m))return;
  c[deep]=0;
  dfs(deep+1);
  if(deep-1>=mlen)return;
  c[deep]=1;
  dfs(deep+1);
}
int main(){
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  scanf("%s",t);
  for(int i=0;i<n;i++)a[i+1]=s[i]-'0';
  for(int i=0;i<m;i++)b[i+1]=t[i]-'0';
  dfs(1);
  for(int i=1;i<=mlen;i++)printf("%d",ans[i]);
  putchar(10);
  return 0;
}
/*
hack:
2 10
00
10010011100
*/
