// Problem: B. Napoleon Cake
// Contest: Codeforces - Codeforces Round #707 (Div. 2, based on Moscow Open
// Olympiad in Informatics) URL: https://codeforces.com/contest/1501/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int T, n, a[200001], vis[200001];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    fill(vis + 1, vis + n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<int> s;
    for (int i = 1; i <= n; i++) {
      s.push(i);
      int len = a[i];
      while (a[i]--) {
        if (s.empty() || i - s.top() + 1 > len) break;
        vis[s.top()] = 1;
        s.pop();
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << vis[i] << " ";
    }
    cout << endl;
  }
  return 0;
}