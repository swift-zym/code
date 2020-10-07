#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
FILE *fstd,*fin,*fout;
int n;
struct candy{
	int a,b,vis;
}c[100001];
int main(int argc,char *argv[])
{
	fin=fopen(argv[1],"r");
	fstd=fopen(argv[2],"r");
	fout=fopen(argv[3],"r");
	int num,ans;
	fscanf(fstd,"%d",&ans);
	fscanf(fout,"%d",&num);
	fscanf(fin,"%d",&n);
	if(ans==-1&&num!=-1){
		return -1;
	}
	if(ans!=-1&&num==-1){
		return -1;
	}
	if(num>n/2+1){
		return -1;
	}
	for(int i=1;i<=n;i++){
		fscanf(fin,"%d",&c[i].a);
	}
	for(int i=1;i<=n;i++){
		fscanf(fin,"%d",&c[i].b);
	}
	long long suma=0,sumb=0;
	for(int i=1;i<=n;i++)suma+=c[i].a,sumb+=c[i].b;
	long long tmpa=0,tmpb=0;
	for(int i=1;i<=num;i++){
		int id;
		fscanf(fout,"%d",&id);
		if(c[id].vis){
			return -1;
		}
		c[id].vis=1;
		tmpa+=c[id].a;
		tmpb+=c[id].b;
	}
	if(tmpa*2>suma&&tmpb*2>sumb){
		return 0;
	}
	return -1;
}
