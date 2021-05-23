//题目名称：种树
#include<bits/stdc++.h>
using namespace std;
int n,h;
int planted[30001];
struct node{
    int b,e,h;
}a[30001];
inline bool cmp(node a,node b){
    return a.e<b.e;
}
int main(){
    scanf("%d%d",&n,&h);
    for(int i=1;i<=h;i++)scanf("%d%d%d",&a[i].b,&a[i].e,&a[i].h);
    sort(a+1,a+h+1,cmp);
    for(int i=1;i<=h;i++){
        for(int j=a[i].e;j>=a[i].b;j--){
            a[i].h-=planted[j];
        }
        for(int j=a[i].e;j>=a[i].b;j--){
            if(a[i].h<=0)break;
            if(!planted[j]){
                a[i].h--;
                planted[j]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=planted[i];
    }
    printf("%d\n",ans);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}