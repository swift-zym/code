#include<iostream>
#include<queue>
using namespace std;
int T,m,n;
int u[100001],v[100001];
queue<int>s[100001],t[100001];
int vis[100001];
int main(){
    scanf("%d%d%d",&T,&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&u[i],&v[i]);
        if(T==1){
            s[u[i]].push(i);
            s[v[i]].push(-i);
        }
        else{
            s[u[i]].push(i);
            t[v[i]].push(i);
        }
    }
    deque<int>ans;
    ans.push_back(1);
    int now=1;
    vis[now]=1;
    if(T==2){
        while(true){
            int bk=now;
            int siz=t[u[now]].size();
            for(int j=1;j<=siz;j++){
                int to=t[u[now]].front();
                if(vis[to]){
                    t[u[now]].pop();
                    continue;
                }
                now=to;
                vis[now]=1;
                ans.push_front(now);
                break;
            }
            if(now==bk)break;
        }
    }
    else{
        while(true){
            int bk=now;
            int siz=s[u[now]].size();
            for(int j=1;j<=siz;j++){
                int to=s[u[now]].front();
                if(vis[abs(to)]){
                    s[u[now]].pop();
                    continue;
                }
                now=abs(to);
                vis[now]=1;
                ans.push_front(to);
                break;
            }
            if(now==bk)break;
        }
    }
    now=1;
    if(T==2){
        while(true){
            int bk=now;
            int siz=s[v[now]].size();
            for(int j=1;j<=siz;j++){
                int to=s[v[now]].front();
                if(vis[to]){
                    s[v[now]].pop();
                    continue;
                }
                now=to;
                vis[now]=1;
                ans.push_back(now);
                break;
            }
            if(now==bk)break;
        }
    }
    else{
        while(true){
            int bk=now;
            int siz=s[v[now]].size();
            for(int j=1;j<=siz;j++){
                int to=s[v[now]].front();
                if(vis[abs(to)]){
                    s[v[now]].pop();
                    continue;
                }
                now=abs(to);
                vis[now]=1;
                ans.push_back(to);
                break;
            }
            if(now==bk)break;
        }
    }
    if(ans.size()==n){
        puts("YES");
        for(int i=0;i<n;i++){
            if(i)putchar(' ');
            printf("%d",ans.front());
            ans.pop_front();
        }
        putchar(10);
    }
    else{
        puts("NO");
    }
    return 0;
}