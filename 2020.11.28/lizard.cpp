#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,a[1000001],ans;
void dfs(vector<int>v,int deep,int mx){
    if(deep==mx+1){
        if(v.size())
        for(int i=0;i<v.size()-1;i++){
            for(int k=v[i]+1;k<v[i+1]-1;k++){
                if(a[k]>a[v[i]])return;
            }
        }
        ans=max(ans,(int)v.size());
        return;
    }
    dfs(v,deep+1,mx);
    if(v.empty()||a[deep]>a[v[v.size()-1]]){
        v.push_back(deep);
        dfs(v,deep+1,mx);
    }
}
int main(){
    freopen("lizard.in","r",stdin);
    freopen("lizard.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i+k-1<=n;i++){
        ans=0;
        dfs(vector<int>(),i,i+k-1);
        printf("%d ",ans);
    }
    putchar(10);
    return 0;
}