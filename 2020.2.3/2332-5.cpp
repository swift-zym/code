#include<bits/stdc++.h>
using namespace std;
int son[500001][2],cnt=1,sum[500001],fin[500001];
void ins(vector<int>v){
  int now=1;
  for(int i=0;i<v.size();i++){
    if(!son[now][v[i]])son[now][v[i]]=++cnt;
    now=son[now][v[i]];
    sum[now]++;
  }
  fin[now]++;
}
int ask(vector<int>v){
  int now=1,ans=0;
  for(int i=0;i<v.size();i++){
    if(!son[now][v[i]]){
      return ans;
    }
    now=son[now][v[i]];
    ans+=fin[now];
  }
  return ans+sum[now]-fin[now];
}
int n,m;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    int k;
    scanf("%d",&k);
    vector<int>v;
    for(int i=1;i<=k;i++){
      int a;
      scanf("%d",&a);
      v.push_back(a);
    }
    ins(v);
  }
  for(int i=1;i<=m;i++){
    int k;
    scanf("%d",&k);
    vector<int>v;
    for(int i=1;i<=k;i++){
      int a;
      scanf("%d",&a);
      v.push_back(a);
    }
    printf("%d\n",ask(v));
  }
  return 0;
}
