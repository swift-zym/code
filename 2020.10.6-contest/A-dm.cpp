#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,w;
int big_rand(){return rand()*rand();}
signed main(){
    srand(time(0));
    cin>>n>>w;
    freopen("A.in","w",stdout);
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        int v=big_rand()%(w*2+1);
        v-=w;
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}