//
// Created by swift on 2020/8/4.
//

#include<bits/stdc++.h>
#define eps 1e-8
using namespace std;
int n;
long double a[51][51];
long double guess(){
    long double ans=1;
    for(int i=1;i<=n;i++){
        int mx=i;
        for(int j=i+1;j<=n;j++){
            if(fabs(a[j][i])>fabs(a[mx][i])){
                mx=j;
            }
        }
        if(mx!=i){
            swap(a[mx],a[i]);
        }
        if(a[i][i]<eps)return 0;
        for(int j=i+1;j<=n;j++){
            long double d=a[j][i]/a[i][i];
            for(int k=i;k<=n;k++){
                a[j][k]-=a[i][k]*d;
            }
        }
        ans*=a[i][i];
    }
    return fabs(ans);
}
int main(){
    double ans=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            long double x;
            cin>>x;
            if(i==j)continue;
            if(1.0-x<eps){
                x-=eps;
            }
            if(x<eps){
                x+=eps;
            }
            if(i<j)ans*=(1.0-x);
            a[i][j]=-x/(1.0-x);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i!=j){
                a[i][i]-=a[i][j];
            }
        }
    n--;
    cout<<ans*guess()<<endl;
    return 0;
}