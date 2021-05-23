#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("out.txt", "w", stdout);
  srand(time(0));
  int n;
  cin >> n;
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      cout << -1 << " ";
    else
      cout << rand() % (i - 1) + 1 << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      cout << -1 << " ";
    else
      cout << rand() % (i - 1) + 1 << " ";
  }
  cout << endl;
  return 0;
}