#include<bits/stdc++.h>
using namespace std;
vector<int>N={7,19,49,49,499,499,4999,4999,4999,4999};
vector<int>K={2,2,3,3,20,20,20,20,5000,5000};
vector<int>tmp;
stack<int>nodes,roots;
int f[10000];
int main(){
    system("mkdir D");
    for(int i=1;i<=10;i++){
        cerr<<"case %"<<i<<endl;
        string name="D/"+to_string(i)+".in";
        freopen(name.c_str(),"w",stdout);
        int n=N[i-1],k=K[i-1];
        for(int i=2;i<=n;i++)tmp.push_back(i);
        roots.push(1);
        random_shuffle(tmp.begin(),tmp.end());
        for(int i=0;i<n-1;i++)nodes.push(tmp[i]);
        cout<<n<<" "<<k<<endl;
        cerr<<"Nodes build finish!"<<endl;
        while(!nodes.empty()){
            int a=nodes.top();nodes.pop();
            int b=nodes.top();nodes.pop();
            int c=roots.top();roots.pop();
            //cerr<<a<<" "<<b<<":"<<c<<endl;
            f[a]=f[b]=c;
            roots.push(a);roots.push(b);
        }
        cerr<<"Graph build finish!";
        for(int i=2;i<=n;i++){
            cout<<f[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}