#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, m;
struct node {
  int v[50001];
  node operator+(const node &t) const {
    if (v[0] == -1) return t;
    if (t.v[0] == -1) return *this;
    node tmp;
    memset(tmp.v, 0, sizeof(tmp.v));
    for (int i = 1; i <= n; i++) {
      tmp.v[i] = max(v[i], t.v[i]);
    }
    return tmp;
  }
  node operator-(const node &t) const {
    if (v[0] == -1) return t;
    if (t.v[0] == -1) return *this;
    node tmp;
    memset(tmp.v, 0, sizeof(tmp.v));
    for (int i = 1; i <= n; i++) {
      tmp.v[i] = min(v[i], t.v[i]);
    }
    return tmp;
  }
  long long sum() {
    long long s = 0;
    for (int i = 1; i <= n; i++) s += v[i];
    return s;
  }
} a[10];
namespace solve {
map<const char, int> priority;  //用map来储存运算符的优先级
int compare(char a, char b) {
  int cmp = 0;
  if (b == ')' && a == '(')
    cmp = 0;
  else if (a == '(')
    cmp = -1;
  else if (priority[a] < priority[b])
    cmp = -1;
  else if (priority[a] >= priority[b])
    cmp = 1;
  return cmp;
}

node cal(node a, node b, char op) {
  node ans;
  if (op == '<')
    ans = a - b;
  else if (op == '>')
    ans = a + b;
  return ans;
}
string str;
int idx = 0;
char getchar() { return str[idx++]; }
node calculator() {
  //根据优先级的关系，可以把他们的优先级定义为下面的形式
  //个别运算符的优先级是与位置前后有关系的，需要特俗处理
  priority['#'] = -1;
  priority['('] = 0;
  priority['<'] = 1;
  priority['>'] = 1;
  priority['*'] = 2;
  priority['/'] = 2;
  priority['('] = 3;
  char ch = getchar();
  stack<char> op;
  stack<node> nums;
  op.push('#');
  node tmp;
  tmp.v[0] = -1;
  nums.push(tmp);
  bool flag = true;
  while (ch != '#' || op.top() != '#') {
    if (ch <= '9' && ch >= '0') {
      int number = 0;
      while (ch >= '0' && ch <= '9') {  //连续出现的数字看做一个整体
        number = number * 10 + (ch - '0');
        ch = getchar();
      }
      //    cout<<"number: "<<number<<endl;
      //    cout<<"op: "<<ch<<endl;
      nums.push(a[number]);
      flag = true;
    } else {  //比较栈顶运算符和新输出运算符的优先级
      int cmp = compare(op.top(), ch);
      // cout<<"compare("<<op.top()<<","<<ch<<") = "<<cmp<<endl;
      if (cmp == -1) {  //顶部优先级低时，把新的运算符压栈
        op.push(ch);
        flag = false;
        ch = getchar();
      } else if (cmp == 0) {  //即栈顶和新的运算符是'('和')'，需要把'('弹出
        op.pop();
        ch = getchar();
      } else if (cmp == 1) {  //栈顶运算符优先级高的时候，就要进行运算
        node num1, num2, tempans;
        char tempop;  //一定要注意num的顺序，否则会导致错误的运算结果
        num2 = nums.top();
        nums.pop();
        num1 = nums.top();
        nums.pop();
        tempop = op.top();
        op.pop();
        tempans = cal(num1, num2, tempop);
        // cout<<"tempans: "<<tempans<<endl;
        nums.push(tempans);
      }
    }
  }
  cin.get();
  return nums.top();
}
node main(string s) {
  idx = 0;
  str = s + "#";
  return calculator();
}
}  // namespace solve
long long ans = 0;
void dfs(string s, int deep) {
  if (deep == s.length()) {
    ans += solve::main(s).sum() % MOD;
    ans %= MOD;
    return;
  }
  if (s[deep] != '?') {
    dfs(s, deep + 1);
    return;
  }
  s[deep] = '<';
  dfs(s, deep + 1);
  s[deep] = '>';
  dfs(s, deep + 1);
}
void file() {
  freopen("expr.in", "r", stdin);
  freopen("expr.out", "w", stdout);
}
int main() {
  file();
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i].v[j];
    }
  }
  string s;
  cin >> s;
  dfs(s, 0);
  cout << ans << endl;
  return 0;
}