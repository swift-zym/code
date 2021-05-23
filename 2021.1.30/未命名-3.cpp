#include <bits/stdc++.h>
using namespace std;
int n, v[1000000], tmp;
vector<int> g[1000000];
int dfs(int now, int fa) {
  int sum = v[now] < 0, num = 0;
  for (auto to : g[now]) {
    if (to == fa) continue;
    num++;
    sum += dfs(to, now);
  }
  if (!num && sum) tmp -= sum;
  if (v[now] >= 0 && sum) sum++;
  return sum;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cout << dfs(1, 1) + tmp << endl;
  return 0;
}