
// Problem: H - LaserTowersDiv1
// Contest: Virtual Judge - 2021校际day29
// URL: https://vjudge.net/contest/423955#problem/H
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
class LaserTowersDiv1 {
 private:
  static const int N = 1000000, inf = 1000000000;
  int n, m, s, t, cnt = 1, ans, head[N], nxt[N], to[N], len[N], dep[N], cur[N];
  void add(int a, int b, int l, bool _rev = false) {
    nxt[++cnt] = head[a];
    to[cnt] = b;
    len[cnt] = l;
    head[a] = cnt;
    if (!_rev) add(b, a, 0, true);
  }
  bool bfs() {
    for (int i = s; i <= t; i++) {
      dep[i] = inf;
      cur[i] = head[i];
    }
    queue<int> q;
    q.push(s);
    dep[s] = 0;
    while (!q.empty()) {
      int now = q.front();
      if (now == t) return 1;
      q.pop();
      for (int i = head[now]; i; i = nxt[i]) {
        if (len[i] && dep[to[i]] == inf) {
          dep[to[i]] = dep[now] + 1;
          q.push(to[i]);
        }
      }
    }
    return 0;
  }
  int dfs(int now, int flow) {
    if (now == t) return flow;
    int use = 0;
    for (int i = cur[now]; i && flow; i = nxt[i]) {
      cur[now] = i;
      if (dep[to[i]] == dep[now] + 1 && len[i]) {
        int v = dfs(to[i], min(flow, len[i]));
        if (!v) dep[to[i]] = inf;
        len[i] -= v;
        len[i ^ 1] += v;
        flow -= v;
        use += v;
      }
    }
    return use;
  }
  vector<string> board;
  void move(int &x, int &y, int i, int j) {
    if (board[i - 1][j - 1] == '>')
      y++;
    else if (board[i - 1][j - 1] == '<')
      y--;
    else if (board[i - 1][j - 1] == 'A')
      x--;
    else
      x++;
  }
  int id(int a, int b, int floor) { return floor * n * m + (a - 1) * m + b; }
  int val(int i, int j) {
    return isdigit(board[i - 1][j - 1]) ? board[i - 1][j - 1] - '0' : 0;
  }

 public:
  int countMaxEnemies(vector<string> _board) {
    board = _board;
    n = board.size();
    m = board[0].size();
    s = 0;
    t = n * m * 2 + 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        char c = board[i - 1][j - 1];
        if (c == '>' || c == '<' || c == 'A' || c == 'V') {
          if (c == '>' || c == '<') {
            add(s, id(i, j, 0), inf);
          } else {
            add(id(i, j, 1), t, inf);
          }
        } else {
          add(id(i, j, 0), id(i, j, 1), inf);
          continue;
        }
        int x, y, a, b, mx = -1;
        x = i, y = j;
        while ((move(x, y, i, j), 1) && x >= 1 && x <= n && y >= 1 && y <= m) {
          mx = max(mx, val(x, y));
        }
        ans += mx;
        a = x = i;
        b = y = j;
        while ((move(x, y, i, j), 1) && x >= 1 && x <= n && y >= 1 && y <= m) {
          if (c == '>' || c == '<') {
            add(id(a, b, 0), id(x, y, 0), mx - val(a, b));
          } else {
            add(id(x, y, 1), id(a, b, 1), mx - val(a, b));
          }
          a = x;
          b = y;
        }
      }
    int flow = 0;
    while (bfs()) flow += dfs(s, inf);
    return ans - flow;
  }
} solution;
int main() {
  cout << solution.countMaxEnemies(
      {"........7..7......4...<...V9.5.", ">.........2.........5..46......",
       ".6...........9..<..>...5.......", ".6...................<..A>...5.",
       ".V>....................6.......", ".....57.............<...>....7.",
       "..............6.........<V....7", "V..V7..V..AA>..............61..",
       "..V.......V..A.....>.....5.....", "......7....V....>.........7....",
       "1...........<>..............6..", "............5...........<......",
       ".........6..V.......V...V..A...", ".2...........<....A..>....7....",
       "5..........................<...", ".............V...5...>.....6...",
       "........5.......V.V....A...>.8.", ".....A.........7.....>......5..",
       "96.........................<...", "....AV..............7V.....VA.A",
       "..............5....6........<.V", "..6................<........V..",
       "....V..............>.......5..6", "8.6................<...>....6..",
       ".........A.............V.....A.", ".....6A........A.A.>.....6.....",
       "69....<.A>.............3.......", "...2.....<....A.......>...2.6..",
       "...76..5.....7..7..5........7<.", "...8.......6..<..V5>.....9..7..",
       "....7.....5.5.<>.4...7.556.4..."});
  return 0;
}