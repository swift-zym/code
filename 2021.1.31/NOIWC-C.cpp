#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define gc getchar
#define pc putchar
#define puts put_s
#define cs const

namespace IO {
namespace READONLY {
cs int Rlen = 1 << 18 | 1;
char buf[Rlen], *p1, *p2;
char obuf[Rlen], *p3 = obuf;
char ch[23];
}  // namespace READONLY
inline char get_char() {
  using namespace READONLY;
  return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, Rlen, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void put_char(cs char &c) {
  using namespace READONLY;
  *p3++ = c;
  if (p3 == obuf + Rlen) fwrite(obuf, 1, Rlen, stdout), p3 = obuf;
}
inline void put_s(cs char *s) {
  for (; *s; ++s) pc(*s);
  pc('\n');
}
inline void FLUSH() {
  using namespace READONLY;
  fwrite(obuf, 1, p3 - obuf, stdout);
  p3 = obuf;
}

inline ll getint() {
  re ll num;
  re char c;
  while (!isdigit(c = gc()))
    ;
  num = c ^ 48;
  while (isdigit(c = gc())) num = (num + (num << 2) << 1) + (c ^ 48);
  return num;
}
inline void outint(ll a) {
  using namespace READONLY;
  if (a == 0) pc('0');
  if (a < 0) pc('-'), a = -a;
  while (a) ch[++ch[0]] = a - a / 10 * 10, a /= 10;
  while (ch[0]) pc(ch[ch[0]--] ^ 48);
}
}  // namespace IO
using namespace IO;

namespace Linear_sieves {
cs int P = 300005;
int prime[P], pcnt;
bool mark[P];

inline void init(int len = P - 5) {
  mark[1] = true;
  for (int re i = 2; i <= len; ++i) {
    if (!mark[i]) prime[++pcnt] = i;
    for (int re j = 1; j <= pcnt && i * prime[j] <= len; ++j) {
      mark[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
}  // namespace Linear_sieves

namespace Find_root {
#define complex COMPLEX
using namespace Linear_sieves;

inline ll mul(cs ll &a, cs ll &b, cs ll &mod) {
  return (a * b - (ll)((long double)a / mod * b) * mod + mod) % mod;
}
inline ll quickpow(ll a, ll b, cs ll &mod, ll res = 1) {
  for (; b; b >>= 1, a = mul(a, a, mod))
    if (b & 1) res = mul(res, a, mod);
  return res;
}

inline ll ex_gcd(cs ll &a, cs ll &b, ll &x, ll &y) {
  if (!b) {
    y = 0;
    x = 1;
    return a;
  }
  ll t = ex_gcd(b, a - a / b * b, y, x);
  y -= (a / b) * x;
  return t;
}
inline ll inv(cs ll a, cs ll mod) {
  ll x, y;
  ll t = ex_gcd(a, mod, x, y);
  return (x % mod + mod) % mod;
}

ll W, Mod;
class complex {
 public:
  ll x, y;
  complex(cs ll &_x = 0, cs ll &_y = 0) : x(_x), y(_y) {}
  inline friend complex operator*(cs complex &a, cs complex &b) {
    return complex((mul(a.x, b.x, Mod) + mul(mul(a.y, b.y, Mod), W, Mod)) % Mod,
                   (mul(a.x, b.y, Mod) + mul(a.y, b.x, Mod)) % Mod);
  }
};

complex quickpow(complex a, ll b) {
  complex res(1, 0);
  for (; b; b >>= 1, a = a * a)
    if (b & 1) res = res * a;
  return res;
}

inline bool isprime(ll x) {
  if (x <= P - 5) return !mark[x];
  if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0 || x % 31 == 0 ||
      x % 24251 == 0)
    return false;
  re ll t = x - 1, s;
  t >>= (s = __builtin_ctzll(t));
  for (int re i = 1; i <= 5; ++i) {
    re ll p = prime[rand() % pcnt + 1];
    re ll num = quickpow(p, t, x), pre = num;
    for (int re j = 0; j < s; ++j) {
      num = mul(num, num, x);
      if (num == 1 && pre != x - 1 && pre != 1) return false;
      pre = num;
      if (num == 1) break;
    }
    if (num ^ 1) return false;
  }
  return true;
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll Pollard_rho(ll x) {
  if (x % 2 == 0) return 2;
  if (x % 3 == 0) return 3;
  if (x % 5 == 0) return 5;
  if (x % 7 == 0) return 7;
  if (x % 31 == 0) return 31;
  if (x % 24251 == 0) return 24251;
  re ll n = 0, m = 0, t = 1, q = 1, c = rand() % (x - 2) + 2;
  for (int re k = 2;; k <<= 1, m = n, q = 1) {
    for (int re i = 1; i <= k; ++i) {
      n = (mul(n, n, x) + c) % x;
      q = mul(q, abs(n - m), x);
    }
    if ((t = gcd(q, x)) > 1) return t;
  }
}

ll fact[60], cntf;
inline void sieves(ll x) {
  if (x == 1) return;
  if (isprime(x)) {
    fact[++cntf] = x;
    return;
  }
  re ll p = x;
  while (p == x) p = Pollard_rho(p);
  sieves(p);
  while (x % p == 0) x /= p;
  sieves(x);
}

inline ll solve_2k(ll a, ll k) {
  if (a % (1 << k) == 0) return 0;
  a %= (1 << k);
  re ll t = 0, res = 1;
  a >>= (t = __builtin_ctzll(a));
  if ((a & 7) ^ 1) return -1;
  if (t & 1) return -1;
  k -= t;
  for (int re i = 4; i <= k; ++i) {
    res = (res + (a % (1 << i) - res * res) / 2) % (1 << k);
  }
  res %= 1 << k;
  if (res < 0) res += 1 << k;
  return res << (t >> 1);
}

inline ll solve_p(ll a, ll p) {
  a %= p;
  if (quickpow(a, (p - 1) >> 1, p) == p - 1) return -1;
  re ll b;
  Mod = p;
  while (true) {
    b = rand() % p;
    W = (mul(b, b, p) - a + p) % p;
    if (quickpow(W, (p - 1) >> 1, p) == p - 1) break;
  }
  re ll ans = quickpow(complex(b, 1), (p + 1) >> 1).x;
  return min(ans, p - ans);
}

inline ll solve_pk(ll a, ll k, ll p, ll mod) {
  if (a % mod == 0) return 0;
  re ll t = 0, hmod = 1;
  while (a % p == 0) a /= p, ++t, hmod *= (t & 1) ? p : 1;
  if (t & 1) return -1;
  k -= t;
  mod /= hmod * hmod;
  re ll res = solve_p(a, p);
  if (res == -1) return -1;
  complex tmp(res, 1);
  W = a;
  Mod = mod;
  tmp = quickpow(tmp, k);
  res = mul(tmp.x, inv(tmp.y, Mod), Mod);
  return res * hmod;
}

ll remain[20], mod[20], p;
inline ll CRT() {
  re ll ans = 0;
  for (int re i = 1; i <= cntf; ++i) {
    ans =
        (ans + mul(mul(p / mod[i], inv(p / mod[i], mod[i]), p), remain[i], p)) %
        p;
  }
  return ans;
}

inline ll solve(ll a, ll pmod) {
  a %= pmod;
  cntf = 0;
  p = pmod;
  sieves(pmod);
  if (cntf > 1) sort(fact + 1, fact + cntf + 1);
  if (cntf > 1) cntf = unique(fact + 1, fact + cntf + 1) - fact - 1;
  for (int re i = 1; i <= cntf; ++i) {
    re ll now = 0, rmod = 1;
    while (pmod % fact[i] == 0) pmod /= fact[i], ++now, rmod *= fact[i];
    mod[i] = rmod;
    if (fact[i] == 2)
      remain[i] = solve_2k(a, now);
    else
      remain[i] = solve_pk(a, now, fact[i], rmod);
    if (remain[i] == -1) return -1;
  }
  return CRT();
}

#undef complex
}  // namespace Find_root

int T;
signed main() {
  srand(time(0));
  Linear_sieves::init();
  T = getint();
  while (T--) {
    re ll a = getint(), p = getint(), ans;
    outint(ans = Find_root::solve(a, p));
    pc('\n');
  }
  FLUSH();
  return 0;
}
