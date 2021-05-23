#include<bits/stdc++.h>
using namespace std;
int n=100;
int main(){
  freopen("out.txt","w",stdout);
  cout<<n<<endl;
  for(int i=1;i<=n;i++){
    cout<<rand()%100+1<<" ";
  }
  putchar(10);
  for(int i=2;i<=n;i++){
    cout<<rand()%(i-1)+1<<" "<<i<<endl;
  }
  return 0;
}
