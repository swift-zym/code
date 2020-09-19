#include<bits/stdc++.h>
#define int long long

//插头dp模板（by swift)
//2020.6.29

using namespace std;
int n,m;
#define MOD 299993
struct HASH{
    int sta[2],dp[2];//状态和dp值
}mp[800000];//哈希表
int nxt[800000];
int head[400000];
int x;
int cnt[2];
int in[20][20];
void ins(int sta,int v){
    int idx=sta%MOD;
    //cout<<idx<<" "<<cnt[x]<<endl;
    for(int i=head[idx];i;i=nxt[i]){
        //cout<<"#"<<i<<endl;
        if(mp[i].sta[x]==sta){
            mp[i].dp[x]+=v;//已有此状态
            return;
        }
    }
    cnt[x]++;//没有，新建状态
    mp[cnt[x]].sta[x]=sta;
    mp[cnt[x]].dp[x]=v;
    nxt[cnt[x]]=head[idx];
    head[idx]=cnt[x];
}
struct sta{
    int a[20];
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
int li,lj;
int ans;
namespace DEBUG{
    void print(sta a){
        for(int i=0;i<=m;i++){
            cout<<a.a[i]<<" ";
        }
        cout<<endl;
    }
}

void solve(){
    ins(0,1);//初始化
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int lst=x;
            x^=1;
            cnt[x]=0;
            memset(head,0,sizeof(head));
            for(int k=1;k<=cnt[lst];k++){
                sta now_sta=pack(mp[k].sta[lst]),tmp=now_sta;
                int now_num=mp[k].dp[lst],l=now_sta.a[0],o=now_sta.a[j];
                if(in[i][j]){
                    if(!l&&!o){
                        ins(unpack(tmp),now_num);
                    }
                }
                else if(!l&&!o){
                    if(!in[i][j+1]&&!in[i+1][j]){
                        tmp.a[0]=2;
                        tmp.a[j]=1;
                        ins(unpack(tmp),now_num);
                        tmp=now_sta;
                    }
                }
                else if(!l&&o){
                    if(!in[i+1][j]){
                        ins(unpack(tmp),now_num);
                    }
                    if(!in[i][j+1]){
                        tmp.a[0]=o;
                        tmp.a[j]=0;
                        ins(unpack(tmp),now_num);
                        tmp=now_sta;
                    }
                }
                else if(!o&&l){
                    if(!in[i][j+1]){
                        ins(unpack(tmp),now_num);
                    }
                    if(!in[i+1][j]){
                        tmp.a[0]=0;
                        tmp.a[j]=l;
                        ins(unpack(tmp),now_num);
                        tmp=now_sta;
                    }
                }
                else if(l==2&&o==1){
                    tmp.a[0]=tmp.a[j]=0;
                    ins(unpack(tmp),now_num);
                    tmp=now_sta;
                }
                else if(l==1&&o==2){
                    tmp.a[0]=tmp.a[j]=0;
                    bool flag=0;
                    for(int i=0;i<=m;i++){
                        if(tmp.a[i]!=0){
                            flag=1;
                            break;
                        }
                    }
                    if(!flag&&i==li&&j==lj){
                        ans+=now_num;
                    }
                }
                else if(l==1&&o==1){
                    int v=1,pos;
                    for(pos=j+1;pos<=m;pos++){
                        if(tmp.a[pos]==1){
                            v++;
                        }
                        else if(tmp.a[pos]==2){
                            v--;
                        }
                        if(!v)break;
                    }
                    tmp.a[pos]=1;
                    tmp.a[0]=tmp.a[j]=0;
                    ins(unpack(tmp),now_num);
                    tmp=now_sta;
                }
                else if(l==2&&o==2){
                    int v=-1,pos;
                    for(pos=j-1;pos;pos--){
                        if(tmp.a[pos]==1){
                            v++;
                        }
                        else if(tmp.a[pos]==2){
                            v--;
                        }
                        if(!v)break;
                    }
                    tmp.a[pos]=2;
                    tmp.a[0]=tmp.a[j]=0;
                    ins(unpack(tmp),now_num);
                    tmp=now_sta;
                }
                /*DEBUG::print(now_sta);
                cout<<l<<" "<<o<<endl;
                cout<<i<<" "<<j<<" "<<now_num<<endl;*/
            }
        }
    printf("%lld\n",ans);
}
signed main(){
    for(int i=0;i<=19;i++)
        for(int j=0;j<=19;j++){
            in[i][j]=1;
        }
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c=getchar();
            while(c!='.'&&c!='*')c=getchar();
            in[i][j]=(c=='*'?1:0);
            if(!in[i][j]){
                li=i;
                lj=j;
            }
        }
    solve();
    return 0;
}