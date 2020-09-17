#include<bits/stdc++.h>
using namespace std;
int n=1000,m=5;
int main(){
    srand(time(0));
    freopen("C.in","w",stdout);
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        cout<<char('a'+rand()%5);
    }
    cout<<endl;
    return 0;
}