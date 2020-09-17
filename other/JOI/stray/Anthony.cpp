#include "Anthony.h"
#include <bits/stdc++.h>
using namespace std;
vector<int>id[20000],to[20000];
int col[20000],ans1[20000],vis[20000];
void dfs(int now,int deep,int pre,int fa,int a){
  if(pre!=-1){
    col[pre]=deep%min(a,3);
  }
  for(int i=0;i<to[now].size();i++){
    if(to[now][i]==fa||col[id[now][i]]==3)continue;
    dfs(to[now][i],deep+1,id[now][i],now,a);
  }
}
struct node{
    int x,y;
    inline bool operator <(const node &a) const {
     return y>a.y;
    }
};
std::vector<int> Mark(int N, int M, int A, int B,
                      std::vector<int> U, std::vector<int> V) {
        if(M==N-1){
        for(int i=0;i<M;i++){
          to[U[i]].push_back(V[i]);
          id[U[i]].push_back(i);
          to[V[i]].push_back(U[i]);
          id[V[i]].push_back(i);
        }
        dfs(0,0,-1,0,A);
        vector<int>ans;
        for(int i=0;i<M;i++){
          ans.push_back(col[i]);
        }
        return ans;
        }
        else{
        for(int i=0;i<M;i++){
          to[U[i]].push_back(V[i]);
          id[U[i]].push_back(i);
          to[V[i]].push_back(U[i]);
          id[V[i]].push_back(i);
          col[i]=3;
        }
        memset(ans1,0x3f,sizeof(ans1));
        priority_queue<node>q;
        q.push((node){0,0});
        ans1[0]=0;
        while(!q.empty()){
          node now=q.top();
          q.pop();
          if(now.y!=ans1[now.x])continue;
          for(int i=0;i<to[now.x].size();i++){
            if(ans1[now.x]+1<ans1[to[now.x][i]]){
                ans1[to[now.x][i]]=ans1[now.x]+1;
                col[id[now.x][i]]=0;
                q.push((node){to[now.x][i],ans1[to[now.x][i]]});
          }
       }
      }
      dfs(0,0,-1,0,A-1);
      vector<int>ans;
      for(int i=0;i<M;i++){
        ans.push_back(col[i]);
      }
      return ans;
  }
}
