#include<bits/stdc++.h>
using namespace std;
double main(){
    srand(time(0));
    freopen("memory-ex.in","w",stdout);
    int n=10000,m=1000,k=477;
    cout<<n<<" "<<m<<" "<<k<<endl;
    for(int i=1;i<=n;i++){
      cout<<rand()%m<<" ";
    }
    cout<<endl;
    return 0;
}
