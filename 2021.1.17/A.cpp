#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
  int x, y, z;
  node() {}
  node(int x, int y, int z) : x(x), y(y), z(z) {}
};
int n;
vector<node> ans;
int main() {
  puts("Yes");
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int k = n - (i + j) % n;
      // find a slope in [j+1,n]
      if (k > j) ans.push_back(node(i, j, k));
    }
  }
  printf("%d\n", ans.size());
  for (node cur : ans) printf("%d %d %d\n", cur.x, cur.y, cur.z);
  return 0;
}