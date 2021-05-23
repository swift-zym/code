#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int x,y;
}a[100001];
int inv[100001];
int t,n;
inline bool cmp(node a,node b){
    if(a.y-a.x!=b.y-b.x){
        return a.y-a.x>b.y-b.x;
    }
    return a.x>b.x;
}
#undef int
int main(){
    inv[1]=1;
    #define int long long
    scanf("%lld",&t);
    for(int i=1;i<=t;i++){
        int t,sum=0,ans;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
            sum+=a[i].x;
        }
        sort(a+1,a+n+1,cmp);
    ans=sum;
    for(int i=1;i<=n;i++){
        if(sum>a[i].y)
        {
            sum-=a[i].x;
        }
        else{
            ans+=a[i].y-sum;
            sum=a[i].y-a[i].x;
        }
    }
    printf("%lld\n",ans);
    }
    return 0;
}