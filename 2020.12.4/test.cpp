#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 2;
int n, a[maxn], b[maxn], pos[maxn], mp[maxn], t[maxn];
long long ans;
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("data.in", "r", stdin);
    //freopen("user.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
        pos[a[i]] = i;
    }
//  for (int i = 1; i <= n; ++i)
//      cout << a[i] << " ";
//  cout << endl;
//  for (int i = 1; i <= n; ++i)
//      cout << pos[i] << " ";
//  cout << endl;
    for (int i = 1; i <= n; ++i)
        mp[i] = max(mp[i - 1], pos[i]);
    for (int i = 1; i <= n; ++i)
        t[i] = max(1, mp[i] - i);
    for (int i = 0; i < n; ++i)
        ans += (long long)max(t[i], t[i + 1]);
    return cout << ans << endl, 0;
}