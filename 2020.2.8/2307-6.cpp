#include<bits/stdc++.h>
using namespace std;
int p=2009;
struct node{
	int a[101][101],l,r;
	node operator *(const node &b){
		node ans;
		memset(ans.a,0,sizeof(ans.a));
		for(int i=1;i<=l;i++)
		for(int j=1;j<=b.r;j++)
		for(int k=1;k<=r;k++){
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
int n,t;
node a;
int main(){
  scanf("%d%d",&n,&t);
  a.l=a.r=9*n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=8;j++){
      a.a[i+j*n][i+(j-1)*n]=1;
    }
    for(int j=1;j<=n;j++){
      int l;
      char c=getchar();
      while(c<'0'||c>'9')c=getchar();
      l=c-'0';
      if(l){
        a.a[i][j+(l-1)*n]=1;
      }
    }
  }
  qpow(a,t);
  printf("%d\n",a.a[1][n]);
  return 0;
}
