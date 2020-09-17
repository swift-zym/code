//
// Created by swift on 2020/6/15.
//

#include<bits/stdc++.h>
using namespace std;
int a,b,c,k,st,ed,check=1,l[10];
int main()
{
    freopen("P1102-3.in","r",stdin);
    freopen("P1102-3.out","w",stdout);
    scanf("%d%d%d",&a,&b,&c);
    k=__gcd(__gcd(a,b),c);
    a/=k,b/=k,c/=k;
    st=123/a+(123%a>0),ed=987/c;
    for(int _i=st;_i<=ed;_i++)
    {
        memset(l,0,sizeof(l));
        int i=_i*a,j=_i*b,k=_i*c,flg=1;
        while(i)l[i%10]++,i/=10;
        while(j)l[j%10]++,j/=10;
        while(k)l[k%10]++,k/=10;
        for(int _j=1;_j<=9;_j++)if(!l[_j])flg=0;
        if(flg)printf("%d %d %d\n",_i*a,_i*b,_i*c),check=0;
    }
    if(check)puts("No!!!");
    return 0;
}