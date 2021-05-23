#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y;
};
vector<node>v;
int main(){
  int n;
  scanf("%d",&n);
  int x=1,y=1;
  if(n%2==1){
    while(1){
    v.push_back({x,y});
    if(v.size()==n*(n+1))break;
    if(x==1&&y%2==1){
      y+=1;
      continue;
    }
    if(x==n&&y%2==0){
      y-=1;
      continue;
    }
    if(x==2&&y%2==0){
      x-=1;
      y+=1;
      continue;
    }
    if(y%2==1&&x%2==0){
      x++;
      y++;
      continue;
    }
    if(y%2==0&&x%2==1){
      x++;
      y--;
      continue;
    }
    if(y%2==1&&x%2==1){
      x--;
      y++;
      continue;
    }
    if(y%2==0&&x%2==0){
      x--;
      y--;
    }
    }
    printf("%d\n",v.size()-1);
    for(int i=0;i<v.size();i++){
      printf("%d %d\n",v[i].x,v[i].y);
    }
  }
  else{
    while(1){
      v.push_back({x,y});
      if(v.size()==n*(n+1))break;
      if(y==n+1){
        x++;
        continue;
      }
      if(x==1&&y%2==0){
        y++;
        continue;
      }
      if(x==n&&y%2==0){
        y--;
        continue;
      }
      if(x%2==1&&y%2==1){
        x++;y++;
        continue;
      }
      if(x%2==1&&y%2==0){
        x--;y--;
        continue;
      }
      if(x%2==0&&y%2==0){
        x++;y--;
        continue;
      }
      if(x%2==0&&y%2==1){
        x--;y++;
      }
    }
    printf("%d\n",v.size()-1);
    for(int i=0;i<v.size();i++){
      printf("%d %d\n",v[i].x,v[i].y);
    }
  }
  return 0;
}
