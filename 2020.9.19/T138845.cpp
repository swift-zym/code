#include<bits/stdc++.h>
using namespace std;
int num[26];
char s[20000000];
int ans;
int main(){
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        num[s[i]-'a']++;
        ans=max(ans,num[s[i]-'a']);
    }
    printf("%d\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}