#include<bits/stdc++.h>
using namespace std;
struct node{
    int t,m;
    bool operator <(const node &b)const{
        return m<b.m;
    }
    bool operator >(const node &b)const{
        return m>b.m;
    }
}a[501];
inline bool cmp(node a,node b){
    return a.t<b.t;
}
int n,m,vis[501],total=0;
int main(){
    scanf("%d",&m);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].t);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].m),a[i].m=-a[i].m,total+=-a[i].m;
    priority_queue<node>q;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(q.size()<a[i].t){
            q.push(a[i]);
        }
        else{
            if(a[i].m<q.top().m){
                q.pop();
                q.push(a[i]);
            }
        }
    }
    while(!q.empty()){
        total+=q.top().m;
        q.pop();
    }
    printf("%d\n",max(0,m-total));
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}