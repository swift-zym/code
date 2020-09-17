#include<bits/stdc++.h>
using namespace std;
struct candy{
    int id,a,b;
    bool operator <(const candy &c)const{
        return a<c.a;
    }
}c[100001];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&c[i].a);
    for(int i=1;i<=n;i++)scanf("%d",&c[i].b);
    for(int i=1;i<=n;i++)c[i].id=i;
    sort(c+1,c+n+1);
    cout<<n/2+1<<endl;
    if(n%2){
        cout<<c[n].id<<" ";n--;
    }
    else{
        cout<<c[n].id<<" "<<c[n-1].id<<" ";n-=2;
    }
    for(int i=1;i<=n;i+=2){
        if(c[i].b>c[i+1].b){
            cout<<c[i].id<<" ";
        }
        else{
            cout<<c[i+1].id<<" ";
        }
    }
    cout<<endl;
    return 0;
}