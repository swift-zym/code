//题目名：Huffman
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[1001],ans;
priority_queue<ll,vector<ll>,greater<ll> >q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        q.push(a[i]);
    }

    while(!q.empty()){
        ll nowa,nowb;
        nowa=q.top();
        q.pop();
        if(q.empty())break;
        nowb=q.top();
        q.pop();
        ans+=nowa+nowb;
        q.push(nowa+nowb);
    }
    printf("%lld\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
}