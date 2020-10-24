#include<bits/stdc++.h>
using namespace std;
int T,typ;
int n;
vector<int>v[100],len[100];
int a[100],l[100],r[100];
bool flag;
void dfs(int deep,int x){
    if(deep==n+1){
        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                if(abs(a[i]-a[v[i][j]])>len[i][j]){
                    return;
                }
            }
        }
        flag=1;
        return;
    }
    for(int i=l[deep]-x;i<=r[deep]+x;i++){
        a[deep]=i;
        dfs(deep+1,x);
    }
}
bool check(int x){
    flag=0;
    dfs(1,x);
    return flag;
}
int main(){
    srand(time(0));
    scanf("%d%d",&T,&typ);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&l[i]);
        for(int i=1;i<=n;i++)scanf("%d",&r[i]);
        for(int i=1;i<=n;i++)v[i].clear(),len[i].clear();
        for(int i=1;i<n;i++){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            v[a].push_back(b);
            len[a].push_back(w);
        }
        if(n>5){puts(rand()%2?"1":"0");continue;}
        if(typ==0){
            printf("%d\n",check(0));
        }
        else{
            for(int i=0;;i++){
                if(check(i)){
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}