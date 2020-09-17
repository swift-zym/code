//
// Created by 张一鸣 on 2020/4/23.
//
#include<bits/stdc++.h>
using namespace std;
int nxt[210];
char a[101][210],name[101][210];
char sos[210];
int n,mx;
vector<int>v;
int main(){
    freopen("save10.in","r",stdin);
    freopen("save10.out","w",stdout);
    sos[0]='s';
    sos[1]='o';
    sos[2]='s';
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",name[i]);
        scanf("%s",a[i]);
    }
    for(int id=1;id<=n;id++){
        memset(nxt,0,sizeof(nxt));
        nxt[0]=-1;
        int num=0;
        int len=strlen(a[id]);
        for(int i=1,j=-1;i<3;i++){
            while(j!=-1&&sos[i]!=sos[j+1])j=nxt[j];
            if(sos[i]==sos[j+1])j++;
            nxt[i]=j;
        }
        for(int i=0,j=-1;i<len;i++){
            while(j!=-1&&a[id][i]!=sos[j+1])j=nxt[j];
            if(a[id][i]==sos[j+1])j++;
            if(j==3-1){
                j=nxt[j];
                num++;
            }
        }
        if(num>mx){
            mx=num;
            v.clear();
            v.push_back(id);
        }
        else if(num==mx){
            v.push_back(id);
        }
    }
    for(int i=0;i<v.size();i++){
        if(i)putchar(' ');
        printf("%s",name[v[i]]);
    }
    putchar(10);
    printf("%d\n",mx);
    return 0;
}
