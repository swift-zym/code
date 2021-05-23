#include<iostream>
#include<algorithm>
using namespace std;
int t;
int main(){
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            m-=x;
        }
        if(m==0){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}