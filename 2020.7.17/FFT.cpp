//
// Created by swift on 2020/7/17.
//

#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
complex<double> a[300001],b[300001];
int idx[300001];
int n,m,mx=1,num;
void FFT(complex<double>*x,int f){
    for(int i=0;i<mx;i++){
        if(idx[i]>i){
            swap(x[i],x[idx[i]]);
        }
    }
    for(int len=1;len<mx;len<<=1){
        complex<double> tmp(cos(PI/len),f*sin(PI/len));
        for(int j=0,r=(len<<1);j<mx;j+=r){
            complex<double> now(1,0);
            for(int k=0;k<len;k++,now*=tmp){
                complex<double> va=x[j+k],vb=now*x[j+len+k];
                x[j+k]=va+vb;
                x[j+len+k]=va-vb;
            }
        }
    }
}
int ans[300001];
char as[150001],bs[150001];
int main(){
    scanf("%d",&n);
    scanf("%s",as);
    scanf("%s",bs);
    n=strlen(as)-1;m=strlen(bs)-1;
    for(int i=0;i<=n;i++){
        a[i].real(as[n-i]-'0');
    }
    for(int i=0;i<=m;i++) {
        b[i].real(bs[m-i]-'0');
    }
    while(mx<=m+n){
        mx*=2;
        num++;
    }
    for(int i=0;i<mx;i++){
        idx[i]=((idx[i>>1]>>1)|((i&1)<<(num-1)));
    }
    FFT(a,1);
    FFT(b,1);
    for(int i=0;i<=mx;i++){
        a[i]*=b[i];
    }
    FFT(a,-1);
    for(int i=0;i<=mx;i++){
        ans[i]+=int(a[i].real()/mx+0.5);
        if(ans[i]>=10){
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
            if(i==mx)mx++;
        }
    }
    bool flag=0;
    for(int i=mx;i>=0;i--){
        if(ans[i]==0&&flag==0)continue;
        cout<<ans[i];
        flag=1;
    }
    if(!flag){
        cout<<0;
    }
    cout<<endl;
    return 0;
}