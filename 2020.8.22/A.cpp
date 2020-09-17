#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main(){
    cin>>a>>b>>c;
    for(long long i=1;;i++){
        a-=i;
        b-=i;
        if(a<0)c+=a,a=0;
        if(b<0)c+=b,b=0;
        if(c<0){
            cout<<i-1<<endl;
            break;
        }
    }
    return 0;
}