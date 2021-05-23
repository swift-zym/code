// Problem: CF600F Edge coloring of bipartite graph
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF600F
// Memory Limit: 250 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int a, b, m, u[100001], v[100001], trans[1001][1001], du[1001];
int main() {
  cin >> a >> b >> m;

  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i];
    v[i] += a;
    du[u[i]]++;
    du[v[i]]++;
  }

  int mx = *max_element(du + 1, du + a + b + 1);
  for (int i = 1; i <= m; i++) {
    int a = min_element(trans[u[i]] + 1, trans[u[i]] + mx + 1) - trans[u[i]],
        b = min_element(trans[v[i]] + 1, trans[v[i]] + mx + 1) - trans[v[i]];
    trans[u[i]][a] = v[i];
    trans[v[i]][b] = u[i];

    if (a == b) continue;

    for (int c = a, cur = u[i]; cur; cur = trans[cur][c], c = a + b - c) {
      swap(trans[cur][a], trans[cur][b]);
    }
  }
  cout << mx << endl;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= mx; j++) {
      if (trans[u[i]][j] == v[i]) {
        cout << j << " ";
      }
    }
  }
  cout << endl;
  return 0;
}