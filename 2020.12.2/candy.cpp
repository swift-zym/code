#include<bits/stdc++.h>
using namespace std;
int n,b[101],sum,a[101];
int main(){
    freopen("candies.in","r",stdin);
    freopen("candies.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+n+1);
    memcpy(a,b,sizeof(b));
    int siz=unique(a+1,a+n+1)-a-1;
    for(int i=1;i<=siz;i++)sum+=a[i];
    for(int i=1;i<n;i++){
        if(b[i]==b[i+1]){
            cout<<b[i]<<" "<<sum+1<<endl;
            exit(0);
        }
    }
    return 0;
}