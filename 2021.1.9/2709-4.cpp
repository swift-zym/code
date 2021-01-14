#include<iostream>
#include<algorithm>
#include<string>
#define MOD 1000000007
#define int long long
using namespace std;
int qpow(int a,int b){
    if(b==0)return 1;
    int tmp=qpow(a,b/2);
    return b%2?tmp*tmp%MOD*a%MOD:tmp*tmp%MOD;
}
int idx[1000000];
void NTT(int *x,int len,int f){
    for(int i=0;i<len;i++){
        if(i<idx[i])swap(x[i],x[idx[i]]);
    }
    for(int mid=1;mid<len;mid<<=1){
        int bas=qpow(3,(MOD-1)/(mid<<1));
        if(f==-1)bas=qpow(bas,MOD-2);
        for(int s=0,t=(1<<mid);s<len;s+=t){
            int now=1;
            for(int k=0;k<mid;k++,now=(now*bas)%MOD){
                int a=x[s+k],b=(now*x[s+mid+k])%MOD;
                x[s+k]=(a+b)%MOD;
                x[s+mid+k]=(a-b+MOD)%MOD;
            }
        }
    }
    if(f==-1){
        int inv=qpow(len,MOD-2);
        for(int i=0;i<len;i++){
            x[i]=x[i]*inv%MOD;
        }
    }
}
int p[1000000],mid,r,ans;
int manacher(string s){
    string x="~|";
    for(auto c:s){
        x+=c;
        x+="|";
    }
    for(int i=1;i<x.length();i++){
        if(i<r){
            p[i]=min(p[mid*2-i],r-i);
        }
        else{
            p[i]=1;
        }
        while(x[i+p[i]]==x[i-p[i]])p[i]++;
        if(i+p[i]>r){
            r=i+p[i];
            mid=i;
        }
        ans+=p[i]/2;
        ans%=MOD;
    }
    return ans;
}
int n,a[1000000],b[1000000],c[1000000];
string s;
signed main(){
    ios::sync_with_stdio(0);
    cin>>s;
    n=s.length();
    int len=1,num=0;
    while(len<2*n){
        len<<=1;num++;
    }
    for(int i=0;i<len;i++){
        idx[i]=((idx[i>>1]>>1)|((i&1)<<(num-1)));
    }
    for(int i=0;i<n;i++){
        a[i]=b[i]=(s[i]=='a');
    }
    NTT(a,len,1);
    NTT(b,len,1);
    for(int i=0;i<len;i++){
        c[i]=(a[i]*b[i])%MOD;
    }
    memset(a,0,sizeof(a));memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        a[i]=b[i]=(s[i]=='b');
    }
    NTT(a,len,1);
    NTT(b,len,1);
    for(int i=0;i<len;i++)c[i]=(c[i]+a[i]*b[i])%MOD;
    int sum=0;
    NTT(c,len,-1);
    for(int i=0;i<=2*n-2;i++){
        sum+=qpow(2,c[i]/2+((i&1)?0:1))-1;
        sum=(sum+MOD%MOD);
    }
    cout<<sum<<" "<<manacher(s)<<endl;
    printf("%lld\n",(sum-manacher(s)+MOD)%MOD);
    return 0;
}