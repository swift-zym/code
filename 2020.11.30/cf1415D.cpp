#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],sum[1000001],ans=1e9;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    if(n>100){
        puts("1");
        return 0;
    }
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    for(int k=i;k<j;k++){
        if((sum[k]^sum[i-1])>(sum[j]^sum[k])){
            ans=min(ans,j-i-1);
        }
    }
    if(ans==1e9){
        puts("-1");
        return 0;
    }
    printf("%d\n",ans);
    return 0;
}