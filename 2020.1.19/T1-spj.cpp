#include<bits/stdc++.h>
#include <unistd.h>
#define int long long
using namespace std;
signed main(){
  int n;
  ios::sync_with_stdio(0);
  freopen("T1.in","r",stdin);
  cin>>n;
  freopen("T1.out","r",stdin);
  int a,sum1=0,sum2=n;
  while(cin>>a){
    if(a==n)break;
    sum1+=a;
  }
  while(cin>>a){
    sum2+=a;
  }

  if(sum1==sum2){
    cerr<<"AC"<<endl;
  }
  else{
    cerr<<"WA"<<endl;
    cerr<<sum1<<" "<<sum2<<endl;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
