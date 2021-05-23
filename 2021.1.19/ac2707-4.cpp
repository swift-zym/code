#include <bits/stdc++.h>
#define N 400
#define M 500
using namespace std;
int T, n, m, X[N + 1], Y[N + 1], power[N + 1], x[M + 1], y[M + 1], limit[M + 1],
    price[M + 1], r[M + 1], finished[M + 1];
bool check(int a, int b) {
  return r[b] * r[b] >=
         (x[a] - X[b]) * (x[a] - X[b]) + (y[a] - Y[b]) * (y[a] - Y[b]);
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &X[i], &Y[i], &power[i]);
    for (int i = 1; i <= m; i++)
      scanf("%d%d%d%d%d%d", &x[i], &y[i], &limit[i], &price[i], &r[i],
            &finished[i]);
  }
  return 0;
}