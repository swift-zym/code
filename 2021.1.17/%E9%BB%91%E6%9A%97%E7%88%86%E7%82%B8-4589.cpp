
// Problem: Hard Nim
// Contest: Virtual Judge - %E9%BB%91%E6%9A%97%E7%88%86%E7%82%B8
// URL: https://vjudge.net/problem/%E9%BB%91%E6%9A%97%E7%88%86%E7%82%B8-4589
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
void fwt(int *a, int len, int v) {
  for (int i = 1; i < len; i <<= 1)
    for (int j = 0; j < len; j += (i << 1))
      for (int k = 0; k < i; k++) {
        int x = a[j + k], y = a[j + i + k];
      }
}
int a[1000000];