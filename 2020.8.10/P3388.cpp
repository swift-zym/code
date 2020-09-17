//
// Created by swift on 2020/8/10.
//

//
// Created by swift on 2020/7/17.
//

#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
complex<double> a[6000001],b[6000001],c[6000001];
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
    if(f==-1){
        for(int i=0;i<mx;i++){
            x[i]/=mx;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        c[n-i]=a[i];
        b[i]=double(1.0/i/i);
    }
    while(mx<=(n<<1)){
        mx*=2;
        num++;
    }
    for(int i=0;i<mx;i++){
        idx[i]=((idx[i>>1]>>1)|((i&1)<<(num-1)));
    }
    FFT(a,1);
    FFT(b,1);
    FFT(c,1);
    /*for(int i=0;i<mx;i++){
        cout<<a[i].real()<<" ";
    }
    cout<<endl;
    for(int i=0;i<mx;i++){
        cout<<b[i].real()<<" ";
    }
    cout<<endl;
    for(int i=0;i<mx;i++){
        cout<<c[i].real()<<" ";
    }
    cout<<endl;*/
    for(int i=0;i<mx;i++){
        a[i]*=b[i];
        c[i]*=b[i];
    }
    FFT(a,-1);
    FFT(c,-1);
    /*for(int i=0;i<mx;i++){
        cout<<a[i].real()<<" ";
    }
    cout<<endl;
    for(int i=0;i<mx;i++){
        cout<<c[i].real()<<" ";
    }
    cout<<endl;*/
    for(int i=1;i<=n;i++){
        printf("%0.3lf\n",a[i].real()-c[n-i].real());
    }
    return 0;
}