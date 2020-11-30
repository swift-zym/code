#include<bits/stdc++.h>
using namespace std;
int main(){
    FILE *ans=fopen("sample1.ans","r"),*out=fopen("sample1.out","r");
    int a,line=0;
    while(fscanf(out,"%d",&a)!=EOF){
        int b;
        fscanf(ans,"%d",&b);
        line++;
        if(a!=b){
            printf("Wrong Answer on line %d,answer:%d,your:%d",line,b,a);
            return 0;
        }
    }
    puts("Accept");
    return 0;
}