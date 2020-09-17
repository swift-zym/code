//
// Created by swift on 2020/7/19.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
inline void read(int &x)
{
    char c=getchar();x=0;
    while(c>'9'||c<'0') c=getchar();
    while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
}
bool vis[310000];;
char s[100];
int x,y,z;
int a[310000];
inline bool judge(int x)
{
    if(x==0) return 0;
    while(x>0)
    {
        if(x%10!=3&&x%10!=2) return 0;
        x/=10;
    }
    return 1;
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.hack.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    for(int i=1;i<=2e4;i++)
    {
        if(judge(i)) vis[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%s",s);
        if(s[0]=='c')
        {
            read(x),read(y);
            //cout<<x<<" "<<y<<endl;
            int ans=0;
            for(int j=x;j<=y;j++)
                ans+=vis[a[j]];
            printf("%d\n",ans);
        }
        else
        {
            read(x),read(y),read(z);
            for(int j=x;j<=y;j++)
                a[j]+=z;
        }

    }
#ifdef _WIN32
    system("pause");
#endif
}