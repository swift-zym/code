#include<iostream>
#include<algorithm>
using namespace std;
int t,a[100001],num[100001];
int main(){
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int mi=1e9;
        for(int v=1;v<=100;v++){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]!=v){
                    ans++;
                    i+=k-1;
                    continue;
                }
            }
            mi=min(mi,ans);
        }
        printf("%d\n",mi);
    }
    return 0;
}