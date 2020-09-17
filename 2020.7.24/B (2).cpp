//
// Created by swift on 2020/7/24.
//

#include<bits/stdc++.h>
using namespace std;

struct taxi{
    int a,dir;
    bool operator <(const taxi &t)const{
        return a<t.a;
    }
}a[100001];
vector<taxi>x,y;
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].a,&a[i].dir);
    }
    for(int i=1;i<=q;i++){
        int t,now;
        scanf("%d%d",&t,&now);
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(a[j].dir==a[now].dir){
                if(a[j].dir==1&&a[now].a>a[j].a){
                    x.push_back(a[j]);
                }
                else if(a[now].a<a[j].a){
                    x.push_back(a[j]);
                }
            }
            else{
                if(a[j].dir==1&&a[now].a>a[j].a){
                    y.push_back(a[j]);
                }
                else if(a[now].a<a[j].a){
                    y.push_back(a[j]);
                }
            }
            sort(x.begin(),x.end());
            sort(y.begin(),y.end());
            if(a[now].dir==1){
                int l=x.size()-1,r=0;
                int tim=0;
                for(;;){
                    if(a[now].dir==1){
                        while(r<y.size()&&a[now].a+tim>y[r].a)r++;
                        double nt=double(t+y[r].a-a[now].a-tim)/2;
                        if(nt>t){
                            printf("%d\n",a[now].a+(t-tim));
                        }
                    }
                    else{
                        while(l&&a[now].a+tim<x[l].a)l--;
                        double nt=double(a[now].a-tim-t+x[l].a)/2;
                        if(nt>t){
                            printf("%d\n",a[now].a-(t-tim));
                        }
                    }
                }
            }
        }
    }
}