#include <bits/stdc++.h>
using namespace std;
int n, v[1000], a[1000], b[1000], vis[1000], ans;
void file() {
  freopen("sequence.in", "r", stdin);
  freopen("sequence.out", "w", stdout);
}
int main() {
  // file();
  srand(time(0));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int _ = 1; _ <= 5000; _++) {
    memcpy(b, a, sizeof(a));
    memset(vis, 0, sizeof(vis));
    int cur = 0;
    for (;;) {
      vector<int> tmp;
      for (int i = 1; i <= n; i++) {
        if (!vis[i]) tmp.push_back(i);
      }
      if (!tmp.size()) break;
      int st = tmp[rand() % tmp.size()];
      int lst = a[st], pre = -1;
      tmp.clear();
      tmp.push_back(st);
      if (st != n) {
        for (int j = st + 1; j <= n; j++) {
          if (vis[j]) continue;
          if (abs(a[j] - lst) != 1) break;
          if (pre != -1 && pre > lst && a[j] > lst) break;
          pre = lst;
          lst = a[j];
          tmp.push_back(j);
        }
      }
      // int pos = rand() % tmp.size();
      int pos = tmp.size() - 1;
      cur += v[pos + 1];
      ans = max(ans, cur);
      for (int i = st; i <= tmp[pos]; i++) vis[i] = 1;
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}