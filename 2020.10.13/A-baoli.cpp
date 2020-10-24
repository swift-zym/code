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
    freopen("out.txt","w",stdout);
    int n;
    for(int n=10;n<=1000;n++){
    a=-1;
    for(int i=1;i<=100;i++)
    for(int j=1;j<=100;j++)
    for(int k=1;k<=100;k++){
        if(i+j*k==n){
            chkans(i,j,k);
        }
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}