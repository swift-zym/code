#include<bits/stdc++.h>
#define int long long
using namespace std;
int p;
struct node{
	int a[5][5],l,r;
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
node fib,bas;
void qpow(int b){
	while(b){
		if(b&1){
			fib=fib*bas;
		}
		bas=bas*bas;
		b>>=1;
	}
}
signed main(){
  DEBUG;
  fib.l=1;fib.r=4;
  bas.l=4;bas.r=4;
	int n;
	scanf("%lld%lld",&n,&p);
  fib.a[1][2]=bas.a[1][1]=bas.a[1][2]=bas.a[1][3]=bas.a[2][1]=bas.a[2][3]=bas.a[3][3]=bas.a[3][4]=bas.a[4][4]=1;
	qpow(n);
  printf("%lld\n",(n*fib.a[1][3]%p-fib.a[1][4]+p)%p);
	return 0;
}
