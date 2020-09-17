//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
#define eps 1e-4
using namespace std;
struct tmp{
  struct node{
    int x,y;
  }b[5];
}a[4];
int main(){
  while(1);
  int t;
  scanf("%d",&t);
  while(t--){
    for(int i=1;i<=3;i++){
      scanf("%d%d",&a[i].b[1].x,&a[i].b[1].y);
    }
    for(int i=1;i<=3;i++){
      scanf("%d%d",&a[i].b[2].x,&a[i].b[2].y);
    }
    for(int i=1;i<=3;i++){
      a[i].b[3]={a[i].b[1].x,a[i].b[2].y};
      a[i].b[4]={a[i].b[2].x,a[i].b[1].y};
    }
    bool flag=0;
    for(int i=1;i<=3;i++){
      for(int j=1;j<=4;j++){

      }
    }
    if(flag){
      puts("0 0 0 0 0 0");
    }
    else{
      puts("-1");
    }
  }
}
//cos(A)=(b*b+c*c-a*a)/(2*b*c)
