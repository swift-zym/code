//
// Created by swift on 2020/6/13.
//

#include<bits/stdc++.h>
using namespace std;
string s;
int len,sa[1000001],cnt[1000001],tmprnk[1000001],tmpsa[1000001];
pair<int,int>rnk[1000001],tmp[1000001];
int main(){
    cin>>s;
    string bf=s;
    s+=s;
    len=s.length();
    for(int i=0;i<len;i++)rnk[i].first=s[i],rnk[i].second=(i==len-1)?0:s[i+1];
    for(int k=1;;k++){
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<len;i++){
            cnt[rnk[i].second]++;
        }
        for(int i=1;i<=1000000;i++){
            cnt[i]+=cnt[i-1];
        }
        for(int i=len-1;i>=0;i--){
            int tmpv=cnt[rnk[i].second]--;
            sa[tmpv-1]=i;
        }
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<len;i++){
            cnt[rnk[sa[i]].first]++;
        }
        for(int i=1;i<=1000000;i++){
            cnt[i]+=cnt[i-1];
        }
        for(int i=len-1;i>=0;i--){
            int tmpv=cnt[rnk[sa[i]].first]--;
            tmpsa[tmpv-1]=sa[i];
        }
        for(int i=0;i<len;i++){
            sa[i]=tmpsa[i];
        }
        for(int i=1;i<len;i++){
            if(rnk[sa[i]].first==rnk[sa[i-1]].first&&rnk[sa[i]].second==rnk[sa[i-1]].second){
                tmprnk[sa[i]]=tmprnk[sa[i-1]];
            }
            else{
                tmprnk[sa[i]]=tmprnk[sa[i-1]]+1;
            }
        }
        for(int i=0;i<len;i++) {
            rnk[i].first=tmprnk[i];
            if(i+(1<<k)<len)
                rnk[i].second=tmprnk[i+(1<<k)];
            else
                rnk[i].second=0;

        }
        if((1<<k)>len){
            break;
        }
    }
    for(int i=0;i<len;i++){
        if(sa[i]<len/2){
            cout<<s[sa[i]+(len/2)-1];
        }
    }
    cout<<endl;
    return 0;
}