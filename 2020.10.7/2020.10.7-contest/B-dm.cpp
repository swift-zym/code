#include<bits/stdc++.h>
using namespace std;
int n=1000;
int main(){
    srand(time(0));
    freopen("B.in","w",stdout);
    cout<<1<<" "<<n<<endl;
    for(int i=2;i<=n;i++){
        cout<<i-1<<" "<<i<<endl;
    }
    int m=1000,ver=0;
    cout<<m<<endl;
    for(int i=1;i<=m;i++){
        int x=rand()%n+1;
        switch (rand()%3){
        case 0:
            cout<<"1 "<<x<<endl;
            ver++;
            break;
        case 1:
            cout<<"2 "<<x<<endl;
            break;
        default:
            x=rand()%(ver+1);
            cout<<"3 "<<x<<endl;
            break;
        }
    }
    return 0;
}