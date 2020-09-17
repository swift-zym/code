#include<bits/stdc++.h>
using namespace std;
int cnt[12],n,ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        ans+=tmp;
        cnt[tmp]++;
    }
    int x=21-ans;
    int xx=0,yy=0;
    for(int i=2;i<=11;i++){
    if(i!=10){
    if(i<=x){
        xx+=4-cnt[i];
    }
    else{
        yy+=4-cnt[i];
    }
    }
    else{
     if(i<=x){
        xx+=16-cnt[i];
    }
    else{
        yy+=16-cnt[i];
    }   
    }
    }
    if(xx>yy){
    printf("VUCI\n");
    }
    else{
    printf("DOSTA\n");
    }
    return 0;
}