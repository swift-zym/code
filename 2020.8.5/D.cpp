#include<iostream>
#include<stack>
using namespace std;
int t,n;
char s[300000];
int pre[300000];
int col[300000],cnt;
int main(){
  scanf("%d",&t);
  while(t--){
    cnt=0;
    scanf("%d",&n);
    scanf("%s",s);
    int num0=0,num1=0;
    stack<int>s0,s1;
    for(int i=0;i<n;i++){
      col[i]=0;
      if(s[i]=='0'){
        if(num1==0){
          pre[i]=-1;
          num0++;
        }
        else{
          int tp=s1.top();s1.pop();
          pre[i]=tp;
          num1--;
          num0++;
        }
        s0.push(i);
      }
      else{
        if(num0==0){
          pre[i]=-1;
          num1++;
        }
        else{
          int tp=s0.top();s0.pop();
          pre[i]=tp;
          num0--;
          num1++;
        }
        s1.push(i);
      }
    }
    for(int i=n-1;i>=0;i--){
      if(!col[i]){
        cnt++;
        int now=i;
        do{
          col[now]=cnt;
          now=pre[now];
        }while(now!=-1);
      }
    }
    printf("%d\n",num0+num1);
    for(int i=0;i<n;i++){
      printf("%d ",col[i]);
    }
    putchar(10);
  }
  return 0;
}
