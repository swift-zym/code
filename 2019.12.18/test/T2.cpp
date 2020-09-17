//Copyright (c) 2019 Copyright Holder All Rights Reserved.
#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,m,k,n[5001];
int ans[50001],cnt;
bool flag=1;
signed main(){
  freopen("out.txt","w",stdout);
  scanf("%lld",&q);
  while(q--){
    scanf("%lld%lld",&m,&k);
    for(int i=1;i<=k;i++)scanf("%lld",&n[i]);
    cnt=0;
    for(int i=1;i<=k;i++){
      flag=1;
      for(int j=1;j<=m;j++){
        int power=1;
        for(int i=1;i<=n[i];i++){
          /*if(power*j<power){
            flag=0;
            break;
          }*/
        }
        //cout<<"DEBUG "<<v<<endl;
        if(v==0&&flag){
          puts("error");
        }
        if(!flag){
          break;
        }
        else{
          ans[++cnt]=v;
        }
      }
    }
    sort(ans+1,ans+cnt+1);
    cnt=unique(ans+1,ans+cnt+1)-ans;
    for(int i=1;i<=cnt;i++){
      cout<<ans[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
