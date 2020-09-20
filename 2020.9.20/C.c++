#include<bits/stdc++.h>
using namespace std;
int cnt;
int a[101],pos[101];
int n;
bool isprime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return 0;
    }
    return 1;
}
int tmp[110];
void check(int x){
    int sta=0;
    for(int i=2;i<=53;i++){
        if(x%i==0&&isprime(i)){
            sta|=(1<<(pos[i]));
        }
    }
    tmp[x]=sta;
}
int dp[110][100000];
int ans[110][100000];
void print(int x,int y){
    if(x>1){
        print(x-1,y^tmp[ans[x][y]]);
    }
    printf("%d ",ans[x][y]);
}
int main(){
    for(int i=2;i<=53;i++){
        if(isprime(i)){
            pos[i]=cnt++;
        }
    }
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=2;i<=58;i++){
        check(i);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    for(int j=0;j<(1<<16);j++){
        for(int k=1;k<=58;k++){
            if((j|tmp[k])!=j)continue;
            if(dp[i-1][j^tmp[k]]+abs(a[i]-k)<dp[i][j]){
                dp[i][j]=dp[i-1][j^tmp[k]]+abs(a[i]-k);
                ans[i][j]=k;
            }
            //if(i>=3)
            //cout<<k<<"->"<<dp[i-1][j^tmp[k]]<<"("<<(j^tmp[k])<<") "<<abs(a[i]-k)<<endl;
        }
        //if(i>=3){
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            //system("pause");
        //}
    }
    //cout<<dp[2][0]<<endl;
    int ans=dp[0][1];
    int idx;
    for(int i=0;i<(1<<16);i++){
        if(dp[n][i]<ans){
            ans=dp[n][i];
            idx=i;
        }
    }
    print(n,idx);
    putchar(10);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}