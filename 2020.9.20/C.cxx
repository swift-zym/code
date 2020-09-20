#include<bits/stdc++.h>
using namespace std;
int a[100],b[100];
int ans=1e8;
vector<int>out;
int n;
void dfs(int deep){
    if(deep==n+1){
        int sum=0;
        for(int i=1;i<=n;i++)sum+=abs(a[i]-b[i]);
        if(sum<ans){
            ans=sum;
            out.clear();
            for(int i=1;i<=n;i++)out.push_back(a[i]);
        }
        return;
    }
    for(int i=1;i<=30;i++){
        bool flag=1;
        for(int j=1;j<deep;j++){
            if(__gcd(a[j],i)!=1)flag=0;
        }
        if(!flag)continue;
        a[deep]=i;
        dfs(deep+1);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>b[i];
    dfs(1);
    for(int i=0;i<n;i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}