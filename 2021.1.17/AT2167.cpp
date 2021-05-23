
// Problem: AT2167 [AGC006F] Blackout
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT2167
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans;
vector<pair<int, int>> v[100000 + 1];
vector<int> col, num;
bool dfs(int x) {
  num[col[x]]++;
  bool flag = true;
  for (auto par : v[x]) {
    int to = par.first, len = par.second;
    if (len == 1) num[3]++;
    if (col[to] == -1) {
      col[to] = (col[x] + len + 3) % 3;
      flag &= dfs(to);
    } else {
      flag &= (col[to] == (col[x] + len + 3) % 3);
    }
  }
  return flag;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(make_pair(b, 1));
    v[b].push_back(make_pair(a, -1));
  }
  col.assign(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    if (col[i] != -1) continue;
    col[i] = 1;
    num.assign(4, 0);
    if (!dfs(i)) {
      ans += (num[0] + num[1] + num[2]) * (num[0] + num[1] + num[2]);
    } else if ((!num[0]) || (!num[1]) || (!num[2])) {
      ans += num[3];
    } else {
      ans += num[0] * num[1] + num[1] * num[2] + num[2] * num[0];
    }
  }
  cout << ans << endl;
  return 0;
}