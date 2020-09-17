#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],start[200001],last[200001],st[200001][20];
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    a[i]+=1000000;
    start[i]=max(start[i-1],last[a[i]]+1);
    st[i][0]=i-start[i]+1;
    last[a[i]]=i;
  }
  for(int i=1;i<=20;i++)
  for(int j=1;j<=n;j++){
    st[j][i]=max(st[j][i-1],st[min(n,j+(1<<(i-1)))][i-1]);
  }
  for(int i=1;i<=m;i++){
    int l,r,pos,ans=0;
    scanf("%d%d",&l,&r);
    l++;
    r++;
    if(start[r]<=l){
      pos=r+1;
    }
    else{
      pos=lower_bound(start+1,start+n+1,l)-start;
    }
    if(pos>l){
      ans=pos-l;
    }
    if(pos<=r){
      int k=log(r-pos+1);
      ans=max(ans,max(st[pos][k],st[r-(1<<k)+1][k]));
    }
    printf("%d\n",ans);
  }
  return 0;
}
