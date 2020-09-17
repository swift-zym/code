//题目名： [USACO09DEC]Cow Toll Paths
#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,money;
}nodes[251];
inline bool cmp(node a,node b){
    if(a.money!=b.money)
    return a.money<b.money;
    return a.id<b.id;
}
int main(){
    int n,m,q,edgeMoney[251][251],answerMoney[251][251],is[251];
    scanf("%d%d%d",&n,&m,&q);
    memset(edgeMoney,0x3f,sizeof(edgeMoney));
    memset(answerMoney,0x3f,sizeof(answerMoney));
    for(int i=1;i<=n;i++){
        scanf("%d",&nodes[i].money);
        nodes[i].id=i;
    }
    sort(nodes+1,nodes+n+1,cmp);
    for(int i=1;i<=n;i++){
        edgeMoney[i][i]=0;
        is[nodes[i].id]=i;
    }
    for(int i=1;i<=m;i++){
        int a,b,m;
        scanf("%d%d%d",&a,&b,&m);
        edgeMoney[is[a]][is[b]]=edgeMoney[is[b]][is[a]]=min(edgeMoney[is[a]][is[b]],m);
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(i==j)continue;
        edgeMoney[i][j]=min(edgeMoney[i][j],edgeMoney[i][k]+edgeMoney[k][j]);
        answerMoney[i][j]=min(answerMoney[i][j],edgeMoney[i][j]+max(nodes[i].money,max(nodes[j].money,nodes[k].money)));
    }
    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",answerMoney[is[a]][is[b]]);
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}