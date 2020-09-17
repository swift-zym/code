//
// Created by swift on 2020/8/2.
//

#include<bits/stdc++.h>
using namespace std;
int n,d,ans;
int main(){
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
        double a,b;
        scanf("%lf%lf",&a,&b);
        if(sqrt(a*a+b*b)<=d){
           ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}