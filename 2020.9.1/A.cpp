#include<bits/stdc++.h>
using namespace std;
int n,h[1000001];
int ans[1000001];
struct node{
    int x,v;
};
stack<node>s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&h[i]);
    for(int i=1;i<=n;i++){
        while((!s.empty())&&s.top().v<h[i]){
            ans[s.top().x]=i;s.pop();
        }
        node tmp;
        tmp.x=i;tmp.v=h[i];
        s.push(tmp);
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}