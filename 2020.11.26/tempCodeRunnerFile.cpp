
struct s{
    int l,r,v;
    bool operator <(const s &t)const{
        return v>t.v;
    }
};
int vis[1000];
vector<s>v;