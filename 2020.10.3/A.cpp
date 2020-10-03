#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001],f[1000001];
int num[1000001];
int tmp;
bool check(int x,int v){
    tmp=0;
    memset(num,0,sizeof(num));
    for(int i=1;i<=x;i++){
        if(num[a[i]]==0){
            //cout<<"@add"<<endl;
            tmp++;
        }
        num[a[i]]++;
        if(num[a[i]]==v){
            tmp--;
        }
    }
    //cout<<"Check "<<x<<" "<<tmp<<endl;
    if(!tmp)return 1;
    for(int i=x+1;i<=n;i++){
        num[a[i-x]]--;
        if(num[a[i-x]]==0){
            tmp--;
        }
        if(num[a[i]]==0){
            tmp++;
        }
        num[a[i]]++;
        if(num[a[i]]==v){
            tmp--;
        }
        if(!tmp)return 1;
    }
    return 0;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&f[i]);
    int v=0;
    for(int len=n;len>=0;len--){
        int l=v,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(len,mid)){
                l=mid+1;
                v=mid;
            }
            else{
                r=mid-1;
            }
        }
        if(v>=f[len]){
            printf("%d\n",len);
            break;
        }
        v--;
    }
    return 0;
}