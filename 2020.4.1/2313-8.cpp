#include<bits/stdc++.h>
using namespace std;
int n,m,h,a[1001][1001];
int mih[1001][1001],mihl[1001][1001];
int mxh[1001][1001],mxhl[1001][1001];
struct node{
  int id,v;
};
int main(){
  scanf("%d%d%d",&n,&m,&h);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%d",&a[i][j]);
    }
  }
  for(int i=1;i<=n;i++){
     node q[1001];
     int l=1,r=1;
     //
     //printf("---line %d---\n",i);
     for(int j=1;j<=m;j++){
       //printf("--pre %d--\n",j);
        // cout<<l<<" "<<r<<endl;
       //for(int i=l;i<r;i++)printf("{%d,%d} ",q[i].id,q[i].v);
       //putchar(10);
       while(l<r&&q[l].id<j-h+1)l++;
       while(l<r&&q[r-1].v>a[i][j])r--;
      // printf("--%d--\n",j);
      //   cout<<l<<" "<<r<<endl;
       q[r++]={j,a[i][j]};
       //for(int i=l;i<r;i++)printf("{%d,%d} ",q[i].id,q[i].v);
       //putchar(10);
       if(j>=h){
         mih[i][j-h+1]=q[l].v;
       }

     }
  }
  for(int i=1;i<=m;i++){
     node q[1001];
     int l=1,r=1;
     for(int j=1;j<=n;j++){
       while(l<r&&q[l].id<j-h+1)l++;
       while(l<r&&q[r-1].v>mih[j][i])r--;
       q[r++]={j,mih[j][i]};
       if(j>=h){
         mihl[j-h+1][i]=q[l].v;
       }
     }
  }
  for(int i=1;i<=n;i++){
     node q[1001];
     int l=1,r=1;
     for(int j=1;j<=m;j++){
       while(l<r&&q[l].id<j-h+1)l++;
       while(l<r&&q[r-1].v<a[i][j])r--;
       q[r++]={j,a[i][j]};
       if(j>=h){
         mxh[i][j-h+1]=q[l].v;
       }
     }
  }
  for(int i=1;i<=m;i++){
     node q[1001];
     int l=1,r=1;
     for(int j=1;j<=n;j++){
       while(l<r&&q[l].id<j-h+1)l++;
       while(l<r&&q[r-1].v<mxh[j][i])r--;
       q[r++]={j,mxh[j][i]};
       if(j>=h){
         mxhl[j-h+1][i]=q[l].v;
       }
     }
  }
  int mi=1e9;
  for(int i=1;i<=n-h+1;i++)
  for(int j=1;j<=m-h+1;j++){
    //cout<<i<<" "<<j<<" "<<mxh[i][j]<<" "<<mih[i][j]<<endl;
    mi=min(mi,mxhl[i][j]-mihl[i][j]);
  }
  printf("%d\n",mi);
  return 0;
}
