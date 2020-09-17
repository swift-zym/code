/*************************
User:Mandy.H.Y
Language:
Algorithm:
Score:
*************************/

//动态插入删除，平衡树，
//算了，用set  ^v^
//还可以用multiset,vactor
//都练练啦

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n,m,dfn[maxn],tot,last,rev[maxn];
int size,first[maxn];
long long dis[maxn];
long long ans;//long long
int father[maxn],top[maxn],cnt[maxn],dep[maxn];
set<int>s;

struct Edge{
    int v,nt,w;
}edge[maxn << 1];

template<class T>inline void read(T &x){
    x = 0;bool flag = 0;char ch = getchar();
    while(!isdigit(ch)) flag |= ch == '-',ch = getchar();
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48),ch = getchar();
    if(flag)x = -x;
}

template<class T>void putch(const T x){
    if(x > 9) putch(x / 10);
    putchar(x % 10 | 48);
}

template<class T>void put(const T x){
    if(x < 0) putchar('-'),putch(-x);
    else putch(x);
}

void file(){
    freopen("stone2.in","r",stdin);
    freopen("stone2.ans","w",stdout);
}

void eadd(int u,int v,int w){
    edge[ ++ size].v = v;
    edge[size].w = w;
    edge[size].nt = first[u];
    first[u] = size;
}

void readdata(){
    file();
    read(n);

    for(int i = 1;i < n;i ++ ){
        int u,v,w;
        read(u);read(v);read(w);
        eadd(u,v,w);eadd(v,u,w);
    }

    read(m);
}

void dfs(int u,int f,int d){

    dfn[u] = ++tot;rev[tot] = u;
    father[u] = f;dep[u] = d;
    top[u] = u;cnt[u] = 1;
    int mcnt = 0,son = 0;

    for(int i = first[u];i;i = edge[i].nt){
        int v = edge[i].v;
        int w = edge[i].w;
        if(v == f) continue;
        dis[v] = dis[u] + w;
        dfs(v,u,d + 1);
        cnt[u] += cnt[v];
        if(mcnt < cnt[v]){
            mcnt = cnt[v];
            son = v;
        }
    }

    if(son) top[son] = u;

}

int find(int x){
    return top[x] == x ? x : top[x] = find(top[x]);
}

int LCA(int x,int y){
    if(find(x) == find(y)) return dep[x] < dep[y] ? x : y;
    else return dep[top[x]] < dep[top[y]] ? LCA(x,father[top[y]]) : LCA(y,father[top[x]]);
    //又打错模板
}

inline set<int>::iterator Left(set<int>::iterator u){
    set<int>::iterator l;
    if(u == s.begin()) l = --s.end();
    else l = --u;
    return l;
}

inline set<int>::iterator Right(set<int>::iterator u){
    set<int>::iterator r;
    if(u == --s.end()) r = s.begin();
    else r = ++u;
    return r;
} //还是打包比较稳妥
void work(){

    dfs(1,0,1);

    while(m -- ){
        char opt = getchar();
        int x;
        while(opt != '+' && opt != '-' && opt != '?') opt = getchar();
        switch(opt){

            case '+':{
                read(x);

                if(s.size()){//判空

                    set<int> :: iterator u = s.lower_bound(dfn[x]),l;

                    if(u == s.end()) u = s.begin();
                    //u是后一个
                    //l是前一个
                    int t = *u;//防止u改变
                    l = Left(u);

                    ans -= (dis[rev[t]] + dis[rev[*l]] - 2 * dis[LCA(rev[*l],rev[t])]);
                    ans += (dis[rev[*l]] + dis[x] - 2 * dis[LCA(x,rev[*l])]);
                    ans += (dis[rev[t]] + dis[x] - 2 * dis[LCA(x,rev[t])]);

                }
                s.insert(dfn[x]);
                break;
            }

            case '-':{
                    read(x);
                    if(s.size()){
                        set<int> :: iterator u = s.find(dfn[x]),l,r;
                        l = Left(u);

                        r = Right(u);


                        ans -= (dis[rev[*l]] + dis[x] - 2 * dis[LCA(x,rev[*l])]);
                        ans -= (dis[rev[*r]] + dis[x] - 2 * dis[LCA(x,rev[*r])]);
                        ans += (dis[rev[*r]] + dis[rev[*l]] - 2 * dis[LCA(rev[*l],rev[*r])]);

                    }
                    s.erase(dfn[x]);
                break;
            }

            default:{

                put(ans / 2);
                puts("");
                break;

            }
        }
    }
}

int main(){
//    file();
    readdata();
    work();
    return 0;
}
