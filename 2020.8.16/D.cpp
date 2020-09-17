#include<bits/stdc++.h>
using namespace std;
char s[300000];
int n;
int t;
int solve_single(int len){
    if(len%3==1)return 1e8;
    if(len%3==0){
        return len/3;
    }
    return len/3+1;
}
//LLRRR
int solve(int l,int r){
    //cout<<l<<" "<<r<<endl;
    int mi=solve_single(l)+solve_single(r);
    for(int i=1;i<=2;i++)
    for(int j=1;j<=2;j++){
        if(l>=i&&r>=j){
            mi=min(mi,solve_single(l-i)+solve_single(r-j));
        }
    }
    return mi;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s);
        int now=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='R'){now=i;break;}
        }
        if(now==-1){
            printf("%d\n",solve_single(n));
            continue;
        }
        vector<int>v;
        int num=0;
        char pre='R';
        for(int i=0;i<n;i++,now=(now+1)%n){
            if(s[now]!=pre){
                pre=s[now];
                v.push_back(num);
                num=1;
            }
            else{
                num++;
            }
        }
        if(num){
            v.push_back(num);
        }
        int ans=0;
        for(int i=0;i<v.size();i+=2){
            if(i==v.size()-1){
                ans+=solve_single(v[i]);
            }
            else{
                ans+=solve(v[i+1],v[i]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}