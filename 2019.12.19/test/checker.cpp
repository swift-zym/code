#include<bits/stdc++.h>
using namespace std;
char inf[101],ans[101];
int fa[100001][21],head[100001],to[200001],nxt[200001],dep[100001],cnt,tmp[100001];
void add(int a,int b){
	nxt[++cnt]=head[a];
	head[a]=cnt;
	to[cnt]=b;
}
void dfs(int now,int father,int deep){
	dep[now]=deep;
	fa[now][0]=father;
	for(int i=head[now];i;i=nxt[i]){
		if(to[i]!=father){
			dfs(to[i],now,deep+1);
		}
	}
}
int lca(int x,int y){
	if(x==y)return x;
	if(dep[x]>dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fa[y][i]]>=dep[x]){
			y=fa[y][i];
		}
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(fa[y][i]!=fa[x][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[y][0];
}
map<int,int>ma;
int main(){
  puts("please input filename (.in) ");
  scanf("%s",inf);
  puts("please input filename (.out)");
  scanf("%s",ans);
  freopen(inf,"r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,1,1);

	for(int i=1;i<=20;i++)
	for(int j=1;j<=n;j++){
		fa[j][i]=fa[fa[j][i-1]][i-1];
	}
  puts("read (.in) finish");
  freopen(ans,"r",stdin);
  string sou;
  cin>>sou;
  if(sou=="Yes"){
    for(int i=1;i<=n;i++){
      scanf("%d",&tmp[i]);
      if(tmp[i]<1||tmp[i]>n||ma[tmp[i]]){
        puts("Wrong Answer");
        exit(0);
      }
      ma[tmp[i]]=1;
    }
    for(int i=1;i<=n;i++){
      if(dep[tmp[i]]+dep[tmp[i%n+1]]-dep[lca(tmp[i],tmp[i%n+1])]*2>3){
        puts("Wrong Answer");
        exit(0);
      }
    }
    puts("Accept");
  }
  else{
    puts("Wrong Answer");
  }
	return 0;
}
