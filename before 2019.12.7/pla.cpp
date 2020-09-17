#include<bits/stdc++.h>
using namespace std;
char s[5001];
bool g[5001][5001];
int f[5001][5001];
inline bool check(int l,int r){
    for(int i=l,j=r;i<j;i++,j--){
        if(s[i]!=s[j])return 0;
    }
    return 1;
}
int main(){
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
    g[i][i]=1;
    f[i][i]++;
    f[i][i+1]=2;
    if(s[i]==s[i+1]&&i+1<len){
        g[i][i+1]=1;
        f[i][i+1]++;
    }
    }
    for(int i=0;i<len-2;i++)
    for(int j=i+2;j<len;j++){
        if(check(i,j)){
            g[i][j]=1;
        }
    }
    for(int i=3;i<=len;i++)
    for(int j=0;j+i-1<len;j++){
        int k=i+j-1;
        f[j][k]=f[j+1][k]+f[j][k-1]-f[j+1][k-1];
        if(g[j][k])f[j][k]++;
    }
    int n,l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        if(l>r)swap(l,r);
        printf("%d\n",f[l-1][r-1]);
    }
}