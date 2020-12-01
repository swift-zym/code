#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct candy{
    int a,b,id;
    bool operator <(const candy &c)const{
        return a+b>c.a+c.b;
    }
}a[100001];
bool cmp(candy a,candy b){
    if(a.b-a.a!=b.b-b.a)
    return a.b-a.a<b.b-b.a;
    return a.a+a.b<b.a+b.b;
}
bool cmpByID(candy a,candy b){
    return a.id<b.id;
}
int n,pre[100001],nxt[100001];
vector<candy>v;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].a,&a[i].b);
    for(int i=1;i<=n;i++)a[i].id=i;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        int pos=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        if(pos>=v.size()){
            v.push_back(a[i]);
        }
        else{
            pre[a[i].id]=v[pos].id;
            nxt[v[pos].id]=a[i].id;
            v[pos]=a[i];
        }
    }
    sort(a+1,a+n+1,cmpByID);
    int cnt=0,num=0;
    for(int i=1;i<=n;i++){
        num+=(!pre[i]);
    }
    printf("%d\n",num);
    for(int i=1;i<=n;i++){
        if(!pre[i]){
            cnt++;
            int now=i;
            while(now){
                printf("%d %d %d\n",a[now].a,a[now].b,cnt);
                now=nxt[now];
            }
        }
    }
    return 0;
}