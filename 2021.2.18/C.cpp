// Problem: C. K-beautiful Strings
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define f(x) (x % k == 0 ? 0 : k - x % k)
using namespace std;
int sum[1000000][26];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (s.length() % k != 0) {
      puts("-1");
      continue;
    }
    s = "$" + s;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < 26; j++) {
        sum[i][j] = sum[i - 1][j] + (s[i] - 'a' == j);
      }
    bool flag = 1;
    for (int j = 0; j < 26; j++) {
      flag &= (sum[n][j] % k == 0);
    }
    if (flag) {
      for (int i = 1; i <= n; i++) {
        cout << s[i];
      }
      cout << endl;
      continue;
    }
    for (int i = n - 1; i >= 0; i--) {
      int v = 0, mx = -1, tmp[26];
      for (int j = 0; j < 26; j++) {
        tmp[j] = f(sum[i][j]);
        v += tmp[j];
      }
      // cout << i << " " << v << " " << n - i << endl;
      if (v <= n - i) {
        // cout << ">" << ((n - i) - v) % 3 << endl;
        if (((n - i) - v) % k != 0) continue;
        if (s[i + 1] == 'z') continue;
        // cout << "OK" << endl;
        if (((n - i) - v) / k && tmp[s[i + 1] - 'a' + 1] == 0) {
          tmp[s[i + 1] - 'a' + 1] += k;
          v += k;
        }
        tmp[0] += (n - i) - v;
        v = n - i;
        int pos = -1;
        for (int j = s[i + 1] - 'a' + 1; j < 26; j++) {
          if (tmp[j]) {
            tmp[j]--;
            pos = j;
            break;
          }
        }
        // cout << pos << endl;
        if (pos == -1) continue;
        // puts("out");
        for (int j = 1; j <= i; j++) cout << s[j];
        cout << char(pos + 'a');
        for (int j = 0; j < 26; j++) {
          for (int k = 1; k <= tmp[j]; k++) {
            cout << char(j + 'a');
          }
        }
        cout << endl;
        break;
      }
    }
  }
  return 0;
}