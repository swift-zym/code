#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t;
char s[210000];
int main(){
  scanf("%d",&t);
  while(t--){
    scanf("%s",s);
    int len=strlen(s);
    int ans=1e8;
    for(int i=0;i<=9;i++)
    for(int j=0;j<=9;j++){
      int num=0,v=0;
      for(int k=0;k<len;k++){
        if(num==0){
          if(s[k]-'0'==i){
            num^=1;
          }
          else
          v++;
        }
        else{
          if(s[k]-'0'==j){
            num^=1;
          }
          else
          v++;
        }
      }
      //cout<<i<<" "<<j<<" "<<v<<endl;
      bool flag=1;
      if((len-v)%2==1&&i!=j)flag=0;
      if(flag)
      ans=min(v,ans);
    }
    printf("%d\n",ans);
  }
  return 0;
}
//1->n-1
//2->n
//3->1
//4->2
//...
//n->n-2
//123456789
//234567891
//912345678
//1->(n-1)->(n-3)->(n-5)->(n-7)
