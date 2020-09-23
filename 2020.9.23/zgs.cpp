#include <bits/stdc++.h>
using namespace std;
int n, m, numX;
vector<char> brand;
void _hurt(int s, int from, int type);
int getblood(int s);
int getjump(int s);
int getlike(int s);
int gettype(int s);
void clears(int s);
void _add3(int s);
void _duel(int pos, int from);
bool _work(int s, int t, int tt, int pos);
void _set(int s);
void win(int s);
struct pig {
  int type;
  int blood = 4;
  int jump;
  int id;
  int like;
  bool arms;
  vector<int> hand;
  void init(int i) {
    id = i;
    string s;
    cin >> s;
    if (s == "MP") {
      type = 1;
      jump = 2;
    } else if (s == "ZP")
      type = 2;
    else
      type = 3, numX++;
    char c;
    for (int i = 1; i <= 4; i++) {
      cin >> c;
      hand.push_back(c);
    }
  }
  void die(int from) {
    blood--;
    if (blood <= 0) {
      for (int i = 0; i < hand.size(); i++) {
        if (hand[i] == 'P') {
          hand.erase(hand.begin() + i);
          blood++;
          break;
        }
      }
    }
    if (blood <= 0) {
      clear();
      if (type == 1) {
        win(1);
      } else if (type == 2) {
        if (gettype(from) == 1) {
          clears(from);
        }
      } else if (type == 3) {
        numX--;
        if (numX == 0) win(0);
        if (from != id) _add3(from);
      }
    }
  }
  int findjd() {
    int nxt = id + 1;
    if (nxt == n + 1) nxt = 1;
    if (type == 1) {
      while (nxt != id) {
        if (getblood(nxt) != 0 && (getjump(nxt) == 1 || getlike(nxt) == 1)) {
          break;
        }
        nxt = nxt + 1;
        if (nxt == n + 1) nxt = 1;
      }
      return nxt == id ? -1 : nxt;
    } else if (type == 2) {
      while (nxt != id) {
        if (getblood(nxt) != 0 && getjump(nxt) == 1) {
          break;
        }
        nxt++;
        if (nxt == n + 1) nxt = 1;
      }
      return nxt == id ? -1 : nxt;
    } else {
      return 1;
    }
  }
  int findkill() {
    int nxt = id + 1;
    if (nxt == n + 1) nxt = 1;
    while (getblood(nxt) == 0) {
      nxt++;
      if (nxt == n + 1) nxt = 1;
    }
    if (type == 1) {
      if (getjump(nxt) == 1 || getlike(nxt) == 1) {
        return nxt;
      }
      return -1;
    } else if (type == 2) {
      if (getjump(nxt) == 1) {
        return nxt;
      }
      return -1;
    } else {
      if (getjump(nxt) == 2) {
        return nxt;
      }
      return -1;
    }
  }
  bool work(int t, int tt, int pos) {
    if (getjump(pos) == 0) return 0;
    if (type == 3) {
      if (tt == 1 && getjump(pos) == 1) return 0;
      if (tt == 0 && getjump(pos) != 1) return 0;
    }
    if (type == 2) {
      if (tt == 1 && getjump(pos) == 2) return 0;
      if (tt == 0 && getjump(pos) != 2) return 0;
    }
    if (type == 1) {
      if (tt == 1 && getjump(pos) != 1 && getlike(pos) != 1) return 0;
      if (tt == 0 && getjump(pos) != 2) return 0;
    }
    for (int i = 0; i < hand.size(); i++) {
      if (hand[i] == 'J') {
        if (type == 2) jump = 2, like = 0;
        if (type == 3) jump = 1;
        hand.erase(hand.begin() + i);
        return 1;
      }
    }
    return 0;
  }
  bool _flag = 0;
  void play() {
    int use = 0;
    int bf = hand.size();
    for (int i = 0; i < bf; i++) {
      if (hand.size() == 0) break;
      char first = hand[i - use];
      if (first == 'P' && blood != 4) {
        hand.erase(hand.begin() + i - use);
        blood++;
        use++;
      }
      if ((_flag == 0 || arms) && first == 'K') {
        int pos = findkill();
        if (pos != -1) {
          _flag = 1;
          if (type == 2)
            jump = 2, like = 0;
          else if (type == 3)
            jump = 1;
          hand.erase(hand.begin() + i - use);
          use++;
          _hurt(pos, id, 1);
        }
      }
      if (first == 'F') {
        int pos = findjd();
        if (pos != -1) {
          if (type == 2)
            jump = 2, like = 0;
          else if (type == 3)
            jump = 1;
          hand.erase(hand.begin() + i - use);
          use++;
          int nxt = id;
          if (nxt == n + 1) nxt = 1;
          bool flag = 0;
          int num = 0;
          do {
            flag = 0;
            int bf = nxt;
            do {
              if (_work(nxt, type, num % 2, pos)) {
                flag = 1;
                nxt++;
                break;
              }
              nxt++;
              if (nxt == n + 1) nxt = 1;
            } while (nxt != bf);
            if (nxt == n + 1) nxt = 1;
            num++;
          } while (flag);
          if (num % 2 == 1) _duel(pos, id);
        }
      }
      if (first == 'Z') {
        arms = 1;
        hand.erase(hand.begin() + i - use);
        use++;
      }
      if (first == 'N') {
        if (i - use >= hand.size()) break;
        hand.erase(hand.begin() + i - use);
        use++;
        int nxtt = id + 1;
        while (nxtt != id) {
          if (getblood(nxtt) == 0) {
            nxtt++;
            if (nxtt == n + 1) nxtt = 1;
            continue;
          }
          if (nxtt == n + 1) nxtt = 1;
          int nxt = id;
          if (nxt == n + 1) nxt = 1;
          bool flag = 0;
          int num = 0;
          do {
            flag = 0;
            int bf = nxt;
            do {
              if (_work(nxt, type, num, nxtt)) {
                flag = 1;
                nxt++;
                if (nxt == n + 1) nxt = 1;
                break;
              }
              nxt++;
              if (nxt == n + 1) nxt = 1;
            } while (nxt != bf);
            if (nxt == n + 1) nxt = 1;
            num++;
          } while (flag);
          if (num % 2 == 1) _hurt(nxtt, id, 2);
          nxtt = nxtt + 1;
          if (nxtt == n + 1) nxtt = 1;
        }
      }
      if (first == 'W') {
        hand.erase(hand.begin() + i - use);
        use++;
        int nxtt = id + 1;
        if (nxtt == n + 1) nxtt = 1;
        while (nxtt != id) {
          if (getblood(nxtt) == 0) {
            nxtt++;
            if (nxtt == n + 1) nxtt = 1;
            continue;
          }
          if (nxtt == n + 1) nxtt = 1;
          int nxt = id;
          if (nxt == n + 1) nxt = 1;
          if (nxt == n + 1) nxt = 1;
          bool flag = 0;
          int num = 0;
          do {
            flag = 0;
            int bf = nxt;
            do {
              if (nxt == n + 1) nxt = 1;
              if (_work(nxt, type, num % 2, nxtt)) {
                flag = 1;
                nxt++;

                if (nxt == n + 1) nxt = 1;
                break;
              }
              nxt++;
              if (nxt == n + 1) nxt = 1;
            } while (nxt != bf);
            num++;
          } while (flag);
          if (num % 2 == 1) _hurt(nxtt, id, 1);
          nxtt = nxtt + 1;
          if (nxtt == n + 1) nxtt = 1;
        }
      }
      if (blood <= 0) return;
    }
  }
  void start() {
    for (int i = 1; i <= 2; i++) {
      hand.push_back(brand[0]);
      if (brand.size() != 1) brand.erase(brand.begin());
    }
    _flag = 0;
    play();
    play();
  }
  void duel(int pos) {
    if (type == 2 && gettype(pos) == 1) {
      _hurt(id, pos, 3);
      return;
    }
    for (int i = 0; i < hand.size(); i++) {
      if (hand[i] == 'K') {
        hand.erase(hand.begin() + i);
        _duel(pos, id);
        return;
      }
    }
    _hurt(id, pos, 3);
  }
  void hurt(int from, int _type) {
    if (type == 1) {
      _set(from);
    }
    if (_type == 3) {
      die(from);
    } else if (_type == 1) {
      for (int i = 0; i < hand.size(); i++) {
        if (hand[i] == 'D') {
          hand.erase(hand.begin() + i);
          return;
        }
      }
      die(from);
    } else if (_type == 2) {
      for (int i = 0; i < hand.size(); i++) {
        if (hand[i] == 'K') {
          hand.erase(hand.begin() + i);
          return;
        }
      }
      die(from);
    }
  }
  void clear() {
    hand.clear();
    arms = 0;
  }
  void add3() {
    for (int i = 1; i <= 3; i++) {
      hand.push_back(brand[0]);
      if (brand.size() != 1) brand.erase(brand.begin());
    }
  }
  void print() {
    if (blood == 0) {
      printf("DEAD\n");
      return;
    }
    for (int i = 0; i < hand.size(); i++) {
      printf("%c ", hand[i]);
    }
    putchar(10);
  }
} a[11];
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    a[i].init(i);
  }
  char c;
  for (int i = 1; i <= m; i++) {
    cin >> c;
    brand.push_back(c);
  }
  int now = 1;
  while (1) {
    if (a[now].blood != 0) {
      a[now].start();
    }
    now++;
    if (now == n + 1) now = 1;
  }
}
int main() {
  solve();
  return 0;
}
void _hurt(int s, int from, int type) { a[s].hurt(from, type); }
int getblood(int s) { return a[s].blood; }
int getjump(int s) { return a[s].jump; }
int getlike(int s) { return a[s].like; }
void _duel(int pos, int from) { a[pos].duel(from); }
int gettype(int s) { return a[s].type; }
bool _work(int s, int t, int tt, int pos) { return a[s].work(t, tt % 2, pos); }
void _add3(int s) { a[s].add3(); }
void clears(int s) { a[s].clear(); }
void win(int s) {
  if (s == 0) {
    printf("MP\n");
  } else {
    printf("FP\n");
  }
  for (int i = 1; i <= n; i++) {
    a[i].print();
  }
  exit(0);
}
void _set(int s) {
  if (!a[s].jump) a[s].like = 1;
}