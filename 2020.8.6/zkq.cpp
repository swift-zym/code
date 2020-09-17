//
// Created by swift on 2020/8/6.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[1000];
int b[1000];
int vis[1000];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(vis,0,sizeof(vis));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++) cin>>a[i],vis[a[i]]++,b[a[i]]=vis[a[i]];
        int ans=0;
        for(int s=1;s<=n*2;s++)
        {
            int res=0;
            for(int i=1;i<=2*n;i++) vis[i]=b[i];
            for(int i=1;i<=n;i++)
            {
                if(s<=a[i]) continue;
                if(s-a[i]==a[i])
                {
                    if(vis[a[i]]>=2) vis[a[i]]-=2,res++;
                    continue;
                }
                if(vis[s-a[i]]&&vis[a[i]]) res++,vis[s-a[i]]--,vis[a[i]]--;
            }
            ans=max(res,ans);
            //	cout<<"  > "<<s<<">>"<<ans<<" "<<res<<endl;
        }
        cout<<ans<<endl;

    }
}