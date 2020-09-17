#include<bits/stdc++.h>
using namespace std;
int n;
int a[20001][6];
int idx[20001][6];
vector<int>v;
unordered_map<int,int>ma,am;
bool cmp(int a,int b){
    int num=0;
    for(int i=1;i<=5;i++){
        if(idx[a][i]<idx[b][i])num++;
    }
    return num>=3;
}
int main(){
    scanf("%d",&n);
    for(int j=1;j<=5;j++)
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=n;i++)v.push_back(a[i][1]);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        ma[v[i]]=i+1;
        am[i+1]=v[i];
    }
    for(int j=1;j<=5;j++)
    for(int i=1;i<=n;i++){
        idx[ma[a[i][j]]][j]=i;
    }
    v.clear();
    for(int i=1;i<=n;i++)v.push_back(i);
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        printf("%d\n",am[v[i]]);
    }
    return 0;
}