#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a[1001];
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    bool flag=1;
    for(int i=2;i<=n;i++){
      if(a[i]-a[i-1]>1)flag=0;
    }
    if(flag){
      puts("YES");
    }
    else{
      puts("NO");
    }
  }
  return 0;
}
