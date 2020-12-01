#include<bits/stdc++.h>
using namespace std;
double a[200][200];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n+1;j++){
        cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        int mx=i;
        for(int j=i+1;j<=n;j++){
            if(fabs(a[j][i])>fabs(a[mx][i]))mx=j;
        }
        if(fabs(a[mx][i])<1e-8){
            puts("No Solution");
            return 0;
        }
        for(int j=1;j<=n+1;j++){
            swap(a[i][j],a[mx][j]);
        }
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            double tmp=a[j][i]/a[i][i];
            for(int k=i+1;k<=n+1;k++){
                a[j][k]-=a[i][k]*tmp;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<fixed<<setprecision(2)<<a[i][n+1]/a[i][i]<<endl;
    }
    return 0;
}