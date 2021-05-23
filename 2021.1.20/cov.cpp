#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    int a, b;
    cin >> a >> b;
    if (s[i] - '0')
      cout << b << " " << a << endl;
    else
      cout << a << " " << b << endl;
  }
  return 0;
}