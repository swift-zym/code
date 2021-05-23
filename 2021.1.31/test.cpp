#include <bits/stdc++.h>
using namespace std;
int n, ans, cur, c[300001], a[300001];
void del(int x) { cur -= (--c[x] == 0); }
void add(int x) { cur += (c[x]++ == 0); }
vector<int> v[300001];
void dfs(int now, int fa) {
  add(a[now]);
  ans += cur;
  for (auto to : v[now]) {
    if (to == fa) continue;
    dfs(to, now);
  }
  del(a[now]);
}
void file() {
  freopen("mushroom.in", "r", stdin);
  freopen("mushroom.out", "w", stdout);
}
int main() {
  file();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    ans = 0;
    dfs(i, i);
    cout << ans << endl;
  }
  return 0;
}