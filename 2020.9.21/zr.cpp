#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[300001],pos[300001];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        bool flag=0;
        for(int i=1;i<=n&&flag==0;i++)
        for(int j=i+1;j<=i+10000000/n&&j<=n;j++){
            if((a[i]+a[j])%2==0&&pos[(a[i]+a[j])/2]>i&&pos[(a[i]+a[j])/2]<j){
                flag=1;
                break;
            }
        }
        if(flag){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}