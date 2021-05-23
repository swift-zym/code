//题目名：简单题
#include<bits/stdc++.h>
using namespace std;
bitset<2000001>b;
int main(){
    b[0]=1;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    int a;
    scanf("%d",&a);
    b^=(b<<a);
    }
    int ans=0;
    for(int i=1;i<=2000000;i++){
        if(b[i])ans^=i;
    }
    printf("%d\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
}