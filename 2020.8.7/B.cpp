//
// Created by swift on 2020/8/7.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int>a;
vector<int>ans;
int gcd(int a,int b){
    if(b==0)return 1;
    return gcd(b,a%b);
}
signed main(){
    cin>>n;
    if(n==1||n==2){
        puts("0");
        return 0;
    }
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            a.push_back(i);
            if(i*i!=n){
                a.push_back(n/i);
            }
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]==1)continue;
        int v=n/a[i]*(a[i]/2);
        if(v*2<n)
        ans.push_back(v*2);
    }
    sort(ans.begin(),ans.end());
    int lst=unique(ans.begin(),ans.end())-ans.begin();
    cout<<lst;
    for(int i=0;i<lst;i++){
        putchar(' ');
        printf("%lld",ans[i]);
    }
    putchar(10);
    return 0;
}