#include<bits/stdc++.h>
using namespace std;
int T;
int w[26];
char s[2000000],ans[2000000];
bool check_char(int len,int idx){
    if(!idx)return 0;
    char c=ans[idx-1];
    if(c=='N')return 0;
    int v=w[s[idx]-'a'];
    if(v==2||v==3||v==6||v==7)return 1;
    else return 0;
}
bool check(int len){
    for(int i=1;i<len;i++){
        if(s[i]=='N'&&s[i-1]=='N')return 0;
    }
    for(int i=0;i<len;i++){
        if(s[i]=='V'){
            if(i==0)return 0;
            if(s[i-1]==1&&check_char(len,i-1)==0)return 0;
        }
    }
    if(s[len-1]!='N'&&check_char(len,len-1)==0)return 0;
    return 1;
}
int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<=25;i++)scanf("%d",&w[i]);
        scanf("%s",s);
        int len=strlen(s);
        int use=0;
        for(int i=0;i<len;i++){
            if(w[s[i]-'a']==1){
                ans[i]='A';
            }
            else if(w[s[i]-'a']==2){
                ans[i]='N';
            }
            else if(w[s[i]-'a']==3){
                ans[i]='A';
            }
            else if(w[s[i]-'a']==4){
                use++;
                ans[i]='V';
            }
            else if(w[s[i]-'a']==5){
                ans[i]='A';
            }
            else if(w[s[i]-'a']==6){
                ans[i]='N';
            }
            else if(w[s[i]-'a']==7){
                ans[i]='A';
            }
        }
        if(use>1){
            puts("No");
            continue;
        }
        else if(use==1){
            if(!check(len)){
                puts("No");
            }
            else{
                puts("Yes");
            }
        }
        else{
            bool flag=0;
            for(int i=0;i<len;i++){
                char bf=ans[i];
                if(w[s[i]-'a']>=4){
                    ans[i]='V';
                    if(check(len)){
                        flag=1;
                    }
                    ans[i]=bf;
                }
            }
            if(flag){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
    }
    return 0;
}
