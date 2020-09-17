#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[251],l[251],r[251];
int qpow(int a,int b){
	if(b==0)return 1;
	int tmp=qpow(a,b/2);
	return b%2?tmp*tmp*a:tmp*tmp;
}
namespace subtask2{
	struct node{
		int l,r;
		bool operator <(const node &t)const{
			if(l!=t.l){
				return l<t.l;
			}
			else{
				return r<t.r;
			}
		}
	}b[251];
	int c[251];
	int mx=0;
	void dfs(int deep,int v){
		if(deep>m){
			if(v)return;
			/*for(int i=1;i<=n;i++){
				cout<<c[i]<<" ";
			}
			putchar(10);*/
			int now=0,ans=0;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=c[i];j++){
					now++;
					if(now>n||b[now].r<i||b[now].l>i)return;
				}
			}
			for(int i=1;i<=m;i++){
				for(int j=1;j<=5;j++){
					ans+=pow(c[i],j)*a[j];
				}
			}
			mx=max(ans,mx);
			return;
		}
		for(int i=0;i<=v;i++){
			c[deep]=i;
			dfs(deep+1,v-i);
		}
	}
	void solve(){
		for(int i=1;i<=n;i++){
			b[i].l=l[i];
			b[i].r=r[i];
		}
		sort(b+1,b+n+1);
		dfs(1,n);
		printf("%lld\n",mx);
	}
}
namespace subtask1{
	void solve(){
		int ans=0;
		for(int i=1;i<=5;i++){
			ans+=a[i]*qpow(n,i);
		}
		printf("%lld\n",ans);
	}
}
bool flag=1;
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=5;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&l[i],&r[i]);
		if(l[i]!=1||r[i]!=m){
			flag=0;
		}
	}
	if(flag){
		subtask1::solve();
	}
	else{
		subtask2::solve();
	}
	return 0;
}
