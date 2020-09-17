//
// Created by swift on 2020/7/25.
//
#include<bits/stdc++.h>
using namespace std;
int n,q,a[1000001];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int test=1;test<=q;test++){
        int opt;
        scanf("%d",&opt);
        if(opt==0){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        else{
            int l1,r1,l2,r2;
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            vector<int>x,y;
            for(int i=l1;i<=r1;i++)x.push_back(a[i]);
            for(int i=l2;i<=r2;i++)y.push_back(a[i]);
            sort(x.begin(),x.end());
            sort(y.begin(),y.end());
            int tmp=x[0]-y[0];
            bool flag=1;
            for(int i=1;i<x.size();i++){
                if(x[i]-y[i]!=tmp){
                    flag=0;
                    break;
                }
            }
            if(flag){
                puts("YES");
            }
            else{
                puts("NO");
            }
        }
    }
    return 0;
}