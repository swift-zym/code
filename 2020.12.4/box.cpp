#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],vis[100000],ans;
vector<int>v;
int main(){
    freopen("box.in","r",stdin);
    freopen("box.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(!vis[a[i]]){
            vis[a[i]]=1;
            ans++;
            for(int j=a[i];j<=m;j++){
                vis[j]|=vis[j-a[i]];
            }
        }
    }
    int num=0;
    for(int i=1;i<=m;i++){
        num+=vis[i];
        //out<<vis[i]<<" ";
    }
    if(num!=n){
        puts("-1");
    }
    else{
        printf("%d\n",ans);
    }
    return 0;
}