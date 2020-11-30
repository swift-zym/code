#include<iostream>
using namespace std;
int main(){
    freopen("gokami.in","w",stdout);
    int n=20;
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%100+1<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%100+1<<" ";
    }
    cout<<endl;
    return 0;
}