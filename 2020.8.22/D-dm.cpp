#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("D.in","w",stdout);
    cout<<10<<endl;
    srand(time(0));
    for(int i=1;i<=10;i++){
        cout<<rand()%100<<" ";
    }
    cout<<endl;
    for(int i=1;i<=10;i++){
        cout<<"-1 ";
    }
    cout<<endl;
    return 0;
}
/*
355
5 10
4 9
3 8
2 7
1 6
*/