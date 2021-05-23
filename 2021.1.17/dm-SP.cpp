#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 1000, m = 10;
  cout << n << " " << m << endl;
  for (int i = 1; i <= n; i++) {
    cout << rand() % 100 << " ";
  }
  cout << endl;
  for (int i = 2; i <= n; i++) {
    if (rand() % 2) {
      cout << i << " " << rand() % (i - 1) + 1 << endl;
    } else {
      cout << rand() % (i - 1) + 1 << " " << i << endl;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << rand() % n + 1 << " " << rand() % n + 1 << endl;
  }
  return 0;
}