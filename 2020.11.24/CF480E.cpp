#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k;
int a[2100][2100],dp[2100][2100];
int qx[2100],qy[2100],up[2100][2100],down[2100][2100];
pair<int,int>v[100000];
void build(int now,int l,int r,int col){
    if(l==r){
        v[now]=make_pair(up[col][l],down[col][r]);
        return;
    }
    int mid=(l+r)/2;
    build(now*2,l,mid,col);build(now*2+1,mid+1,r,col);
    v[now]=make_pair(min(v[now*2].first,v[now*2+1].first),min(v[now*2].second,v[now*2+1].second));
}
pair<int,int> query(int now,int l,int r,int L,int R){
    if(l==L&&r==R)return v[now];
    int mid=(l+r)/2;
    if(R<=mid)return query(now*2,l,mid,L,R);
    else if(L>mid)return query(now*2+1,mid+1,r,L,R);
    else{
        auto lv=query(now*2,l,mid,L,mid),rv=query(now*2+1,mid+1,r,mid+1,R);
        return make_pair(min(lv.first,rv.first),min(lv.second,rv.second));
    }
}
bool check(int len,int row){
    for(int i=max(1,row-len+1);i<=m-len+1;i++){
        auto tmp=query(1,1,m,i,i+len-1);
        if(tmp.first+tmp.second>len)return 1;
    }
    return 0;
}
vector<int>val;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        char c=getchar();
        while(c!='.'&&c!='#')c=getchar();
        a[i][j]=(c=='.');
    }
    for(int i=1;i<=k;i++){
        scanf("%d%d",&qx[i],&qy[i]);
        a[qx[i]][qy[i]]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(!a[i][j])continue;
        dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
        ans=max(ans,dp[i][j]);
    }
    for(int j=1;j<=m;j++)
    for(int i=1;i<=n;i++){
        up[i][j]=a[i][j]?up[i-1][j]+1:0;
    }
    for(int j=1;j<=m;j++)
    for(int i=n;i>=1;i--){
        down[i][j]=a[i][j]?down[i+1][j]+1:0;
    }
    val.push_back(ans);
    for(int i=k;i>=1;i--){
        a[qx[i]][qy[i]]=1;
        up[qx[i]][qy[i]]=up[qx[i]-1][qy[i]]+1;
        for(int j=qx[i]+1;j<=n;j++){
            if(!a[j][qy[i]])break;
            up[j][qy[i]]+=up[qx[i]][qy[i]];
        }
        down[qx[i]][qy[i]]=down[qx[i]+1][qy[i]]+1;
        for(int j=qx[i]-1;j;j--){
            if(!a[j][qy[i]])break;
            down[j][qy[i]]+=down[qx[i]][qy[i]];
        }
        build(1,1,m,qx[i]);
        while(check(ans+1,qy[i]))ans++;
        if(i-1)
        val.push_back(ans);
    }
    reverse(val.begin(),val.end());
    for(auto now:val){
        printf("%d\n",now);
    }
    return 0;
}