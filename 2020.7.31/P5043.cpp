//
// Created by swift on 2020/7/31.
//

#include<bits/stdc++.h>
#define int unsigned long long
#define BAS 17019
using namespace std;
vector<int>v[1000];
void clear() {
    for (int i = 1; i <= 500; i++)v[i].clear();
}
int val[100];
void dfs(int now,int fa){
    vector<int>tmp;
    for(int i=0;i<v[now].size();i++){
        if(v[now][i]!=fa){
            dfs(v[now][i],now);
            tmp.push_back(val[v[now][i]]);
        }
    }
    val[now]=1;
    if(!tmp.size()){
        return;
    }
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<tmp.size();i++){
        val[now]=val[now]*BAS+tmp[i];
    }
}
vector<int>ans[1000];
int m;
bool cmp(vector<int>a,vector<int>b){
    if(a.size()!=b.size())return 0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])return 0;
    }
    return 1;
}
signed main(){
    scanf("%llu",&m);
    for(int i=1;i<=m;i++){
        int n;
        clear();
        scanf("%llu",&n);
        for(int j=1;j<=n;j++){
            int f;
            scanf("%llu",&f);
            if(f){
                v[f].push_back(j);
                v[j].push_back(f);
            }
        }
        for(int j=1;j<=n;j++){
            dfs(j,j);
            ans[i].push_back(val[j]);
        }
        sort(ans[i].begin(),ans[i].end());
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=i;j++){
            if(cmp(ans[i],ans[j])){
                printf("%llu\n",j);
                break;
            }
        }
    return 0;
}
//1997 1997->844793062->848205935(1,2)
//1997->3414870 1997->848205935(3,3)