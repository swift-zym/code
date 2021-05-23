// Problem: B - uNrEaDaBlE sTrInG
// Contest: AtCoder - AtCoder Beginner Contest 192
// URL: https://atcoder.jp/contests/abc192/tasks/abc192_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i += 2) {
    if (s[i] < 'a' || s[i] > 'z') {
      puts("No");
      goto ed;
    }
  }
  for (int i = 1; i < s.length(); i += 2) {
    if (s[i] < 'A' || s[i] > 'Z') {
      puts("No");
      goto ed;
    }
  }
  puts("Yes");
ed:;
  return 0;
}