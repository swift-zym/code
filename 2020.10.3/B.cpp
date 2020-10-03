#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
int pos;
int poss;
int k;
struct node{
    string s;
    int id;
    bool operator <(const node &t)const{
        return s<t.s;
    }
};
vector<node>v;
int main(){
    cin>>s;
    ans="";
    for(int i=1;i<=2001;i++)ans+="z";
    cin>>k;
    int len=s.length();
    s+=s;
    if(k==1){
        for(int i=0;i<len;i++){
            string tmp=s.substr(i,len);
            if(tmp<ans){
                ans=tmp;
                pos=i+1;
            }
        }
        printf("%d\n",pos);
    }
    else if(k==2){
        for(int i=0;i<len;i++){
            for(int j=i+1;j<i+len;j++){
                string tmp1=s.substr(i,j-i);
                string tmp2=s.substr(j,len-(j-i));
                string tmp;
                if(tmp1<tmp2)tmp=tmp2;
                else tmp=tmp1;
                if(tmp<ans){
                    ans=tmp;
                    pos=i+1;
                    poss=j%len+1;
                }
            }
        }
        printf("%d %d\n",min(pos,poss),max(pos,poss));
    }
    else{
        for(int i=0;i<len;i++){
            v.push_back({s.substr(i,len),i+1});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<k;i++)ans.push_back(v[i].id);
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++){
            printf("%d ",ans[i]);
        }
        putchar(10);
    }
    return 0;
}