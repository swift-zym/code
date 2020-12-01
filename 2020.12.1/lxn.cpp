#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
#define N 1000002
int T,x;
bool ban[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
		int l=1,r=10000,mid,ans=-1;
		for(int i=1;i<=10000;i++)ban[i]=0;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(mid*(mid+1)/2>=x)ans=mid,r=mid-1;
			else l=mid+1;
		}int pos=ans*(ans+1)/2,as1=ans+pos-x;
		for(int i=ans;i;i--)if(pos-i>=x)
		{
			pos-=i;ban[i]=1;
		}
		if(ban[1])printf("%d\n",as1);
		else printf("%d\n",ans);
	}
}