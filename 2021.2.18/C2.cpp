// Problem: C2. Guessing the Greatest (hard version)
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/C2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n, a[100001];
int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  cout.flush();
  int idx;
  cin >> idx;
  return idx;
}
void answer(int x) {
  cout << "! " << x << endl;
  cout.flush();
}
int main() {
  cin >> n;
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
        v = query(l, r);
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
        v = query(l, r);
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