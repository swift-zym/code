#include <bits/stdc++.h>
using namespace std;
int b,lx,ly;
char tmp[3000];
int x[3000],y[3000],ans[3000];
int cha(char a){
    if(a>='0'&&a<='9')return a-'0';
    return a-'A'+10;
}
int ret(int a){
    if(a<=9)return a+'0';
    return a-10+'A';
}
int main() {
    scanf("%d",&b);
    scanf("%s",tmp);
    lx=strlen(tmp);
    for(int i=lx-1;i>=0;i--){
        x[lx-i-1]=cha(tmp[i]);
    }
    scanf("%s",tmp);
    ly=strlen(tmp);
    for(int i=ly-1;i>=0;i--){
        y[ly-i-1]=cha(tmp[i]);
    }
    for(int i=0;i<=2500;i++){
        ans[i]+=x[i]+y[i];
        if(ans[i]>=b){
            ans[i]-=b;
            ans[i+1]++;
        }
    }
    bool flag=0;
    for(int i=2500;i>=0;i--){
        if(ans[i]==0&&flag==0)continue;
        if(ans[i]!=0)flag=1;
        putchar(ret(ans[i]));
    }
    if(flag==0){
        putchar('0');
    }
    putchar(10);
    return 0;
}
