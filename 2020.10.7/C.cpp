#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int n,m;
int a[11],b[11],c[11],d[11];
int pos[100];
int work(int x,int y){
    int val=0;
    for(int i=1;i<x;i++){
        val+=n-i;
    }
    return pos[val+y-x];
}
int ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(int i=1;i<=n*(n-1)/2;i++){
        v.push_back(i);
    }
    do{
        for(int i=0;i<v.size();i++){
            pos[v[i]]=i;
        }
        bool flag=1;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        for(int k=j+1;k<=n;k++){
            if(!(\
            (work(i,j)<work(i,k)&&work(i,k)<work(j,k))||\
            (work(i,j)>work(i,k)&&work(i,k)>work(j,k))\
            )){
                flag=0;
            }
        }
        for(int i=1;i<=m;i++){
            if(work(a[i],b[i])>work(c[i],d[i]))flag=0;
        }
        if(flag)ans++;
    }while(next_permutation(v.begin(),v.end()));
    printf("%d\n",ans);
    return 0;
}