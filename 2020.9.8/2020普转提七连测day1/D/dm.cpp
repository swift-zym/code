#include<bits/stdc++.h>
using namespace std;
void out(int x){
    string tmp=to_string(x)+".in";
    freopen(tmp.c_str(),"w",stdout);
}
struct book{
    long long t,p;
};
vector<book>v;
int main(){
    for(int i=20;i<=20;i++){
        v.clear();
        out(i);
        int n=rand()%1000+1000,m=300000;
        cout<<n<<" "<<m<<endl;
        for(int i=1;i<=m;i++){
            if(rand()%2&&v.size()!=0){
                int id=rand()%v.size();
                book tmp=v[id];
                v.erase(v.begin()+id);
                cout<<"RETURN "<<tmp.t<<" "<<tmp.p<<endl;
            }
            else{
                v.push_back({rand()%1000+1,rand()%(long long)(1e9)+1});
                book tmp=v[v.size()-1];
                cout<<"BORROW "<<tmp.t<<" "<<tmp.p<<endl;
            }
        }
    }
    return 0;
}