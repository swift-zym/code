//题目名：飓风营救(http://218.62.22.209:8080 刺杀大使https://luogu.org)
#include<bits/stdc++.h>
using namespace std;
int p[1001][1001],m,n,maxn,vis[1001][1001],mx[]={0,1,0,-1},my[]={1,0,-1,0};
bool flag;
void dfs(int x,int y){
	if(x==n){
		flag=1;
		return;
	}
	vis[x][y]=1;
	for(int i=0;i<=3;i++){
		int nx=x+mx[i],ny=y+my[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]==0&&p[nx][ny]<=maxn){
			dfs(nx,ny);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++){
			cin>>p[i][j];
	  }
	  flag=0;
	  maxn=100;
	  dfs(1,1);
	int l=0,r=1001;
	while(l!=r){
		memset(vis,0,sizeof(vis));
		int mid=(l+r)/2;
		maxn=mid;
		flag=0; 
		dfs(1,1);
		if(flag){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",l);
	#ifdef WIN32
	system("pause");
	#endif
	return 0;
}
