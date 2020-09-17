//
// Created by swift on 2020/6/27.
//

#include<bits/stdc++.h>
using namespace std;
int n,a[10000000];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        unsigned char c;
        cin>>c;
        while(c<33||c>254)cin>>c;
        a[i]=c;
    }
    int i=0,j=1,k=0;
    while(i<n&&j<n&&k<n){
        if(a[(i+k)%n]==a[(j+k)%n]){
            k++;
        }
        else{
            if(a[(i+k)%n]>a[(j+k)%n]){
                i+=k+1;
            }
            else{
                j+=k+1;
            }
            if(i==j)i++;
            k=0;
        }
    }
    int idx=min(i,j);
    for(int i=1;i<=n;i++){
        cout<<(unsigned char)(a[idx]);
        idx++;
        idx%=n;
    }
    cout<<endl;
    return 0;
}