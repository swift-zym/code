#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int head[2000],nxt[10000],c[10000],f[10000],to[10000];
int deep[2000];
int cnt=-1;
int n,k,s,t;
void clear(){
    cnt=-1;
    memset(head,-1,sizeof(head));
}
bool bfs(){
	memset(deep,0,sizeof(deep));
	queue<int>q;
	q.push(s);
	deep[s]=1;
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=head[now];i!=-1;i=nxt[i]){
			if(!deep[to[i]] && c[i]>f[i]){
				deep[to[i]]=deep[now]+1;
				q.push(to[i]);
			}
		}
	}
	return deep[t] != 0;
}
int dfs(int now,int flow){
	if(now==t)return flow;
	int tmp=0;
	for(int i=head[now];i!=-1&&tmp<flow;i=nxt[i]){
		if(deep[now]+1==deep[to[i]]&&c[i]>f[i]){
			int tmpp=dfs(to[i],min(flow-tmp,c[i]-f[i]));
			f[i]+=tmpp;
			f[i^1]-=tmpp;
			tmp+=tmpp;
		}
	}
	return tmp;
}
int dinic(){
	int ans=0;
	while(bfs())
		ans+=dfs(s,1000000000);
	return ans;
}
void add(int a,int b,int l){
	nxt[++cnt]=head[a];
	to[cnt]=b;
	c[cnt]=l;
	f[cnt]=0;
	head[a]=cnt;
	nxt[++cnt]=head[b];
	to[cnt]=a;
	c[cnt]=0;
	f[cnt]=0;
	head[b]=cnt;
}
int a[200001],b[200001],q;
namespace subtask{
    int t[200001],mp[200001];
    void add(int x,int v){
      for(;x<=n;x+=x&-x){
          t[x]+=v;
      }  
    }
    int query(int x){
        int v=0;
        for(;x;x-=x&-x){
            v+=t[x];
        }
        return v;
    }
    void solve(){
        for(int i=1;i<=k;i++){
            if(!mp[a[i]]){
                mp[a[i]]=1;
                add(a[i],1);
            }
        }
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            if(query(r)-query(l-1)==r-l+1){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    scanf("%d",&q);
    if(n>500||k>500||q>1000){
        subtask::solve();
        return 0;
    }
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        clear();
        s=0;t=n+k+1;
        for(int i=1;i<=k;i++){
            add(s,i,1);
        }
        for(int i=1;i<=k;i++){
            add(i,a[i]+k,1);
            add(i,b[i]+k,1);
        }
        for(int i=l;i<=r;i++){
            add(i+k,t,1);
        }
        if(dinic()==r-l+1){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
	return 0;
}