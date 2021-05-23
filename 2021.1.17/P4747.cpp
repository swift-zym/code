// Problem: P4747 [CERC2017]Intrinsic Interval
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4747
// Memory Limit: 500 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define N 200000
using namespace std;
int n, m, rt, tot, a[N], mx[N][20], mi[N][20], v[N << 2], tag[N << 2], l[N],
    r[N], tmp[N], type[N], f[N][20], dep[N];
void pushup(int x) { v[x] = min(v[x * 2], v[x * 2 + 1]); }
void pushdown(int x) {
  v[x * 2] += tag[x];
  v[x * 2 + 1] += tag[x];
  tag[x * 2] += tag[x];
  tag[x * 2 + 1] += tag[x];
  tag[x] = 0;
}
int query_max(int l, int r) {
  int k = log2(r - l + 1);
  return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
int query_min(int l, int r) {
  int k = log2(r - l + 1);
  return min(mi[l][k], mi[r - (1 << k) + 1][k]);
}
int query(int x, int l, int r) {
  if (l == r) return l;
  pushdown(x);
  int mid = (l + r) / 2;
  if (!v[x * 2])
    return query(x * 2, l, mid);
  else
    return query(x * 2 + 1, mid + 1, r);
}
int bl[N];
void add(int x, int l, int r, int L, int R, int val) {
  if (L > R) return;
  if (l == L && r == R) {
    v[x] += val;
    tag[x] += val;
    return;
  }
  pushdown(x);
  int mid = (l + r) / 2;
  if (R <= mid)
    add(x * 2, l, mid, L, R, val);
  else if (L > mid)
    add(x * 2 + 1, mid + 1, r, L, R, val);
  else
    add(x * 2, l, mid, L, mid, val),
        add(x * 2 + 1, mid + 1, r, mid + 1, R, val);
  pushup(x);
}
int check(int l, int r) { return query_max(l, r) - query_min(l, r) == r - l; }
template <class T>
struct Stack {
  vector<T> data;
  void push(T x) { data.push_back(x); }
  void pop() { data.pop_back(); }
  T top() { return data.back(); }
  T second() { return data[data.size() - 2]; }
  bool empty() { return data.size() == 0; }
  int size() { return data.size(); }
  void print() {
    puts("---");
    for (auto v : data) {
      cout << v << " ";
    }
    cout << endl;
    puts("---");
  }
};
Stack<pair<int, int>> s[2];
Stack<int> st;
vector<int> g[N];
void build() {
  for (int i = 1; i <= n; i++) {
    // cout << i << endl;
    while (!s[0].empty() && a[i] <= s[0].top().second) {
      add(1, 1, n, s[0].size() == 1 ? 1 : s[0].second().first + 1,
          s[0].top().first, s[0].top().second);
      s[0].pop();
    }
    while (!s[1].empty() && a[i] >= s[1].top().second) {
      add(1, 1, n, s[1].size() == 1 ? 1 : s[1].second().first + 1,
          s[1].top().first, -s[1].top().second);
      s[1].pop();
    }
    add(1, 1, n, s[0].empty() ? 1 : s[0].top().first + 1, i, -a[i]);
    add(1, 1, n, s[1].empty() ? 1 : s[1].top().first + 1, i, a[i]);
    s[0].push(make_pair(i, a[i]));
    s[1].push(make_pair(i, a[i]));
    int idx = query(1, 1, n);
    l[i] = r[i] = tmp[i] = i;
    int now = i;
    // st.print();
    while (!st.empty() && l[st.top()] >= idx) {
      if (type[st.top()] && check(tmp[st.top()], r[now])) {
        g[st.top()].push_back(now);
        r[st.top()] = r[now];
        tmp[st.top()] = l[now];
        now = st.top();
        st.pop();
      } else if (check(l[st.top()], r[now])) {
        tot++;
        l[tot] = l[st.top()];
        r[tot] = r[now];
        tmp[tot] = l[now];
        type[tot] = 1;
        g[tot].push_back(st.top());
        g[tot].push_back(now);
        now = tot;
        st.pop();
      } else {
        tot++;
        g[tot].push_back(now);
        r[tot] = r[now];
        while (!check(l[st.top()], r[now])) {
          g[tot].push_back(st.top());
          st.pop();
        }
        g[tot].push_back(st.top());
        l[tot] = l[st.top()];
        st.pop();
        now = tot;
      }
    }
    st.push(now);
    add(1, 1, n, 1, i, -1);
  }
  // cout << "OK!" << endl;
  rt = st.top();
  // cout << rt << endl;
}
void print(int x, int d = 1) {
  cout << x << "(" << l[x] << "," << r[x] << ")" << endl;
  for (auto to : g[x]) {
    for (int i = 1; i <= d; i++) putchar('-');
    print(to, d + 1);
  }
}
void dfs(int x) {
  for (auto to : g[x]) {
    f[to][0] = x;
    dep[to] = dep[x] + 1;
    for (int i = 1; i < 20; i++) {
      f[to][i] = f[f[to][i - 1]][i - 1];
    }
    dfs(to);
  }
}
int gf(int x, int d) {
  for (int i = 19; i >= 0; i--) {
    if (d & (1 << i)) {
      x = f[x][i];
    }
  }
  return x;
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 19; i >= 0; i--) {
    if (dep[f[x][i]] >= dep[y]) {
      x = f[x][i];
    }
  }
  if (x == y) return x;
  for (int i = 19; i >= 0; i--) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  }
  return f[x][0];
}
int main() {
  scanf("%d", &n);
  tot = n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) mi[i][0] = mx[i][0] = a[i];
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      mi[j][i] = min(mi[j][i - 1], mi[min(j + (1 << (i - 1)), n)][i - 1]);
      mx[j][i] = max(mx[j][i - 1], mx[min(j + (1 << (i - 1)), n)][i - 1]);
    }
  }
  build();
  // print(rt);
  f[rt][0] = rt;
  dfs(rt);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int L, R;
    scanf("%d%d", &L, &R);
    int x = lca(L, R);
    if (type[x]) {
      printf("%d %d\n", l[gf(L, dep[L] - dep[x] - 1)],
             r[gf(R, dep[R] - dep[x] - 1)]);
    } else {
      printf("%d %d\n", l[x], r[x]);
    }
  }
  return 0;
}