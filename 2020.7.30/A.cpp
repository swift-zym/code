//
// Created by swift on 2020/7/30.
//

#include<bits/stdc++.h>
using namespace std;
int n;
int a[100],num[100];
char s[1000];
int main(){
    scanf("%d",&n);
    memset(num,0x3f,sizeof(num));
    for(int i=1;i<=n;i++){
        memset(a,0,sizeof(a));
        scanf("%s",s);
        int len=strlen(s);
        for(int j=0;j<len;j++){
            a[s[j]-'a']++;
        }
        for(int j=0;j<=25;j++){
            num[j]=min(num[j],a[j]);
        }
    }
    for(int i=0;i<=25;i++){
        for(int j=1;j<=num[i];j++){
            putchar('a'+i);
        }
    }
    putchar(10);
    return 0;
}