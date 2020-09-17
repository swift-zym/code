#include<bits/stdc++.h>
#define int long long
using namespace std;
int flag,n,m,s,head[1001],nxt[10001],to[10001],len[10001],cnt,vis[10001],ans[1001],num[1001];
void add(int a,int b,int l){
	nxt[++cnt]=head[a];
	to[cnt]=b;
	len[cnt]=l;
	head[a]=cnt;
}
double tmp;
void SPFA(int now){
	if(!flag)return;
	queue<int>q;
	q.push(now);
	vis[now]=1;
	while(!q.empty()){
	now=q.front();
	num[now]++;
	q.pop();
	vis[now]=0;
	for(int i=head[now];i;i=nxt[i]){
		if(ans[to[i]]>ans[now]+len[i]){
			ans[to[i]]=ans[now]+len[i];
			if(!vis[to[i]]){
				vis[to[i]]=1;
				if(num[to[i]]==n){
					flag=0;
					return;
				}
				q.push(to[i]);
			}
		}
	}
	}
}
signed main(){
	freopen("test5.in","r",stdin);
	scanf("%lld%lld%lld",&n,&m,&s);
	for(int i=1;i<=m;i++){
		int a,b,l;
		scanf("%lld%lld%lld",&a,&b,&l);
		add(a,b,l);
	}
	cout<<"***"<<endl;
	flag=1;
	for(int i=1;i<=n;i++){
	cout<<i<<endl;
	if(ans[i]==0)
	SPFA(i);
	}
	if(!flag){
		puts("-1");
	}
	else{
	  for(int i=1;i<=n;i++)ans[i]=1e8;
	  memset(num,0,sizeof(num));
	  memset(vis,0,sizeof(vis));
		ans[s]=0;
		SPFA(s);
		for(int i=1;i<=n;i++){
			if(ans[i]==1e8){
				puts("NoPath");
			}
			else{
				printf("%lld\n",ans[i]);
			}
		}
	}
	return 0;
}
