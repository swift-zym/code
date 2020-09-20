#include<bits/stdc++.h>
using namespace std;
int T,n,m;
string s[501];
int num[501][2];
int main(){
    cin>>T;
    while(T--){
        memset(num,0,sizeof(num));
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>s[i];
        for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++){
            num[j][s[i][j]-'0']++;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int val=0;
            if(2-num[i][1]>0)val+=(2-num[i][1]);
            if(1-num[i][0]>0)val+=(1-num[i][0]);
            ans=max(ans,val);
        }
        cout<<ans<<endl;
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}
/*
(1,0)->1:xor/or
     ->0:and
(0,0)->1:
     ->0:and/or/xor
(1,1)->1:or/and
     ->0:xor
*/