#include<iostream>
#include<cstdio>
using namespace std;
char s[23000000];
int len=1,r,mid,ans,p[23000000];
int main(){
    char c=getchar();
    s[0]='~';s[1]='|';
    while(c>='a'&&c<='z'){
        s[++len]=c;
        s[++len]='|';
        c=getchar();
    }
    for(int i=1;i<=len;i++){
        if(i<r){
            p[i]=min(p[2*mid-i],r-i);
        }
        else{
            p[i]=1;
        }
        while(s[i-p[i]]==s[i+p[i]])p[i]++;
        if(i+p[i]>r){
            r=i+p[i];
            mid=i;
            ans=max(ans,p[i]);
        }
    }
    printf("%d\n",ans-1);
    return 0;
}