#include<bits/stdc++.h>
using namespace std;
int n,sum,xorSum;
int main(){
    
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        a^=sum;
        xorSum^=a;
        sum+=b;
        cout<<sum<<endl;
    }
    return 0;
}