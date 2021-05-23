#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y, theta;
};

struct Hull {
  vector<point> h;
  point fir;
  Hull(vector<point> p) {}
  Hull() {}
} A, B;
void test(string str) { cout << str << endl; }
int main() {
  test("1"), (test("2"), true), (void)test("3"), test("4");
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  vector<point> p;
  for (int i = 1; i <= n; i++) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    point c;
    c.x = x, c.y = y;
    p.push_back(c);
  }
  A = Hull(p);
}