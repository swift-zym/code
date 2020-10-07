#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,k,ans;
vector<int>p;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)p.push_back(i);
    do{
        bool flag=1;
        for(int i=0;i<p.size();i++){
            if(p[p[i]-1]!=i+1)flag=0;
        }
        if(!flag)continue;
        int num=0;
        for(int i=0;i<p.size();i++)
        for(int j=i+1;j<p.size();j++){
            if(p[i]>p[j]){
                num++;
            }
        }
        ans+=(num==k);
    }while(next_permutation(p.begin(),p.end()));
    printf("%d\n",ans);
    return 0;
}
