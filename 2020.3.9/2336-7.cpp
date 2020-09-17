#include<bits/stdc++.h>
using namespace std;
struct node{
  int a[6][6];
  bool operator <(const node &t)const{
    for(int i=1;i<=5;i++)
    for(int j=1;j<=5;j++){
      if(a[i][j]!=t.a[i][j]){
        return a[i][j]<t.a[i][j];
      }
    }
    return 1;
  }
  void operator =(const node &t){
    for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
        a[i][j]=t.a[i][j];
      }
    }
  }
}sta[10001];
void print(node a){
  for(int i=1;i<=5;i++){
    for(int j=1;j<=5;j++){
      printf("%d",a.a[i][j]);
    }
    putchar(10);
  }
}
int tp,np[100001];
vector<int>prime;
void pre(){
  np[1]=1;
  for(int i=2;i<=99999;i++){
    if(!np[i]){
      prime.push_back(i);
    }
    for(int j=0;j<prime.size()&&i*prime[j]<=99999;j++){
      np[i*prime[j]]=1;
      if(i%prime[j]==0)break;
    }
  }
}
int isp(int a){
  if(a<10000)return 0;
  return !np[a];
}
int sum,s;
void solve7(){
    int v=sum-sta[tp].a[2][3]-sta[tp].a[3][3]-sta[tp].a[4][3]-sta[tp].a[5][3];
    if(v<0||v>9)return;
    sta[tp].a[1][3]=v;
    if(!isp(sta[tp].a[1][3]*10000+sta[tp].a[2][3]*1000+sta[tp].a[3][3]*100+sta[tp].a[4][3]*10+sta[tp].a[5][3]))return;
    v=sum-sta[tp].a[1][1]-sta[tp].a[1][2]-sta[tp].a[1][3]-sta[tp].a[1][5];
    if(v<0||v>9)return;
    sta[tp].a[1][4]=v;
    if(!isp(sta[tp].a[1][1]*10000+sta[tp].a[1][2]*1000+sta[tp].a[1][3]*100+sta[tp].a[1][4]*10+sta[tp].a[1][5]))return;
    int v1=sum-sta[tp].a[5][1]-sta[tp].a[5][2]-sta[tp].a[5][3]-sta[tp].a[5][5];
    if(v1<0||v1>9)return;
    sta[tp].a[5][4]=v1;
    if(!isp(sta[tp].a[5][1]*10000+sta[tp].a[5][2]*1000+sta[tp].a[5][3]*100+sta[tp].a[5][4]*10+sta[tp].a[5][5]))return;
    int v2=sum-sta[tp].a[1][4]-sta[tp].a[2][4]-sta[tp].a[3][4]-sta[tp].a[4][4];
    if(v2<0||v2>9)return;
    sta[tp].a[5][4]=v2;
    if(!isp(sta[tp].a[1][4]*10000+sta[tp].a[2][4]*1000+sta[tp].a[3][4]*100+sta[tp].a[4][4]*10+sta[tp].a[5][4]))return;
    if(v1!=v2)return;
    tp++;
    sta[tp]=sta[tp-1];
}
void solve7_1(){
  for(int i=0;i<=9;i++){
    sta[tp].a[5][3]=i;
    solve7();
  }
}
void solve6(){
  int v=sum-sta[tp].a[2][2]-sta[tp].a[3][2]-sta[tp].a[4][2]-sta[tp].a[5][2];
  if(v<0||v>9)return;
  sta[tp].a[1][2]=v;
  if(!isp(sta[tp].a[1][2]*10000+sta[tp].a[2][2]*1000+sta[tp].a[3][2]*100+sta[tp].a[4][2]*10+sta[tp].a[5][2]))return;
  solve7_1();
}
void solve6_1(){
  for(int i=0;i<=9;i++){
    sta[tp].a[5][2]=i;
    solve6();
  }
}
void solve5(){
  int v=sum-sta[tp].a[3][1]-sta[tp].a[3][3]-sta[tp].a[3][4]-sta[tp].a[3][5];
  if(v<0||v>9)return;
  sta[tp].a[3][2]=v;
  if(!isp(sta[tp].a[3][1]*10000+sta[tp].a[3][2]*1000+sta[tp].a[3][3]*100+sta[tp].a[3][4]*10+sta[tp].a[3][5]))return;
  v=sum-sta[tp].a[1][5]-sta[tp].a[2][5]-sta[tp].a[3][5]-sta[tp].a[5][5];
  if(v<0||v>9)return;
  sta[tp].a[4][5]=v;
  if(!isp(sta[tp].a[1][5]*10000+sta[tp].a[2][5]*1000+sta[tp].a[3][5]*100+sta[tp].a[4][5]*10+sta[tp].a[5][5]))return;
  v=sum-sta[tp].a[4][1]-sta[tp].a[4][2]-sta[tp].a[4][4]-sta[tp].a[4][5];
  if(v<0||v>9)return;
  sta[tp].a[4][3]=v;
  if(!isp(sta[tp].a[4][1]*10000+sta[tp].a[4][2]*1000+sta[tp].a[4][3]*100+sta[tp].a[4][4]*10+sta[tp].a[4][5]))return;
  solve6_1();
}
void solve5_2(){
  for(int i=0;i<=9;i++){
    sta[tp].a[3][5]=i;
    solve5();
  }
}
void solve5_1(){
  for(int i=0;i<=9;i++){
    sta[tp].a[3][4]=i;
    solve5_2();
  }
}
void solve4(){
  int v=sum-sta[tp].a[5][1]-sta[tp].a[3][3]-sta[tp].a[2][4]-sta[tp].a[1][5];
  if(v<0||v>9)return;
  sta[tp].a[4][2]=v;
  if(!isp(sta[tp].a[5][1]*10000+sta[tp].a[4][2]*1000+sta[tp].a[3][3]*100+sta[tp].a[2][4]*10+sta[tp].a[1][5]))return;
  solve5_1();
}
void solve4_1(){
  for(int i=0;i<=9;i++){
    sta[tp].a[1][5]=i;
    solve4();
  }
}
void solve3(){
  int v=sum-sta[tp].a[2][1]-sta[tp].a[2][2]-sta[tp].a[2][4]-sta[tp].a[2][5];
  if(v<0||v>9)return;
  sta[tp].a[2][3]=v;
  if(!isp(sta[tp].a[2][1]*10000+sta[tp].a[2][2]*1000+sta[tp].a[2][3]*100+sta[tp].a[2][4]*10+sta[tp].a[2][5]))return;
  solve4_1();
}
void solve3_2(){
  for(int i=0;i<=9;i++){
    sta[tp].a[2][5]=i;
    solve3();
  }
}
void solve3_1(){
  for(int i=0;i<=9;i++){
    sta[tp].a[2][4]=i;
    solve3_2();
  }
}
void solve2(){
  int v=sum-sta[tp].a[1][1]-sta[tp].a[3][1]-sta[tp].a[4][1]-sta[tp].a[5][1];
  if(v<0||v>9)return;
  sta[tp].a[2][1]=v;
  if(!isp(sta[tp].a[1][1]*10000+sta[tp].a[2][1]*1000+sta[tp].a[3][1]*100+sta[tp].a[4][1]*10+sta[tp].a[5][1]))return;
  solve3_1();
}
void solve2_3(){
  for(int i=0;i<=9;i++){
    sta[tp].a[5][1]=i;
    solve2();
  }
}
void solve2_2(){
  for(int i=0;i<=9;i++){
    sta[tp].a[4][1]=i;
    solve2_3();
  }
}
void solve2_1(){
  for(int i=0;i<=9;i++){
    sta[tp].a[3][1]=i;
    solve2_2();
  }
}
void solve1(){
  int v=sum-sta[tp].a[1][1]-sta[tp].a[3][3]-sta[tp].a[4][4]-sta[tp].a[5][5];
  if(v<0||v>9)return;
  sta[tp].a[2][2]=v;
  if(!isp(sta[tp].a[1][1]*10000+sta[tp].a[2][2]*1000+sta[tp].a[3][3]*100+sta[tp].a[4][4]*10+sta[tp].a[5][5])){
    return;
  }
  solve2_1();
}
void solve1_3(){
  for(int i=0;i<=9;i++){
    sta[tp].a[5][5]=i;
    solve1();
  }
}
void solve1_2(){
  for(int i=0;i<=9;i++){
    sta[tp].a[4][4]=i;
    solve1_3();
  }
}
void solve1_1(){
  for(int i=0;i<=9;i++){
    sta[tp].a[3][3]=i;
    solve1_2();
  }
}
int main(){
  pre();
  scanf("%d%d",&sum,&s);
  sta[tp].a[1][1]=s;
  solve1_1();
  if(tp==0){
    puts("NONE");
    return 0;
  }
  sort(sta,sta+tp);
  for(int i=0;i<tp;i++){
    print(sta[i]);
    if(i+1!=tp)putchar(10);
  }
  return 0;
}
