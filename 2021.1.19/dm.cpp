#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("out.txt", "w", stdout);
  cout << 1500 << " " << 1500 << endl;
  for (int i = 1; i <= 1500; i++) {
    for (int j = 1; j < 1500; j++) {
      cout << 1 << " ";
    }
    cout << endl;
  }
  for (int i = 1; i < 1500; i++) {
    for (int j = 1; j <= 1500; j++) {
      cout << 1 << " ";
    }
    cout << endl;
  }
  return 0;
}