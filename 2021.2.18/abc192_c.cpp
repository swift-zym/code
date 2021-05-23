// Problem: C - Kaprekar Number
// Contest: AtCoder - AtCoder Beginner Contest 192
// URL: https://atcoder.jp/contests/abc192/tasks/abc192_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;
bool cmp1(int a, int b) { return a > b; }
bool cmp2(int a, int b) { return a < b; }
int g(int x, int idx) {
  char s[20];
  sprintf(s, "%d", x);
  int l = strlen(s);
  for (int i = 0; i < l; i++) {
    s[i] -= '0';
  }
  if (idx == 1)
    sort(s, s + l, cmp1);
  else
    sort(s, s + l, cmp2);
  int ans = 0;
  for (int i = 0; i < l; i++) {
    ans = ans * 10 + s[i];
  }
  return ans;
}
int f(int x) { return g(x, 1) - g(x, 2); }
int main() {
  int n, k;
  cin >> n >> k;
  while (k--) n = f(n);
  cout << n << endl;
  return 0;
}