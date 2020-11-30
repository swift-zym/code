#include<iostream>
#include<vector>
using namespace std;
void solve(int x){
    vector<int>ans;
    while(x){
        int i;
        for(i=1;i*(i+1)/2<=x;i++);
        i--;
        ans.push_back(i);
        x-=i*(i+1)/2;
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i];j++){
            putchar('a'+i);
        }
    }
    putchar(10);
}
int T;
int main(){
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        solve(n);
    }
    return 0;
}