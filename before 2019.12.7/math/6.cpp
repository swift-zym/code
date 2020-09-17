#include<bits/stdc++.h>
using namespace std;
long long pow(int a,int b){
    if(b==0)return 1;
    int tmp=pow(a,b/2);
    return b%2?tmp*tmp*a:tmp*tmp;
}
int main(){
    int total=0,_total=0;
    for(int i=1;i<=100;i++){
        total+=pow(i,2);
        _total+=i;
    }
    printf("%d\n",abs(total-pow(_total,2)));
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}