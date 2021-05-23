#include <map>
#include <queue>

#include "testlib.h"
#ifndef open_dbg_func
#define err(args...)
#endif
using namespace std;
using ll = long long;

const int maxn = 2e5 + 7;

bool in_vec(const vector<int>& a, int val) {
  for (auto& p : a)
    if (p == val) return true;
  return false;
}

int n, m;
vector<int> a[maxn];  // edge
map<int, int> E[maxn];
int in_val[maxn];
int id[maxn];
char output_str[maxn], stdout_str[maxn];

bool judge() {
  int cnt = 0;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (in_val[i] == 0) {
      id[i] = ++cnt;
      q.push(i);
    }
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    for (auto& p : a[tmp]) {
      in_val[p]--;
      if (in_val[p] == 0) {
        id[p] = ++cnt;
        q.push(p);
      }
    }
  }
  if (cnt != n) return false;
  for (int i = 1; i <= n; i++) {
    int min = n + 1, min_pos;
    for (auto& p : a[i])
      if (id[p] < min) {
        min = id[p];
        min_pos = p;
      }
    if (min == n + 1) continue;
    for (auto& p : a[i])
      if (p != min_pos && !E[min_pos][p]) return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  n = inf.readInt();
  m = inf.readInt();
  string s1, s2;
  s1 = ouf.readString();
  s2 = ans.readString();
  for (int i = 0; i < s1.size(); i++) {
    output_str[i] = s1[i];
    if ((i > 0) && !(s1[i] == '0' || s1[i] == '1')) quitf(_wa, "WA!");
  }
  for (int i = 0; i < s2.size(); i++) stdout_str[i] = s2[i];
  bool ans;
  if (stdout_str[0] == '-')
    ans = (output_str[0] == '-' && output_str[1] == '1');
  else {
    for (int i = 0; i < m; i++) {
      int x, y;
      x = inf.readInt();
      y = inf.readInt();
      if (output_str[i] == '0') {
        a[x].push_back(y);
        E[x][y] = 1;
        in_val[y]++;
      } else {
        a[y].push_back(x);
        E[y][x] = 1;
        in_val[x]++;
      }
    }
    ans = judge();
  }
  if (ans)
    quitf(_ok, "Correct.");
  else
    quitf(_wa, "WA!");
}
