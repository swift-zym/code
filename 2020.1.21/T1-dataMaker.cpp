#include<bits/stdc++.h>
using namespace std;
int main(){
  srand(time(0));
  freopen("T1.in","w",stdout);
  int n=1000,q=10;
  cout<<n<<" "<<q<<endl;
  for(int i=1;i<=q;i++){
    cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%n+1<<endl;
  }
  return 0;
}
