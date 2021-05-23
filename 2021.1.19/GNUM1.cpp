#include <bits/stdc++.h>
#define N 10000000
#define inf 1000000000
using namespace std;
vector<int> prime;
int n, cnt, s, t, tot, head[N], nxt[N], to[N], len[N], cur[N], dep[N], a[500],
    b[500];
void clear() {
  cnt = 1;
  memset(head, 0, sizeof(head));
}
void add(int a, int b, int l, bool _rev = false) {
  // if (!_rev) cout << a << " " << b << " " << l << endl;
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, true);
}
bool bfs() {
  for (int i = 0; i <= tot; i++) {
    dep[i] = inf;
    cur[i] = head[i];
  }
  dep[2000000] = inf;
  cur[2000000] = head[2000000];
  queue<int> q;
  dep[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if (now == t) return 1;
    for (int i = head[now]; i; i = nxt[i]) {
      if (len[i] && dep[to[i]] == inf) {
        dep[to[i]] = dep[now] + 1;
        q.push(to[i]);
      }
    }
  }
  return 0;
}
int dfs(int now, int flow) {
  if (now == t) return flow;
  int use = 0;
  for (int i = cur[now]; i && flow; i = nxt[i]) {
    cur[now] = i;
    if (len[i] && dep[to[i]] == dep[now] + 1) {
      int v = dfs(to[i], min(flow, len[i]));
      len[i] -= v;
      len[i ^ 1] += v;
      flow -= v;
      use += v;
    }
  }
  return use;
}
vector<int> p, q;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int np[200000];
unordered_map<int, int> mp;
vector<int> f(int x) {
  vector<int> ret;
  for (int i = 0; i < prime.size() && prime[i] * prime[i] <= x; i++) {
    if (x % prime[i] == 0) {
      ret.push_back(prime[i]);
      while (x % prime[i] == 0) x /= prime[i];
    }
  }
  if (x > 1) ret.push_back(x);
  return ret;
}
int main() {
  np[1] = 1;
  for (int i = 2; i <= 34000; i++) {
    if (!np[i]) {
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() & i * prime[j] <= 34000; j++) {
      np[i * prime[j]] = 1;
      if (!i % prime[j]) break;
    }
  }
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    clear();
    p.clear();
    q.clear();
    mp.clear();
    t = 2000000;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        int v;
        if (b[j] > a[i] && (v = gcd(a[i], b[j])) != 1) {
          p.push_back(v);
        }
        if (b[i] < a[j] && (v = gcd(a[j], b[i])) != 1) {
          q.push_back(v);
        }
      }
    unordered_map<int, int> num[2];
    for (auto x : p) num[0][x]++;
    for (auto x : q) num[1][x]++;
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    tot = p.size() + q.size();
    for (int i = 0; i < p.size(); i++) {
      add(s, i + 1, num[0][p[i]]);
      vector<int> tmp = f(p[i]);
      assert(tmp.size() <= 9);
      for (auto x : tmp) {
        if (!mp.count(x)) {
          mp[x] = ++tot;
        }
        add(i + 1, mp[x], inf);
      }
    }
    for (int i = 0; i < q.size(); i++) {
      add(p.size() + i + 1, t, num[1][q[i]]);
      vector<int> tmp = f(q[i]);
      for (auto x : tmp) {
        if (!mp.count(x)) {
          mp[x] = ++tot;
        }
        add(mp[x], p.size() + i + 1, inf);
      }
    }
    int ans = 0;
    while (bfs()) {
      ans += dfs(s, inf);
    }
    cout << ans << endl;
  }
  return 0;
}