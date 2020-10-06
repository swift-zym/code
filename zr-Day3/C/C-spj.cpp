#include<bits/stdc++.h>
using namespace std;
FILE *fin,*fstd,*fout,*ferr;
int ans[101],out[101];
int a[101];
int main(int argc,char *argv[]){
    fin=fopen(argv[1],"r");
	fstd=fopen(argv[2],"r");
	fout=fopen(argv[3],"r");
	ferr=fopen(argv[4],"w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++){
        fscanf(fin,"%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        fscanf(fstd,"%d",&ans[i]);
    }
    for(int i=1;i<=n;i++){
        if(fscanf(fout,"%d",&out[i])==EOF){
            fprintf(ferr,"Wrong Answer[1]");
            return -1;
        }
    }
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++){
        if(__gcd(out[i],out[j])!=1){
            fprintf(ferr,"Wrong Answer[3]");
            return -1;
        }
    }
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        sum1+=abs(ans[i]-a[i]);
    }
    for(int i=1;i<=n;i++){
        sum2+=abs(out[i]-a[i]);
    }
    if(sum1!=sum2){
        fprintf(ferr,"Wrong Answer[2]");
        return -1;
    }
    fprintf(ferr,"Accept");
    return 0;
}