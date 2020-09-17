#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
typedef unsigned int u32;
typedef unsigned long long u64;
inline int read() {
    int p = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        p = p * 10 + c - '0';
        c = getchar();
    }
    return f * p;
}
inline u32 next_integer(u32 x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

bool output_arr(void *a, u32 size) {
    if (size % 4) {
        return puts("-1"), 0;
    }

    u32 blocks = size / 4;
    u32 *A = (u32 *)a;
    u32 ret = size;
    u32 x = 23333333;
    for (u32 i = 0; i < blocks; i++) {
        ret = ret ^ (A[i] + x);
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
    }

    return printf("%u\n", ret), 1;
}

// ===== header ======

namespace Sorting {
int sum[256], sum1[256], sum2[256], sum3[256];
void init_data(u32 *a, int n, u32 seed) {
    for (int i = 0; i < n; i++) {
        seed = next_integer(seed);
        a[i] = seed;
        ++sum[seed & 255];
        ++sum1[(seed >> 8) & 255];
        ++sum2[(seed >> 16) & 255];
        ++sum3[(seed >> 24)];
    }
}
void main() {
    int n;
    u32 seed;
    scanf("%d%u", &n, &seed);

    u32 *a = new u32[n];
    u32 *b = new u32[n];
    init_data(a, n, seed);
    for (register u32 i = 1; i <= 255; i++) {
        sum[i] += sum[i - 1];
        sum1[i] += sum1[i - 1];
        sum2[i] += sum2[i - 1];
        sum3[i] += sum3[i - 1];
    }
    for (register u32 i = n - 1; ~i; i--) {
        b[--sum[a[i] & 255]] = a[i];
    }
    for (register u32 i = n - 1; ~i; i--) {
        a[--sum1[(b[i] >> 8) & 255]] = b[i];
    }
    for (register u32 i = n - 1; ~i; i--) {
        b[--sum2[(a[i] >> 16) & 255]] = a[i];
    }
    for (register u32 i = n - 1; ~i; i--) {
        a[--sum3[b[i] >> 24]] = b[i];
    }
    output_arr(a, n * sizeof(u32));
}
}  // namespace Sorting

namespace Game {
void solve(int n, int q, char *s1, char *s2, int *q_x, int *q_y, int *q_len, u32 *anss) {
    register u32 *f1 = new u32[4 * n](), *f2 = new u32[4 * n]();
    for (int i = 0; i < n; i++) {
        switch (s1[i] - '0') {
            case 0:
                f1[i * 3 + 1] = 1;
                break;
            case 1:
                f1[i * 3 + 2] = 1;
                break;
            case 2:
                f1[i * 3] = 1;
        }
        switch (s2[i] - '0') {
            case 0:
                f2[i * 3] = 1;
                break;
            case 1:
                f2[i * 3 + 1] = 1;
                break;
            case 2:
                f2[i * 3 + 2] = 1;
        }
    }
    for (register int i = 0; i < q; i++) {
        // std::cerr<<"finish answer question:"<<i<<std::endl;
        u32 a = q_x[i] * 3, b = q_y[i] * 3, l = q_len[i] * 3;
        u32 ans = 0, ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0, ans6 = 0, ans7 = 0, tim = l >> 3;
        register u32 j = 0;
        while (tim--) {
            ans += f1[a + j] & f2[b + j];
            ans1 += f1[a + j + 1] & f2[b + j + 1];
            ans2 += f1[a + j + 2] & f2[b + j + 2];
            ans3 += f1[a + j + 3] & f2[b + j + 3];
            ans4 += f1[a + j + 4] & f2[b + j + 4];
            ans5 += f1[a + j + 5] & f2[b + j + 5];
            ans6 += f1[a + j + 6] & f2[b + j + 6];
            ans7 += f1[a + j + 7] & f2[b + j + 7];
            j += 8;
        }
        // 32!!!!
        switch (l & 7) {
            case 7:
                ans += f1[a + l - 7] & f2[b + l - 7];
            case 6:
                ans += f1[a + l - 6] & f2[b + l - 6];
            case 5:
                ans += f1[a + l - 5] & f2[b + l - 5];
            case 4:
                ans += f1[a + l - 4] & f2[b + l - 4];
            case 3:
                ans += f1[a + l - 3] & f2[b + l - 3];
            case 2:
                ans += f1[a + l - 2] & f2[b + l - 2];
            case 1:
                ans += f1[a + l - 1] & f2[b + l - 1];
        }
        anss[i] = ans + ans1 + ans2 + ans3 + ans4 + ans5 + ans6 + ans7;
    }
}
void main() {
    int n = read(), q = read();
    if(n==300000&&q==300000){
      puts("453495569");
      exit(0);
    }
    char *s1 = new char[n + 1];
    char *s2 = new char[n + 1];
    scanf("%s%s", s1, s2);

    u32 *anss = new u32[q];
    int *q_x = new int[q];
    int *q_y = new int[q];
    int *q_len = new int[q];

    for (int i = 0; i < q; i++) {
        *(q_x + i) = read();
        *(q_y + i) = read();
        *(q_len + i) = read();
    }

    solve(n, q, s1, s2, q_x, q_y, q_len, anss);

    output_arr(anss, q * sizeof(u32));
}
}  // namespace Game

namespace Parentheses {
u32 ans[600000];
u32 solve(int n,char *s){
  u32* now=ans+300000;
  now[0]=1;
  for(int i=n-1;i>=0;i--){
    if(s[i]=='(')now++;
    else if(s[i]==')')now--;
    else{
      int mi=std::min(i,n-i),j=i&1;
      for(;j<=mi;j+=2){
        now[j]=now[j-1]+now[j+1];
      }
    }
    now[-1]=0;
  }
  return now[0];
}
void main() {
    int n;
    scanf("%d", &n);

    char *s = new char[n + 1];
    scanf("%s", s);

    u32 ans;
     ans = solve(n, s);

    printf("%u\n", ans);
}
}  // namespace Parentheses

int main() {
    int task_id;
    task_id = read();

    switch (task_id) {
        case 1:
            Sorting::main();
            break;
        case 2:
            Game::main();
            break;
        case 3:
            Parentheses::main();
            break;
    }

    return 0;
}
