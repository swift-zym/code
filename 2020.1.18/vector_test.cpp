#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
  for(int i=1;i<=5;i++)v.push_back(i);
  vector<int>::iterator now=v.begin();
  for(;now!=v.end();now++){
    printf("%d %d\n",distance(v.begin(),now),*now);
  }
}
