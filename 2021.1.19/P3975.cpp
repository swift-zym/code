
// Problem: P3975 [TJOI2015]弦论
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3975
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
string s;
int k, t;
struct SAM {
  int trans[1000000][26], f[1000000], cnt = 1, lst = 1, len[1000000],
                                      sum[1000000];
  vector<int> v[1000000];
  void insert(int c) {
    int p = lst, now = ++cnt;
    lst = now;
    siz[now] = 1;
    len[now] = len[p] + 1;
    while (p && !trans[p][c]) {
      trans[p][c] = now;
      p = f[p];
    }
    if (!p) {
      f[now] = 1;
      return;
    }
    int q = trans[p][c];
    if (len[q] == len[p] + 1) {
      f[now] = q;
      return;
    }
    int nq = ++cnt;
    memcpy(trans[nq], trans[q], sizeof(trans[q]));
    f[nq] = f[q];
    f[q] = f[now] = nq;
    len[nq] = len[p] + 1;
    while (p && trans[p][c] == q) {
      trans[p][c] = nq;
      p = f[p];
    }
  }
  void build() {
    for (int i = 1; i <= cnt; i++) {
      v[f[i]].push_back(i);
    }
  }
  void df5(int now) {
    for (auto to : v[now]) {
      df5(to);
      siz[now] += siz[to];
    }
  }
  int siz[1000000];
  void dfs(int now) {
    if (sum[now]) return;
    sum[now] = siz[now];
    for (int i = 0; i <= 25; i++) {
      if (trans[now][i]) {
        dfs(trans[now][i]);
        sum[now] += sum[trans[now][i]];
      }
    }
  }
  void print(int now, int k) {
    if (siz[now] >= k) return;
    k -= siz[now];
    for (int i = 0; i <= 25; i++) {
      if (!trans[now][i]) continue;
      if (sum[trans[now][i]] < k) {
        k -= sum[trans[now][i]];
      } else {
        putchar('a' + i);
        print(trans[now][i], k);
        return;
      }
    }
  }
} SAM;
int main() {
  ios::sync_with_stdio(0);
  cin >> s;
  cin >> t >> k;
  for (auto c : s) {
    SAM.insert(c - 'a');
  }
  if (!t) {
    for (int i = 1; i <= SAM.cnt; i++) {
      SAM.siz[i] = 1;
    }
  } else {
    SAM.build();
    SAM.df5(1);
  }
  SAM.siz[1] = 0;
  SAM.dfs(1);
  if (SAM.sum[1] < k) {
    puts("-1");
    return 0;
  }
  SAM.print(1, k);
  return 0;
}