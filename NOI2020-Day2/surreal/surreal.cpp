#include<bits/stdc++.h>
using namespace std;
int v[1000001][2];
int isEnd[1000001];
int ls[1000001],rs[1000001];
int m,n;
int mxdep;
int mxid;
void dfs(int now,int id,int dep=1){
    mxdep=max(mxdep,dep);
    mxid=max(id,mxid);
    //cout<<">"<<now<<" "<<v[now][0]<<" "<<v[now][1]<<endl;
    //cout<<">"<<id<<endl;
    if(v[now][0]==0&&v[now][1]==0){
        isEnd[id]=1;
        //cout<<"set "<<id<<endl;
    }
    if(v[now][0]){
        ls[id]=1;
        dfs(v[now][0],id*2,dep+1);
    }
    if(v[now][1]){
        rs[id]=1;
        dfs(v[now][1],id*2+1,dep+1);
    }
}
int ans;
void dfss(int now){
    //cout<<now<<" "<<ls[now]<<" "<<rs[now]<<endl;
    if(isEnd[now]==0&&(ls[now]==0||rs[now]==0)){
        ans=0;
        return;
    }
    if(isEnd[now])return;
    if(ls[now])dfss(now*2);
    if(rs[now])dfss(now*2+1);
}
int main(){
    freopen("surreal.in","r",stdin);
    freopen("surreal.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&m);
        bool flag1=1,flag2=0,flag3=0;
        bool tmp1=0,tmp2=0,tmp3=0;
        mxdep=0;
        mxid=0;
        for(int num=1;num<=m;num++){
            scanf("%d",&n);
            if(n==1)flag2=1;
            for(int i=1;i<=n;i++){
                int l,r;
                scanf("%d%d",&l,&r);
                if(l!=0&&r!=0){
                   flag1=0;
                }
                if(i==1){
                    if(l==0&&r!=0)tmp1=1;
                    if(l!=0&&r==0)tmp2=1;
                    if(l!=0&&r!=0)tmp3=1;
                    if(n==3&&l!=0&&r!=0)flag3=1;
                }
                if(l)v[i][0]=l;
                if(r)v[i][1]=r;
            }
            dfs(1,1);
            //puts("---");
            for(int i=1;i<=n;i++)v[i][0]=v[i][1]=0;
        }
        if(mxdep==1){
            puts("Almost Complete");
        }
        else if(mxdep==2){
            //cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
            if(flag2){
                puts("Almost Complete");
            }
            else if(tmp1&&tmp2&&tmp3){
                puts("Almost Complete");
            }
            else{
                puts("No");
            }
        }
        else if(flag1){
            puts("No");
        }
        else{
            if(flag3){
                puts("Almost Complete");
            }
            else{
                puts("No");
            }
        }
    }
    return 0;
}
/*
1->2->4
1->3->7
1->3->6
1->2
*/