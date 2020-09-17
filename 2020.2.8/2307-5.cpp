#include<bits/stdc++.h>
#define D cout<<__LINE__<<"-ok"<<endl;
using namespace std;
int p;
struct node{
	int a[30][30],l,r;
	node operator *(const node &b){
		node ans;
		memset(ans.a,0,sizeof(ans.a));
		for(int i=0;i<l;i++)
		for(int j=0;j<b.r;j++)
		for(int k=0;k<r;k++){
			ans.a[i][j]+=(a[i][k]*b.a[k][j])%p;
			ans.a[i][j]%=p;
		}
        ans.l=l;
        ans.r=b.r;
		return ans;
	}
};
void qpow(node &a,int b){
  node c=a;
  b--;
	while(b){
		if(b&1){
			a=a*c;
		}
		c=c*c;
		b>>=1;
	}
}
int n,m,nxt[30];
string s;
node a;
int main(){
  ios::sync_with_stdio(0);
  cin>>n>>m>>p>>s;
  a.l=a.r=m;
  nxt[0]=-1;
  for(int i=1,j=-1;i<m;i++){
    while(j!=-1&&s[j+1]!=s[i])j=nxt[j];
    if(s[j+1]==s[i])j++;
    nxt[i]=j;
  }
  for(int i=-1;i<m-1;i++){
    for(int j=0;j<=9;j++){
      char c='0'+j;
      int k=i;
      while(k!=-1&&s[k+1]!=c)k=nxt[k];
      if(s[k+1]==c)k++;
      a.a[i+1][k+1]++;
    }
  }
  qpow(a,n);
  int ans=0;
  for(int i=0;i<m;i++){
    ans+=a.a[0][i];
    ans%=p;
  }
  cout<<ans<<endl;
  return 0;
}
