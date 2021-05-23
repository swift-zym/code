//
// Created by 张成 on 2020/5/24.
//
/*
 * G-
 */
#include<bits/stdc++.h>
using namespace std;
int n,k,a[1100000];
int main(){
    freopen("kettle.in","r",stdin);
    freopen("kettle.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&k);
    k++;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    int ans=0;
    for(int i=k;i<=n;i++){
        //printf("%d~%d:%d\n",i-k+1,i,a[i]-a[i-k]);
        ans=max(ans,a[i]-a[i-k]);
    }
    printf("%d\n",ans);
    return 0;
}