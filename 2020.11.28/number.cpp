#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int copy1(int x){
    char s[101];
    sprintf(s,"%lld",x);
    int tmp=0,len=strlen(s);
    for(int i=0;i<len;i++){
        tmp*=10;
        tmp+=s[i]-'0';
    }
    for(int i=len-1;i>=0;i--){
        tmp*=10;
        tmp+=s[i]-'0';
    }
    return tmp;
}
int copy2(int x){
    char s[101];
    sprintf(s,"%lld",x);
    int tmp=0,len=strlen(s);
    for(int i=0;i<len-1;i++){
        tmp*=10;
        tmp+=s[i]-'0';
    }
    for(int i=len-1;i>=0;i--){
        tmp*=10;
        tmp+=s[i]-'0';
    }
    return tmp;
}
int trans(int x){
    int bas=1,val=0;
    while(x){
        val+=bas*(x%10);
        x/=10;
        bas*=9;
    }
    return val;
}
int trans2(int x){
    int tmp=0;
    while(x){
        tmp*=10;
        tmp+=(x%9);
        x/=9;
    }
    return tmp;
}
int solve(int x){
    if(!x)return 0;
    int sum=0;
    int l=1,r=x,ans;
    cout<<trans2(10)<<endl;
    while(l<=r){
        int mid=(l+r)/2;
        cout<<mid<<" "<<trans(copy1(trans2(mid)))<<endl;
        if(trans(copy1(trans2(mid)))<=x){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    sum+=ans;
    cout<<ans<<endl;
    l=1;r=x;
    while(l<=r){
        int mid=(l+r)/2;
        if(trans(copy2(trans2(mid)))<=x){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    sum+=ans;
    cout<<ans<<endl;
    return sum;
}
signed main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    int T;scanf("%lld",&T);
    while(T--){
        int l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(r)-solve(l-1));
    }
    return 0;
}