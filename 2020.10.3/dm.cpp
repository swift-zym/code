#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("in.txt","w",stdout);
    int n=100000;
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%40000<<" ";
    }
    cout<<endl;
    vector<int>tmp;
    for(int i=1;i<=n;i++){
        tmp.push_back(rand()%30000+2);
    }
    sort(tmp.begin(),tmp.end());
    for(int i=n-1;i>=0;i--){
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
    return 0;
}