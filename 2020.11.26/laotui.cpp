#include<iostream>
#include<cstring>
using namespace std;
char s[11000000];
int main(){
    freopen("laotui.in","r",stdin);
    freopen("laotui.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        bool flag=1;
        for(int i=0;i<len;i++){
            if(s[i]!='l'&&s[i]!='t'){
                puts("0 0");
                flag=0;
                break;
            }
            if(i){
                if(s[i]=='l'&&s[i-1]=='l'){
                    puts("0 0");
                    flag=0;
                    break;
                }
            }
        }
        if(!flag)continue;
        if(s[0]=='t'){
            puts("0 1");
        }
        else{
            puts("1 1");
        }
    }
    return 0;
}