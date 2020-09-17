#include<bits/stdc++.h>
using namespace std;
int st[60000][20];
int a[60000];
int year[60000];
int n,m;
int query(int l,int r){
    if(l>r)return 0;
    int k=log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
    //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&year[i],&a[i]);
    for(int i=1;i<=n;i++)st[i][0]=a[i];
    for(int i=1;i<=19;i++)
    for(int j=1;j<=n;j++){
        st[j][i]=max(st[j][i-1],st[min(n,j+(1<<(i-1)))][i-1]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        //cout<<">"<<x<<" "<<y<<endl;
        int xx=lower_bound(year+1,year+n+1,x)-year;
        int yy=lower_bound(year+1,year+n+1,y)-year;
        if(yy!=n+1&&year[yy]==y&&year[xx]!=x){
            if(query(xx,yy-1)>=a[yy]){
                puts("false");
                continue;
            }
        }
        if(xx!=n+1&&year[xx]==x&&(yy==n+1||year[yy]!=y)){
            yy--;
            if(query(xx+1,yy)>=a[xx]){
                puts("false");
                continue;
            }
        }
        if(xx==n+1||yy==n+1||year[xx]!=x||year[yy]!=y){
            puts("maybe");
            continue;
        }
        if(a[yy]>a[xx]){
            puts("false");
            continue;
        }
        int v=query(xx+1,yy-1);
        //cout<<v<<endl;
        if(v>=a[yy]){
            puts("false");
        }
        else if(yy-xx==y-x){
            puts("true");
        }
        else{
            puts("maybe");
        }
    }
    return 0;
}