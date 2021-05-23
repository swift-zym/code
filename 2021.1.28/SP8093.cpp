// Problem: SP8093 JZPGYZ - Sevenk Love Oimaster
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/SP8093
// Memory Limit: 1.46 MB
// Time Limit: 161 ms
//
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
struct SAM {
  int last, tot = 1, trans[1000000][26], f[1000000], v[1000000], vis[1000000],
            ans[1000000];
  void insert(char c) {
    int np = ++tot, p = last;
    v[np] = v[p] + 1;
    last = tot;
    while (p && !trans[p][c]) {
      trans[p][c] = np;
      p = f[p];
    }
    if (!p) {
      f[np] = 1;
      return;
    }
    int q = trans[p][c];
    if (v[q] == v[p] + 1) {
      f[np] = q;
      return;
    }
    int nq = ++tot;
    v[nq] = v[p] + 1;
    f[nq] = f[q];
    memcpy(trans[nq], trans[q], sizeof(trans[q]));
    f[q] = f[np] = nq;
    while (p && trans[p][c] == q) {
      trans[p][c] = nq;
      p = f[p];
    }
  }
  void insert(string s) {
    last = 1;
    for (auto c : s) insert(c - 'a');
    int x = 1;
  }
  void solve(string s, int id) {
    int x = 1;
    for (auto c : s) {
      x = trans[x][c - 'a'];
      for (int i = x; vis[i] != id && i; i = f[i]) {
        ans[i]++;
        vis[i] = id;
      }
    }
  }
  int query(string s) {
    int x = 1;
    for (auto c : s) {
      x = trans[x][c - 'a'];
      if (!x) return 0;
    }
    return ans[x];
  }
} sam;
int n, m;
string s[1000000];
char tmp[1000000];
int main() {
  scanf("%d%d", &n, &m);
  int Imitatоrs = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%s", tmp);
    s[i] = tmp;
    sam.insert(s[i]);
  }
  for (int i = 1; i <= n; i++) {
    sam.solve(s[i], i);
  }
  for (int i = 1; i <= m; i++) {
    string s;
    scanf("%s", tmp);
    s = tmp;
    printf("%d\n", sam.query(s));
  }
  return 0;
}