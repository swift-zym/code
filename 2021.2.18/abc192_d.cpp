// Problem: D - Base n
// Contest: AtCoder - AtCoder Beginner Contest 192
// URL: https://atcoder.jp/contests/abc192/tasks/abc192_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;

struct bign {
  int d[maxn], len;

  void clean() {
    while (len > 1 && !d[len - 1]) len--;
  }

  bign() {
    memset(d, 0, sizeof(d));
    len = 1;
  }
  bign(int num) { *this = num; }
  bign(long long num) { *this = num; }
  bign(char* num) { *this = num; }
  bign operator=(const char* num) {
    memset(d, 0, sizeof(d));
    len = strlen(num);
    for (int i = 0; i < len; i++) d[i] = num[len - 1 - i] - '0';
    clean();
    return *this;
  }
  bign operator=(int num) {
    char s[20];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
  }
  bign operator=(long long num) {
    char s[40];
    sprintf(s, "%lld", num);
    *this = s;
    return *this;
  }
  bign operator+(const bign& b) {
    bign c = *this;
    int i;
    for (i = 0; i < b.len; i++) {
      c.d[i] += b.d[i];
      if (c.d[i] > 9) c.d[i] %= 10, c.d[i + 1]++;
    }
    while (c.d[i] > 9) c.d[i++] %= 10, c.d[i]++;
    c.len = max(len, b.len);
    if (c.d[i] && c.len <= i) c.len = i + 1;
    return c;
  }
  bign operator-(const bign& b) {
    bign c = *this;
    int i;
    for (i = 0; i < b.len; i++) {
      c.d[i] -= b.d[i];
      if (c.d[i] < 0) c.d[i] += 10, c.d[i + 1]--;
    }
    while (c.d[i] < 0) c.d[i++] += 10, c.d[i]--;
    c.clean();
    return c;
  }
  bign operator*(const bign& b) const {
    int i, j;
    bign c;
    c.len = len + b.len;
    for (j = 0; j < b.len; j++)
      for (i = 0; i < len; i++) c.d[i + j] += d[i] * b.d[j];
    for (i = 0; i < c.len - 1; i++) c.d[i + 1] += c.d[i] / 10, c.d[i] %= 10;
    c.clean();
    return c;
  }
  bign operator/(const bign& b) {
    int i, j;
    bign c = *this, a = 0;
    for (i = len - 1; i >= 0; i--) {
      a = a * 10 + d[i];
      for (j = 0; j < 10; j++)
        if (a < b * (j + 1)) break;
      c.d[i] = j;
      a = a - b * j;
    }
    c.clean();
    return c;
  }
  bign operator%(const bign& b) {
    int i, j;
    bign a = 0;
    for (i = len - 1; i >= 0; i--) {
      a = a * 10 + d[i];
      for (j = 0; j < 10; j++)
        if (a < b * (j + 1)) break;
      a = a - b * j;
    }
    return a;
  }
  bign operator+=(const bign& b) {
    *this = *this + b;
    return *this;
  }

  bool operator<(const bign& b) const {
    if (len != b.len) return len < b.len;
    for (int i = len - 1; i >= 0; i--)
      if (d[i] != b.d[i]) return d[i] < b.d[i];
    return false;
  }
  bool operator>(const bign& b) const { return b < *this; }
  bool operator<=(const bign& b) const { return !(b < *this); }
  bool operator>=(const bign& b) const { return !(*this < b); }
  bool operator!=(const bign& b) const { return b < *this || *this < b; }
  bool operator==(const bign& b) const { return !(b < *this) && !(b > *this); }

  string str() const {
    char s[maxn] = {};
    for (int i = 0; i < len; i++) s[len - 1 - i] = d[i] + '0';
    return s;
  }
};

istream& operator>>(istream& in, bign& x) {
  string s;
  in >> s;
  x = s.c_str();
  return in;
}

ostream& operator<<(ostream& out, const bign& x) {
  out << x.str();
  return out;
}
#define int bign
int x, m;
int f(int v, int c) {
  int bas = 1, ans = 0;
  while (v != 0) {
    ans += (v % 10) * bas;
    if (ans > m) return 0;
    if (bas > m) return 0;
    v = v / 10;
    bas = bas * c;
  }
  return 1;
}
int s(int v) {
  int mx = 0;
  while (v != 0) {
    if (v % 10 > mx) mx = v % 10;
    v = v / 10;
  }
  return mx;
}
signed main() {
  cin >> x >> m;
  if (x <= 9) {
    if (m < x)
      cout << 0 << endl;
    else
      cout << 1 << endl;
    return 0;
  }
  int l = s(x) + 1, r = (long long)1e18, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (f(x, mid) != 0) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  if (ans == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (f(x, ans) == 0) {
    cout << 0 << endl;
  } else {
    cout << ans - s(x) << endl;
  }
  return 0;
}