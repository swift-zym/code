#include <bits/stdc++.h>
#define inf 10000000
using namespace std;
int T, n, cnt, s, t;
string str[2];
int head[200001], cur[200001], nxt[10000000], to[10000000], len[10000000],
    deep[10000000];
void clear() {
  cnt = 1;
  memset(head, 0, sizeof(head));
}
void add(int a, int b, int l, int _rev = 1) {
  if (_rev) add(b, a, 0, 0);
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
}
bool bfs() {
  for (int i = s; i <= t; i++) deep[i] = inf, cur[i] = head[i];
  deep[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int now = q.front();
    if (now == t) return 1;
    q.pop();
    for (int i = head[now]; i; i = nxt[i]) {
      if (deep[to[i]] == inf && len[i]) {
        deep[to[i]] = deep[now] + 1;
        q.push(to[i]);
      }
    }
  }
  return 0;
}
int dfs(int now, int flow) {
  int use = 0;
  if (now == t) return flow;
  for (int i = cur[now]; i && flow; i = nxt[i]) {
    cur[now] = i;
    if (deep[to[i]] == deep[now] + 1 && len[i]) {
      int v = dfs(to[i], min(flow, len[i]));
      if (!v) deep[to[i]] = inf;
      len[i] -= v;
      len[i ^ 1] += v;
      flow -= v;
      use += v;
    }
  }
  return use;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> str[0] >> str[1];
    str[0] = "$" + str[0];
    str[1] = "$" + str[1];
    clear();
    s = 0;
    t = 2 * n + 1;
    int tot = 0;
    for (int i = 0; i <= 1; i++)
      for (int j = 1; j <= n; j++) {
        if (str[i][j] == '1')
          tot++, add(s, i * n + j, 1);
        else
          add(i * n + j, t, 1);
      }
    for (int i = 0; i <= 1; i++)
      for (int j = 1; j <= n; j++) {
        if (str[i][j] != '1') continue;
        if (i && str[i - 1][j] == '0') {
          add(n + j, j, 1);
        }
        if (!i && str[i + 1][j] == '0') {
          add(j, n + j, 1);
        }
        if (j != 1 && str[i][j - 1] == '0') {
          add(i * n + j, i * n + j - 1, 1);
        }
        if (j != n && str[i][j + 1] == '0') {
          add(i * n + j, i * n + j + 1, 1);
        }
      }
    int ans = 0;
    while (bfs()) {
      ans += dfs(s, inf);
    }
    puts((ans == tot) ? "RP" : "++");
  }
  return 0;
}