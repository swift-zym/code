#include<iostream>
#include<cmath>
#include<complex>
#include<cstdio>
using namespace std;
const double pi=acos(-1);
int idx[3000000];
void FFT(complex<double> *x,int len,int f){
    for(int i=0;i<len;i++){
        if(i<idx[i])swap(x[i],x[idx[i]]);
    }
    for(int mid=1;mid<len;mid<<=1){
        complex<double> bas(cos(pi/mid),f*sin(pi/mid));
        for(int s=0,t=(mid<<1);s<len;s+=t){
            complex<double>now(1,0);
            for(int k=0;k<mid;k++,now*=bas){
                complex<double>a=x[s+k],b=now*x[s+mid+k];
                x[s+k]=a+b;
                x[s+mid+k]=a-b;
            }
        }
    }
}
complex<double>a[3000000],b[3000000];
int main(){
    int n,m,len=1,num=0;
    scanf("%d%d",&n,&m);
    while(len<=n+m)len<<=1,num++;
    for(int i=0;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[i].real(x);
    }
    for(int i=0;i<=m;i++){
        int x;
        scanf("%d",&x);
        b[i].real(x);
    }
    for(int i=0;i<len;i++){
        idx[i]=((idx[i>>1]>>1)|((i&1)<<(num-1)));
    }
    FFT(a,len,1);
    FFT(b,len,1);
    for(int i=0;i<len;i++)a[i]*=b[i];
    FFT(a,len,-1);
    for(int i=0;i<=n+m;i++){
        printf("%d ",int(a[i].real()/len+0.5));
    }
    puts("");
    return 0;
}