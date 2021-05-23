#include <bits/stdc++.h>
#define ls x * 2
#define rs x * 2 + 1
#define mid ((l + r) >> 1)
using namespace std;
int T, k, m, a[2000000], dp[2000000];
vector<int> v[2000000];
void dfs(int x, int l, int r) {
  if (l == r) {
    v[x].push_back(a[l]);
    return;
  }
  dfs(ls, l, mid);
  dfs(rs, mid + 1, r);
  int i, j;
  for (int k = 0; k < v[ls].size(); k++) {
    if (v[ls][k] + m >= v[rs][0]) {
      i = k;
      break;
    }
  }
  for (int k = 0; k < v[rs].size(); k++) {
    if (v[rs][k] + m >= v[ls][0]) {
      j = k;
      break;
    }
  }
  while (i < v[ls].size() && j < v[rs].size()) {
    if (v[ls][i] <= v[rs][j]) {
      v[x].push_back(v[ls][i++]);
    } else {
      v[x].push_back(v[rs][j++]);
    }
  }
  while (i < v[ls].size()) v[x].push_back(v[ls][i++]);
  while (j < v[rs].size()) v[x].push_back(v[rs][j++]);
}

void df5(int x, int l, int r) {
  if (l == r) {
    dp[x] = a[l];
    return;
  }
  df5(ls, l, mid);
  df5(rs, mid + 1, r);
  int mi = min(dp[ls], dp[rs]), mx = max(dp[ls], dp[rs]);
  if (mx - mi <= m) {
    dp[x] = mi;
    return;
  }
  if (dp[ls] < dp[rs]) {
    if (lower_bound(v[ls].begin(), v[ls].end(), dp[rs] - m) != v[ls].end()) {
      dp[x] = *lower_bound(v[ls].begin(), v[ls].end(), dp[rs] - m);
    } else {
      dp[x] = mx;
    }
  } else {
    if (lower_bound(v[rs].begin(), v[rs].end(), dp[ls] - m) != v[rs].end()) {
      dp[x] = *lower_bound(v[rs].begin(), v[rs].end(), dp[ls] - m);
    } else {
      dp[x] = mx;
    }
  }
}
bool check() {
  int x = 1;
  while ((x << 1) < ((1 << k) << 1)) {
    if (dp[rs] > a[1] + m) return 0;
    x <<= 1;
  }
  return 1;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &k, &m);
    for (int i = 1; i <= (1 << k); i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i < (1 << (k + 1)); i++) {
      v[i].clear();
    }
    dfs(1, 1, (1 << k));
    df5(1, 1, (1 << k));
    printf("%s\n", check() ? "Kotori" : "Yoshino");
  }
  return 0;
}