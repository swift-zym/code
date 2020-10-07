#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[2000000],ans[200000];
int len[2000000];
signed main(){
    freopen("A.in","r",stdin);
    freopen("A.ans","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    a[0]=-1e9;
    a[n+1]=1e9;
    int pos;
    for(int i=1;i<=n+1;i++){
        ans[i]=-1e17;
        for(int j=1;j<=i;j++){
            if(a[i]>=a[i-j])
            if(ans[i-j]+(i==n+1?0:a[i])-(j-1)*j/2>ans[i]){
                ans[i]=ans[i-j]+(i==n+1?0:a[i])-(j-1)*j/2;
                pos=i-j;
            }
        }
        //cout<<i<<" "<<pos<<endl;
        //cout<<">"<<ans[i]<<endl;
    }
    printf("%lld\n",ans[n+1]);
    return 0;
}*