#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
int vis[1000000];
int num[26];
int main(){
    cin>>n>>k;
    cin>>s;
    if(2*k<=n){
        int ans=0;
        for(int i=0;i<k;i++){
            if(s[i]!=s[n-k+i])ans++;
        }
        cout<<ans<<endl;
    }
    else{
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int a=0,b=0;
                memset(num,0,sizeof(num));
                int now=i;
                //cout<<i<<endl;
                for(int now=i;now<n;now+=(n-k)){
                    vis[now]=1;
                    b++;
                    num[s[now]-'a']++;
                    if(num[s[now]-'a']>a){
                        a=num[s[now]-'a'];
                    }
                }
                ans+=b-a;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}