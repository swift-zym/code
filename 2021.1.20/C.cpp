// Problem: C. Going Home
// Contest: Codeforces - Codeforces Round #707 (Div. 2, based on Moscow Open
// Olympiad in Informatics) URL: https://codeforces.com/contest/1501/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n, a[1000000];
vector<pair<int, int>> v[10000000];
bool cmp(int a, int b, int c, int d) {
  if (a == d || a == c || a == b || b == d || b == c || c == d) return 1;
  return 0;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (v[a[i] + a[j]].size() &&
          !cmp(i, j, v[a[i] + a[j]][0].first, v[a[i] + a[j]][0].second)) {
        puts("YES");
        cout << i << " " << j << " " << v[a[i] + a[j]][0].first << " "
             << v[a[i] + a[j]][0].second << endl;
        return 0;
      }
      v[a[i] + a[j]].push_back(make_pair(i, j));
    }
  puts("NO");
  return 0;
}