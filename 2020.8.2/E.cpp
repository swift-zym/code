//
// Created by swift on 2020/8/2.
//

#include<bits/stdc++.h>
using namespace std;
int n,k,a[200001],mx;
bool check(int x){
    int tmp=0;
    for(int i=1;i<=n;i++){
        int num=ceil(double(a[i])/double(x));
        tmp+=num-1;
    }
    return tmp<=k;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
    }
    int l=1,r=mx,ans;
    while(l!=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",l);
    return 0;
}