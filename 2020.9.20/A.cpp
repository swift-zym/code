#include<bits/stdc++.h>
using namespace std;
int n,k;string s;
int ans=0;
void solve(int l,int r,int k){
    //cout<<l<<" "<<r<<" "<<k<<endl;
    int len=k*2-(r-l+1);
    if(len<0){
        for(int i=0;i<k;i++){
            if(s[l+i]!=s[r-k+1+i]){s[l+i]=s[r-k+1+i];ans++;}
        }
    }
    else{
        solve(l,l+k-1,len);
        for(int i=0;i<(r-l+1)-k;i++){
            if(s[l+len+i]!=s[l+k+i]){
                //cout<<"diff "<<l+len+i<<" "<<l+k+i<<endl;
                s[l+k+i]=s[l+len+i];
                ans++;
            }
        }
    }
    //cout<<s<<endl;
}
int main(){
    cin>>n>>k>>s;
    int len=k*2-n;
    solve(0,n-1,k);
    cout<<ans<<endl;
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}
/*
xx......xx
*/
/*
----*****
    ----*****
*/
/*
aabaabaabc
   xxxxxxxxxx
*/