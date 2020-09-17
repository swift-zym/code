#include<bits/stdc++.h>
using namespace std;
int main(){
  srand(time(0));
  freopen("T2.in","w",stdout);
  int n=100,q=100;
  cout<<n<<endl;
  cout<<q<<endl;
  for(int i=1;i<=q;i++){
    int opt=rand()%3+1,l,r,x;
    if(opt==1||opt==2){
      l=rand()%n+1,r=rand()%n+1;
      if(l>r)swap(l,r);
      printf("%d %d %d\n",opt,l,r);
    }
    else{
      x=rand()%n+1;
      printf("%d %d\n",opt,x);
    }
  }
  return 0;
}
