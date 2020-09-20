#include<bits/stdc++.h>
using namespace std;
int a[1000];
int n;
set<int>prime;
bool isprime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return 0;
    }
    return 1;
}
int find(int x,bool del=true){
    auto it=prime.lower_bound(x);
    if(it==prime.end())it--;
    int v=abs(*it-x);
    cout<<x<<" "<<*it<<endl;
    if(it!=prime.begin()){
        it--;
        if(abs(*it-x)<v){
            cout<<"OK!"<<endl;
            v=*it;
            prime.erase(it);
        }
        else{
            ++it;
            v=*it;
            prime.erase(it);
        }
    }
    return v;
}
int main(){
    for(int i=2;i<=60;i++){
        if(isprime(i)){
            prime.insert(i);
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]!=1&&(!isprime(a[i]))){
            if(prime.size())
            a[i]=find(a[i]);
            else
            {
                a[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}