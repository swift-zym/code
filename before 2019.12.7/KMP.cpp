//KMP模板
#include<bits/stdc++.h>
using namespace std;
int nxt[1000000];
string s1,s2;
int main(){
cin>>s1>>s2;
int i=1,j=-1;
nxt[0]=-1;
while(i<s2.length()){
    while(j!=-1&&s2[i]!=s2[j+1])j=nxt[j];
    if(s2[i]==s2[j+1])j++;
    nxt[i]=j;
    i++;
}
i=0,j=-1;
while(i<s1.length()){
    while(j!=-1&&s1[i]!=s2[j+1])j=nxt[j];
    if(s1[i]==s2[j+1])j++;
    if(j==s2.length()-1){
        printf("%d\n",i-s2.length()+2);
        j=nxt[j];
    }
    i++;
}
for(int i=0;i<s2.length();i++){
    printf("%d ",nxt[i]+1);
}
#ifdef WIN32
system("pause");
#endif
}