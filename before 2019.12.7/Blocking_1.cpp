//题目名：分块1
#include<bits/stdc++.h>
using namespace std;
int n,l[50001],r[50001],a[50001],of[50001],add[50001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int t=sqrt(n);
    for(int i=1;i<=t;i++){
        l[i]=(i-1)*t+1;
        r[i]=i*t;
    }
    if(r[t]<n)t++,l[t]=r[t-1]+1,r[t]=n;
    for(int i=1;i<=t;i++){
       for(int j=l[i];j<=r[i];j++){
           of[j]=i;
       }
    }
    for(int i=1;i<=n;i++){
        int opt,ll,rr,c;
        cin>>opt>>ll>>rr>>c;
        if(opt){
            cout<<a[rr]+add[of[rr]]<<endl;
        }
        else{
            if(of[ll]==of[rr]){
                for(int j=ll;j<=rr;j++){
                    a[j]+=c;
                }
            }
                else{
                    for(int j=of[ll]+1;j<=of[rr]-1;j++){
                        add[j]+=c;
                    }
                    for(int j=ll;j<=r[of[ll]];j++)a[j]+=c;
                    for(int j=l[of[rr]];j<=rr;j++)a[j]+=c;
                }
            }
        }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}