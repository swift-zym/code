//题目名：Power Strings
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        if (s == ".")
            break;
        string s2 = s;
        int nxt[s.length() + 1];
        memset(nxt, 0, sizeof(nxt));
        nxt[0] = -1;
        int i = -1, j = 1;
        while (j < s.length())
        {
            while (i != -1 && s[j] != s[i + 1])
                i = nxt[i];
            if (s[j] == s[i + 1])
                i++;
            nxt[j] = i;
            j++;
        }
        int n = s.length();
        if (n % (n - 1 - nxt[n - 1]) == 0)
        {
            printf("%d\n", n / (n - 1 - nxt[n - 1]));
        }
        else
        {
            printf("1\n");
        }
    }
}