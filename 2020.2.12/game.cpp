#include<bits/stdc++.h>
using namespace std;
void game_over();
int main()
{
    int i,a[1001],j;
    cout<<"真宗雷神出品，抄袭举报！"<<endl;
    cout<<"游戏开始"<<endl;
    cout<<"火柴人逃生总集版"<<endl;
    cout<<"1.新年囧事  2.雪山寻宝（实时更新，敬请期待）  3.丛林逃脱（实时更新，敬请期待）"<<endl;
    cout<<"4.火柴人神逃脱（实时更新，敬请期待）  5.密室逃脱（实时更新，敬请期待）"<<endl;
    cin>>i;
    if(i==1)
    {
        for(j=1;j<=100;j++)
        {
          cout<<"你打算怎么回乡？"<<endl;
          cout<<"1.柴程  2.飞人  3.飞机  4.冲浪"<<endl;
          cin>>a[1];
          if(a[1]==1)
          {
          cout<<"1.超快列车  2.普通  3.特等座"<<endl;
          cin>>a[2];
          }
          if(a[1]==2)
          {
          cout<<"在空中发现没有余额了，被飞人从空中扔了下来."<<endl;
          game_over();
          break;
          }
          if(a[1]==3)
          {
            cout<<"飞机坠毁,死亡！"<<endl;
            game_over();
            break;
          }
          if(a[1]==4)
          {
            cout<<"回到家都该吃元宵了！"<<endl;
            game_over();
            break;
          }
          if(a[2]==1||a[2]==3)
          {
            cout<<"没有钱！"<<endl;
            game_over();
            break;
          }
          if(a[2]==2)
          {
            cout<<"你在火车上遇到了强盗"<<endl;
            cout<<"1.躲厕所  2.躲车顶  3.装强盗"<<endl;
            cin>>a[3];
          }
          if(a[3]==1)
          {
            cout<<"厕所里有人，你被抓住了"<<endl;
            game_over();
            break;
          }
          if(a[3]==2)
          {
            cout<<"火车穿过隧道，你被撞死了"<<endl;
            game_over();
              break;
          }
          if(a[3]==3)
          {
            cout<<"你逃脱了强盗的追捕"<<endl;
            cout<<"1.继续装强盗  2.下车"<<endl;
            cin>>a[4];
          }
          if(a[4]==1)
          {
            cout<<"你被警察抓住了"<<endl;
            game_over();
            break;
          }
          if(a[4]==2)
          {
            cout<<"1.坐出租车回家  2.走路回家"<<endl;
            cin>>a[5];
          }
          if(a[5]==1)
          {
            cout<<"你会到了家"<<endl;
            cout<<"1.放鞭炮  2.吃大餐  3.吃饺子"<<endl;
            cin>>a[6];
          }
          if(a[5]==2)
          {
            cout<<"你家里火车站有150公里......"<<endl;
            game_over();
            break;
          }
          if(a[6]==1)
          {
            cout<<"难道你不知道不能放鞭炮吗？"<<endl;
            game_over();
            break;
          }
          if(a[6]==2)
          {
            cout<<"你吃撑死了"<<endl;
            game_over();
            break;
          }
          if(a[6]==3)
          {
            cout<<"1.吃光所有饺子  2.不吃饺子"<<endl;
            cin>>a[7];
          }
          if(a[7]==1)
          {
            cout<<"过年成功!!!"<<endl;
            game_over();
              break;
          }
          if(a[7]==2)
          {
            cout<<"你会饿死的"<<endl;
            game_over();
            break;
          }
        }
    }
}
void game_over(){
  cout<<"重新开始?:(Y/N)";
  char c=getchar();
  while(c!='Y'&&c!='N')c=getchar();
  if(c=='N')exit(0);
  system("clear");
  main();
}
