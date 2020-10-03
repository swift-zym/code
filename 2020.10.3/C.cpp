#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000000],b[1000000];
int ansA[1000000],ansB[100000];
int ans;
int vis[1000000];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)a[i]=i;
    for(int i=0;i<n;i++)b[i]=i;
    for(int i=0;i<=10000000/n;i++){
        random_shuffle(a,a+n);
        random_shuffle(b,b+n);
        int num=0;
        for(int j=0;j<n;j++)vis[j]=0;
        for(int j=0;j<n;j++){
            if(!vis[abs(a[j]-b[j])])num++;
            vis[abs(a[j]-b[j])]=1;
        }
        if(num>ans){
            for(int j=0;j<n;j++){
                ansA[j]=a[j];
                ansB[j]=b[j];
            }
            ans=num;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",ansA[i]);
    }
    putchar(10);
    for(int i=0;i<n;i++){
        printf("%d ",ansB[i]);
    }
    putchar(10);
    return 0;
}