#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"? 1 1"<<endl;cout.flush();
        int x;
        cin>>x;
        if(x){
            cout<<"! 1"<<endl;
        }
        else{
            cout<<"! 0"<<endl;
        }
        cout.flush();
    }
    else{
        cout<<"? 1 1"<<endl;cout.flush();
        int x,a,b;
        cin>>x;a=x;
        cout<<"? 2 2"<<endl;
        cout.flush();
        cin>>x;
        if(x==1){
            cout<<"! "<<a<<" 2"<<endl;
            return 0;
        }
        if(!a)
        cout<<"? 2 1"<<endl;
        else
        cout<<"? 1 2"<<endl;
        cout.flush();
        cin>>x;
        cout<<"! "<<a<<" "<<x<<endl;
        cout.flush();
    }
    return 0;
}