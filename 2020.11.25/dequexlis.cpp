#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100001],len,b[100001],v[100001],ans;
int main(){
    freopen("dequexlis.in","r",stdin);
    freopen("dequexlis.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
        int pos=lower_bound(b+1,b+len+1,a[i])-b;
        if(pos>len)len++;
        b[pos]=a[i];
        v[i]=pos;
    }
    len=0;
    for(int i=n;i>=1;i--){
        int pos=lower_bound(b+1,b+len+1,-a[i])-b;
        if(pos>len)len++;
        b[pos]=-a[i];
        v[i]+=pos-1;
        ans=max(ans,v[i]);
    }
    printf("%d\n",ans);
    return 0;
}