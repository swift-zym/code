#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1001][1001],go[1001][1001],bf[1001][1001];
int n,m;
vector<int>v;
void add(int x,int y){
  if(!go[x][y])return;
  add(x,go[x][y]);
  v.push_back(go[x][y]);
  add(go[x][y],y);
}
signed main(){
  scanf("%lld%lld",&n,&m);
  memset(a,0x0f,sizeof(a));
  for(int i=1;i<=m;i++){
    int x,y,z;
    scanf("%lld%lld%lld",&x,&y,&z);
    a[x][y]=a[y][x]=min(a[x][y],z);
  }
  memcpy(bf,a,sizeof(a));
  int ans=0x3f3f3f3f;
  for(int k=1;k<=n;k++){
    for(int i=1;i<k;i++)
    for(int j=i+1;j<k;j++){
      if(a[i][j]+bf[j][k]+bf[k][i]<ans){
        ans=a[i][j]+bf[j][k]+bf[k][i];
        v.clear();
        v.push_back(i);
        add(i,j);
        v.push_back(j);
        v.push_back(k);
      }
    }
    for(int i=1;i<=n;i++){
      if(i==k)continue;
      for(int j=1;j<=n;j++){
        if(j==k||j==i)continue;
        if(a[i][j]>a[i][k]+a[k][j]){
          a[i][j]=a[i][k]+a[k][j];
          go[i][j]=k;
        }
      }
    }
  }
  if(ans==0x3f3f3f3f){
    puts("No solution.");
  }
  else{
    for(int i=0;i<v.size();i++){
      if(i)putchar(' ');
      printf("%lld",v[i]);
    }
    putchar(10);
  }
  return 0;
}
