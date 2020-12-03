#include<bits/stdc++.h>
using namespace std;
int n,m,s1[100000],s2[100000],a[100000],ans;
int main(){
    freopen("bins.in","r",stdin);
    freopen("bins.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n/2;i++){
        s1[a[i]]++;
        if(i!=1)s2[a[i]]--;
        s2[a[2*i]]++;
        if(i!=1)s2[a[2*i-1]]++;
        int tmp=0;
        for(int j=1;j<=m;j++){
            tmp=max(0,tmp-s2[j]);
            tmp+=s1[j];
        }
        if(!tmp)ans=max(ans,i);
    }
    printf("%d\n",ans);
    return 0;
}