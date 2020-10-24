#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[30];
vector<int>x;
int main(){
    srand(time(0));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a]-=c;v[b]+=c;
    }
    int ans=n;
    for(int i=1;i<=n;i++){
        if(!v[i])ans--;
        else x.push_back(v[i]);
    }
    int mi=ans;
    int num=1e7/x.size();
    for(int i=1;i<=num;i++){
        random_shuffle(x.begin(),x.end());
        int tmp=ans;
        int sum=0;
        for(auto j:x){
            sum+=j;
            if(!sum)tmp--;
        }
        mi=min(mi,tmp);
    }
    printf("%d\n",mi);
    return 0;
}
/*
0 0 0 0
-1 1 0 0
-1 -1 2 0
-1 -1 -1 3
*/