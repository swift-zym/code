#include <bits/stdc++.h>
using namespace std;
char s[2000000];int nxt[2000000];
vector<int>ans;
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
        ans.clear();
        int now=nxt[len-1];
        while(now!=-1){
          if(s[now]==s[len-1])ans.push_back(now+1);
          now=nxt[now];
        }
        ans.push_back(len);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
          if(i)putchar(' ');
          printf("%d",ans[i]);
        }
        putchar(10);
    }
    return 0;
}
