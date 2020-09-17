#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX 501

int Dfn[MAX],vis[MAX],Low[MAX];
bool cut[MAX];
long long Num,Cut,Time,root,rs,m,n,Ans1,Ans2,Case,Group;

void Init();//多组数据，初始化

struct Node  //定义边
{
       int v,next;
}e[MAX*MAX];

int h[MAX],cnt;

void Add(int u,int v)  //添加边
{
      e[cnt]=(Node){v,h[u]};
      h[u]=cnt++;
}

void Tarjan(int u,int f)  //Tarjan跑出所有割点
{
       int v;
       Dfn[u]=Low[u]=++Time;

       for(int i=h[u];i!=-1;i=e[i].next)//枚举所有直接连接的点
       {
                v=e[i].v;
                if(!Dfn[v])  //如果没有访问过，证明v是u的子节点
                {
                       Tarjan(v,u);
                       Low[u]=min(Low[u],Low[v]); //更新Low值
                       if(Low[v]>=Dfn[u])  //如果v能够回到u或者u的祖先
                       {
                               if(u!=root)    //如果u不是子树的根节点
                                   cut[u]=true; //u是割点
                               else
                                   rs++;      //根节点子节点数增加
                       }
                }
                else
                   if(v!=f)    //如果v不是u的父节点，但是v已经访问过
                      Low[u]=min(Low[u],Dfn[v]);  //判断是否能够更新Low
       }
}

void DFS(int u)//DFS搜索一边联通块
{
        int v;

        vis[u]=Group; //标记组
        Num++;        //非割点数

        for(int i=h[u];i!=-1;i=e[i].next)//访问子节点
        {
               v=e[i].v;
               if(cut[v]&&vis[v]!=Group) //如果v是割点并且v没有在这个分组内被访问过
               {
                        Cut++;         //割点数增加
                        vis[v]=Group;  //标记分组
               }
               if(!vis[v])     //如果vis未被访问过
                   DFS(v);     //搜索v
        }
}

int main()
{
       long long u,v;
       Case=1;

       while(cin>>m&&m)
       {
              Init(); //初始化

           for(int i=1;i<=m;++i)//读入边
           {
                   cin>>u>>v;
                   Add(u,v);
                   Add(v,u);
                   n=max(n,v);
                   n=max(n,u);
           }

           for(int i=1;i<=n;++i)//Tarjan算法求割点
           {
                     if(!Dfn[i])
                     {
                              root=i;
                              rs=0;
                              Tarjan(i,i);
                              if(rs>=2)       //如果子树根节点的儿子数不少于2个，则这个根节点才是割点
                                  cut[i]=true;
                     }
           }

           for(int i=1;i<=n;++i)//枚举所有点来搜索分组
           {
                    cout<<cut[i]<<endl;
                    if(!vis[i]&&!cut[i])//如果i节点没有被访问过并且不是割点
                    {
                            ++Group;  //增加一个分组
                            Num=Cut=0;
                            DFS(i);   //搜索这个分组

                            if(Cut==0)//如果没有割点
                            {
                                      Ans1+=2;//至少需要建立两个出口
                                      Ans2*=(Num-1)*Num/2;//从任意非割点的地方选择两个点建立
                            }

                            if(Cut==1)//如果这个分组只有一个割点
                            {
                                Ans1+=1;  //只需要在分组内设立一个出口
                                Ans2*=Num;//可以设立在任意一个非割点的地方
                            }

                            if(Cut>=2)//如果有两个及以上个割点，则无需建立，可以直接到达其他联通块
                            {
                                ;
                        }
                    }
           }

           cout<<"Case "<<Case++<<": "<<Ans1<<" "<<Ans2<<endl;//输出结果
       }

       return 0;
}

void Init()
{
       memset(h,-1,sizeof(h));
       memset(Dfn,0,sizeof(Dfn));
       memset(Low,0,sizeof(Low));
       memset(cut,0,sizeof(cut));
       memset(vis,0,sizeof(vis));
       Time=cnt=n=Ans1=Group=0;
       Ans2=1;
}
