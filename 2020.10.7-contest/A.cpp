#include<bits/stdc++.h>
using namespace std;
int n;
bool isPrime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return 0;
    }
    return 1;
}
int main(){
    int n,ans=0;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            int num=0;
            for(int j=2;j<=i;j++){
                if(i%j==0&&isPrime(j)){
                    num++;
                }
            }   
            ans+=(1<<num);
        }
        cout<<ans<<endl;
    }
    return 0;
}