#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define Maxn 100010
struct Data{
    int a,b,id;
    bool operator <(const Data &z)const{return a<z.a;}
}data[Maxn];
bool sta[Maxn];
inline void rd(int &x){
    x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
}
int main(int argc,char *argv[]){
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
    rd(n);
    for(register int i=1;i<=n;++i)rd(data[i].a),data[i].id=i;
    for(register int i=1;i<=n;++i)rd(data[i].b);
    sort(data+1,data+n+1);
    for(register int i=1;i<=n-1;i+=2){
        if(data[i].b>data[i+1].b)sta[i]=true;
        else sta[i+1]=true;
    }
    if(n&1)sta[n]=true;
    else{
        sta[n]=sta[n-1]=true;
    }
    printf("%d\n",n/2+1);
    for(register int i=1;i<=n;++i)
        if(sta[i])printf("%d ",data[i].id);
    return 0;
}
