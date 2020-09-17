#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
char tmp[1100000],s[2100000];
int p[2100000];
int cnt;
int cfl[2100000][3],cfr[2100000][3];
signed main(){
  int T;
  scanf("%lld",&T);
  while(T--){
    memset(cfl,0,sizeof(cfl));
    memset(cfr,0,sizeof(cfr));
    memset(p,0,sizeof(p));
    cnt=0;
    scanf("%s",tmp);
    s[0]='|';
    int len=strlen(tmp);
    int bf=len;
    for(int i=0;i<len;i++){
      s[++cnt]=tmp[i];
      s[++cnt]='|';
    }
    len=cnt+1;
    int m,r=0;
    for(int i=1;i<len;i++){
      if(i<r)p[i]=min(p[2*m-i],r-i);
      else p[i]=0;
      while(i+p[i]+1<=len&&i-p[i]-1>=0&&s[i+p[i]+1]==s[i-p[i]-1])p[i]++;
      if(p[i]+i>r){
        r=p[i]+i;
        m=i;
      }
      if(p[i]){
        int l=(i-p[i])/2,r=(i+p[i]-1)/2,mid=(i-1)/2;
        cfl[l][0]+=(r+1);
        cfl[mid+1][0]-=(r+1);
        cfl[l+1][1]-=1;
        cfl[mid+1][1]+=1;
        cfl[mid+1][2]+=(mid-l);
        mid=i/2;
        cfr[mid][0]+=(i+1)/2;
        cfr[r+1][0]-=(i+1)/2;
        cfr[mid+1][1]-=1;
        cfr[r+1][1]+=1;
        cfr[r+1][2]+=(r-mid);
      }
    }
    int ans=0;
    for(int i=1;i<=bf;i++){
      cfl[i][0]+=cfl[i-1][0];
      cfl[i][0]%=MOD;
      cfl[i][1]+=cfl[i-1][1];
      cfl[i][1]%=MOD;
      cfl[i][2]+=cfl[i-1][2];
      cfl[i][2]%=MOD;
      cfl[i][2]+=cfl[i][1];
      cfl[i][2]%=MOD;
      cfr[i][0]+=cfr[i-1][0];
      cfr[i][0]%=MOD;
      cfr[i][1]+=cfr[i-1][1];
      cfr[i][1]%=MOD;
      cfr[i][2]+=cfr[i-1][2];
      cfr[i][2]%=MOD;
      cfr[i][2]+=cfr[i][1];
      cfr[i][2]%=MOD;
      ans+=(((cfl[i][2]+cfl[i][0])%MOD)*((cfr[i-1][2]+cfr[i-1][0])%MOD))%MOD;
      ans%=MOD;
    }
    printf("%lld\n",ans);
  }
  return 0;
}
