#include <bits/stdc++.h>
#define N 100000
#define ls ch[x][0]
#define rs ch[x][1]
#define isroot(x) (ch[f[x]][0] != x && ch[f[x]][1] != x)
using namespace std;
int ch[N][2], f[N], tag[N];
void reverse(int x) {
  tag[x] ^= 1;
  swap(ls, rs);
}
void pushdown(int x) {
  if (tag[x]) {
    tag[x] ^= 1;
    if (ls) reverse(ls);
    if (rs) reverse(rs);
  }
}
void rotate(int x) {
  int y = f[x], z = f[y], k = (ch[y][1] == x), w = ch[x][k ^ 1];
  ch[x][k ^ 1] = y;
  ch[y][k] = w;
  if (!isroot(y)) ch[z][ch[z][1] == y] = x;
  f[x] = z;
  f[y] = x;
  if (w) f[w] = y;
}
void pushall(int x) {
  if (!isroot(x)) pushall(f[x]);
  pushdown(x);
}
void splay(int x) {
  pushall(x);
  while (!isroot(x)) {
    int y = f[x], z = f[y];
    if (!isroot(y)) rotate(((ch[y][1] == x) ^ (ch[z][1] == y)) ? x : y);
    rotate(x);
  }
}
void access(int x) {
  for (int y = 0; x; y = x, x = f[x]) {
    splay(x);
    rs = y;
  }
}
void makeroot(int x) {
  access(x);
  splay(x);
  reverse(x);
}
int findroot(int x) {
  access(x);
  splay(x);
  while (ls) {
    pushdown(x);
    x = ls;
  }
  splay(x);
  return x;
}
void link(int x, int y) {
  makeroot(x);
  access(y);
  splay(y);
  f[x] = y;
}
void cut(int x, int y) {
  makeroot(x);
  access(y);
  splay(y);
  ch[y][0] = f[x] = 0;
}
bool query(int x, int y) {
  makeroot(x);
  return findroot(y) == x;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    char s[10];
    int a, b;
    scanf("%s %d %d", s, &a, &b);
    if (s[0] == 'Q') {
      printf("%s\n", query(a, b) ? "Yes" : "No");
    } else if (s[0] == 'C')
      link(a, b);
    else
      cut(a, b);
  }
  return 0;
}

class Module {
 public:
  virtual char* getClassName() = 0;
};
class String : public Module {
 public:
  char* getClassName() { return "String"; }
};