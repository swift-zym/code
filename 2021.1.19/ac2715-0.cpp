#include <bits/stdc++.h>
#define eps -1e9
using namespace std;
typedef double db;
int n, m, x[101], y[101];
bool solve(int xx, int yy) {
  int num = 0;
  for (int i = 1; i <= n; i++) {
    int sx = x[i], sy = y[i], ex = x[i == n ? 1 : i + 1],
        ey = y[i == n ? 1 : i + 1];
    if ((xx == sx && yy == sy) || (xx == ex && yy == ey)) return true;
    if ((ey >= yy && yy > sy) || (sy >= yy && yy > ey)) {
      cout << sx << " " << ex << " " << sy << " " << ey << " " << xx << " "
           << yy << endl;
      if (fabs((db)sx + (db)(ex - sx) / (ey - sy) * (yy - sy) - (db)xx) < eps)
        num++;
    }
  }
  return num % 2 ? true : false;
}
int main() {
  while (cin >> n) {
    if (!n) break;
    cin >> m;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 1; i <= m; i++) {
      int xx, yy;
      cin >> xx >> yy;
      cout << (solve(xx, yy) ? "Within" : "Outside") << endl;
    }
  }
  return 0;
}