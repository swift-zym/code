//
// Created by swift on 2020/6/27.
//

#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r,mi,mx;
}a[4100000];
int n,d;
int a1[1000001],a2[1000001];
int l1=1,l2=1,r1,r2;
struct val{
    int v,x;
}q1[1000001],q2[1000001];
bool check(int mid){
    l1=l2=1;r1=r2=0;
    for(int i=1;i<=1000000;i++){
        while(l1<=r1&&q1[r1].v<a1[i])r1--;
        q1[++r1]={a1[i],i};
        while(l2<=r2&&q2[r2].v>a2[i])r2--;
        q2[++r2]={a2[i],i};
        int v1=q1[l1].v,v2=q2[l2].v;
        /*cout<<"_____"<<endl;
        /*
        cout<<l1<<" "<<r1<<endl;
        cout<<l2<<" "<<r2<<endl;
        cout<<a1[i]<<" "<<a2[i]<<endl;
        */
        if(v1-v2>=d)return 1;
        while(l1<=r1&&q1[l1].x<=i+1-mid)l1++;
        while(l2<=r2&&q2[l2].x<=i+1-mid)l2++;
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&d);
    memset(a2,0x3f,sizeof(a2));
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a1[x]=max(a1[x],y);
        a2[x]=min(a2[x],y);
    }
    int l=1,r=1000000;
    if(!check(r)){
        puts("-1");
        return 0;
    }
    while(l!=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",l-1);
    return 0;
}