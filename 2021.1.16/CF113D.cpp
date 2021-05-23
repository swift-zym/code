
// Problem: CF113D Museum
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF113D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(s)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
struct matrix {
  int s;
  double v[254][254] = {0};
  matrix operator*(const matrix &t) const {
    matrix a;
    a.s = s;
    for (int i = 1; i <= s; i++)
      for (int j = 1; j <= s; j++)
        for (int k = 1; k <= s; k++) {
          a.v[i][j] += v[i][k] * t.v[k][j];
        }
    return a;
  }
} a;
int n, m, s, t;
double p[30];
vector<int> v[100];
int encode(int x, int y) {
  if (x > y) swap(x, y);
  return y * (y - 1) / 2 + x;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  memset(a.v, 0, sizeof(a.v));
  for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
  for (int i = 1; i <= n; i++) {
    a.v[encode(i, i)][encode(i, i)] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      a.v[encode(i, j)][encode(i, j)] += p[i] * p[j];
      for (auto to : v[i]) {
        a.v[encode(i, j)][encode(to, j)] += (1.0 - p[i]) / v[i].size() * p[j];
        for (auto too : v[j]) {
          a.v[encode(i, j)][encode(to, too)] +=
              (1.0 - p[i]) / v[i].size() * (1.0 - p[j]) / v[j].size();
        }
      }
      for (auto to : v[j]) {
        a.v[encode(i, j)][encode(i, to)] += (1.0 - p[j]) / v[j].size() * p[i];
      }
    }
  a.s = n * (n + 1) / 2;
  for (int i = 1; i <= 30; i++) a = a * a;
  for (int i = 1; i <= n; i++) {
    printf("%0.10lf ", a.v[encode(s, t)][encode(i, i)]);
  }
  puts("");
  return 0;
}