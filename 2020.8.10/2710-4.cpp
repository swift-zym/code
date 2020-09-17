//
// Created by swift on 2020/8/10.
//

#include<bits/stdc++.h>
using namespace std;
int n,m,bel[1000001],num[1000001],a[1000001];
struct Change{
    int pos,col;
};
int tmp[1000001];
struct Query{
    int id,l,r,tim;
    bool operator <(const Query &t)const{
        if(bel[l]!=bel[t.l]){
            return bel[l]<bel[t.l];
        }
        if(bel[r]!=bel[t.r]){
            return bel[r]<bel[t.r];
        }
        return tim<t.tim;
    }
};
vector<Change>c;
vector<Query>q;
int ans;
void add(int x){
    if(num[x]++==0)ans++;
}
void del(int x){
    if(--num[x]==0)ans--;
}
void change(int idx,int x){
    //cout<<q[idx].l<<" "<<q[idx].r<<" "<<x<<" "<<c[x].pos<<endl;
    if(q[idx].l<=c[x].pos&&q[idx].r>=c[x].pos){
        del(a[c[x].pos]);
        add(c[x].col);
    }
    swap(a[c[x].pos],c[x].col);
}
int now,l=1,r=0;
int main(){
    scanf("%d%d",&n,&m);
    int siz=pow(n,3.0/4.0);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        bel[i]=i/siz;
    }
    for(int i=1;i<=m;i++){
        char opt=getchar();
        while(opt!='Q'&&opt!='R')opt=getchar();
        if(opt=='Q'){
            int l,r;
            scanf("%d%d",&l,&r);
            q.push_back({(int)q.size(),l,r,(int)c.size()});
        }
        else{
            int p,col;
            scanf("%d%d",&p,&col);
            c.push_back({p,col});
        }
    }
    sort(q.begin(),q.end());
    for(int i=0;i<q.size();i++){
        while(l<q[i].l){
            del(a[l++]);
        }
        while(l>q[i].l){
            add(a[--l]);
        }
        while(r<q[i].r){
            add(a[++r]);
        }
        while(r>q[i].r){
            del(a[r--]);
        }
        while(now<q[i].tim){
            change(i,now++);
        }
        //cout<<now<<" "<<q[i].tim<<endl;
        while(now>q[i].tim){
            change(i,--now);
        }
        tmp[q[i].id]=ans;
    }
    for(int i=0;i<q.size();i++){
        printf("%d\n",tmp[i]);
    }
    return 0;
}