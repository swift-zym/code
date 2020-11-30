#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
set<pair<int,int>>st;
int n,cnt;
struct candy{
    int id,s,t;
    bool operator <(const candy &c)const{
        return s<c.s;
    }
};
vector<candy>v,ans;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int s,t;
        scanf("%d%d",&s,&t);
        v.push_back({i,s,t});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        auto c=v[i];
        bool flag=1;
        auto it=st.lower_bound({c.t,0});
        if(it!=st.end()){
            if(abs(v[it->second].s-c.s)>abs(v[it->second].t-c.t)){
                flag=0;
            }
        }
        if(it!=st.begin()){
            it--;
            if(abs(v[it->second].s-c.s)>abs(v[it->second].t-c.t)){
                flag=0;
            }
        }
        if(flag){
            st.insert({c.t,i});
        }
        else{
            ++cnt;
            for(auto x:st){
                ans.push_back({cnt,v[x.second].s,v[x.second].t});
            }
            st.clear();
            st.insert({c.t,i});
        }
    }
    ++cnt;
    for(auto x:st){
        ans.push_back({cnt,v[x.second].s,v[x.second].t});
    }
    printf("%d\n",cnt);
    for(auto r:ans){
        printf("%d %d %d\n",r.s,r.t,r.id);
    }
    return 0;
}