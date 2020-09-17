//
// Created by swift on 2020/8/4.
//

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int ans[1100000],nxt[1100000];
char s[1100000];
int n;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        int len=strlen(s);
        memset(nxt,0,sizeof(nxt));
        ans[0]=0;ans[1]=1;
        for(int i=1,j=0;i<len;i++){
            while(j&&s[j]!=s[i]){
                j=nxt[j];
            }
            j+=(s[i]==s[j]);
            nxt[i+1]=j;
            ans[i+1]=ans[j]+1;
        }
        long long tmp=1;
        for(int i=1,j=0;i<len;i++){
            while(j&&s[j]!=s[i]){
                j=nxt[j];
            }
            j+=(s[i]==s[j]);
            while(j*2>(i+1))j=nxt[j];
            tmp*=(long long)(ans[j]+1);
            tmp%=MOD;
        }
        printf("%lld\n",tmp);
    }
    return 0;
}