#include<bits/stdc++.h>
using namespace std;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int n;string s;
    while(cin>>n){
        cin>>s;
        int i=-1,j=-1;
        s="$"+s;
        for(int idx=1;idx<=n;idx++){
            if(s[idx]!='0'){
                i=idx;
                break;
            }
        }
        for(int idx=n;idx>=1;idx--){
            if(s[idx]!='0'){
                j=idx;
                break;
            }
        }
        if(i==-1){
            puts(n%2?"FIRST":"SECOND");
            continue;
        }
        int flag=(i-1)^(n-j);
        for(int k=i+1;k<=j;k++){
            if(s[k]!='0'){
                if(k-i>1&&s[i]==s[k])flag^=1;
                i=k;
            }
        }
        puts(flag?"FIRST":"SECOND");
    }
    return 0;
}