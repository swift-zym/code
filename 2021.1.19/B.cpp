
// Problem: B. Card Deck
// Contest: Codeforces - Codeforces Round #704 (Div. 2)
// URL: https://codeforces.com/contest/1492/problem/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
int T, n, p[1000000], idx[1000000];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
      idx[p[i]] = i;
    }
    int tp = n;
    for (int i = n; i >= 1; i--) {
      if (idx[i] > tp) continue;
      for (int j = idx[i]; j <= tp; j++) {
        cout << p[j] << " ";
      }
      tp = idx[i] - 1;
    }
    cout << endl;
  }
  return 0;
}