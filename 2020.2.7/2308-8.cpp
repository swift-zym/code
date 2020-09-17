#include<bits/stdc++.h>
using namespace std;
int main(){
  int cnt=0;
  while(1){
    ++cnt;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a+b+c+d!=-4){
      int i;
      for(i=d+1;i<21252;i++){
        if((i-c)%33==0)break;
      }
      for(;i<21252;i+=33){
        if((i-b)%28==0)break;
      }
      for(;i<21252;i+=28*33){
        if((i-a)%23==0)break;
      }
      printf("Case %d: the next triple peak occurs in %d days.\n",cnt,i-d);
    }
    else{
      break;
    }
  }
  return 0;
}
