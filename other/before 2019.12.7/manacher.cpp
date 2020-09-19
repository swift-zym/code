#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=11000002;
int mid,r,p[maxn<<1],ans,cnt=1;
char s[maxn<<1];
#define RP(t,a,b) for(int t=(a),edd=(b);t<=edd;t++)
inline void preWork(){
    s[0]='~';
    s[1]='|';
    char c=getchar();
    while(c<'a'||c>'z')c=getchar();
    while(c>='a'&&c<='z'){
        s[++cnt]=c;
        s[++cnt]='|';
        c=getchar();
    }
    return;
}
inline int minn(int a,int b){
    if(a<b)return a;
    return b;
}
int main(){
    preWork();
    RP(i,1,cnt){
        if(i<r){
            p[i]=minn(p[(mid<<1)-i],r-i);
        }
        else{
            p[i]=1;
        }
        while(s[i-p[i]]==s[i+p[i]])p[i]++;
        if(i+p[i]>r)mid=i,r=i+p[i];
        if(p[i]>ans)ans=p[i];
    }
    cout<<ans-1<<endl;
    return 0;
}