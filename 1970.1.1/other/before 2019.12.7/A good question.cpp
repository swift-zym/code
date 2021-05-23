// LUOGU U73951
#include<bits/stdc++.h>
using namespace std;
void exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    int t=x;x=y,y=t-a/b*y;
}
int main(){
    int n,p,x,y;
    cin>>n>>p;
    exgcd(n,p,x,y);
    cout<<x<<endl;
}