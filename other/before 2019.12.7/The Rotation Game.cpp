//题目名：The Rotation Game
#include <bits/stdc++.h>
using namespace std;
int a[8][8], ans, maxDeep;
char out[100001];
bool flag;
void moveR(int s)
{
    int bf = a[s][7];
    for (int i = 7; i >= 2; i--)
    {
        a[s][i] = a[s][i - 1];
    }
    a[s][1] = bf;
}
void moveL(int s)
{
    int bf = a[s][1];
    for (int i = 1; i <= 6; i++)
    {
        a[s][i] = a[s][i + 1];
    }
    a[s][7] = bf;
}
void moveD(int s)
{
    int bf = a[7][s];
    for (int i = 7; i >= 2; i--)
    {
        a[i][s] = a[i - 1][s];
    }
    a[1][s] = bf;
}
void moveU(int s)
{
    int bf = a[1][s];
    for (int i = 1; i <= 6; i++)
    {
        a[i][s] = a[i + 1][s];
    }
    a[7][s] = bf;
}
int cmp()
{
    int maxn = -1;
    map<int, int> ma;
    ma[a[3][3]]++;
    maxn = max(maxn, ma[a[3][3]]);
    ma[a[3][4]]++;
    maxn = max(maxn, ma[a[3][4]]);
    ma[a[3][5]]++;
    maxn = max(maxn, ma[a[3][5]]);
    ma[a[4][3]]++;
    maxn = max(maxn, ma[a[4][3]]);
    ma[a[4][5]]++;
    maxn = max(maxn, ma[a[4][5]]);
    ma[a[5][3]]++;
    maxn = max(maxn, ma[a[5][3]]);
    ma[a[5][4]]++;
    maxn = max(maxn, ma[a[5][4]]);
    ma[a[5][5]]++;
    maxn = max(maxn, ma[a[5][5]]);
    return maxn;
}
void dfs(int deep)
{
    if (!flag)
        return;
    if (cmp() == 8)
    {
        ans = min(ans, deep - 1);
        flag = 0;
        return;
    }
    if (deep > maxDeep)
        return;
    if (8 - cmp() + deep > ans)
        return;
    out[deep] = 'A';
    moveU(3);
    dfs(deep + 1);
    if (!flag)
        return;
    moveD(3);
    out[deep] = 'B';
    moveU(5);
    dfs(deep + 1);
    if (!flag)
        return;
    out[deep] = 'C';
    moveD(5);
    moveR(3);
    dfs(deep + 1);
    if (!flag)
        return;
    moveL(3);
    out[deep] = 'D';
    moveR(5);
    dfs(deep + 1);
    if (!flag)
        return;
    moveL(5);
    out[deep] = 'E';
    moveD(5);
    dfs(deep + 1);
    if (!flag)
        return;
    moveU(5);
    out[deep] = 'F';
    moveD(3);
    dfs(deep + 1);
    if (!flag)
        return;
    out[deep] = 'G';
    moveU(3);
    moveL(5);
    dfs(deep + 1);
    if (!flag)
        return;
    moveR(5);
    out[deep] = 'H';
    moveL(3);
    dfs(deep + 1);
    if (!flag)
        return;
    moveR(3);
} 
int main()
{
    int s[25];
    while (scanf("%d", &s[1]) != EOF)
    {
        if (s[1] == 0)
            break;
        ans = 1e8;
        for (int i = 2; i <= 24; i++)
            scanf("%d", &s[i]);
        a[1][3] = s[1];
        a[1][5] = s[2];
        a[2][3] = s[3];
        a[2][5] = s[4];
        for (int i = 5; i <= 11; i++)
        {
            a[3][i - 4] = s[i];
        }
        a[4][3] = s[12];
        a[4][5] = s[13];
        for (int i = 14; i <= 20; i++)
        {
            a[5][i - 13] = s[i];
        }
        a[6][3] = s[21];
        a[6][5] = s[22];
        a[7][3] = s[23];
        a[7][5] = s[24];
        for (maxDeep = 1;; maxDeep++)
        {
            flag = 1;
            dfs(1);
            if (ans != 1e8)
            {
                for (int i = 1; i <= ans; i++)
                {
                    printf("%c", out[i]);
                }
                putchar(10);
                printf("%d\n", a[3][3]);
                break;
            }
        }
    }
    return 0;
}