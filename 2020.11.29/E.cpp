#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>v[200001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    return 0;
}