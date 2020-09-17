#include<bits/stdc++.h>
using namespace std;
struct node{
  int sta=0,ans=0;
};
int vis[1000000];
int main(){
  node s1,s2;
  for(int i=0;i<=3;i++)
  for(int j=0;j<=3;j++){
    char c=getchar();
    while(c!='0'&&c!='1')c=getchar();
    int a=c-'0';
    if(a)
    s1.sta|=(1<<(4*i+j));
  }
  for(int i=0;i<=3;i++)
  for(int j=0;j<=3;j++){
    char c=getchar();
    while(c!='0'&&c!='1')c=getchar();
    int a=c-'0';
    if(a)
    s2.sta|=(1<<(4*i+j));
  }
  queue<node>q;
  q.push(s1);
  while(!q.empty()){
    node now=q.front();
    vis[now.sta]=1;
    q.pop();
    if(now.sta==s2.sta){
      printf("%d\n",now.ans);
      return 0;
    }
    for(int i=0;i<=3;i++)
    for(int j=0;j<=3;j++){
      if(j<3&&((now.sta&(1<<(i*4+j)))!=(now.sta&(1<<(i*4+j+1))))){
        node nxt=now;
        int a=(now.sta&(1<<(i*4+j)))>=1;
        if(a){
          nxt.sta|=(1<<(i*4+j+1));
          nxt.sta&=(~(1<<(i*4+j)));
        }
        else{
          nxt.sta|=(1<<(i*4+j));
          nxt.sta&=(~(1<<(i*4+j+1)));
        }
        nxt.ans++;
        if(!vis[nxt.sta]){
        vis[nxt.sta]=1;
        q.push(nxt);
        }
      }
      if(i<3&&((now.sta&(1<<(i*4+j)))!=(now.sta&(1<<((i+1)*4+j))))){
        node nxt=now;
        int a=(now.sta&(1<<(i*4+j)))>=1;
        if(a){
          nxt.sta|=(1<<((i+1)*4+j));
          nxt.sta&=(~(1<<(i*4+j)));
        }
        else{
          nxt.sta|=(1<<(i*4+j));
          nxt.sta&=(~(1<<((i+1)*4+j)));
        }
        nxt.ans++;
        if(!vis[nxt.sta]){
        vis[nxt.sta]=1;
        q.push(nxt);
        }
      }
    }
  }
  return 0;
}
