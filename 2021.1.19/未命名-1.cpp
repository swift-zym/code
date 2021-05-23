#include <bits/stdc++.h>
#define maxn 10000
#define eps 1e-9
using namespace std;
struct node {
  int x, y;
  node(int a, int b) {
    x = a;
    y = b;
  }
  node(){};
};
int n;
node point[maxn];  //保存多边形顶点数组
bool solve(node yo) {
  int ox = yo.x, oy = yo.y;
  int num = 0;
  for (int i = 0; i < n - 1; i++) {
    int sx = point[i].x, sy = point[i].y;
    int ex = point[i + 1].x, ey = point[i + 1].y;
    if ((ox == sx && oy == sy) || (ox == ex && oy == ey)) {
      return true;
    }  //判断点是否与多边形的顶点重合

    if ((sy >= oy && ey < oy) ||
        (ey >= oy && sy < oy))  //当线段的端点位于射线的上下两侧时
    {
      double midx;
      midx =
          sx + (oy - sy) * (ex - sx) * 1.0 / (ey - sy);  //计算直线与线段的交点
      double rx = ox;
      if (fabs(midx - rx) < eps)  //判断点是否在多边形的边上
      {
        return true;
      }

      if (midx > rx) num++;
    }
  }
  if (num % 2) {
    return true;
  }  //当与多边形有奇数个交点时
  else
    return false;
}
int main() {
  while (cin >> n && n) {
    int m;
    cin >> m;
    for (int i = 0; i < n; i++) cin >> point[i].x >> point[i].y;
    for (int i = 1; i <= m; i++) {
      node ver;
      cin >> ver.x >> ver.y;

      if (solve(ver))
        cout << "T\n";
      else
        cout << "F\n";
    }
  }
}