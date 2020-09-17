#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int isOk(int a){
    vector<int>v;
    while(a){
        v.push_back(a%2);
        a/=2;
    }
    int num=0;
    for(int i=0;i<v.size();i++){
        num+=v[i];
        if(i>=m){
            num-=v[i-m];
        }
        if(num>=k)return 0;
    }
    return 1;
}
int main(){
    cin>>n>>m>>k;
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        if(isOk(i))ans++;
    }
    printf("%d\n",ans);
    return 0;
}