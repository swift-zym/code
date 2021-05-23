#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,n,mxdep,num[26];
int cnt;
void dfs(string s){
    if(s.length()==k*(k+1)/2){
        int tmp=0;
        for(int i=0;i<=25;i++){
            tmp+=(num[i]!=0);
        }
        if(tmp!=k)return;
        for(int i=0;i<=25;i++)
        for(int j=i+1;j<=25;j++){
            if((num[i]|num[j])&&(num[i]==num[j]))return;
        }
        cnt++;
        if(cnt==n){
            cout<<s<<endl;
            exit(0);
        }
        return;
    }
    for(int i=0;i<=25;i++){
        char c='a'+i;
        if(s.length()&&c==s[s.length()-1])continue;
        if(num[i]>k)continue;
        num[i]++;
        dfs(s+c);
        num[i]--;
    }
}
signed main(){
    scanf("%d%d",&k,&n);
    if(k>3){puts("-1");return 0;}
    dfs("");
    puts("-1");
    return 0;
}