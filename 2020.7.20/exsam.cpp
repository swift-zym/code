//
// Created by swift on 2020/7/21.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[100001];
int n,k,len[100001];
struct SAM{
    struct node{
        int fail,go[26],val,ans;
    }a[1000000];
    int cnt=1,last=1;
    void ins(int x){
        int np=++cnt,p=last;
        last=np;
        a[np].val=a[p].val+1;
        while(p&&!a[p].go[x]){
            a[p].go[x]=np;
            p=a[p].fail;
        }
        if(!p){
            a[np].fail=1;
            return;
        }
        int q=a[p].go[x];
        if(a[p].val+1==a[q].val){
            a[np].fail=q;
            return;
        }
        else{
            int nq=++cnt;
            a[nq].val=a[p].val+1;
            a[nq].fail=a[q].fail;
            memcpy(a[nq].go,a[q].go,sizeof(a[q].go));
            a[q].fail=nq;
            a[np].fail=nq;
            while(p&&a[p].go[x]==q){
                a[p].go[x]=nq;
                p=a[p].fail;
            }
        }
    }
    int tmp[1000000],id[1000000],col[1000000],num[1000000];
    void solve(){
        for(int i=1;i<=cnt;i++)tmp[a[i].val]++;
        for(int i=1;i<=cnt;i++)tmp[i]+=tmp[i-1];
        for(int i=1;i<=cnt;i++)id[tmp[a[i].val]--]=i;
        for(int i=1;i<=n;i++){
            int st=1;
            for(int j=0;j<len[i];j++){
                st=a[st].go[s[i][j]-'a'];
                for(int now=st;now&&col[now]!=i;now=a[now].fail){
                    //cout<<now<<" "<<i<<endl;
                    col[now]=i;
                    num[now]++;
                }
            }
        }
        for(int i=1;i<=cnt;i++){
            int now=id[i];
            a[now].ans=a[a[now].fail].ans+(num[now]>=k?a[now].val-a[a[now].fail].val:0);
        }
        for(int i=1;i<=n;i++){
            int now=1,ans=0;
            for(int j=0;j<len[i];j++){
                now=a[now].go[s[i][j]-'a'];
                ans+=a[now].ans;
            }
            cout<<ans<<" ";
        }
    }
}sam;
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        len[i]=s[i].length();
        sam.last=1;
        for(int j=0;j<len[i];j++){
            sam.ins(s[i][j]-'a');
        }
    }
    sam.solve();
    return 0;
}