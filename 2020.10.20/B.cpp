#include<bits/stdc++.h>
using namespace std;
int x[51],y[51],n,ans[51];
vector<int>v;
int main(){
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    memset(ans,0x3f,sizeof(ans));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=0;i<=500;i++)
    for(int j=0;j<=500;j++){
        v.clear();
        for(int k=1;k<=n;k++){
            v.push_back(abs(x[k]-i)+abs(y[k]-j));
        }
        sort(v.begin(),v.end());
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            ans[i]=min(ans[i],sum);
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}