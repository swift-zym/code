#pragma GCC optimize("Ofast")
// Problem: P5366 [SNOI2017]遗失的答案
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5366
// Memory Limit: 500 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, g, l, q, dp[2][1000][1 << 16];
vector<int> v;
vector<pair<int, int> > pr, group;
map<int, int> mp, rec, ans;
int qpow(int a, int b) {
  if (!b) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? 1ll * tmp * tmp % MOD * a % MOD : 1ll * tmp * tmp % MOD;
}
void fwt(int *a, int len, int f = 1) {
  for (int l = 1; l < len; l <<= 1)
    for (int s = 0; s < len; s += (l << 1))
      for (int j = 0; j < l; j++) {
        if (f == 1) {
          a[s + l + j] = (a[s + l + j] + a[s + j]) % MOD;
        } else {
          a[s + l + j] = (a[s + l + j] - a[s + j] + MOD) % MOD;
        }
      }
}
string decode(int mask) {
  string sol = "";
  for (int i = pr.size() * 2 - 1; i >= 0; i--) {
    if (mask & (1 << i))
      sol += "1";
    else
      sol += "0";
  }
  return sol;
}
signed main() {
  scanf("%d%d%d%d", &n, &g, &l, &q);
  if (l % g) {
    while (q--) puts("0");
    return 0;
  }
  l /= g;
  n /= g;
  for (int i = 1; i <= sqrt(l) && i <= n; i++) {
    if (l % i == 0) {
      v.push_back(i);
      if (i * i != l && l / i <= n) v.push_back(l / i);
    }
  }
  int x = l;
  for (int i = 2; i <= sqrt(l); i++) {
    int cnt = 0;
    while (x % i == 0) {
      x /= i;
      cnt++;
    }
    if (cnt) {
      pr.push_back(make_pair(i, cnt));
    }
  }
  if (x != 1) {
    pr.push_back(make_pair(x, 1));
  }
  for (auto x : v) {
    int mask = 0, bk = x;
    for (int i = 0; i < pr.size(); i++) {
      int cnt = 0;
      while (x % pr[i].first == 0) {
        cnt++;
        x /= pr[i].first;
      }
      if (!cnt) {
        mask |= (1 << i);
      }
      if (cnt == pr[i].second) {
        mask |= (1 << (i + pr.size()));
      }
    }
    mp[mask]++;
    rec[bk] = mask;
  }
  for (auto x : mp) {
    group.push_back(make_pair(x.first, qpow(2, x.second) - 1));
  }
  sort(group.begin(), group.end());
  dp[0][0][0] = dp[1][group.size()][0] = 1;
  int limit = (1 << (pr.size() << 1));
  int siz = group.size();
  for (int i = 0; i < siz; i++) {
    for (int j = 0; j < limit; j++) {
      dp[0][i + 1][j] = (dp[0][i + 1][j] + dp[0][i][j]) % MOD;
      dp[0][i + 1][j | group[i].first] = (dp[0][i + 1][j | group[i].first] +
                                          1ll * dp[0][i][j] * group[i].second) %
                                         MOD;
    }
  }
  for (int i = siz; i; i--) {
    for (int j = 0; j < limit; j++) {
      dp[1][i - 1][j] = (dp[1][i - 1][j] + dp[1][i][j]) % MOD;
      dp[1][i - 1][j | group[i - 1].first] =
          (dp[1][i - 1][j | group[i - 1].first] +
           1ll * dp[1][i][j] * group[i - 1].second) %
          MOD;
    }
  }
  /*for (auto p : group) {
    cout << decode(p.first) << endl;
  }*/
  for (int i = 0; i <= siz; i++) {
    fwt(dp[0][i], limit);
    fwt(dp[1][i], limit);
  }
  for (int i = 0; i < siz; i++) {
    for (int j = 0; j < limit; j++) {
      dp[0][i][j] = (1ll * dp[0][i][j] * dp[1][i + 1][j]) % MOD;
    }
    /*cout << "::" << i << endl;
    cout << ":l0" << endl;
    for (int j = 0; j < limit; j++) {
      cout << decode(j) << " " << dp[0][i][j] << endl;
    }
    cout << ":l1" << endl;
    for (int j = 0; j < limit; j++) {
      cout << decode(j) << " " << dp[1][i + 1][j] << endl;
    }*/
  }
  for (int i = 0; i <= siz; i++) {
    fwt(dp[0][i], limit, -1);
  }

  for (int i = 0; i < siz; i++) {
    int tmp = 0;
    for (int j = 0; j < limit; j++) {
      if ((j | group[i].first) == (limit - 1)) {
        tmp = (tmp + 1ll * dp[0][i][j] * (group[i].second + 1) % MOD *
                         ((MOD + 1) >> 1)) %
              MOD;
      }
    }
    ans[group[i].first] = tmp;
    // cout << decode(group[i].first) << " " << tmp << endl;
  }
  while (q--) {
    scanf("%d", &x);
    if (x % g != 0) {
      puts("0");
      continue;
    }
    x /= g;
    if (l % x != 0 || x > n) {
      puts("0");
      continue;
    }
    // cout << x << " " << decode(rec[x]) << endl;
    printf("%d\n", ans[rec[x]] % MOD);
  }
  return 0;
}
/*
2 001110
3 010101
5 100011
6 011100
10 101010
15 110001
*/