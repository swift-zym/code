#include <bits/stdc++.h>
#define MOD 9901
using namespace std;
int inv[20001], jc[20001];
void exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    int t = x;
    x = y, y = t - a / b * y;
}
int main()
{
    jc[0] = 1;
    for (int i = 1; i <= 20001; i++)
    {
        jc[i] = i % MOD * jc[i - 1] % MOD;
        if (jc[i] == 0)
            jc[i] = 1;
    }
    for (int i = 1; i <= 20001; i++)
    {
        int x, y;
        exgcd(jc[i], MOD, x, y);
        inv[i] = (x % MOD + MOD) % MOD;
    }
    int m, n;
    cin >> m >> n;
    cout << jc[m] * inv[n] % MOD * inv[m - n] % MOD;
#ifdef WIN32
    system("pause");
#endif
    return 0;
}