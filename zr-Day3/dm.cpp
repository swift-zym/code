#include<bits/stdc++.h>
using namespace std;
vector<int>M={5,5,5,20,20,20,500,500,500,500};
vector<int>N={67,300,700,1000,300000,300000,300000,300000,300000,300000};
vector<int>tmp;
int f[10000];
string random_string(int length,bool _only_a_b=false){
    string tmp="";
    if(_only_a_b)
    for(int i=1;i<=length;i++)tmp+=rand()%2?"a":"b";
    else
    for(int i=1;i<=length;i++)tmp+=char(rand()%26+'a');
    return tmp;
}
string random_01(int length){
    string tmp="";
    for(int i=1;i<=length;i++){
        if(rand()%2)tmp+="0";
        else
        {
            tmp+="1";
        }
    }
    return tmp;
}
void solve(int l,int r){
    if(l==r)return;
    vector<int>v;
    for(int i=l;i<=r;i++){
        if((i-l)%2==0)v.push_back(tmp[i]);
    }
    int mid=l+v.size()-1;
    for(int i=l;i<=r;i++){
        if((i-l)%2==1)v.push_back(tmp[i]);
    }
    for(int i=0;i<v.size();i++){
        tmp[l+i]=v[i];
    }
    solve(l,mid);
    solve(mid+1,r);   
}
int main(){
    system("mkdir D");
    for(int i=1;i<=10;i++){
        cerr<<"case %"<<i<<endl;
        string name="D/"+to_string(i)+".in";
        freopen(name.c_str(),"w",stdout);
        int T=10;
        cout<<T<<endl;
        while(T--){
            int idx,n;
            if(i==1)idx=1;
            else if(i<=4){
                idx=rand()%3+2;
            }
            else{
                idx=rand()%6+5;
            }
            n=N[idx-1];
            tmp.clear();
            if(rand()%2){
                for(int i=1;i<=n;i++)tmp.push_back(i);
                random_shuffle(tmp.begin(),tmp.end());
            }
            else{
                n-=rand()%20;
                for(int i=1;i<=n;i++)tmp.push_back(i);
                solve(0,n-1);
            }
            cout<<n<<endl;
            for(int i=0;i<tmp.size();i++){
                cout<<tmp[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}