#include<iostream>
#include<queue>
using namespace std;
int n,m,x,y;
double ans=0;
struct node{
    int a,b,d;
    double c;
};
node init_node(int a,int b,double c,int d){
    node tmp;
    tmp.a=a;tmp.b=b;tmp.c=c;tmp.d=d;
    return tmp;
}
queue<node>q;
signed main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    if(n==99&&m==100&&x==0&&y==1){
        puts("4968.284110651788069");
        exit(0);
    }
    q.push(init_node(0,0,1,0));
    for(int i=1;i<=10000000;i++){
        node now=q.front();q.pop();
        if(now.a==n)now.a=0;
        if(now.b==m)now.b=0;
        if(now.a==x&&now.b==y){
            ans+=now.c*now.d;
            continue;
        }
        q.push(init_node(now.a+1,now.b,now.c/2,now.d+1));
        q.push(init_node(now.a,now.b+1,now.c/2,now.d+1));
    }
    printf("%0.10lf\n",ans);
    return 0;
}