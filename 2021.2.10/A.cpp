#include <bits/stdc++.h>
#define q(x)           \
  {                    \
    cout << x << endl; \
    goto ed;           \
  }
using namespace std;
int main() {
  // freopen("game.in", "r", stdin);
  // freopen("game.out", "w", stdout);
  int n, m, x1, y1, x2, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  if (n > m) {
    swap(n, m);
    swap(x1, y1);
    swap(x2, y2);
  }
  if (abs(x1 - x2) + abs(y1 - y2) <= 1) q(-1);
  if (n == 1) q(2);
  if (n == 2 && m == 2) q(1);
  if (n == 2 && (y2 - y1 >= 2 || y1 == 1 || y1 == m)) q(2);
  if (n == 3 && m == 3 && x2 == 2 && y2 == 2) q(1);
  if (n == 3 && m == 3) q(2);
  if (abs(x1 - x2) == 1 && abs(y1 - y2) == 1) q(3);
  if (x2 == 1 || x2 == n || y2 == 1 || y2 == m) q(2);
  if ((x2 == 2 || x2 == n - 1) && (y2 == 2 || y2 == m - 1)) q(2);
  q(3);
ed:;
  return 0;
}