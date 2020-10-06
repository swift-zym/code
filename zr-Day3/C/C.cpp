#include <bits/stdc++.h>
//#include <windows.h>
//#define int long long
int prime[18]= {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
using namespace std;
int gc(int a,int b)
{
    return b?gc(b,a%b):a;
}
int gcd(int a,int b)
{
    if(a<b)
    {
        swap(a,b);
    }
    return gcd(a,b);
}
#define N 101
int n;
int g[N];
int p1,p2,p3;
int top;
int p[20];
bool used[20];
int debug;
int dp[N][20];
int bk[N][20];
int ans[N];
int answer=114514;
void add(int a,int b,int c,bool fuck)
{
    p[0]=1;
    debug++;
    memset(used,0,sizeof(used));
    top=0;
    if(a)
    {
        top++;
        p[top]=a;
        for(int i=1; i<=17; i++)
        {
            if(a%prime[i]==0)
            {
                used[i]=1;
            }
        }
    }
    if(b)
    {
        top++;
        p[top]=b;
        for(int i=1; i<=17; i++)
        {
            if(b%prime[i]==0)
            {
                used[i]=1;
            }
        }
    }
    if(c)
    {
        top++;
        p[top]=c;
        for(int i=1; i<=17; i++)
        {
            if(c%prime[i]==0)
            {
                used[i]=1;
            }
        }
    }
    for(int i=1; i<=17; i++)
    {
        if(!used[i])
        {
            if(i==4)
            {
                if(fuck)
                {
                    top++;
                    p[top]=49;
                }
                else
                {
                    top++;
                    p[top]=7;
                }
                continue;
            }
            top++;
            p[top]=prime[i];
        }
    }
    sort(p+1,p+top+1);
    //for(int i=1; i<=top; i++)
    //{
    //    printf("%d ",p[i]);
    //}
    //printf("\n");
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1; i<=n; i++)
    {
        int mn=114514,mnp;
        bk[i][0]=0;
        dp[i][0]=dp[i-1][0]+g[i]-1;
        for(int j=1; j<=top; j++)
        {
            if(dp[i-1][j-1]<=mn)
            {
                mn=dp[i-1][j-1];
                mnp=j-1;
            }
            if(dp[i-1][j]+g[i]-1<=mn+abs(g[i]-p[j]))
            {
                dp[i][j]=dp[i-1][j]+g[i]-1;
                bk[i][j]=j;
            }
            else
            {
                dp[i][j]=mn+abs(g[i]-p[j]);
                bk[i][j]=mnp;
            }

        }
    }
    //for(int i=1; i<=n; i++)
    //{
    //    for(int j=0; j<=top; j++)
    //    {
    //        if(dp[i][j]==0x3f3f3f3f)
    //        {
    //            printf("X ");
    //        }
    //        else
    //        {
    //            printf("%2d",dp[i][j]);
    //        }
    //        printf("(%d)",bk[i][j]);
    //    }
    //    printf("\n");
    //}
    int as=114514;
    int asp;
    for(int i=0; i<=top+1; i++)
    {
        if(as>dp[n][i])
        {
            as=dp[n][i];
            asp=i;
        }
    }
    //printf("ans=%d\n",as);
    if(as<answer)
    {
        answer=as;
        top=asp;
        for(int i=n; i>=1; i--)
        {
            if(bk[i][top]==top)
            {
                ans[i]=1;
            }
            else
            {
                ans[i]=p[top];
                top=bk[i][top];
            }
        }
    }

    //for(int i=1; i<=n; i++)
    //{
    //    printf("%d ",ans[i]);
    //}
}
struct node
{
    int a,id;
    friend bool operator <(node a,node b)
    {
        return a.a<b.a;
    }
} gt[N];
int rk[N];
int main(int argc,char *argv[])
{
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&gt[i].a);
        gt[i].id=i;
    }
    sort(gt+1,gt+n+1);
    for(int i=1; i<=n; i++)
    {
        g[i]=gt[i].a;
        rk[gt[i].id]=i;
    }
    for(p1=2; p1<=58; p1+=2)
    {
        if(p1%3==0)
        {
            if(p1%5==0)
            {
                add(p1,0,0,0);
                add(p1,0,0,1);
            }
            else
            {
                for(p3=5; p3<=55; p3+=10)
                {
                    if(p3%3==0)
                    {
                        continue;
                    }
                    add(p1,0,p3,0);
                    add(p1,0,p3,1);
                }
            }
        }
        else
        {
            for(p2=3; p2<=57; p2+=6)
            {
                if(p1%5==0 || p2%5==0)
                {
                    add(p1,p2,0,0);
                    add(p1,p2,0,1);
                }
                else
                {
                    for(p3=5; p3<=55; p3+=10)
                    {
                        if(p3%3==0)
                        {
                            continue;
                        }
                        add(p1,p2,p3,0);
                        add(p1,p2,p3,1);
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        printf("%d ",ans[rk[i]]);
    }
    return 0;
}