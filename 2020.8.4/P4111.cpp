//
// Created by swift on 2020/8/4.
//

#include<bits/stdc++.h>
#define MOD 1000000000
#define int long long
using namespace std;
int n,m,a[101][101];
void add(int x,int y){
    a[x][y]--;
    a[y][x]--;
    a[x][x]++;
    a[y][y]++;
}
int guess(int n){
    int ans=1;
    for(int i=1;i<=n;i++) {
        for (int k = i + 1; k <= n; k++) {
            while (a[k][i]) {
                int d = a[i][i] / a[k][i];
                for (int j = i; j <= n; j++) {
                    a[i][j] -= a[k][j] * d % MOD;
                    a[i][j] = (a[i][j] + MOD) % MOD;
                }
                swap(a[i],a[k]);
                ans *= -1;
            }
        }
        ans*=a[i][i];
        ans%=MOD;
        ans=(ans+MOD)%MOD;
    }
    return ans;
}
int cnt,id[101][101];
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c=getchar();
            while(c!='.'&&c!='*')c=getchar();
            if(c=='.'){
                id[i][j]=++cnt;
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(id[i][j]){
                if(id[i-1][j]){
                    add(id[i-1][j],id[i][j]);
                }
                if(id[i][j-1]){
                    add(id[i][j-1],id[i][j]);
                }
            }
        }
    printf("%lld\n",guess(cnt-1));
    return 0;
}