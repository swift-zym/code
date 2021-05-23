
// Problem: E. DZY Loves Planting
// Contest: Codeforces - Codeforces Round #254 (Div. 1)
// URL: https://codeforces.com/contest/444/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, w;
  bool operator<(const edge &e) const { return w < e.w; }
};
vector<edge> v;
int n, x[4000], siz[4000], f[4000], sum;
int gf(int now) { return f[now] == now ? now : f[now] = gf(f[now]); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    v.push_back({a, b, c});
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    siz[i] = 1;
    f[i] = i;
    sum += x[i];
  }
  for (int i = 0; i < v.size(); i++) {
    int a = gf(v[i].u), b = gf(v[i].v);
    f[b] = a;
    x[a] += x[b];
    siz[a] += siz[b];
    if (siz[a] > sum - x[a]) {
      printf("%d\n", v[i].w);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}