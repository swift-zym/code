#include<bits/stdc++.h>
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f  = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int n, A, B, C, D, a[1000000];
double Cal(double x) {return ((A * x + B) * x + C) * x + D;}
int main() {
	freopen("example_min3.in","r",stdin);
    n = ri(); A = ri(); B = ri(); C = ri(); D = ri();
    for(int i = 1;i <= n; ++i) a[i] = ri();
    for(int i = 1;i <= n; ++i) if(fabs(Cal(a[i])) >= 1e13) {return printf("%d\n", a[i]), 0;};
    puts("ODK");
	return 0;
}

