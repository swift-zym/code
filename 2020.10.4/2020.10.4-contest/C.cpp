#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2001],b[2001],times[2001];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    int now=0,num=0;
    while(now!=n+1){
        times[now]++;
        if(now==0)now++;
        else if(times[now]%2==1){
            now-=a[now];
        }
        else{
            now+=b[now];
        }
        num++;
    }
    printf("%d\n",num);
    return 0;
}