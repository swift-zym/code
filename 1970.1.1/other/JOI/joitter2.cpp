#include<bits/stdc++.h>
using namespace std;
int a[51][51],b[51][51],n,m;
int main(){
  scanf("%d%d",&n,&m);
  for(int l=1;l<=m;l++){
    int x,y;
    scanf("%d%d",&x,&y);
    a[x][y]=1;
    memcpy(b,a,sizeof(a));
    bool flag;
    int num=0;
    do{
      flag=0;
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          for(int k=1;k<=n;k++){
            if(i==j||i==k||j==k){
              continue;
            }
            if(b[i][j]==1&&b[i][k]==0&&b[j][k]==1&&b[k][j]==1){
              b[i][k]=1;
              num++;
              flag=1;
            }
          }
        }
      }
    }while(flag);
    printf("%d\n",l+num);
  }
  return 0;
}
