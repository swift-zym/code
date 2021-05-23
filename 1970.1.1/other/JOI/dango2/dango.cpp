#include<bits/stdc++.h>
using namespace std;
char a[510][510];
int vis[510][510];
int r,c,num;
int mx[8]={0,1,0,-1,1,-1,-1,1},my[8]={1,0,-1,0,1,1,-1,-1};
char m[8]={'-','|','-','|','\\','/','\\','/'};
int tmp[8]={0,2,1,3,5,7,4,6};
int main(){
  srand(time(0));
  freopen("input_06.txt","r",stdin);
  freopen("output_06.txt","w",stdout);
  scanf("%d%d",&r,&c);
  for(int i=1;i<=r;i++){
    scanf("%s",a[i]+1);
  }
  for(int i=1;i<=r;i++)
  for(int j=1;j<=c;j++){
    shuffle(tmp,tmp+8,std::default_random_engine(time(0)));
    if(a[i][j]=='P'&&vis[i][j]==0){
      for(int kk=0;kk<8;kk++){
        int k=tmp[kk];
        int nx=i+mx[k],ny=j+my[k];
        if(nx<=0||nx>r||ny<=0||ny>c)continue;
        if(a[nx][ny]!='W'||vis[nx][ny])continue;
        nx+=mx[k];
        ny+=my[k];
        if(nx<=0||nx>r||ny<=0||ny>c)continue;
        if(a[nx][ny]!='G'||vis[nx][ny])continue;
        vis[nx][ny]=1;
        nx-=mx[k];
        ny-=my[k];
        a[nx][ny]=m[k];
        vis[nx][ny]=1;
        nx-=mx[k];
        ny-=my[k];
        vis[nx][ny]=1;
        num++;
        break;
      }
    }
  }
  cout<<num<<endl;
  for(int i=1;i<=r;i++){
    printf("%s\n",a[i]+1);
  }

  return 0;
}
