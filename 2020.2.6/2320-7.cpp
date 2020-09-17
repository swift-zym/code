#include<bits/stdc++.h>
using namespace std;
struct node{
  int a[5];
  bool operator !=(node t){
    for(int i=1;i<=3;i++)if(a[i]!=t.a[i])return 1;
    return 0;
  }
  void sort(){
    std::sort(a+1,a+4);
  }
  void print(){
    for(int i=1;i<=3;i++){
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
}a1,a2;
int v;
node gf(node a,int k){
  node ans;
  int c1=a.a[2]-a.a[1],c2=a.a[3]-a.a[2];
  for(int i=1;i<=3;i++)ans.a[i]=a.a[i];
  if(c1==c2)return ans;
  if(c1<c2){
    int tmp=min(k,(c2-1)/c1);
    k-=tmp;
    v+=tmp;
    ans.a[2]+=tmp*c1,ans.a[1]+=tmp*c1;
  }
  else{
    int tmp=min(k,(c1-1)/c2);
    k-=tmp;
    v+=tmp;
    ans.a[2]-=tmp*c2,ans.a[3]-=tmp*c2;
  }
  if(k)return gf(ans,k);
  else return ans;
}
int main(){
  for(int i=1;i<=3;i++)scanf("%d",&a1.a[i]);
  for(int i=1;i<=3;i++)scanf("%d",&a2.a[i]);
  a1.sort();
  a2.sort();
  v=0;node b1=gf(a1,0x3f3f3f3f);
    int v1=v;
  v=0;node b2=gf(a2,0x3f3f3f3f);
    int v2=v;
  if(b1!=b2){
    puts("NO");
    return 0;
  }
  if(v1>v2){
    swap(v1,v2);
    swap(a1,a2);
  }
  int tmp=v2-v1;
  a2=gf(a2,tmp);
  int l=0,r=v1;
  while(l<r){
    int mid=(l+r)/2;
    if(gf(a1,mid)!=gf(a2,mid))l=mid+1;
    else r=mid;
  }
  puts("YES");
  printf("%d\n",tmp+2*l);
  return 0;
}
