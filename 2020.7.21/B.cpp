#include <iostream>
#include <cstdio>
using namespace std;
int a[100001];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      int n,k=0;
      scanf("%d",&n);
      for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
      }
      int now=0;
      for(int i=1;i<=n;i++){
        if(a[i]==1)k^=1;
        else break;
        now++;
      }
      if(now==n){
        if(k==0){
          puts("Second");
        }
        else{
          puts("First");
        }
      }
      else{
        if(k==1){
          puts("Second");
        }
        else{
          puts("First");
        }
      }
    }
}
