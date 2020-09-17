#include<bits/stdc++.h>
using namespace std;
int n,a[100],vis[100],num,len,mx,sum;
bool cmp(int a,int b){return a>b;}
bool dfs(int tot,int deep,int s){
  if(tot==num+1)return 1;
  if(s==0){
    return dfs(tot+1,2,len);
  }
  for(int i=deep;i<=n;i++){
    if(vis[i]==0&&s>=a[i]){
      vis[i]=1;
      if(dfs(tot,deep+1,s-a[i]))return 1;
      vis[i]=0;
      if(s==len||s==a[i])return 0;
      while(a[i]==a[i+1])i++;
    }
  }
  return 0;
}
int main(){
  while(scanf("%d",&n)!=EOF){
  mx=sum=0;
  if(!n)break;
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    if(a[i]>50){
      i--;
      n--;
      continue;
    }
    sum+=a[i];
    mx=max(mx,a[i]);
  }
  sort(a+1,a+n+1,cmp);
  for(len=mx;len<=sum;len++){
    if(sum%len)continue;
    memset(vis,0,sizeof(vis));
    num=sum/len;
    if(dfs(1,1,len-a[1])){
      printf("%d\n",len);
      break;
    }
  }
  }
  return 0;
}
