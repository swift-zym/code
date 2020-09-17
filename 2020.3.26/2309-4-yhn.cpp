#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define int unsigned long long
using namespace std;
int s,m,cnt,ans[111111],pri[111111],v[111111],f[111111];
void prime()
{
	memset(v,0,sizeof(v));
	for(int i=2;i<=100000;i++)
	{
		if(v[i]==0)
		{
			v[i]=i;
			pri[++m]=i;
		}
		for(int j=1;j<=m;j++)
		{
			if(v[i]<pri[j]||i*pri[j]>100000) break;
			v[i*pri[j]]=pri[j];
		}
	}
}
bool check(int x)
{
	if(x<=100000){ if(v[x]==x) return true;else return false;}
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0) return false;
	}
	return true;
}
void dfs(int lim,int now,int s)
{
	if(s==1)
	{
		if(f[now]==0) ans[++cnt]=now,f[now]=1;
		return;
	}
	if(s-1>=pri[lim]&&check(s-1))
	{
		if(f[now*(s-1)]==0) ans[++cnt]=now*(s-1),f[now*(s-1)]=1;
	}
	for(int i=lim;pri[i]*pri[i]<=s;i++)
	{
		int pow=1,sum=1;
		while(sum<=s)
		{
			pow=pow*pri[i];
			sum=sum+pow;
			if(s%sum==0)
			{
				dfs(i+1,now*pow,s/sum);
			}
		}
	}
	return;
}
signed main()
{
	prime();
	while(scanf("%lld",&s)==1)
	{
		memset(ans,0,sizeof(ans));
    cnt=0;
		dfs(1,1,s);
		if(cnt==0)
		{
			printf("0\n");
			continue;
		}
		printf("%lld\n",cnt);
		sort(ans+1,ans+cnt+1);
		for(int i=1;i<=cnt;i++)
		{
			printf("%lld ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
