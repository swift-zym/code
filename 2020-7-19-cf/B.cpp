//
// Created by swift on 2020/7/19.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,l,r,m;
signed main(){
    cin>>t;
    while(t--){
        cin>>l>>r>>m;
        for(int i=l;i<=r;i++){
            int j=m/i;
            if(j!=0&&m-i*j<=(r-l)){
                int v=m-i*j;
                cout<<i<<" "<<l+v<<" "<<l<<endl;
                break;
            }
            j++;
            if(i*j-m<=(r-l)){
                int v=i*j-m;
                cout<<i<<" "<<l<<" "<<l+v<<endl;
                break;
            }
        }
    }
    return 0;
}