#include<bits/stdc++.h>
#define int long long
using namespace std;
int mx;
int a=-1,b,c;
void chkans(int x,int y,int z){
    if(a==-1){a=x;b=y;c=z;return;}
    if(x*2+y*5+z<a*2+b*5+c){a=x;b=y;c=z;return;}
    if(x*2+y*5+z==a*2+b*5+c){
        if(x<a){a=x;b=y;c=z;return;}
        else if(x==a){
            if(y<b){a=x;b=y;c=z;return;}
        }
    }
}
signed main(){
    int n;cin>>n;
    for(int j=1;j*j<=n;j++){
        int k=n/j,i=n%j;
        if(i==0){k--;i+=j;}
        if(i+j*k==n){
            chkans(i,j,k);
        }
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}