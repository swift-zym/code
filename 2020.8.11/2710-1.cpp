//
// Created by swift on 2020/8/11.
//

#include<bits/stdc++.h>
using namespace std;
int ans;
inline void read(int &x)
{
    char c=getchar();x=0;
    bool f=0;
    while(c>'9'||c<'0') {if(c=='-') f=1;c=getchar();}
    while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    x=f?-x:x;
}
int n,c,m;
int a[100001],num[100001];
int main(){
    
    read(n);read(c);read(m);
    for(int i=1;i<=n;i++)read(a[i]);
    for(int i=1;i<=m;i++){
        int l,r;
        read(l);read(r);
        l=(l+ans)%n+1;r=(r+ans)%n+1;
        if(l>r)swap(l,r);
        for(int i=l;i<=r;i++){
            num[a[i]]++;
        }
        ans=0;
        for(int i=1;i<=c;i++){
            if(num[i]%2==0&&num[i]/2>0){
              ans++;
            }
        }
        for(int i=l;i<=r;i++){
            num[a[i]]--;
        }
        printf("%d\n",ans);
    }
    return 0;
}