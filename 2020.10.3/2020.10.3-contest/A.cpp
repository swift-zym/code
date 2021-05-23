#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int c[200001];
struct node{
    int a,b;
    bool operator <(const node &t)const{
        return a<t.a;
    }
}a[200001];
int mi=1e8;
int ned,tot,tmp,tmp_val;
int ans;
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=m;i++)scanf("%lld%lld",&a[i].a,&a[i].b);
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++){
        if(a[i].b==-1){
            mi=min(mi,a[i].a);
        }
    }
    for(int i=1;i<=n;i++)ned+=c[i];
    for(int i=1;i<=m;i++){
        if(a[i].a<mi){
            tmp+=a[i].b;
            tmp_val+=a[i].a*a[i].b;
        }
        else{
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(tot+tmp<=ned){
            tot+=tmp;
            ans+=tmp_val;
        }
        else if(tot<ned){
            for(int j=1;j<=m;j++){
                if(tot==ned)break;
                if(a[j].b>(ned-tot)){
                    ans+=a[j].a*(ned-tot);
                    tot=ned;
                }
                else{
                    ans+=a[j].a*a[j].b;
                    tot+=a[j].b;
                }
            }
        }
        if(tot<c[i]){
            ans+=(c[i]-tot)*mi;
            ned-=c[i];
            tot=0;
        }
        else{
            tot-=c[i];
            ned-=c[i];
        }
    }
    printf("%lld\n",ans);
    
    return 0;
}