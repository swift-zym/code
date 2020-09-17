#include<bits/stdc++.h>
using namespace std;
#define N 200000
int a[N][4];
multiset<int> s[4];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&a[i][j]);
            s[j].insert(a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            s[j].erase(s[j].find(a[i][j]));
        }
        if(*s[0].rbegin()<=*s[2].begin()&&*s[1].rbegin()<=*s[3].begin()){
            cout<<*s[0].rbegin()<<' '<<*s[1].rbegin()<<endl;
            break;
        }
        for(int j=0;j<4;j++){
            s[j].insert(a[i][j]);
        }
    }
    return 0;
}
