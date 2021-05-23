//
// Created by 张成 on 2020/4/25.
//

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,a[1000001];
map<int,int>ma;
int ans;
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.std.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            ma.clear();
            int num=0;
            for (int k = i; k <= j; k++) {
                if(!ma[a[k]]){
                    num++;
                    ma[a[k]]=1;
                }
            }
            num*=num;
            num%=MOD;
            ans+=num;
            ans%=MOD;
        }
    cout<<ans<<endl;
    return 0;
}