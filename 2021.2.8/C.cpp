#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 200
using namespace std;
int qpow(int a, int b) {
  if (!b) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
namespace gauss {
int a[N][N];
void init() { memset(a, 0, sizeof(a)); }
void solve(int n) {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n + 1; j++) {
      a[i][j] = (a[i][j] + MOD) % MOD;
    }
  for (int i = 0; i <= n; i++) {
    int mx = i;
    for (int j = i + 1; j <= n; j++) {
      if (abs(a[j][i]) > abs(a[mx][i])) mx = j;
    }
    swap(a[mx], a[i]);
    for (int j = 0; j <= n; j++) {
      if (i == j) continue;
      int tmp = a[j][i] * qpow(a[i][i], MOD - 2) % MOD;
      for (int k = i + 1; k <= n + 1; k++) {
        a[j][k] -= a[i][k] * tmp % MOD;
        a[j][k] = (a[j][k] + MOD) % MOD;
      }
    }
  }
  for (int i = 0; i <= n; i++)
    a[i][n + 1] *= qpow(a[i][i], MOD - 2), a[i][n + 1] %= MOD;
}
}  // namespace gauss
namespace AC {
int tot, ch[N][26], fail[N], ed[N];
void init() {
  memset(ch, 0, sizeof(ch));
  memset(fail, 0, sizeof(fail));
  memset(ed, 0, sizeof(ed));
  tot = 0;
}
void insert(string s) {
  int now = 0;
  for (auto c : s) {
    if (!ch[now][c - 'a']) {
      ch[now][c - 'a'] = ++tot;
    }
    now = ch[now][c - 'a'];
  }
  ed[now] = 1;
}
void build() {
  queue<int> q;
  for (int i = 0; i <= 25; i++) {
    if (ch[0][i]) q.push(ch[0][i]);
  }
  while (!q.empty()) {
    int now = q.front();
    ed[now] |= ed[fail[now]];
    q.pop();
    for (int i = 0; i <= 25; i++) {
      if (ch[now][i]) {
        fail[ch[now][i]] = ch[fail[now]][i];
        q.push(ch[now][i]);
      } else {
        ch[now][i] = ch[fail[now]][i];
      }
    }
  }
}
int dp() {
  for (int i = 0; i <= tot; i++) {
    if (ed[i]) {
      gauss::a[i][i] = 1;
      gauss::a[i][tot + 1] = 0;
      continue;
    }
    gauss::a[i][i] = 26;
    gauss::a[i][tot + 1] = 26;
    for (int j = 0; j <= 25; j++) {
      gauss::a[i][ch[i][j]]--;
    }
  }
  /*for (int i = 0; i <= tot; i++) {
    for (int j = 0; j <= tot + 1; j++) {
      cout << gauss::a[i][j] << " ";
    }
    cout << endl;
  }*/
  gauss::solve(tot);
  return gauss::a[0][tot + 1];
}
}  // namespace AC
void file() {
  freopen("substring.in", "r", stdin);
  freopen("substring.out", "w", stdout);
}
signed main() {
  file();
  int T;
  cin >> T;
  while (T--) {
    gauss::init();
    AC::init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      AC::insert(s);
    }
    AC::build();
    cout << AC::dp() << endl;
  }
}