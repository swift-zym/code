#include<iostream>
#define int long long
#define MOD 1000000007
using namespace std;
int n,x,pos,a,b;
int P(int r,int s){
    int val=1;
    for(int i=r;i>r-s;i--){
        val*=i;
        val%=MOD;
    }
    return val;
}
signed main(){
    cin>>n>>x>>pos;
    bool flag=1;
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(mid==pos)flag=0;
        if(mid<pos+1){
            a++;
            l=mid+1;
        }
        else{
            b++;
            r=mid;
        }
    }
    int ans=1;
    if(flag){
        ans*=P(x-1,a);
        ans%=MOD;
        ans*=P(n-x,b);
        ans%=MOD;
        ans*=P(n-a-b-1,n-a-b-1);
    }
    else
    {
        ans*=P(x-1,a-1);
        ans%=MOD;
        ans*=P(n-x,b);
        ans%=MOD;
        ans*=P(n-a-b,n-a-b);
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}