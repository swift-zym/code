#include<bits/stdc++.h>
using namespace std;
int t;
int a[101][101];
bool isPrime(int x){
    if(x==1)return 0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return 0;
    }
    return 1;
}
int main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num=0;
        memset(a,0,sizeof(a));
        for(int i=4;;i++){
            if(isPrime(i)){
                num++;
                a[num][num]=i-1;
                if(num==n-1)break;
            }
        }
        for(int i=1;i<=n;i++)a[i][n]=a[n][i]=1;
        int val=n;
        while(!(isPrime(val)==1&&isPrime(val-(n-1))==0))val++;
        a[n][n]=val-(n-1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}