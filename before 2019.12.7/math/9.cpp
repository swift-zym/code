#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=1;i<1000;i++)
    for(int j=i+1;j<=1000;j++){
        if(i+j+sqrt(double(pow(i,2)+pow(j,2)))==1000){
            printf("%d\n",i*j*(1000-i-j));
            #ifdef WIN32
            system("pause");
            #endif
            return 0;
        }
    }
    #ifdef WIN32
    system("pause");
    #endif
}