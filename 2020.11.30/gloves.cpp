#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int n,a[100],b[100],c[100];
unordered_map<int,int>mx;
void check(int m,int n){
    //cout<<m<<" "<<n<<endl;
    if(n>mx[m]){
        mx[m]=n;
    }
}
int tmp[100][2],cnt;
void dfs(int deep){
    if(deep==n+1){
        int x=0,y=0;
        for(int i=1;i<=n;i++){
            if(c[i]==0)x+=a[i];
            else y+=b[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]>0&&b[i]>0){
                if(c[i]==0){
                    check(x-a[i]+1,y+1);
                }
                else{
                    check(x+1,y-b[i]+1);
                }
            }
        }
        return;
    }
    c[deep]=0;
    dfs(deep+1);
    c[deep]=1;
    dfs(deep+1);
}
int add1,add2;
int main(){
    freopen("gloves.in","r",stdin);
    freopen("gloves.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&tmp[i][0]);
    for(int i=1;i<=n;i++)scanf("%d",&tmp[i][1]);
    for(int i=1;i<=n;i++){
        if(tmp[i][0]==0){
            add2+=tmp[i][1];
        }
        else if(tmp[i][1]==0){
            add1+=tmp[i][0];
        }
        else{
            a[++cnt]=tmp[i][0];
            b[cnt]=tmp[i][1];
        }
    }
    n=cnt;
    dfs(1);
    int mi=INT_MAX,x,y;
    for(auto i:mx){
        //cout<<i.first<<" "<<i.second<<endl;
        if(i.first+i.second<mi){
            x=i.first;y=i.second;
            mi=i.first+i.second;
        }
    }
    printf("%d\n%d\n",x+add1,y+add2);
    return 0;
}