#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        char c1,c2;
        int a,b;
        vector<char>v;
        cin>>c1>>a>>c2>>b;
        if(a>m||b>m){
            printf("-1\n");
        }
        if(c1=='C'){
            swap(a,b);
        }
        while(b>26){
            v.push_back('a'+b%26-1);
            b/=26;
        }
        printf("%d ",a);
        for(int i=v.size()-1;i;i--){
            printf("%c",v[i]);
        }
        putchar(10);
    }
    return 0;
}