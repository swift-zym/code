#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[1000000];
int val[1000000];
int siz[1000000];
void dfs(int now){
    siz[now]=1;
    for(int i:v[now]){
        dfs(i);
        siz[now]+=siz[i];
    }
}
int main(){
    srand(time(0));
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        v[rand()%(i-1)+1].push_back(i);
    }
    for(int i=1;i<=n;i++){
        val[i]=(rand()<<15|rand())%(1000000000)+1;
    }
    freopen("in.txt","w",stdout);
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++)cout<<val[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j:v[i]){
            cout<<i<<" "<<j<<endl;
        }
    }
    dfs(1);
    for(int i=1;i<=m;i++){
        int pos=rand()%n+1,x=rand()%siz[pos]+1;
        cout<<pos<<" "<<x<<endl;
    }
    return 0;
}