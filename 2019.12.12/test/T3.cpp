#include<bits/stdc++.h>
using namespace std;
char s[300];
int T,cnt;
bool KMP(string a,string b){
  int l1=a.length(),l2=b.length();
  for(int i=0;i<l1;i++){
    bool flag=1;
    for(int j=0;j<l2;j++){
      if(b[j]!=a[i+j]){
        flag=0;
        break;
      }
    }
    if(flag){
      a.erase(i,l2);
      l1=a.length();
      i=max(0,i-2*l2)-1;
    }
  }
  return l1==0;
}
string ans[300];
int main(){
  scanf("%d",&T);
  while(T--){
    memset(s,0,sizeof(s));
    cnt=0;
    scanf("%s",s);
    string tmp=s;
    int l=tmp.length();
    for(int i=1;i<=l;i++){
    bool flag=0;
    for(int j=0;j<l;j++){
      if(j+i-1>=l)break;
      string tmp2="";
      for(int k=j;k<=j+i-1;k++){
        tmp2+=tmp[k];
      }
      if(KMP(tmp,tmp2)){
        //cout<<tmp2<<endl;
        ans[++cnt]=tmp2;
        flag=1;
      }
    }
    if(flag){
      break;
    }
    }
    sort(ans+1,ans+cnt+1);
    memset(s,0,sizeof(s));
    int len=ans[1].length();
    for(int i=0;i<len;i++){
      s[i]=ans[1][i];
    }
    printf("%s\n",s);
  }
  return 0;
}
/*
2
hhehellolloelhellolo
hhehellolloelhellolo
*/
