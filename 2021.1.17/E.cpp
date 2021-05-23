
// Problem: E. Fox And Polygon
// Contest: Codeforces - Codeforces Round #290 (Div. 1)
// URL: https://codeforces.com/problemset/problem/512/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<int, int>, bool> mp;
vector<int> v;
vector<pair<int, int>> ans[2];
void init() {
  mp.clear();
  v.clear();
  for (int i = 1; i <= n; i++) {
    int nxt = i == n ? 1 : i + 1;
    mp[make_pair(i, nxt)] = 1;
    mp[make_pair(nxt, i)] = 1;
  }
  v.push_back(2);
  v.push_back(n);
}
void solve(int x, int y, int idx) {
  for (int i = 2; i <= n; i++) {
    if (mp[make_pair(x, i)] && mp[make_pair(y, i)]) {
      mp[make_pair(x, y)] = 0;
      mp[make_pair(y, x)] = 0;
      mp[make_pair(1, i)] = 1;
      mp[make_pair(i, 1)] = 1;
      v.push_back(i);
      if (idx == 0)
        ans[0].push_back(make_pair(x, y));
      else
        ans[1].push_back(make_pair(1, i));
      return;
    }
  }
}
void exec(int idx) {
  init();
  for (int i = 1; i <= n - 3; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    mp[make_pair(a, b)] = 1;
    mp[make_pair(b, a)] = 1;
    if (a == 1) v.push_back(b);
    if (b == 1) v.push_back(a);
  }
  sort(v.begin(), v.end());
  while (v.size() < n - 1) {
    sort(v.begin(), v.end());
    int cur = v.size();
    for (int i = 1; i < cur; i++) {
      if (v[i] - v[i - 1] > 1) {
        solve(v[i], v[i - 1], idx);
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  exec(0);
  exec(1);
  reverse(ans[1].begin(), ans[1].end());
  printf("%d\n", (int)(ans[0].size() + ans[1].size()));
  for (auto p : ans[0]) {
    printf("%d %d\n", p.first, p.second);
  }
  for (auto p : ans[1]) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}