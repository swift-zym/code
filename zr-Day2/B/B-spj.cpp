#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
FILE *fstd,*fin,*fout,*ferr;
int n;
struct candy{
	int a,b,vis;
}c[100001];
int main(int argc,char *argv[])
{
	fin=fopen(argv[1],"r");
	fstd=fopen(argv[2],"r");
	fout=fopen(argv[3],"r");
	ferr=fopen(argv[4],"w");
	int num,ans;
	fscanf(fstd,"%d",&ans);
	fscanf(fout,"%d",&num);
	fscanf(fin,"%d",&n);
	if(ans==-1&&num!=-1){
		fprintf(ferr,"Wrong Answer[1]");
		return -1;
	}
	if(ans!=-1&&num==-1){
		fprintf(ferr,"Wrong Answer[2]");
		return -1;
	}
	if(num>n/2+1){
		fprintf(ferr,"Wrong Answer[3]");
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
			fprintf(ferr,"Wrong Answer[5]");
			return -1;
		}
		c[id].vis=1;
		tmpa+=c[id].a;
		tmpb+=c[id].b;
	}
	if(tmpa*2>suma&&tmpb*2>sumb){
		fprintf(ferr,"Accept");
		return 0;
	}
	fprintf(ferr,"Wrong Answer[4],%lld,%lld,%lld,%lld",tmpa,tmpb,suma,sumb);
	return -1;
}
