// Problem: E. Pattern Matching
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n, m, k, x[1000000];
string a[1000000], b[1000000];
unordered_map<string, int> mp;
unordered_map<string, queue<int>> num;
vector<string> tmp, pat;
string lim[1000000];
void add(string &x, string y) {
  if (x == "") {
    x = y;
    return;
  }
  for (int i = 0; i < k; i++) {
    if (x[i] == y[i] || x[i] == '_' || y[i] == '_') continue;
    x[i] = '_';
  }
}
bool check(string x, string y) {
  for (int i = 0; i < k; i++) {
    if (x[i] == y[i] || x[i] == '_' || y[i] == '_') continue;
    return 0;
  }
  return 1;
}
int count(string x) {
  int num = 0;
  for (auto c : x) {
    num += (c == '_');
  }
  return num;
}
bool cmp(string x, string y) { return count(x) < count(y); }
int idx[1000000];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!num[a[i]].size()) {
      pat.push_back(a[i]);
    }
    num[a[i]].push(i);
    lim[i] = "";
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i] >> x[i];
    int v = mp[b[i]];
    if (!v) {
      tmp.push_back(b[i]);
    }
    if (v && v != x[i]) {
      cout << "NO" << endl;
      return 0;
      break;
    }
    mp[b[i]] = x[i];
  }
  for (auto s : tmp) {
    add(lim[mp[s]], s);
  }
  sort(pat.begin(), pat.end(), cmp);
  for (auto str : pat) {
    for (int i = 1; i <= n && !num[str].empty(); i++) {
      if (lim[i] != "" && idx[i] == 0) {
        if (check(str, lim[i])) {
          idx[i] = num[str].front();
          num[str].pop();
        }
      }
    }
  }
  for (auto str : pat) {
    for (int i = 1; i <= n && !num[str].empty(); i++) {
      if (idx[i] == 0) {
        if (lim[i] == "" || check(str, lim[i])) {
          idx[i] = num[str].front();
          num[str].pop();
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!idx[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << idx[i] << " ";
  }
  cout << endl;
  return 0;
}