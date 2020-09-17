//
// Created by swift on 2020/8/2.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[60];
void ins(int x){
    for(int i=50;i>=0;i--){
        if(x&(1ll<<i)){
            if(!p[i]){
                p[i]=x;
                break;
            }
            x^=p[i];
        }
    }
}
int n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        int x=0;
        for(int i=0;i<n;i++){
            if(s[i]=='O')x|=(1ll<<i);
        }
        ins(x);
    }
    int ans=0;
    for(int i=0;i<=50;i++){
        if(p[i])ans++;
    }
    cout<<(1ll<<ans)%2008<<endl;
    return 0;
}