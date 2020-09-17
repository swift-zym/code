#include<bits/stdc++.h>
#define double long double
using namespace std;
int n,p;
double a[100],b[100];
double getPoint(int idx,double hard,double dist){
    //cout<<idx<<" "<<double(100)/(1+exp(hard-dist*a[idx]))<<endl;
    return (double)(100)/(1+exp(hard-dist*a[idx]));
}
double getSum(double hard,double dist){
    //cout<<hard<<" "<<dist<<endl;
    double ans=0;
    for(int i=1;i<=n;i++){
        ans+=b[i]*log((double)(100)/getPoint(i,hard,dist));
        ans+=((double)(100)-b[i])*log((double)(100)/((double)(100)-getPoint(i,hard,dist)));
    }
    //cout<<">"<<ans<<endl;
    return ans;
}
double solve(double hard){
    double l=0,r=0.5;
    while(r-l>1e-15){
        double mid=(l+r)/2,mmid=(mid+r)/2;
        if(getSum(hard,mid)>getSum(hard,mmid)){
            l=mid;
        }
        else{
            r=mmid;
        }
    }
    return getSum(hard,l);
}
void print(double val,int p){
	char ss[55];
	sprintf(ss+1,"%.11Lf",val);
	int i,f=0;
	for(int i=1;i<=p;i++)
    if(ss[i]=='.'){
        f=1;p++;
    }
	if(!f){
        while(ss[p]!='.'){
            p++;if (ss[p]=='.')break;
        ss[p]='0';
        }
        p--;
    }
	for(int i=1;i<=p;i++) printf("%c",ss[i]);
    puts("");
}
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    double c=(double)(100)/(n-1);
    for(int i=2;i<=n;i++){
        b[i]=(i-1)*c;
    }
    double l=0,r=100;
    while(r-l>1e-15){
        double mid=(l+r)/2,mmid=(mid+r)/2;
        if(solve(mid)>solve(mmid)){
            l=mid;
        }
        else{
            r=mmid;
        }
    }
    print(solve(l),p);
    return 0;
}