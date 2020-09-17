#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("T1.in","w",stdout);
  int n=1000,w=1000;
  cout<<n<<" "<<w<<endl;
  for(int i=1;i<=n;i++){
    cout<<rand()%1000+1<<" "<<rand()%1000+1<<endl;
  }
  int m=1000;
  cout<<m<<endl;
  for(int i=1;i<=m;i++){
    cout<<rand()%1000+1<<endl;
  }
  return 0;
}
