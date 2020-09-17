#include<iostream>
#include<cstring>
using namespace std;
int n,t;
char a[200000],b[200000];
int tmp[50][50];
int main(){
  scanf("%d",&t);
  while(t--){
    memset(tmp,0,sizeof(tmp));
    scanf("%d",&n);
    scanf("%s",a+1);
    scanf("%s",b+1);
    bool flag=0;
    for(int i=1;i<=n;i++){
      if(a[i]>b[i]){
        flag=1;
        break;
      }
    }
    if(flag){
      puts("-1");
      continue;
    }
    for(int i=1;i<=n;i++){
      if(a[i]!=b[i]){
        tmp[a[i]-'a'][b[i]-'a']++;
      }
    }
    int sum=0;
    for(int i=0;i<=19;i++){
      int mi=-1;
      for(int j=0;j<=19;j++){
        if(tmp[i][j]){
          mi=j;
          break;
        }
      }
      if(mi==-1)continue;
      sum++;
      for(int j=mi+1;j<=19;j++){
        tmp[mi][j]+=tmp[i][j];
      }
    }
    printf("%d\n",sum);
  }
  return 0;
}
