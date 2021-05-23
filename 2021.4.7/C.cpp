#pragma GCC optmize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int num[] = {1, 2, 3, 5, 7}, mod[] = {2, 3, 5, 7, 11, 47};
int n, v[1000][5][6], dp[2][2][3][5][7][11][47], ans;
int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 6; j++) {
      v[0][i][j] = num[i] % mod[j];
    }
  for (int i = 1; i < 1000; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 6; k++) {
        v[i][j][k] = v[i - 1][j][k] * 10 % mod[k];
      }
    }
  }
  int x = 0;
  dp[x ^ 1][0][0][0][0][0][0] = 1;
  for (int i = 1; i <= n; i++, x ^= 1) {
    int tmp[6];
    for (int j = 0; j < 5; j++) {
      for (tmp[0] = 0; tmp[0] < mod[0]; tmp[0]++)
        for (tmp[1] = 0; tmp[1] < mod[1]; tmp[1]++)
          for (tmp[2] = 0; tmp[2] < mod[2]; tmp[2]++)
            for (tmp[3] = 0; tmp[3] < mod[3]; tmp[3]++)
              for (tmp[4] = 0; tmp[4] < mod[4]; tmp[4]++)
                for (tmp[5] = 0; tmp[5] < mod[5]; tmp[5]++) {
                  dp[x][(tmp[0] + v[i - 1][j][0]) % mod[0]]
                    [(tmp[1] + v[i - 1][j][1]) % mod[1]]
                    [(tmp[2] + v[i - 1][j][2]) % mod[2]]
                    [(tmp[3] + v[i - 1][j][3]) % mod[3]]
                    [(tmp[4] + v[i - 1][j][4]) % mod[4]]
                    [(tmp[5] + v[i - 1][j][5]) % mod[5]] +=
                      dp[x ^ 1][tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]][tmp[5]];
                  dp[x][(tmp[0] + v[i - 1][j][0]) % mod[0]]
                    [(tmp[1] + v[i - 1][j][1]) % mod[1]]
                    [(tmp[2] + v[i - 1][j][2]) % mod[2]]
                    [(tmp[3] + v[i - 1][j][3]) % mod[3]]
                    [(tmp[4] + v[i - 1][j][4]) % mod[4]]
                    [(tmp[5] + v[i - 1][j][5]) % mod[5]] %= 9973;
                }
    }
  }
  int tmp[6];
  for (tmp[0] = 1; tmp[0] < mod[0]; tmp[0]++)
    for (tmp[1] = 1; tmp[1] < mod[1]; tmp[1]++)
      for (tmp[2] = 1; tmp[2] < mod[2]; tmp[2]++)
        for (tmp[3] = 1; tmp[3] < mod[3]; tmp[3]++)
          for (tmp[4] = 1; tmp[4] < mod[4]; tmp[4]++)
            for (tmp[5] = 1; tmp[5] < mod[5]; tmp[5]++) {
              ans += dp[x ^ 1][tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]][tmp[5]];
              ans %= 9973;
            }
  cout << ans << endl;
}