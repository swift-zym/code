#include <bits/stdc++.h>
int tmp[32], s[10000000];
void add(int i, int j, int k) {
  std::cout << "ADD " << i << " " << j << " " << k << std::endl;
  // s[k] = s[i] + s[j];
}
void sub(int i, int j, int k) {
  std::cout << "SUB " << i << " " << j << " " << k << std::endl;
  // s[k] = s[i] - s[j];
}
void div(int i, int j, int k) {
  std::cout << "DIV " << i << " " << j << " " << k << std::endl;
  // s[k] = s[i] / s[j];
}
void set(int x, int k) {
  std::cout << "SET " << x << " " << k << std::endl;
  // s[x] = k;
}
void cpy(int i, int k) {
  std::cout << "CPY " << i << " " << k << std::endl;
  // s[k] = s[i];
}
void mul(int i, int j, int k, int m) {
  std::cout << "MUL " << i << " " << j << " " << k << " " << m << std::endl;
  // s[k] = s[i] * s[j] % s[m];
}
void adv(int i, int k) {
  std::cout << "ADV " << i << " " << k << std::endl;
  // s[k] = s[s[i]];
}
void com(int i, int k) {
  std::swap(i, k);
  std::cout << "COM " << i << " " << k << std::endl;
  // s[s[k]] = s[i];

  // fflush(stdout);
}
void cmp(int i, int j, int k) {
  std::cout << "CMP " << i << " " << j << " " << k << std::endl;
  // s[k] = (s[i] > s[j]);
}
void cpypro(int x, int y) {
  adv(x, -10);
  com(y, -10);
}
void cmppro(int i, int j, int k) {
  adv(i, -11);
  adv(j, -12);
  cmp(-11, -12, k);
}
int main() {
  set(-1, 1000);
  set(-2, 1);
  std::cout << "prepare: ";
  puts("JMP -1 init");
  sub(-1, -2, -3);
  cpypro(-3, -1);
  cpy(-3, -1);
  puts("JMP -19 prepare");
  std::cout << "init: ";
  set(-15, 99999999);
  set(-1, 1);
  set(2001, 1);
  set(2002, 1000);
  set(2003, 0);
  std::cout << "sort: ";
  // sort:
  // if (!s[-1]) goto ed;  // JMP -1 exit
  puts("JMP -1 exit");
  set(-31, 3);
  set(-30, 1);
  sub(-1, -30, -32);
  mul(-32, -31, -32, -15);
  set(-29, 2000);
  add(-32, -29, -32);
  add(-32, -30, -32);
  adv(-32, -2);  // l
  add(-32, -30, -32);
  adv(-32, -3);  // r
  add(-32, -30, -32);
  adv(-32, -4);  // vis
  // read vaule from stack
  sub(-2, -3, -32);
  sub(-1, -30, -1);
  puts("JMP -32 sort");
  puts("JMP -4 fir");
  cpy(-2, -5);  // i

  add(-2, -3, -7);
  set(-32, 2);

  div(-7, -32, -7);  // mid
  cpy(-7, -6);       // j
  add(-6, -30, -6);
  set(-8, 1001);
  std::cout << "forfirst: ";

  cmppro(-5, -6, -13);
  puts("JMP -30 fal");
  /*i>j*/
  fflush(stdout);
  cpypro(-6, -8);
  add(-6, -30, -6);
  add(-8, -30, -8);
  puts("JMP -19 nxt");
  std::cout << "fal: ";
  cpypro(-5, -8);
  fflush(stdout);
  add(-5, -30, -5);
  add(-8, -30, -8);
  /*i<=j*/
  puts("nxt:");
  cmp(-5, -7, -31);
  cmp(-6, -3, -32);
  add(-31, -32, -32);
  cmp(-32, -19, -32);
  puts("JMP -32 forfirst");

  cmp(-5, -7, -31);
  puts("JMP -31 forsecond");
  puts("JMP -19 nxttry");
  std::cout << "forsecond: ";

  cpypro(-5, -8);
  add(-5, -30, -5);
  add(-8, -30, -8);

  cmp(-5, -7, -31);
  puts("JMP -31 forsecond");
  std::cout << "nxttry: ";
  cmp(-6, -3, -31);
  puts("JMP -31 forthird");
  puts("JMP -19 sort");
  std::cout << "forthird: ";

  cpypro(-6, -8);
  add(-6, -30, -6);
  add(-8, -30, -8);

  cmp(-6, -3, -31);
  puts("JMP -31 forthird");
  std::cout << "finalfor: ";
  set(-8, 1001);
  std::cout << "finalforrun: ";
  cpypro(-8, -2);
  add(-2, -30, -2);
  add(-8, -30, -8);

  cmp(-2, -3, -31);
  puts("JMP -31 finalfor");

  puts("JMP -19 sort");
  std::cout << "fir: ";
  add(-2, -3, -16);
  set(-30, 2);
  div(-16, -30, -16);

  set(-31, 3);
  set(-30, 1);
  add(-1, -30, -1);
  sub(-1, -30, -32);
  mul(-32, -31, -32, -15);
  set(-29, 2000);
  add(-32, -29, -32);

  add(-16, -30, -17);

  add(-32, -30, -32);  // l
  com(-32, -2);

  add(-32, -30, -32);  // r
  com(-32, -3);

  add(-32, -30, -32);  // vis
  com(-32, -30);

  add(-32, -30, -32);  // l
  com(-32, -2);

  add(-32, -30, -32);  // r
  com(-32, -16);

  add(-32, -30, -32);  // vis
  com(-32, -18);

  add(-32, -30, -32);  // l
  com(-32, -17);

  add(-32, -30, -32);  // r
  com(-32, -3);

  add(-32, -30, -32);  // vis
  com(-32, -18);

  add(-1, -30, -1);
  add(-1, -30, -1);  // update stack's top
  // write vaule to stack
  puts("JMP -19 sort");

  return 0;
}