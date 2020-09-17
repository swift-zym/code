#include<bits/stdc++.h>
#define int long long
using namespace std;
int p;
struct node{
	int a[2][2];
	node operator *(const node &b){
		node ans;
		ans.a[0][0]=ans.a[1][0]=ans.a[0][1]=ans.a[1][1]=0;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++){
			ans.a[i][j]+=(a[i][k]*b.a[k][j])%p;
			ans.a[i][j]%=p;
		}
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
	int n;
	while(scanf("%lld",&n)!=EOF){
	fib.a[0][0]=0;
	fib.a[0][1]=1;
	fib.a[1][0]=1;
	fib.a[1][1]=0;
	bas.a[0][0]=1;
	bas.a[0][1]=1;
	bas.a[1][0]=1;
	bas.a[1][1]=0;
	if(n==-1)break;
	p=10000;
	qpow(n);
	printf("%lld\n",fib.a[0][0]);
	}
	return 0;
}
