
// Problem: CF113D Museum
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF113D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
struct matrix {
  int s;
  double v[500][500];
  matrix operator*(const matrix &t) const {
    matrix a;
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
  if (x > y)
    ;
  swap(x, y);
  return y * (n - 1) + x;
}
int main() {
  scanf("%d%d", &n, &m, &s, &t);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
  for (int i = 1; i <= n; i++) {
    a.v[encode(i, i)][encode(i, i)] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      a.v[encode(i, j)][encode(i, j)] = p[i] * p[j];
      for (auto to : v[i]) {
        a.v[encode(i, j)][encode(to, j)] = (1.0 - p[i]) / v[i].size() * p[j];
        for (auto too : v[j]) {
          a.v[encode(i, j)][encode(to, too)] =
              (1.0 - p[i]) / v[i].size() * (1.0 - p[j]) / v[j].size();
        }
      }
      for (auto to : v[j]) {
        a.v[encode(i, j)][encode(i, to)] = (1.0 - p[j]) / v[j].size() * p[i];
      }
    }
  a.s = n * n;
  for (int i = 1; i <= 30; i++) a = a * a;
  for (int i = 1; i <= n; i++) {
    printf("%0.10lf ", a.v[encode(s, t)])
  }
  puts("");
  return 0;
}
