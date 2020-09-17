#include<bits/stdc++.h>
using namespace std;
int main(){
  srand(time(0));
  freopen("str-ex.in","w",stdout);
  int n=1000,m=10;
  cout<<n<<" "<<m<<endl;
  for(int i=1;i<=n;i++){
    cout<<rand()%2;
  }
  cout<<endl;
  for(int i=1;i<=m;i++){
    cout<<rand()%2;
  }
  cout<<endl;
  return 0;
}
