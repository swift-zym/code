#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,d,e,f;
int main(){
  scanf("%d",&T);
  while(T--){
    d=e=f=0;
    scanf("%d",&n);
    bool flag=1;
    for(int i=1;i<=n;i++){
      scanf("%d%d%d",&c,&a,&b);
      if(abs(a-d)+abs(b-e)>c-f||(c-f-abs(a-d)-abs(b-e))%2==1){
        flag=0;
      }
      f=c;
      d=a;
      e=b;
    }
    if(flag){
      puts("Yes");
    }
    else{
      puts("No");
    }
  }
  return 0;
}
