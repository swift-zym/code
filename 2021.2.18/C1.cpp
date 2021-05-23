// Problem: C1. Guessing the Greatest (easy version)
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/C1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// n-1
// l mid
// n-3
// n-2
// 1,mid-->n-1
// 1,mid-1-->
#include <bits/stdc++.h>
#define TEST
using namespace std;
int n, a[100001], q;
int query(int l, int r) {
  if (!(l < r)) {
    cout << l << " " << r << endl;
    exit(0);
  }
  q++;
  cout << "? " << l << " " << r << endl;
  cout.flush();
  int idx;
#ifdef TEST
  int v = *max_element(a + l, a + r + 1), mx = -1, id;
  for (int i = l; i <= r; i++) {
    if (a[i] != v && a[i] > mx) mx = a[i], id = i;
  }
  return id;
#else
  cin >> idx;
#endif
  return idx;
}
void answer(int x) {
  cout << "! " << x << endl;
#ifdef TEST
  cout << a[x] << " " << n - 1 << endl;
  cout << q << endl;
  puts("---");
  assert(a[x] == n && q <= 40);
#endif
  cout.flush();
}
int mian() {
#ifdef TEST
  for (int i = 1; i <= n; i++) a[i] = i;
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle(a + 1, a + n + 1, std::default_random_engine(seed));
#endif
  int l = 1, r = n, v = query(1, n);
  while (r - l > 1) {
    int mid = (l + r) / 2, nv;
    if (v <= mid) {
      if (l == mid) {
        l = mid + 1;
        continue;
      }
      if ((nv = query(l, mid)) != v) {
        l = mid + 1;
        cout << "pre:" << nv << " " << v << endl;
        if (l != r) v = query(l, r);
        cout << "lst:" << v << endl;
      } else {
        r = mid;
        v = nv;
      }
    } else {
      if (mid + 1 == r) {
        r = mid;
        continue;
      }
      if ((nv = query(mid + 1, r)) != v) {
        r = mid;
        cout << "pre:" << nv << " " << v << endl;
        if (l != r) v = query(l, r);
        cout << "lst:" << v << endl;
      } else {
        l = mid + 1;
        v = nv;
      }
    }
  }
  if (l == r) {
    answer(l);
    return 0;
  }
  if (query(l, r) == r)
    answer(l);
  else
    answer(r);
  return 0;
}
int main() {
  cin >> n;
  for (;;) {
    q = 0;
    mian();
  }
}