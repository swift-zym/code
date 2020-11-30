#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    freopen("colour.in","w",stdout);
    int n=2000,q=2000;
    vector<int>tmp;
    for(int i=1;i<=n;i++)tmp.push_back(i);
    random_shuffle(tmp.begin(),tmp.end());
    cout<<n<<endl;
    for(int i=0;i<n-1;i++){
        cout<<tmp[i]<<" "<<tmp[i+1]<<endl;
    }
    cout<<q<<endl;
    for(int i=1;i<=q;i++){
        int t=rand()%2,r=rand()%n+1,b=rand()%n+1;
        if(rand()%10==0)r=b;
        cout<<t<<" "<<r<<" "<<b<<endl;
    }
    return 0;
}