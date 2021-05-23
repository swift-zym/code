#include <bits/stdc++.h>
using namespace std;
struct node {
  node operator++() { cout << "++ called" << endl; }
  node operator+(const node &t) const { cout << "+ called" << endl; }
};
int main() {
  node a;
  b = (++a) + (a++);
  return 0;
}