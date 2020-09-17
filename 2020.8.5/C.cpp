#include<iostream>
#include<cstring>
using namespace std;
int t,n,a[51],num[51],tmp[51];
int main(){
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++){
      num[a[i]]++;
    }
    int mx=0;
    for(int s=2;s<=2*n;s++){
      memcpy(tmp,num,sizeof(num));
      int ans=0;
      for(int i=1;i<=n;i++){
        if(s-i!=i){
            if(s-i>=1&&s-i<=n){
              while(tmp[i]>0&&tmp[s-i]>0){
                tmp[i]--;tmp[s-i]--;
                ans++;
              }
            }
        }
        else{
          while(tmp[i]>1){
            tmp[i]-=2;
            ans++;
          }
        }
      }
      mx=max(mx,ans);
    }
    cout<<mx<<endl;
  }
  return 0;
}
