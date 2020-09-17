//
// Created by swift on 2020/8/10.
//

#include<bits/stdc++.h>
using namespace std;
int n,q,a[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=q;i++){
        char c;
        int l,r,w,ans=0;
        cin>>c>>l>>r>>w;
        if(c=='A'){
            for(int j=l;j<=r;j++){
                if(a[j]>=w)ans++;
            }
            cout<<ans<<endl;
        }
        else{
            for(int j=l;j<=r;j++){
                a[j]+=w;
            }
        }
    }
    return 0;
}