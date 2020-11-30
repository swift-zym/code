#include<iostream>
#include<set>
using namespace std;
int T,n,a[1000001];
set<pair<int,int> >st;
void solve(){
    st.clear();
    for(int i=1;i<=n;i++)st.insert(make_pair(a[i],i));
    int num=-1;
    while(true){
        if(st.size()==2){
            st.erase(st.begin());
            if(num!=-1){
                printf("%d\n",num+(num-st.size())%2);
            }
            else{
                puts("1");
            }
            return;
        }
        auto tmp=st.end();tmp--;
        auto fir=st.begin();
        st.erase(tmp);st.erase(fir);
        st.insert(make_pair(tmp->first-fir->first,tmp->second));
        if(st.begin()->second!=tmp->second){
            if(num!=-1){
                printf("%d\n",num+(num-st.size())%2);
                return;
            }
        }
        else{
            if(num==-1)num=st.size();
        }
    }
}
int main(){
    scanf("%d",&T);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    solve();
    while(--T){
        int k;
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        solve();
    }
    return 0;
}