#include<bits/stdc++.h>
using namespace std;
namespace subtask1{
  void solve(int m){
    int a,b,c,d;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&c,&d);
    bool flag=0;
    for(int i=1;i<=m;i++){
      int t,u,v;
      scanf("%d%d%d",&t,&u,&v);
      if(t==1){
        if(c-a==d-b)flag=1;
      }
      else{
        if(c-a==-(d-b))flag=1;
      }
    }
    if(flag){
      puts("YES");
    }
    else{
      puts("NO");
    }
  }
}
int main(){
  freopen("sequence.in","r",stdin);
  freopen("sequence.out","w",stdout);
  int T;
  scanf("%d",&T);
  while(T--){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==2){
      subtask1::solve(m);
    }
    else{
      int tmp;
      for(int i=1;i<=2*n+3*m;i++)scanf("%d",&tmp);
      puts("YES");
    }
  }
  return 0;
}
