//
// Created by swift on 2020/8/10.
//

#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
    return x * f;
}
const int N = 400007;
const double pi = acos(-1.0);
int n;
int rev[N];
struct CP {
    double x,y;
    CP operator + (CP el) { return (CP)<%x+el.x , y+el.y%>; }
    CP operator - (CP el) { return (CP)<%x-el.x , y-el.y%>; }
    CP operator * (CP el) { return (CP)<%x*el.x-y*el.y , x*el.y+y*el.x%>; }
}a[N],b[N],c[N];
void FFT(CP *A,int n,int flag) {
    for(int i=0;i<n;++i) if(i < rev[i]) swap(A[i],A[rev[i]]);
    for(int mid=1;mid<n;mid<<=1) {
        CP Wn = (CP)<%cos(2*pi/(mid<<1)) , flag*sin(2*pi/(mid<<1))%>;
        for(int i=0;i<n;i+=(mid<<1)) {
            CP W = (CP)<%1 , 0%>;
            for(int j=0;j<mid;++j,W=(W*Wn)) {
                CP tmp0 = A[i+j], tmp1 = W*A[i+mid+j];
                A[i+j] = tmp0 + tmp1;
                A[i+mid+j] = tmp0 - tmp1;
            }
        }
    }
    if(flag == -1) {
        for(int i=0;i<n;++i) A[i].x /= n;
    }
}
int main()
{
    //freopen("Li.txt","r",stdin);
    //freopen("My.out","w",stdout);
    n = read();
    for(int i=1;i<=n;++i) {
        scanf("%lf",&a[i].x);
        c[n-i].x = a[i].x;
        b[i].x = (double)(1.0 / i / i);
    }
    int lim = 1, L = 0; while(lim <= (n<<1)) lim <<= 1, ++L;
    for(int i=0;i<lim;++i) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(L-1));
    FFT(a,lim,1), FFT(b,lim,1), FFT(c,lim,1);
    for(int i=0;i<lim;i++){
        printf("%lf ",a[i].x);
    }
    putchar(10);
    for(int i=0;i<lim;i++){
        printf("%lf ",b[i].x);
    }
    putchar(10);
    for(int i=0;i<lim;i++){
        printf("%lf ",c[i].x);
    }
    putchar(10);
    for(int i=0;i<lim;++i) a[i] = a[i]*b[i], c[i] = c[i]*b[i];
    FFT(a,lim,-1), FFT(c,lim,-1);
    for(int i=0;i<lim;i++){
        printf("%lf ",a[i].x);
    }
    putchar(10);
    for(int i=0;i<lim;i++){
        printf("%lf ",c[i].x);
    }
    putchar(10);
    for(int i=1;i<=n;++i)
        printf("%.3lf\n",a[i].x-c[n-i].x);
    return 0;
}
/*
5
4006373.885184
15375036.435759
1717456.469144
8514941.004912
1410681.345880

-16838672.693
3439.793
7509018.566
4595686.886
10903040.872

31024489.140879 14690597.113960 -7893934.324219 -9622042.872463 -6860095.430847 -12121542.176968 -9135947.685605 7052987.935471 16755465.740463 7052987.935471 -9135947.685605 -12121542.176968 -6860095.430847 -9622042.872463 -7893934.324219 14690597.113960
1.463611 1.127869 0.537755 0.140209 -0.187500 -0.493762 -0.662755 -0.774316 -0.838611 -0.774316 -0.662755 -0.493762 -0.187500 0.140209 0.537755 1.127869
31024489.140879 16375657.892558 -7446512.538043 -10749898.394311 3699598.761920 11142410.854623 2255127.459435 -11125444.969349 -16755465.740463 -11125444.969349 2255127.459435 11142410.854623 3699598.761920 -10749898.394311 -7446512.538043 16375657.892558
-0.000000 0.000000 4006373.885184 16376629.907055 6006368.231993 10903040.871773 4851439.826322 2021117.379323 757624.443337 428765.224314 56427.253835 0.000000 -0.000000 -0.000000 0.000000 -0.000000
0.000000 1410681.345880 8867611.341382 4002934.092136 16838672.693264 8629572.557338 3157869.522565 1474790.689910 865399.825254 160254.955407 0.000000 0.000000 0.000000 -0.000000 -0.000000 0.000000
-16838672.693
3439.793
7509018.566
4595686.886
10903040.872
 */