#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
int head[101],nxt[2001],to[2001],len[2001],ans[101],vis[101];
void add(int a,int b,int l){
    nxt[++cnt]=head[a];
    to[cnt]=b;
    len[cnt]=l;
    head[a]=cnt;
}
bool cmp(int a,int b){
    return ans[a]<ans[b];
}
vector<int>food;
int val;
int main(){
    //freopen("cavecow.in","r",stdin);
    //freopen("cavecow.out","w",stdout);
    memset(ans,0,sizeof(ans));
    ans[1]=0x3f3f3f3f;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        int x;
        scanf("%d",&x);
        food.push_back(x);
        val+=(x==1);
    }
    for(int i=1;i<=m;i++){
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        add(a,b,l);add(b,a,l);
    }
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=head[now];i;i=nxt[i]){
            if(ans[to[i]]<min(ans[now],len[i])){
                ans[to[i]]=min(ans[now],len[i]);
                if(!vis[to[i]]){
                    vis[to[i]]=1;
                    q.push(to[i]);
                }
            }
        }
    }
    ans[1]=0;
    sort(food.begin(),food.end(),cmp);
    int now=0;
    for(auto i=food.begin();i!=food.end();i++){
        //cout<<*i<<" "<<ans[*i]<<endl;
        if(now<ans[*i]){
            now++;
        }
    }
    printf("%d\n",now+val);
    #ifdef WIN32
    system("pause");
    #endif
    return 0;
}