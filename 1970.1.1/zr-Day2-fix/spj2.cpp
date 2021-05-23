#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
FILE *fstd,*fin,*fout;
int n;
struct candy{
	int a,b;
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
	if(ans!=num)return -1;
	for(int i=1;i<=n;i++){
		fscanf(fin,"%d%d",&c[i].a,&c[i].b);
	}
	long long suma=0,sumb=0;
	for(int i=1;i<=n;i++)suma+=c[i].a,sumb+=c[i].b;
	long long tmpa=0,tmpb=0;
	for(int i=1;i<=num;i++){
		int id;
		fscanf(fout,"%d",&id);
		tmpa+=c[id].a;
		tmpb+=c[id].b;
	}
	if(tmpa*2>suma&&tmpb*2>sumb)return 0;
	return -1;
}
