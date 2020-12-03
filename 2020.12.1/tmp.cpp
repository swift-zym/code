#include<bits/stdc++.h>
#define int long long
using namespace std;
int q;
int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int countDaysBC(int s,int t){
	int ans=0;
	while(s%4!=0){
		ans+=365;
		s++;
	}
	while(t%4!=0){
		ans+=365;
		t--;
	}
	ans+=366;
	ans+=(t-s)/4*(365*4+1);
	return ans;
}
int checkYear(int y,int m){
	if(m!=2)return 0;
	if(y<=1582){
		return (y+(y<0?1:0))%4==0;
	}
	else{
		return y%100==0?y%400==0:y%4==0;
	}
}
void makeDate(int y,int r){
	int m=1,d=1;
	for(int i=1;i<=r;i++){
		d++;
		if(d>days[m]+checkYear(y,m)){
			d=1;
			m++;
			if(m==13){
				m=1;
				y++;
				if(y==0)y=1;
			}
		}
		if(y==1582&&m==10&&d==5)d=15;
	}
	if(y<0)
	printf("%lld %lld %lld BC\n",d,m,-y);
	else
	printf("%lld %lld %lld\n",d,m,y);
}
signed main(){
	scanf("%lld",&q);
	for(int i=1;i<=q;i++){
		int r;
		scanf("%lld",&r);
		int tmp=countDaysBC(-4713+1,1581);
		if(r<tmp){
			int v=r/(365*4+1);
			int tmpy=-4713+4*v;
			r%=(365*4+1);
			if(tmpy>=0)tmpy++;
			makeDate(tmpy,r);
		}
		else{
			r-=tmp;
			if(r<355){
				makeDate(1582,r);
			}
			else{
				r-=355;
				int v=r/(365*400+97);
				int tmpy=1583+400*v;
				r%=(365*400+97);
				while(r>=365+checkYear(tmpy,2)){
					r-=365+checkYear(tmpy,2);
					tmpy++;
				}
				makeDate(tmpy,r);
			}
		}
	}
	return 0;
}