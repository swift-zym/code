#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
int Num,len,flag,ring,n,m1,m2;
int head[200001],to[400001],nxt[400001],c[400001],cnt,vis[200001];
int mxh,mxel,mx00l,mx11l;
int numh[200001],numl[200001],num00l[200001],num11l[200001];
int jc[200001];
int qpow(int a,int b){
    if(b==0)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
 
void pre(){
    jc[0]=1;
    for(int i=1;i<=n;i++){
        jc[i]=jc[i-1]*i%MOD;
    }
}
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    c[cnt]=l;
    head[a]=cnt;
}
void dfs(int now,int pre,int fc){
  vis[now]=1;
  int num=0,D,numm=0;
  len++;
  for(int i=head[now];i;i=nxt[i]){
    D=c[i];
    numm++;
    if(to[i]!=pre){
        if(vis[to[i]]){
            ring=1;
            continue;
        }
        num++;
        dfs(to[i],now,c[i]);
    }
  }
  if(num==0){
    flag+=fc;
  }
  else if(numm==1){
    flag+=D;
  }
}
signed main(){
  scanf("%lld%lld%lld",&n,&m1,&m2);
  pre();
  for(int i=1;i<=m1;i++){
    int a,b;
    scanf("%lld%lld",&a,&b);
    add(a,b,1);
    add(b,a,1);
  }
  for(int i=1;i<=m2;i++){
    int a,b;
    scanf("%lld%lld",&a,&b);
    add(a,b,0);
    add(b,a,0);
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
        len=flag=ring=0;
        dfs(i,i,-1);
        if(ring){
            numh[len]++;
            mxh=max(mxh,len);
        }
        else{
            len--;
            numl[len]++;
            if(len%2==0){
                mxel=max(mxel,len);
            }
            if(flag==0){
//              cout<<"0"<<len<<endl;
                mx00l=max(mx00l,len);
                num00l[len]++;
            }
            if(flag==2){
//              cout<<"1"<<len<<endl;
                mx11l=max(mx11l,len);
                num11l[len]++;
            }
        }
    }
  }
  int ans=jc[n],tmp=1;
//  cout<<mxh<<" "<<mxel<<" "<<mx11l<<" "<<mx00l<<endl;
  for(int i=2;i<=mxh;i++){
    tmp*=qpow(i,numh[i]);
    tmp%=MOD;
    tmp*=jc[numh[i]];
    tmp%=MOD;
  }
//  cout<<tmp<<endl;
  for(int i=0;i<=mxel;i+=2){
    tmp*=jc[numl[i]];
    tmp%=MOD;
  }
//  cout<<tmp<<endl;
  for(int i=1;i<=mx00l;i+=2){
    tmp*=qpow(2,num00l[i]);
    tmp%=MOD;
    tmp*=jc[num00l[i]];
    tmp%=MOD;
//  cout<<tmp<<endl;
  }
//  cout<<tmp<<endl;
  for(int i=1;i<=mx11l;i+=2){
    tmp*=qpow(2,num11l[i]);
    tmp%=MOD;
    tmp*=jc[num11l[i]];
    tmp%=MOD;
//  cout<<tmp<<endl;
  }
 // cout<<tmp<<endl;
  printf("%lld\n",tmp);
  return 0;
}