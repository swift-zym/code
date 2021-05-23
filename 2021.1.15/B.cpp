#include <bits/stdc++.h>
using namespace std;
int n, a[501], ans;
vector<int> add(vector<int> v, int l, int r, int val) {
  for (int i = l; i <= r; i++) v[i] = (v[i] + val) % 7;
  vector<int> tmp;
  for (int i = 0; i < v.size(); i++) {
    if (i && v[i] == v[i - 1]) continue;
    tmp.push_back(v[i]);
  }
  return tmp;
}
vector<int> v;
void file() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
}
int main() {
  // file();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i != 1 && a[i] == a[i - 1]) continue;
    v.push_back(a[i]);
  }
  while (v.size()) {
    int mi = INT_MAX, l, r;
    for (int i = 0; i < v.size(); i++) {
      while (i < v.size() && !v[i]) i++;
      if (!v[i]) continue;
      int val = 7 - v[i];
      for (int j = i; j < v.size(); j++) {
        auto tmp = add(v, i, j, val);
        if (tmp.size() <= mi) {
          mi = tmp.size();
          l = i;
          r = j;
        }
      }
    }
    if (mi == INT_MAX) break;
    v = add(v, l, r, 7 - v[l]);
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
