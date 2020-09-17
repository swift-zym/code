#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int T,n;
int sg[2000000],vis[100];
void solve(){
    for(int i=(1<<20)-1;i>=0;i--){
        memset(vis,0,sizeof(vis));
        int pos=-1;
        int mx=0;
        for(int j=19;j>=0;j--){
            if((i|(1<<j))!=i){
                pos=j;
            }
            else{
                if(pos==-1)continue;
                int nxt=i;
                nxt&=(~(1<<j));
                nxt|=(1<<pos);
                vis[sg[nxt]]=1;
                //sg[i]=max(sg[i],sg[nxt]+1);
            }
        }
        for(int j=0;;j++){
            if(!vis[j]){
                sg[i]=j;
                break;
            }
        }
    }
}
int main(){
    solve();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){
            int m;
            scanf("%d",&m);
            int tmp=0;
            for(int j=1;j<=m;j++){
                int a;
                scanf("%d",&a);
                tmp|=(1<<(a-1));
            }
            ans^=sg[tmp];
        }
        if(ans==0){
            puts("NO");
        }
        else{
            puts("YES");
        }
    }
    return 0;
}