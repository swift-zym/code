#include<bits/stdc++.h>
#include<bits/extc++.h>
#define MOD 9901
using namespace std;
#define int long long
int qpow(int a,int b){
    if(b==0)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
int solve(int a,int b){
    if(b==0)return 1;
    return b%2?(qpow(a,(b+1)/2)+1)*solve(a,(b-1)/2)%MOD
              :((qpow(a,b/2)+1)*solve(a,b/2-1)+qpow(a,b))%MOD;
}
signed main(){
    int a,b,ans=1;
    cin>>a>>b;
    for(int i=2;i<=a;i++){
        int num=0;
        while(a%i==0){
            a/=i;
            num++;
        }
        ans*=solve(i,num*b);
        ans%=MOD;
    }
    if(!a)puts("0");
    else cout<<ans<<endl;
    return 0;
}
/*
{
    name: "张一鸣",
    id: "swift",
    belong: "2025",
    say: "Write the Code. Change the world.",
    qq: 1149395947,
    zhihu: "https://www.zhihu.com/people/swift-zym",
    music_163: "https://music.163.com/#/user/home?id=1986415245",
    bilibili: "https://space.bilibili.com/492358939",
    blog: "https://zhangyiming.tech/",
}
*/