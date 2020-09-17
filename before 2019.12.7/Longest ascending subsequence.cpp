//题目名称：最长上升子序列

//单调栈解法

#include <iostream>
using namespace std;
int main()
{
    int n, stack[5001], top = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int now;
        scanf("%d", &now);
        if (top == 0 || now > stack[top])
        {
            stack[++top] = now;
        }
        else
        {
            int l = 1, r = top;
            while (l <= r)
            {

                int mid = (l + r) / 2;
                if (stack[mid] < now)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            stack[l] = now;
        }
    }
    printf("%d\n", top);
#ifdef WIN32
    system("pause");
#endif
    return 0;
}

//dp解法
