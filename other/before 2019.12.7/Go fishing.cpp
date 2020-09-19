//题目名：钓鱼
#include<iostream>
#include<queue>
using namespace std;
int n,h,a[101],b[101],c[100],sum[100];
struct node
{
    int id,num;
    bool operator <(const node &t)const{
        return num<t.num;
    }
};

int main(){
    cin>>n>>h;
    h*=60;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<n;i++)cin>>c[i],sum[i]=sum[i-1]+c[i]*5;
    int now=1,maxn=0;
    for(int i=1;i<=n;i++){
        int ans=0;
        int H=h-sum[i-1];
        priority_queue<node>p;
        for(int j=1;j<=i;j++){
            p.push({j,a[j]});
        }
        while(H>=5){
            node tmp=p.top();
            p.pop();
            if(tmp.num>0)
            ans+=tmp.num;
            tmp.num-=b[tmp.id];
            H-=5;
            p.push(tmp);
        }
        maxn=max(ans,maxn);
    }
    cout<<maxn;
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}