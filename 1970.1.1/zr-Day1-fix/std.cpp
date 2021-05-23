#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 0x3f3f3f3f
using namespace std;
int n, ans = 0, res = 0;
ll m;
struct node {
	ll x, t;
} a[maxn];
priority_queue <int> q;
ll tot = 0;
int cmp (node x, node y) {
	return x.x < y.x;
}
int main () {
	scanf ("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld %lld", &a[i].x, &a[i].t);
		if (a[i].x+a[i].t > m) i--, n--;
	}
	if (n == 0) {
		puts("0");
		return 0;
	}
	sort (a+1, a+n+1, cmp);
	for (int i = 1; i <= n; i++) {
		q.push(a[i].t), tot += a[i].t, res++;
		while (tot+a[i].x > m) tot -= q.top(), q.pop(), res--;
		ans = max (ans, res);
	}
	printf ("%d", ans);
    return 0;
}