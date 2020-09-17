#include"explore.h"
#include<bits/stdc++.h>
using namespace std;
int last[501];
void explore(int N,int M){
    for(int i=0;i<N-1;i++){
        modify(i);
        for(int j=i+1;j<N;j++){
            int v=query(j);            
            if(v!=last[j]){
                report(i,j);
            }
            last[j]=v;
        }
    }
}
