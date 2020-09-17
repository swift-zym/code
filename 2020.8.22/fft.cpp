//
// Created by swift on 2020/7/17.
//

#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
complex<double> a[6000001],b[6000001];
int idx[6000001];
int n,mx=1,num;
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
int main(){
    //ios::sync_with_stdio(0);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[i].real(x);b[n-i-1].real(y);
    }
    while(mx<=n*2+1){
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
    for(int i=n-1;i<n*2-1;i++){
        printf("%d\n",int(a[i].real()/mx+0.5));
    }
    cout<<endl;
    return 0;
}