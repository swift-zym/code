#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int dis(int a,int b,int c,int d){
    return abs(a-c)+abs(b-d);
}
int main(){
    int t;
    int n,m,r,c;
    cin>>t;
    while(t--){
        cin>>n>>m>>r>>c;
        cout<<max(dis(1,m,r,c),max(dis(1,1,r,c),max(dis(n,m,r,c),dis(n,1,r,c))))<<endl;
    }
    return 0;
}