//
// Created by swift on 2020/8/3.
//

#include<bits/stdc++.h>
using namespace std;
int T;
struct sta{
    int x,y;
    string s;
};
unordered_map<string,int>ma1,ma2,vis1,vis2;
string ss;
int sx,sy;
int decode(int x,int y){
    return x*5+y;
}
int mx[]={1,1,-1,-1,2,2,-2,-2};
int my[]={2,-2,2,-2,1,-1,1,-1};
string bas="111110111100*110000100000";
int main(){
    cin>>T;
    while(T--){
        ma1.clear();ma2.clear();vis1.clear();vis2.clear();
        ss="";
        queue<sta>q;
        for(int i=0;i<5;i++){
           string s;
           cin>>s;
           for(int j=0;j<5;j++){
               if(s[j]=='*'){
                   sx=i;sy=j;
               }
           }
           ss+=s;
        }
        vis1[ss]=1;
        q.push({sx,sy,ss});
        bool flag=0;
        while(!q.empty()){
            sta now=q.front();q.pop();
            //cout<<now.s<<" "<<ma1[now.s]<<endl;
            //cout<<">"<<now.x<<" "<<now.y<<endl;
            if(ma1[now.s]==8)continue;
            if(now.s==bas){
                flag=1;
                printf("%d\n",ma1[now.s]);
                break;
            }
            for(int i=0;i<=7;i++){
                int nx=now.x+mx[i],ny=now.y+my[i];
                if(nx<0||nx>4||ny<0||ny>4)continue;
                string ns=now.s;
                swap(ns[decode(now.x,now.y)],ns[decode(nx,ny)]);
                if(!vis1[ns]){
                    vis1[ns]=1;
                    ma1[ns]=ma1[now.s]+1;
                    q.push({nx,ny,ns});
                }
            }
        }
        //puts("---");
        vis2[bas]=1;
        q.push({2,2,bas});
        if(!flag)
        while(!q.empty()){
            sta now=q.front();q.pop();
            //cout<<now.s<<" "<<ma2[now.s]<<endl;
            if(ma2[now.s]==8)continue;
            if(vis1[now.s]){
                printf("%d\n",ma1[now.s]+ma2[now.s]);
                flag=1;
                break;
            }
            for(int i=0;i<=7;i++){
                int nx=now.x+mx[i],ny=now.y+my[i];
                if(nx<0||nx>4||ny<0||ny>4)continue;
                string ns=now.s;
                swap(ns[decode(now.x,now.y)],ns[decode(nx,ny)]);
                if(!vis2[ns]){
                    vis2[ns]=1;
                    ma2[ns]=ma2[now.s]+1;
                    q.push({nx,ny,ns});
                }
            }
        }
        if(!flag){
            puts("-1");
        }
    }
    return 0;
}