#include <bits/stdc++.h>
using namespace std;
long long ans[1005],now[1005],maxnDeep;
bool flag;
void dfs(long long total,long long m,int deep){
    if(deep==0){
        if(total==0){
            flag=1;
            if(now[maxnDeep]<ans[maxnDeep]){
                for(int i=1;i<=maxnDeep;i++){
                    ans[i]=now[i];
                }
            }
            return;
        }
    }
    if(m*deep/total>ans[maxnDeep]||now[maxnDeep-deep]>ans[maxnDeep]){
        return;
    }
    for(long long i=max(now[maxnDeep-deep]+1,m/total);i<=(m*deep)/total;i++){
        now[maxnDeep-deep+1]=i;
        if(total*i<m)continue;
        dfs((total*i-m),i*m,deep-1);
    }
}
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    memset(ans,0x3f,sizeof(ans));
    for(int i=1;;i++){
        maxnDeep=i;
        dfs(a,b,i);
        if(flag){
            for(int j=1;j<=i;j++)
                printf("%lld ",ans[j]);
            printf("\n");
            break;
        }
    }
    return 0;
}
