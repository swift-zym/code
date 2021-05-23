// Problem: P5504 [JSOI2011] 柠檬
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5504
// Memory Limit: 128 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define N 200000
#define int long long
int n, dp[N], c[N], s[N], num[N];
#define y(i) (dp[i - 1] + s[i] * c[i] * c[i] - 2 * s[i] * c[i])
#define k(i) (s[i] * c[i])
#define x(i) (2ll * c[i])
#define slope(i, j) ((double)(y(j) - y(i)) / (x(j) - x(i)))
struct Stack {
  vector<int> data;
  int top() { return data.back(); }
  int second() { return data[data.size() - 2]; }
  int size() { return data.size(); }
  void push(int x) { data.push_back(x); }
  void pop() { data.pop_back(); }
} stk[N];
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    c[i] = ++num[s[i]];
  }
  for (int i = 1; i <= n; i++) {
    Stack *cur = &stk[s[i]];
    while (cur->size() >= 2 &&
           slope(cur->second(), cur->top()) <= slope(cur->second(), i))
      cur->pop();
    cur->push(i);
    while (cur->size() >= 2 && slope(cur->second(), cur->top()) <= k(i))
      cur->pop();
    dp[i] = dp[cur->top() - 1] +
            s[i] * (c[i] - c[cur->top()] + 1) * (c[i] - c[cur->top()] + 1);
  }
  cout << dp[n] << endl;
  return 0;
}