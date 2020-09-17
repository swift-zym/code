#include<bits/stdc++.h>
using namespace std;
int n;
stack<int>s[100000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char c=getchar();
        while(c!='a'&&c!='s'&&c!='t')c=getchar();
        int x;
        if(c=='a'||c=='t')scanf("%d",&x);
        if(c=='t')s[i]=s[x-1];
        else s[i]=s[i-1];
        if(c=='a')s[i].push(x);
        else if(c=='s')s[i].pop();
        if(s[i].empty())puts("-1");
        else printf("%d\n",s[i].top());
    }
    return 0;
}