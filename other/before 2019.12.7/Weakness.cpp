//题目名：Weakness
#include<bits/stdc++.h>
using namespace std;
int n;
double a[200001];
inline double check(double x){
	double sum=0,ret=0,Min=0,Max=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i]-x;
		ret=max(ret,fabs(sum-Min));
		ret=max(ret,fabs(sum-Max));
		Min=min(Min,sum);
        Max=max(Max,sum); 
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	double l=0,r;
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
	for(int i=1;i<=n;i++){
		l=min(l,-fabs(a[i]));
	}
	r=-l;
	int cnt=0;
	while(cnt++<300){
		double m1=l+(r-l)/3,m2=r-(r-l)/3;
		double a1=check(m1),a2=check(m2);
		if(a1<a2){
			r=m2;
		}
		else{
			l=m1;
		}
	}
	printf("%.6lf\n",check((l+r)/2.0));
	#ifdef WIN32
	system("pause");
	#endif
	return 0;
}
