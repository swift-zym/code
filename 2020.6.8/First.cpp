#include<bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001],idx[100001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memcpy(b,a,sizeof(a));
    sort(b+1,b+n+1);
    int num=0;
    for(int i=1;i<=n;i++){
        num+=1-b[i];
    }
    int rk0=0,rk1=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            rk0++;
            idx[i]=rk0;
        }
        else{
            rk1++;
            idx[i]=num+rk1;
        }
    }
    int now=1;
    vector<int>ans;
    ans.push_back(a[now]);
    for(int i=1;i<n;i++){
        now=idx[now];
        ans.push_back(a[now]);
    }
    for(int i=n-1;i>=0;i--){
        printf("%d",ans[i]);
        if(i)putchar(' ');
    }
    putchar(10);
    return 0;
}