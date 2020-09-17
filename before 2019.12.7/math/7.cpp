#include<bits/stdc++.h>
using namespace std;
int cnt;
bool cmp(int now){
    for(int i=2;i<=sqrt(now);i++){
        if(now%i==0)return 0;
    }
    return 1;
}
int main(){
    for(int i=2;i;i++){
        if(cmp(i))cnt++;
        if(cnt==10001){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}