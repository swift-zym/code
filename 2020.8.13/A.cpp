#include<bits/stdc++.h>
using namespace std;
struct node{
    int h,v;
    bool operator <(const node &t)const{
        return h<t.h;
    }
}a[100001];
int n;
vector<int>v;
int ans[1000001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].h,&a[i].v);
    }
    sort(a+1,a+n+1);
    v.push_back(-1);
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(n-i<a[i].v){
            puts("Impossible");
            return 0;
        }
        ans[v[min(a[i].v+1,(n-i)-a[i].v+1)]]=a[i].h;
        v.erase(v.begin()+min(a[i].v+1,(n-i)-a[i].v+1));
    }
    for(int i=1;i<=n;i++){
        if(i!=1)putchar(' ');
        printf("%d",ans[i]);
    }
    return 0;
}