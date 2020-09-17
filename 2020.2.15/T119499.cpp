#include<bits/stdc++.h>
using namespace std;
__int128 ma[100000];
string s;
__int128 l;
__int128 mx=-1;
inline __int128 read(){
   __int128 X=0,w=0; char ch=0;
   while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
   while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
   return w?-X:X;
}
inline void print(__int128 x){
   if(x<0){putchar('-');x=-x;}
   if(x>9) print(x/10);
   putchar(x%10+'0');
}
int main(){
  cin>>s;
  l=read();
  __int128 len=s.length();
  for(int i=0;i<len;i++){
    ma[int(s[i])]++;
    mx=max(mx,ma[int(s[i])]);
  }
  __int128 bas=mx,ans=0;
  while(len<l){
    len+=bas;
    bas*=2;
    ans++;
  }
  print(ans);
  return 0;
}
