#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int n,q;
struct status{
    string s;
    int dp[21][21];
};
struct sta{
    int t=-1;
    status a[40000];
    bool empty(){return t==-1;}
    status top(){return a[t];}
    status back(){return a[0];}
    void push(status x){a[++t]=x;}
    void pop(){t--;}
    void clear(){t=-1;}
    void rever(){
        reverse(a,a+t+1);
    }
};
sta up,down;
#define MOD 1000000007
void add(int &to,int v){
    to+=v;
    to%=MOD;
}
signed main(){
    freopen("bin10.in","r",stdin);
    freopen("bin10.txt","w",stdout);
    ios::sync_with_stdio(false);
    int _a=clock();
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        string opt;
        cin>>opt;
        if(opt=="add"){
            cin>>opt;
            status tmp;tmp.s=opt;
            if(down.empty()){
                for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    tmp.dp[i][j]=(i==j);
                }
                down.push(tmp);
                continue;
            }
            for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                int val=0;
                if(j-1&&down.top().s[j-2]==tmp.s[j-1])add(val,down.top().dp[i][j-1]);
                if(down.top().s[j-1]==tmp.s[j-1])add(val,down.top().dp[i][j]);
                if(j+1<=n&&down.top().s[j]==tmp.s[j-1])add(val,down.top().dp[i][j+1]);
                tmp.dp[i][j]=val;
            }
            down.push(tmp);
        }
        else if(opt=="remove"){
            if(!up.empty())up.pop();
            else{
                up=down;
                down.clear();
                up.rever();
                up.pop();
                for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    up.a[0].dp[i][j]=(i==j);
                }
                for(int k=1;k<=up.t;k++){
                    for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++){
                        int val=0;
                        if(j-1&&up.a[k].s[j-1]==up.a[k-1].s[j-2]){
                            add(val,up.a[k-1].dp[i][j-1]);
                        }
                        if(up.a[k].s[j-1]==up.a[k-1].s[j-1]){
                            add(val,up.a[k-1].dp[i][j]);
                        }
                        if(j+1<=n&&up.a[k].s[j-1]==up.a[k-1].s[j]){
                            add(val,up.a[k-1].dp[i][j+1]);
                        }
                        up.a[k].dp[i][j]=val;
                    } 
                }
            }
        }
        else{
            int c,d;
            cin>>c>>d;
            if(up.empty()){
                //down.top().print();
                cout<<down.top().dp[c][d]<<endl;
            }
            else if(down.empty()){
                cout<<up.top().dp[d][c]<<endl;
            }
            else{
                int ans=0;
                for(int i=1;i<=n;i++){
                    if(i-1&&up.back().s[i-2]==down.back().s[i-1]){
                        add(ans,up.top().dp[i-1][c]*down.top().dp[i][d]%MOD);
                    }
                    if(up.back().s[i-1]==down.back().s[i-1]){
                        add(ans,up.top().dp[i][c]*down.top().dp[i][d]%MOD);
                    }
                    if(i+1<=n&&up.back().s[i]==down.back().s[i-1]){
                        add(ans,up.top().dp[i+1][c]*down.top().dp[i][d]%MOD);
                    }
                }
            }
        }
    }
    cout<<(double(clock()-_a))/CLOCKS_PER_SEC;
    return 0;
}