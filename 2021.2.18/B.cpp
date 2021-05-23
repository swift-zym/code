// Problem: B. Planet Lapituletti
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int T, mp[10];
bool check(int h, int m, int mxh, int mxm) {
  int v1 = h / 10, v2 = h % 10, v3 = m / 10, v4 = m % 10;
  // cout << v1 << " " << v2 << " " << v3 << " " << v4 << endl;
  if (mp[v1] == -1 || mp[v2] == -1 || mp[v3] == -1 || mp[v4] == -1) return 0;
  v1 = mp[v1], v2 = mp[v2], v3 = mp[v3], v4 = mp[v4];
  h = v4 * 10 + v3;
  m = v2 * 10 + v1;
  if (h >= mxh || m >= mxm) return 0;
  return 1;
}
int main() {
  mp[0] = 0, mp[1] = 1, mp[2] = 5, mp[3] = -1, mp[4] = -1, mp[5] = 2,
  mp[6] = -1, mp[7] = -1, mp[8] = 8, mp[9] = -1;
  scanf("%d", &T);
  while (T--) {
    int h, m, sh, sm;
    scanf("%d%d", &h, &m);
    scanf("%d:%d", &sh, &sm);
    while (!check(sh, sm, h, m)) {
      sm++;
      if (sm == m) {
        sm = 0;
        sh++;
        if (sh == h) {
          sh = 0;
        }
      }
    }
    printf("%02d:%02d\n", sh, sm);
  }
  return 0;
}