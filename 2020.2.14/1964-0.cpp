//1964-0 == 2316-0
#include<bits/stdc++.h>
using namespace std;
int head[1001],nxt[2001],to[2001],cnt,dp[2001][2000],ls[2001],rs[2001],len[2001],dl[2001],dr[2001];
int n,q;
void add(int a,int b,int l){
	nxt[++cnt]=head[a];
	head[a]=cnt;
	to[cnt]=b;
	len[cnt]=l;
}
void dfs(int now,int fa){
	for(int i=head[now];i;i=nxt[i]){
		if(to[i]==fa)continue;
		if(ls[now]==0){
			ls[now]=to[i];
			dl[now]=len[i];
		}
		else{
			rs[now]=to[i];
			dr[now]=len[i];
		}
	}
	if(ls[now]){
		dfs(ls[now],now);
		dfs(rs[now],now);
	}
}
void getDp(int now,int fa){
	if(ls[now]==0)return;
	getDp(ls[now],now);
	getDp(rs[now],now);
	for(int i=head[now];i;i=nxt[i]){
		if(to[i]==fa)continue;
		for(int j=1;j<=n-1;j++){
		dp[now][j]=max(dp[now][j],dp[rs[now]][j-1]+dr[now]);
		dp[now][j]=max(dp[now][j],dp[ls[now]][j-1]+dl[now]);
		for(int k=1;k<=j-2;k++){
			dp[now][j]=max(dp[now][j],dp[ls[now]][k]+dp[rs[now]][j-2-k]+dl[now]+dr[now]);
		}
		}
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		add(a,b,l);
		add(b,a,l);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++){
		//cout<<ls[i]<<" "<<rs[i]<<endl;
	}
	getDp(1,1);
	cout<<dp[1][q]<<endl;
	return 0;
}
