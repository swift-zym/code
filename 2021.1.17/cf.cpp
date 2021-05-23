#include <bits/stdc++.h>
#define N 100
using namespace std;
int n, v[N], y[N], m[N], d[N];
void scan(int i) {
  char c = getchar();
  while (c != '+' && c != '-' && c != '0') c = getchar();
  if (c == '0') {
    scanf("%d/%d/%d", &y[i], &m[i], &d[i]);
    return;
  }
  int f = (c == '+') ? 1 : -1;
  scanf("%d %d/%d/%d", &v[i], &y[i], &m[i], &d[i]);
  v[i] *= f;
}
void print(int v) {
  if (v < 1200) {
    cout << v << " Newbie" << endl;
  } else if (v < 1400) {
    cout << v << " Pupil" << endl;
  } else if (v < 1600) {
    cout << v << " Specialist" << endl;
  } else if (v < 1900) {
    cout << v << " Expert" << endl;
  } else if (v < 2100) {
    cout << v << " Candidate Master" << endl;
  } else if (v < 2300) {
    cout << v << " Master" << endl;
  } else if (v < 2400) {
    cout << v << " International Master" << endl;
  } else if (v < 2600) {
    cout << v << " Grandmaster" << endl;
  } else if (v < 3000) {
    cout << v << " International Grandmaster" << endl;
  } else {
    cout << v << " Legendary Grandmaster" << endl;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scan(i);
  int cur = 1500, mx = INT_MIN;
  if (y[1] > 2020 || (y[1] == 2020 && m[1] > 5) ||
      (y[1] == 2020 && m[1] == 5 && d[1] >= 26)) {
    cur = 100;
  }
  for (int i = 1; i <= n; i++) {
    cur += v[i];
    mx = max(mx, cur);
  }
  print(cur);
  print(mx);
  return 0;
}
// 1355 1358