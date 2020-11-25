#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions") 
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
#include<vector>
#define int long long
using namespace std;
int n,q;
struct status{
    string s;
    signed dp[21][21];
    void print(){
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
            if(j==n)putchar(10);
        }
    }
};
struct sta{
    vector<status*>a;
    int sz;
    bool empty(){return sz==0;}
    status*top(){return a[sz-1];}
    status*back(){return a[0];}
    void push(status&x){a[sz++]=&x;}
    void pop(){sz--;}
    void clear(){
        sz=0;
        //a.clear();
        //vector<status>tmp;
        //swap(tmp,a);
    }
    void rever(){
        for(signed i=0;i<sz/2;i++){
            swap(a[i]->s,a[sz-i-1]->s);
        }
        //reverse(a.begin(),a.end());
    }
};
sta up,down;
const int MOD=1000000007;
void add(int &to,int v){
    to+=v;
    if(to>=MOD)to-=MOD;
    //to%=MOD;
}
status Pool[300003];
signed main(){
    freopen("bin10.in","r",stdin);
    freopen("bin10.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>q;
    up.a.resize(300003);
    down.a.resize(300003);
    cerr<<double(clock())/CLOCKS_PER_SEC<<endl;
    for(int w=1;w<=q;w++){
        string opt;
        cin>>opt;
        if(opt=="add"){
            cin>>Pool[w].s;
            if(down.empty()){
                for(signed i=1;i<=n;i++)
                for(signed j=1;j<=n;j++){
                    Pool[w].dp[i][j]=(i==j);
                }
                down.push(Pool[w]);
                continue;
            }status*s=down.top();
            for(signed i=1;i<=n;i++)
            for(signed j=1;j<=n;j++){
                unsigned val=0;
                if(j-1&&s->s[j-2]==Pool[w].s[j-1])val+=s->dp[i][j-1];
                if(s->s[j-1]==Pool[w].s[j-1])val+=s->dp[i][j];
                if(j+1<=n&&s->s[j]==Pool[w].s[j-1])val+=s->dp[i][j+1];
                Pool[w].dp[i][j]=val%MOD;
            }
            down.push(Pool[w]);
        }
        else if(opt=="remove"){
            if(!up.empty())up.pop();
            else{
                up=down;
                down.clear();
                up.rever();
                up.pop();
                for(signed i=1;i<=n;i++)
                for(signed j=1;j<=n;j++){
                    up.a[0]->dp[i][j]=(i==j);
                }
                for(signed k=1,tp=up.sz;k<=tp;k++){
                    for(signed i=1;i<=n;i++)
                    for(signed j=1;j<=n;j++){
                        unsigned val=0;
                        if(j-1&&up.a[k]->s[j-1]==up.a[k-1]->s[j-2]){
                            val+=up.a[k-1]->dp[i][j-1];
                        }
                        if(up.a[k]->s[j-1]==up.a[k-1]->s[j-1]){
                            val+=up.a[k-1]->dp[i][j];
                        }
                        if(j+1<=n&&up.a[k]->s[j-1]==up.a[k-1]->s[j]){
                            val+=up.a[k-1]->dp[i][j+1];
                        }
                        up.a[k]->dp[i][j]=val%MOD;
                    }
                }
            }
        }
        else{
            int c,d;
            cin>>c>>d;
            if(up.empty()){
                cout<<down.top()->dp[c][d]<<endl;
            }
            else if(down.empty()){
                cout<<up.top()->dp[d][c]<<endl;
            }
            else{
                int ans=0;
                for(signed i=1;i<=n;i++){
                    if(i-1&&up.back()->s[i-2]==down.back()->s[i-1]){
                        ans+=up.top()->dp[i-1][c]*1ll*down.top()->dp[i][d];
                    }
                    if(up.back()->s[i-1]==down.back()->s[i-1]){
                        ans+=up.top()->dp[i][c]*1ll*down.top()->dp[i][d];
                    }
                    if(i+1<=n&&up.back()->s[i]==down.back()->s[i-1]){
                        ans+=up.top()->dp[i+1][c]*1ll*down.top()->dp[i][d];
                    }
                    ans%=MOD;
                }
                cout<<ans<<endl;
            }
        }
    }
    cerr<<double(clock())/CLOCKS_PER_SEC<<endl;
    exit(0);
    return 0;
}