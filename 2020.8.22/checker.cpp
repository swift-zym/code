#include "testlib.h"
#include <bits/stdc++.h>

const int N=5e5+5;

int n,a[N],p[N],X[N],Y[N];
bool f[N];

int main(int argc,char* argv[]){
	registerTestlibCmd(argc,argv);
	
	n=inf.readInt();
	for(int i=1;i<=n;i++)a[i]=inf.readInt();
	for(int i=1;i<=n;i++)p[i]=inf.readInt();
	
	long long jans=ans.readLong(),pans=ouf.readLong();
	if(jans!=pans)quitf(_wa,"The answer is wrong: expected = %lld, found = %lld.",jans,pans);
	else if(jans==-1)quitf(_ok,"The answer is correct, congratulations!");
	
	for(int i=1;i<=n/2;i++)X[i]=ouf.readInt(),Y[i]=ouf.readInt();
	
	while(!ouf.seekEof())ouf.readToken();
	while(!inf.seekEof())inf.readToken();
	while(!ans.seekEof())ans.readToken();
	
	long long cnt=0;
	for(int i=1;i<=n/2;i++){
		int x=X[i],y=Y[i];
		if(x<=0||x>n)quitp(0.6,"On line %d you output a crystal %d, which is beyond the confine.",i,x);
		if(y<=0||y>n)quitp(0.6,"On line %d you output a crystal %d, which is beyond the confine.",i,y);
		if(x==y)quitp(0.6,"On line %d you output two identical crystals %d.",i,x);
		if(f[x])quitp(0.6,"On line %d you output a crystal %d, which has been destroyed.",i,x);
		if(f[y])quitp(0.6,"On line %d you output a crystal %d, which has been destroyed.",i,y);
		if(y==p[x]||x==p[y])quitp(0.6,"On line %d you output two crystals %d and %d, which disobeys the rule.",i,x,y);
		cnt+=1ll*i*std::min(a[x],a[y]),f[x]=f[y]=1;
	}
	if(cnt<pans)quitp(0.6,"The answer is %lld, but your project gives a cost of %lld",pans,cnt);
	else if(cnt>pans)quitf(_fail,"Oops! Your answer is better than jury's answer!",pans,cnt);
	else quitf(_ok,"The answer and the project are correct, congratulations!.");
	return 0;
}

