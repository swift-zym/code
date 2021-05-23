//
// Created by swift on 2020/7/17.
//
#include<bits/stdc++.h>
using namespace std;
int n,m;
#define MOD 299993
#define int long long
struct HASH{
    int sta[2],dp[2];//状态和dp值
}mp[8000000];//哈希表
int nxt[8000000];
int head[400000];
int x;
int cnt[2];
int in[101][101];

struct sta{
    int a[101];
};//状态
sta pack(int a){
    sta tmp;
    tmp.a[0]=a&3;
    for(int i=1;i<=m;i++){
        tmp.a[i]=(a>>(i<<1))&3;
    }
    return tmp;
}//状态加密
int unpack(sta a){
    int tmp=0;
    tmp|=a.a[0];
    for(int i=1;i<=m;i++){
        tmp|=(a.a[i]<<(i<<1));
    }
    return tmp;
}//状态解密
namespace DEBUG{
    void print(sta a){
        for(int i=0;i<=m;i++){
            cout<<a.a[i]<<" ";
        }
        cout<<endl;
    }
}
void ins(int sta,int v){
    /*cout<<"ins:"<<endl;
    DEBUG::print(pack(sta));
    cout<<":ins"<<endl;*/
    v%=20110520;
    int idx=sta%MOD;
    //cout<<idx<<" "<<cnt[x]<<endl;
    for(int i=head[idx];i;i=nxt[i]){
        //cout<<"#"<<i<<endl;
        if(mp[i].sta[x]==sta){
            mp[i].dp[x]+=v;//已有此状态
            mp[i].dp[x]%=20110520;
            return;
        }
    }
    cnt[x]++;//没有，新建状态
    mp[cnt[x]].sta[x]=sta;
    mp[cnt[x]].dp[x]=v;
    nxt[cnt[x]]=head[idx];
    head[idx]=cnt[x];
}
int lx,ly,ans;
void solve(){
    ins(0,1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            memset(head,0,sizeof(head));
            int lst=x;
            /*cout<<"NOW_TOT "<<cnt[x]<<endl;
            cout<<"begin:"<<endl;
            for(int k=1;k<=cnt[x];k++){
                DEBUG::print(pack(mp[k].sta[x]));
            }
            cout<<":end"<<endl;*/
            x^=1;
            cnt[x]=0;
            for(int k=1;k<=cnt[lst];k++){
                sta now=pack(mp[k].sta[lst]),tmp=now;
                int v=mp[k].dp[lst];
                int l=now.a[0],o=now.a[j];
                if(!in[i][j]){
                    if(!l&&!o)
                        ins(unpack(tmp),v);
                }
                else {
                    if (o == 0 && l == 0) {
                        tmp.a[0] = 1;
                        if(in[i][j+1])
                            ins(unpack(tmp), v);
                        tmp = now;
                        tmp.a[j] = 1;
                        if(in[i+1][j])
                            ins(unpack(tmp), v);
                        tmp = now;
                        tmp.a[j] = tmp.a[0] = 2;
                        if(in[i][j+1]&&in[i+1][j])
                            ins(unpack(tmp), v);
                    }
                    if (o == 1 && l == 1) {
                        if(i==lx&&j==ly){
                            ans+=v;
                            ans%=20110520;
                        }
                        tmp.a[0] = tmp.a[j] = 0;
                        ins(unpack(tmp), v);
                        tmp = now;
                    }
                    if (o == 1 && l == 0) {
                        if(in[i+1][j])
                            ins(unpack(tmp), v);
                        tmp = now;
                        tmp.a[0] = 2;
                        tmp.a[j] = 0;
                        if(in[i][j+1])
                            ins(unpack(tmp), v);
                    }
                    if (o == 0 && l == 1) {
                        if(in[i][j+1])
                            ins(unpack(tmp), v);
                        tmp = now;
                        tmp.a[0] = 0;
                        tmp.a[j] = 2;
                        if(in[i+1][j])
                            ins(unpack(tmp), v);
                    }
                    if (o == 2 && l == 0) {
                        if(in[i+1][j])
                            ins(unpack(tmp), v);
                        tmp.a[j] = 0;
                        ins(unpack(tmp), v);
                        if (i == lx && j == ly) {
                            ans += v;
                            ans%=20110520;
                        }
                    }
                    if (o == 0 && l == 2) {
                        if(in[i][j+1])
                            ins(unpack(tmp), v);
                        tmp.a[0] = 0;
                        ins(unpack(tmp), v);
                        if (i == lx && j == ly) {
                            ans += v;
                            ans%=20110520;
                        }
                    }
                }
                //DEBUG::print(now);
                //cout<<i<<" "<<j<<endl;
            }
        }
    printf("%lld\n",ans);
}

signed main(){
    scanf("%lld%lld",&n,&m);
    /*for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++){
            in[i][j]=1;
        }*/
    if(m>n) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                char c = getchar();
                while (c != '*' && c != '_')c = getchar();
                in[j][i] = (c == '_');
                if (in[j][i]) {
                    lx = j;
                    ly = i;
                }
            }
        swap(n, m);
    }
    else{
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                char c = getchar();
                while (c != '*' && c != '_')c = getchar();
                in[i][j] = (c == '_');
                if (in[i][j]) {
                    lx = i;
                    ly = j;
                }
            }
    }
    solve();
    return 0;
}