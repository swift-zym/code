#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(s)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
int n,m,a[40001],b[40001],num[40001],type[40001];
int ans;
inline void read(int &x){
    char c=getchar();x=0;
    bool f=0;
    while(c>'9'||c<'0') {if(c=='-') f=1;c=getchar();}
    while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    x=f?-x:x;
}
int main(){
    read(n);
    read(m);
    for(int i=1;i<=n;i++)read(a[i]);
    mempcpy(b,a,sizeof(a));
    sort(b+1,b+n+1);
    int nn=unique(b+1,b+n+1)-b;
    for(int i=1;i<=n;i++){
        int tmp=a[i];
        a[i]=lower_bound(b+1,b+nn,a[i])-b;
        type[a[i]]=tmp;
    }
    for(int i=1;i<=m;i++){
        int l,r;
        read(l);read(r);

        l=(l+ans-1)%n+1;
        r=(r+ans-1)%n+1;
        int mx=-1,id;
        if(l>r)swap(l,r);
        for(int i=l;i<=r;i++){
            num[a[i]]++;
        }
        for(int i=1;i<=nn;i++){
            if(num[i]>mx){
                mx=num[i];
                id=i;
            }
        }
        ans=type[id];
        printf("%d\n",ans);
        for(int i=l;i<=r;i++){
            num[a[i]]--;
        }
    }
    return 0;
}