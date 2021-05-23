#include <bits/stdc++.h>
using namespace std;
int n, pos[10000];
int main() {
  freopen("circle.in", "r", stdin);
  freopen("circle.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    pos[i] = n - i + 2;
    if (pos[i] > n) pos[i] -= n;
  }
  vector<pair<int, pair<int, int>>> v;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (pos[j] > j) {
        v.push_back(make_pair(i, make_pair(j, pos[j])));
      }
      pos[j]--;
      if (!pos[j]) pos[j] = n;
    }
  }
  cout << "Yes" << endl << v.size() << endl;
  for (auto pr : v) {
    cout << pr.first << " " << pr.second.first << " " << pr.second.second
         << endl;
  }
  return 0;
}