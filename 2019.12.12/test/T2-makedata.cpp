#include<bits/stdc++.h>
using namespace std;
int n,f[100001],c[100001],d[100001],a[100001];
int main(){
  ios::sync_with_stdio(0);
  cout<<"please input n:";
  cin>>n;
  srand(time(0));
  freopen("data.in","w",stdout);
  cout<<n<<endl;
  for(int i=1;i<=n;i++){
    f[i]=i;
  }
  for(int i=1;i<=n;i++){
    swap(f[rand()%n+1],f[rand()%n+1]);
    c[i]=rand()%1000000+1;
    d[i]=rand()%1000000+1;
    a[i]=rand()%1000000+1;
  }
  for(int i=1;i<=n;i++){
    cout<<f[i]<<" "<<c[i]<<" "<<d[i]<<" "<<a[i]<<endl;
  }
  return 0;
}
