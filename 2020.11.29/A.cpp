#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        double k,v1,v2,x;
        scanf("%lf%lf%lf%lf",&k,&v1,&v2,&x);
        printf("%0.10lf\n",x/(v1+v2)*v1);
    }
    return 0;
}