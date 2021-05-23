#include "Catherine.h"
#include <bits/stdc++.h>
using namespace std;
int a,b,pre=-1;
void Init(int A, int B) {
  a=A;b=B;
}
int Move(std::vector<int> y) {
  if(pre==-1){
    if(y[0]&&y[1]){
      pre=0;
      return 0;
    }
    if(y[1]&&y[2]){
      pre=1;
      return 1;
    }
    if(y[2]&&y[0]){
      pre=2;
      return 2;
    }
    for (int j=0;j<a;++j) {
      if (y[j]!=0&&j!=pre) {
        pre=j;
        return j;
      }
    }
  }

  for (int j=0;j<a;++j) {
    if (y[j]!=0&&j!=pre) {
      pre=j;
      return j;
    }
  }
  return -1;
}
