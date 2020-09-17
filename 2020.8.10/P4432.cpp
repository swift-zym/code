//
// Created by swift on 2020/8/10.
//

#include<bits/stdc++.h>
using namespace std;
struct node{
    double x,y;
    bool operator <(const node &t)const{
        if(x!=t.x){
            return x<t.x;
        }
        return y<t.y;
    }
}a[200001];
int n;
double ans=1e18;
double dis(int x,int y){
    //cout<<">"<<a[x].x<<" "<<a[x].y<<" "<<a[y].x<<" "<<a[y].y<<endl;
    //cout<<x<<" "<<y<<" "<<(a[x].x-a[y].x)*(a[x].x-a[y].x)<<" "<<(a[x].y-a[y].y)*(a[x].y-a[y].y)<<" "<<sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y))<<endl;
    return sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));
}
void solve(int x){
    for(int i=1;i<=n;i++){
        double tx=a[i].x,ty=a[i].y;
        a[i].x=cos(x)*tx-sin(x)*ty;
        a[i].y=sin(x)*tx+cos(x)*ty;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n&&j<=i+10;j++)
            for(int k=j+1;k<=n&&k<=j+10;k++){
                //cout<<dis(i,j)+dis(j,k)+dis(i,k)<<endl;
                ans=min(ans,dis(i,j)+dis(j,k)+dis(i,k));
            }
}
int main(){
    srand(time(0));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&a[i].x,&a[i].y);
    }
    solve(rand()%360);
    solve(rand()%360);
    printf("%0.6lf\n",ans);
    return 0;
}