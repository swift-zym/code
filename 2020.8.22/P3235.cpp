#include<bits/stdc++.h>
using namespace std;
int sg[100001];
int vis[100001];
int t,f;
int getsg(int x){
    if(sg[x]!=-1)return sg[x];
    if(x<f)return sg[x]=0;
    sg[x]=0;
    //memset(vis,0,sizeof(vis));
    for(int i=2;i<=x;i=x/(x/i)+1){
        for(int j=i;j<=min(i+1,x);j++){
            int val=0;
            if((x%j)%2)val^=getsg(x/j+1);
            if((j-x%j)%2)val^=getsg(x/j);
            vis[val]=x;
        }
    }
    while(vis[sg[x]]==x)sg[x]++;
    return sg[x];
}

int main(){

    memset(sg,-1,sizeof(sg));
    scanf("%d%d",&t,&f);
    while(t--){
        int n;
        scanf("%d",&n);
        int flag=0;
        for(int i=1;i<=n;i++){
            int tmp;
            scanf("%d",&tmp);
            flag^=getsg(tmp);
        }
        printf("%d",flag?1:0);
        if(t)putchar(' ');
    }
    return 0;
}