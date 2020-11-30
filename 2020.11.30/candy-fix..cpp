#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct candy{
    int s,t,w;
    bool operator <(const candy &c)const{
        if(w!=c.w)
        return w<c.w;
        return t<c.t;
    }
};
vector<candy>v;
int main(){
    ios::sync_with_stdio(0);
    freopen("candy2.out","r",stdin);
    freopen("candy2.txt","w",stdout);
    int w;
    cin>>w;
    for(int i=1;i<=w;i++){
        int s,t,w;
        cin>>s>>t>>w;
        v.push_back({s,t,w});
    }
    sort(v.begin(),v.end());
    cout<<w<<endl;
    for(auto s:v){
        cout<<s.s<<" "<<s.t<<" "<<s.w<<endl;
    }
    return 0;
}