//
// Created by swift on 2020/6/27.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int p=1;
    while(p*(p-1)/2<m)p++;
    for(int i=1;i<=n-p;i++){
        printf("%d ",i);
    }
    printf("%d ",n-p*(p-1)/2+m);
    for(int i=n;i>=n-p+1;i--){
        if(i!=n-p*(p-1)/2+m){
            printf("%d",i);
            if(i!=n-p+1){
                putchar(' ');
            }
        }
    }
    putchar(10);
    return 0;
}
