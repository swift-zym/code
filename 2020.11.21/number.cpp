#include<iostream>
#include<set>
using namespace std;
bool check(int x){
    set<int>s;
    while(x){
        s.insert(x%10);
        x/=10;
    }
    return s.size()<=2;
}
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n>300000){
            puts("3");
            continue;
        }
        if(check(n)){
            puts("1");
        }
        else{
            bool flag=0;
            for(int i=1;i<=n;i++){
                if(check(i)&&check(n-i)){
                    flag=1;
                }
            }
            if(flag){
                puts("2");
            }
            else{
                puts("3");
            }
        }
    }
    return 0;
}