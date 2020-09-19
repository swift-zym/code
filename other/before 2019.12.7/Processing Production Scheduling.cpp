//题目名称：加工生产调度（209） 二道工序（204）
#include<bits/stdc++.h>
using namespace std;
#define OJ204
struct node{
    int a,b,id;
}a[25001];
int Cmp(node a){
    if(a.a<a.b)return -1;
    else if(a.a==a.b)return 0;
    else return 1;
}
bool cmp(node a,node b){
    if(Cmp(a)!=Cmp(b)){
        return Cmp(a)<Cmp(b);
    }
    if(Cmp(a)==-1)return a.a<b.a;
    else return b.b<a.b;
}
int n;
int main(){
    #ifdef OJ204
    #ifndef WIN32
    freopen("mqueue.in","r",stdin);
    freopen("mqueue.out","w",stdout);
    #endif
    #endif
    scanf("%d",&n);
    #ifndef OJ204
    for(int i=1;i<=n;i++)scanf("%d",&a[i].a),a[i].id=i;
    for(int i=1;i<=n;i++)scanf("%d",&a[i].b);
    #else 
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].b);
    #endif
    sort(a+1,a+n+1,cmp);
    int t1=0,t2=0;
    for(int i=1;i<=n;i++){
        t1+=a[i].a;
        t2=max(t1+a[i].b,t2+a[i].b);
    }
    printf("%d\n",max(t1,t2));
    #ifndef OJ204
    for(int i=1;i<=n;i++)printf("%d ",a[i].id);
    #endif
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}