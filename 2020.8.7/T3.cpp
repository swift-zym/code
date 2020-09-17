//
// Created by swift on 2020/8/8.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,a[100001],num[100],sum[100];
signed main(){
    //freopen("3.in","r",stdin);
    //freopen("3.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        vector<int>v;
        int tmp=a[i];
        while(tmp){
            v.push_back(tmp%2);
            tmp/=2;
        }
        for(int j=0;j<v.size();j++){
            num[j]+=v[j];
        }
    }
    scanf("%lld",&q);
    for(int i=1;i<=q;i++){
        int m,ans=0;
        scanf("%lld",&m);
        bool flag=1;
        int tmp=0;
        for(int k=60-1;k>=0;k--){
            if((m-tmp)/(1ll<<k)<min(n-num[k],num[k])){
                flag=0;
                break;
            }
            tmp+=min(n-num[k],num[k])*(1ll<<k);
            sum[k]=tmp;
        }
        if(flag)
        for(int j=60;j>=0;j--){
            //cout<<m<<" "<<ans<<endl;
            tmp=sum[0]-sum[j];
            //cout<<">"<<tmp<<endl;
            //cout<<">"<<n<<" "<<num[j]<<endl;
            if((m-tmp)/(1ll<<j)>=n-num[j]){
                //cout<<"ok"<<endl;
                //flag=1;
                m-=(n-num[j])*(1ll<<j);
                ans|=(1ll<<j);
            }
            else{
                if(m/(1ll<<j)<num[j]){
                   // puts("type2");
                    flag=0;
                    break;
                }
                m-=num[j]*(1ll<<j);
            }
        }
        if(flag&&m>=0)
        printf("%lld\n",ans);
        else
        puts("-1");
    }
    return 0;
}