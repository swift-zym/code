#include<bits/stdc++.h>
using namespace std;
bool cmp(int a){
    int tmp[100],cnt=0;
    while(a){
        tmp[++cnt]=a%10;
        a/=10;
    }
    for(int i=1;i<=cnt/2;i++){
        if(tmp[i]!=tmp[cnt+1-i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int maxn=-1;
    for(int i=100;i<=999;i++)
        for(int j=100;j<=999;j++){
            if(cmp(i*j))maxn=max(maxn,i*j);
        }
    cout<<maxn<<endl;
    #ifdef WIN32
    system("pause");
    #endif
}