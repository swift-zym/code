#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << n << endl;
  srand(time(0));
  for (int i = 2; i <= n; i++) {
    cout << (rand() % (i - 1)) + 1 << " " << i << endl;
  }
  return 0;
}