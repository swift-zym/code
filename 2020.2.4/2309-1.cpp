#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int a0,a1,b0,b1,ans=0;
    scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
    int x=a0/a1,y=b1/b0;
    for(int i=1;i*i<=b1;i++){
      if(b1%i==0){
        if(i%a1==0&&gcd(i/a1,x)==1&&gcd(y,b1/i)==1)ans++;
        int j=b1/i;
        if(i==j)continue;
        if(j%a1==0&&gcd(j/a1,x)==1&&gcd(y,b1/j)==1)ans++;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
