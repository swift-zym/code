#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001],f[1000001];
int num[1000001];
int tmp;
bool check(int x){
    tmp=0;
    memset(num,0,sizeof(num));
    for(int i=1;i<=x;i++){
        if(num[a[i]]==0){
            tmp++;
        }
        num[a[i]]++;
        if(num[a[i]]>=f[x]){
            tmp--;
        }
    }
    if(!tmp)return 1;
    for(int i=x+1;i<=n;i++){
        num[a[i-x]]--;
        if(num[a[i-x]]==0){
            tmp--;
        }
        if(num[a[i]]==0){
            tmp++;
        }
        num[a[i]]++;
        if(num[a[i]]>=f[x]){
            tmp--;
        }
        if(!tmp)return 1;
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&f[i]);
    bool flag=1;
    for(int i=2;i<=n;i++){
        if(f[i]!=f[i-1])flag=0;
    }
    for(int i=n;i>=0;i--){
        if(f[i]>i)continue;
        if(check(i)){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}