#include <set>
#include <cctype>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 200010;
const unsigned long long num = 19260817,num2=123529;
const unsigned long long MOD = 998244353,MOD2=1000000007;
struct node{
    unsigned long long x,y;
    bool operator <(const node &t)const{
        if(x!=t.x)return x<t.x;
        return y<t.y;
    }
};
set<node> S;
unsigned long long h[maxn],hh[maxn];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    h[1] = getchar();
    while (!isalpha(h[1])) h[1] = getchar();
    h[1] -= 'a';
    hh[1]=h[1];
    unsigned long long p = 1;
    for (int i = 1; i <= m; i++) p *= num,p%=MOD;
    unsigned long long pp = 1;
    for (int i = 1; i <= m; i++) pp *= num2,pp%=MOD2;
    for (int i = 2; i <= n; i++){
         char c=getchar();
         h[i] = (h[i - 1] * num%MOD + c - 'a')%MOD;
         hh[i] = (hh[i - 1] * num2%MOD2 + c - 'a')%MOD2;
    }
    for (int i = 0; i + m <= n; i++){
         S.insert({(h[i + m] - h[i] * p%MOD+MOD)%MOD,(hh[i + m] - hh[i] * pp%MOD2+MOD2)%MOD2});
    }
    printf("%llu\n", S.size());
    return 0;
}