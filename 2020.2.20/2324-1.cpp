#include<bits/stdc++.h>
using namespace std;
int in[30],out[30],fa[30];
int gf(int now){
  if(fa[now]==now)return now;
  int f=gf(fa[now]);
  return fa[now]=f;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n;
    scanf("%d",&n);
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=0;i<=25;i++)fa[i]=i;
    for(int i=1;i<=n;i++){
      char s[1050];
      scanf("%s",s);
      int a=s[0]-'a',b=s[strlen(s)-1]-'a';
      fa[gf(a)]=gf(b);
      out[a]++;
      in[b]++;
    }
    int num=0,num1=0,num2=0;
    for(int i=0;i<=25;i++){
      if(((in[i]||out[i])&&fa[i]==i)||abs(in[i]-out[i])>1){
        num++;
      }
    }
    if(num>1){
      puts("The door cannot be opened.");
      continue;
    }
    for(int i=0;i<=25;i++){
      if(in[i]>out[i])num1++;
      else if(out[i]>in[i])num2++;
    }
    if(num1!=num2||num1>1){
      puts("The door cannot be opened.");
      continue;
    }
    puts("Ordering is possible.");
  }
  return 0;
}
