//
// Created by swift on 2020/8/8.
//

#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
    long long k,x;
    cin>>k>>x;
    while(x){
        v.push_back(x%10);
        x/=10;
    }
    if(v.size()<k+1){
        while(v.size()<k+1)
        v.push_back(0);
        v.push_back(1);
    }
    else{
        v[k]++;
        for(int i=k;i<v.size();i++){
            if(v[i]>=10){
                v[i]-=10;
                if(i!=v.size()-1)v[k+1]++;
                else v.push_back(1);
            }
        }
    }
    for(int i=v.size()-1;i;i--){
        cout<<v[i];
    }
    return 0;
}