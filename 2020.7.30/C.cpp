//
// Created by swift on 2020/7/30.
//

#include<bits/stdc++.h>
using namespace std;
int T,n,a[101];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int num=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                if(a[j]>a[i])num++;
            }
        if(num%2)
        puts("Q");
        else
        puts("T");
    }
    return 0;
}