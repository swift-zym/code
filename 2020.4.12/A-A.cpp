#include<bits/stdc++.h>
using namespace std;
int l1,r1,l2,r2,n,k,ans,mi=0;
struct node{
  int v,x;
};
node q1[3000001],q2[3000001];
int main(){
  scanf("%d%d",&k,&n);
  for(int i=1;i<=n;i++){
    int a;
    scanf("%d",&a);
    while(l1<r1&&q1[r1-1].v>a){/*cout<<"--1"<<endl;*/r1--;}
    q1[r1++]={a,i};
    while(l2<r2&&q2[r2-1].v<a){/*cout<<"--2"<<endl;*/r2--;}
    q2[r2++]={a,i};
    if(q2[l2].v-q1[l1].v>k){
      int id=min(q2[l2].x,q1[l1].x);
      while(l1<r1&&q1[l1].x<=id)l1++;
      while(l2<r2&&q2[l2].x<=id)l2++;
      mi=id;
    }
    //include<bits/stdc++.h
    ans=max(ans,i-mi);
  }
  printf("%d\n",ans);
  return 0;
}
