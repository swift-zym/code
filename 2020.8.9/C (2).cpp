//
// Created by swift on 2020/8/9.
//
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
vector<int>v[800001];
int n,q,dep[800001],f[800001][20],dfn[800001],id[800001],T;
int col[800001];
set<int>st;
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    for(int i=19;i>=0;i--){
        if(dep[f[a][i]]>=dep[b]){
            a=f[a][i];
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(f[a][i]!=f[b][i]){
            a=f[a][i];
            b=f[b][i];
        }
    }
    return f[a][0];
}
stack<int>s;
inline void read(int &x){
    char c=getchar();x=0;
    bool f=0;
    while(c>'9'||c<'0') {if(c=='-') f=1;c=getchar();}
    while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    x=f?-x:x;
}
int main(){
    read(n);read(q);
    for(int i=2;i<=n;i++){
        int f;
        read(f);
        v[f].push_back(i);
    }
    s.push(1);
    f[1][0]=1;
    dep[1]=1;
    while(!s.empty()){
        int now=s.top();
        //cout<<">"<<now<<endl;
        if(!dfn[now]) {
            dfn[now] = ++T;
            id[T] = now;
        }
        int i;
        bool flag=false;
        while(v[now].size()){
            i=v[now].size()-1;
            f[v[now][i]][0]=now;
            dep[v[now][i]]=dep[now]+1;
            s.push(v[now][i]);
            v[now].pop_back();
            flag=true;
            break;
        }
        if(!flag){
            s.pop();
        }
    }

    for(int i=1;i<=19;i++)
        for(int j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]][i-1];
            //cout<<j<<" "<<i<<" "<<f[j][i]<<endl;
        }
    /*for(int i=1;i<=n;i++){
        cout<<dfn[i]<<" ";
    }
    cout<<endl;*/
    for(int i=1;i<=q;i++){
        int x;
        scanf("%d",&x);
        if(x>0){
            if(col[x]){
                col[x]=0;
                st.erase(dfn[x]);
            }
            else{
                col[x]=1;
                st.insert(dfn[x]);
            }
        }
        else{
            if(!st.size()){
                puts("0");
            }
            else {
                x = -x;
                set<int>::iterator it = st.lower_bound(dfn[x]);
                int v1=0,v2=0;
                /*for(int i=x;i!=1;i=f[i][0]){
                    cout<<i<<endl;
                }
                puts("---");*/
                if(it!=st.end()){
                    v2=lca(x,id[*it]);
                    //cout<<">"<<id[*it]<<endl;
                }
                if(it!=st.begin()) {
                    it--;
                    v1 = lca(x,id[*it]);
                    //cout<<">>"<<id[*it]<<endl;
                }
                //cout<<v1<<" "<<v2<<endl;
                if(dep[v1]<dep[v2]){
                    printf("%d\n",v2);
                }
                else{
                    printf("%d\n",v1);
                }
            }
        }
    }
    //cin>>n;
    return 0;
}