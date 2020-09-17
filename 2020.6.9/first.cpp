//
// Created by swift on 2020/6/9.
//
#include<bits/stdc++.h>
using namespace std;
string s,tmp_s;
int len,sa[1000001],cnt[1000001],tmprnk[1000001],tmpsa[1000001];
pair<int,int>rnk[1000001],tmp[1000001];
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    s="";
    tmp_s="";
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        s=s+c;
        tmp_s=c+tmp_s;
    }
    s=s+"0"+tmp_s;
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
    int h=0,t=n+1;
    for(int i=0;i<n;i++){
        if(tmprnk[h]>tmprnk[t]){
            putchar(s[t++]);
        }
        else{
            putchar(s[h++]);
        }
        if((i+1)%80==0){
            putchar(10);
        }
    }
    putchar(10);
    return 0;
}