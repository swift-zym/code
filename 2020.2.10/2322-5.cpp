#include<bits/stdc++.h>
using namespace std;
int tmp[51],last[51],num[51],ans;
int n,k,p,now=-1;
int main(){
  scanf("%d%d%d",&n,&k,&p);
  for(int i=1;i<=n;i++){
    int c,pp;
    scanf("%d%d",&c,&pp);
    if(pp<=p){
      now=i;
    }
    if(now>=last[c]){
      tmp[c]=num[c];
    }
    num[c]++;
    last[c]=i;
    ans+=tmp[c];
  }
  printf("%d\n",ans);
  return 0;
}
