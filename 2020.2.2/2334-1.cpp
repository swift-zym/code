#include <bits/stdc++.h>
using namespace std;
char s[2000000];int nxt[2000000];
int main() {
    while (scanf("%s", s) != EOF) {
        nxt[0] = -1;
        int len = strlen(s);
        for (int i = 1, j = -1; i < len; i++) {
            while (j != -1 && s[j + 1] != s[i]) j = nxt[j];
            if (s[j + 1] == s[i])
                j++;
            nxt[i] = j;
        }
        if ((len) % (len - 1 - nxt[len - 1]) == 0) {
            printf("%d\n", (len) / (len - 1 - nxt[len - 1]));
        } else {
            puts("1");
        }
    }
    return 0;
}
