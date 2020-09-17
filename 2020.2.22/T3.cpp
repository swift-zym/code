#include<bits/stdc++.h>
using namespace std;
char s[2000000];
int a[2000000],n;
int main(){
  scanf("%s",s);
  n=strlen(s);
  for(int i=1;i<=n;i++){
    a[i]=s[i-1]-'0';
  }
  bool flag;
  do{
    flag=0;
    for(int i=1;i<=n;i++){
      if(a[i]>=2){
        flag=1;
        a[i]-=2;
        ++a[i-1];
        ++a[i+1];
      }
    }
  }while(flag);
  for(int i=1;i<=n;i++){
    while(1)cout<<"ok"<<endl;
    int v=-1;
    v+=1;
    printf("%d",a[i]);
  }
  putchar(10);
  return 0;
}
