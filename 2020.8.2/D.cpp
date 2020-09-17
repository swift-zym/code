//
// Created by swift on 2020/8/2.
//

#include<bits/stdc++.h>
using namespace std;
int n,num,ans;;
char s[300000];
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
       if(s[i]=='R')num++;
    }
    for(int i=0;i<n;i++){
        if(i>=num&&s[i]=='R')ans++;
    }
    printf("%d\n",ans);
    return 0;
}