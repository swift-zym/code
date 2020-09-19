//题目名:奶牛的歌声
#include<bits/stdc++.h>
using namespace std;
struct cow{
    int h,v;
}a[50001];
int n,ans[50001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].h>>a[i].v;
    stack<int>s;
    for(int i=1;i<=n;i++){
        while((!s.empty())&&a[i].h>a[s.top()].h){
            ans[i]+=a[s.top()].v;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=n;i>=1;i--){
        while((!s.empty())&&a[i].h>a[s.top()].h){
            ans[i]+=a[s.top()].v;
            s.pop();
        }
        s.push(i);
    }
    int maxn=-1;
    for(int i=1;i<=n;i++){
        maxn=max(maxn,ans[i]);
    }
    cout<<maxn<<endl;
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}