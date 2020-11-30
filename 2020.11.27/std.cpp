#include <bits/stdc++.h>
#define mid ((l+r)>>1)
#define ls l,mid,t<<1
#define rs mid+1,r,t<<1^1
#define N 300500
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
vector<int> E[N];
 
int n;
int dep[N], fa[N], siz[N], son[N], dfn[N], tp[N], tot;
 
int ag[4*N], ll, rr, v, opt;
 
struct Node{int lc,rc,sum;}tr[4*N], id;
Node operator+(Node p1, Node p2) {
	if (p2.lc == 0) return p1;
	if (p1.lc == 0) return p2;
	Node ret = id;
	ret.lc = p1.lc;
	ret.rc = p2.rc;
	ret.sum = p1.sum + p2.sum + (p1.rc!=p2.lc);
	return ret;
}
 
void push_down(int t) {
	if (!ag[t]) return ;
	tr[t<<1] = tr[t<<1^1] = (Node){ag[t], ag[t], 0};
	ag[t<<1] = ag[t<<1^1] = ag[t];
	ag[t] = 0;
}
 
Node build(int l,int r,int t) {
	return tr[t] = l==r ? (Node){-l,-l, 0} : build(ls) + build(rs);
}
 
Node query(int l,int r,int t) {
	if (l > rr || r < ll) return id;
	if (l >= ll && r <= rr) return tr[t];
	push_down(t);
	return query(ls) + query(rs);
}
 
void update(int l,int r,int t) {
	if (l > rr || r < ll) return ;
	if (l >= ll && r <= rr) {
		tr[t] = (Node){v,v,0};
		ag[t] = v;
		return ;
	}
	push_down(t);
	update(ls);
	update(rs);
	tr[t] = tr[t<<1] + tr[t<<1^1];
}
 
void dfs1(int u, int f) {
	siz[u] = 1;
	for (int i=0;i<(int)E[u].size();i++) {
		int v = E[u][i]; if (v == f) continue;
		dep[v]=dep[u]+1;
		fa[v]=u;
		dfs1(v, u);
		siz[u] += siz[v];
		if (!son[u] || siz[v] > siz[ son[u] ]) son[u] = v;
	}
}
 
void dfs2(int u, int f, int h) {
	dfn[u] = ++tot;
	tp[u] = h;
	if (son[u]) dfs2(son[u], u, h);
	for (int i=0;i<(int)E[u].size();i++) {
		int v = E[u][i];
		if (v == f || v == son[u]) continue;
		dfs2(v, u, v);
	}
}
 
void calc(int a, int b) {
	Node ansA = id, ansB = id;
	while(tp[a]!=tp[b]){
		if(dep[tp[a]] < dep[tp[b]]) {
			swap(a, b);
			swap(ansA, ansB);
		}
		
		ll = dfn[tp[a]], rr = dfn[a];
		a = fa[ tp[a] ];
		ansA = query(1, n, 1) + ansA;
	}
	
	
	if(dep[a] > dep[b]) {
		swap(a, b);
		swap(ansA, ansB);
	}
	ll=dfn[a], rr=dfn[b];
	ansB = query(1, n, 1) + ansB;
	
	swap(ansA.lc, ansA.rc);
	ansA = ansA + ansB;
	
	printf("%d\n", ansA.sum);
}
 
void walk(int a, int b) {
	v = ++opt;
	while(tp[a]!=tp[b]){
		if(dep[tp[a]] < dep[tp[b]]) swap(a, b);
		ll = dfn[tp[a]], rr = dfn[a];
		a = fa[ tp[a] ];
		update(1, n, 1);
	}
	
	if(dep[a] > dep[b]) swap(a, b);
	ll=dfn[a], rr=dfn[b];
	update(1, n, 1);
}
 
int main() { 
	n = rd();
	for (int i=1;i<n;i++) {
		int x = rd(), y = rd();
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	dfs1(1, 1);
	dfs2(1, 1, 1);
	fa[1] = 1;
 
	build(1, n, 1);
	
	for (int q=rd();q;q--) {
		int cmd = rd(), x = rd(), y = rd();
		if (cmd == 0) {
			calc(x, y);
		} else {
			walk(x, y);
		}
	}
	
	return 0;
}
