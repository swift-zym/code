#include<bits/stdc++.h>
#define int long long
using namespace std;
char s[500005];
int lastans;
struct PAM{
    int siz;
    int trans[500005][26];
    int fail[500005],len[500005];
    int cnt[500005];
    int last;
    void build(){
        len[0]=0;
        len[1]=-1;
        last=1;
        siz=1;
        fail[0]=fail[1]=1;
    }
    void add(int c,int idx){
        int u=last;
        while(s[idx]!=s[idx-len[u]-1]){
            u=fail[u];
        }
        if(!trans[u][c]){
            ++siz;
            int v=fail[u];
            len[siz]=len[u]+2;
            while(s[idx]!=s[idx-len[v]-1])v=fail[v];
            fail[siz]=trans[v][c];
            trans[u][c]=siz;
        }
        last=trans[u][c];
        cnt[last]++;
    }
}bas;
int ans=-1;
signed main(){
    scanf("%s",s);
    bas.build();
    int len=strlen(s);
    for(int i=0;i<len;i++){
        s[i]=(s[i]-97+lastans)%26+97;
        bas.add(s[i]-'a',i);
    }
    for(int i=bas.siz;i>=0;i--){
        bas.cnt[bas.fail[i]]+=bas.cnt[i];
        ans=max(ans,bas.len[i]*bas.cnt[i]);
    }
    printf("%lld\n",ans);
    return 0;
}