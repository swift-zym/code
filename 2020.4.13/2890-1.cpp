//
// Created by 张一鸣 on 2020/4/23.
//
#include<bits/stdc++.h>
using namespace std;
double x,l=1e-8,r=1e6;
int main(){
    scanf("%lf",&x);
    while(r-l>1e-8){
        double mid=(l+r)/2;
        if(pow(mid,mid)>x){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    printf("%0.6lf\n",l);
    return 0;
}
/*
 *
 * a--(c)-->b=dis+lca
 */