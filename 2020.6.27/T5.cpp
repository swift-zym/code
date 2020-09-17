//
// Created by swift on 2020/6/27.
//

#include<bits/stdc++.h>
using namespace std;
int l,n,mi,mx;
int main(){
    scanf("%d",&l);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        mi=max(mi,min(a,l-a+1));
        mx=max(mx,max(a,l-a+1));
    }
    printf("%d %d\n",mi,mx);
    return 0;
}