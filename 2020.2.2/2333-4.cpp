#include<bits/stdc++.h>
using namespace std;
int nxt[10000001],_next[10000001];
string s,t;
void getNext(){
	nxt[0]=-1;
	for(int i=-1,j=1;j<t.length();j++){
		while(t[i+1]!=t[j]&&i!=-1)i=nxt[i];
		if(t[i+1]==t[j]){
			i++;
		}
		nxt[j]=i;
	}
}
stack<int>ss;
int main(){
	cin>>s>>t;
	getNext();

	for(int i=-1,j=0;j<s.length();j++){
		while(i!=-1&&s[j]!=t[i+1])i=nxt[i];
		if(s[j]==t[i+1])i++;
		_next[j]=i;
		ss.push(j);
		if(i==t.length()-1){
			for(int ii=1;ii<=t.length();ii++)ss.pop();
			if(ss.empty())i=-1;
			else i=_next[ss.top()];
		}
	}
	vector<int>ans;
	while(!ss.empty()){
		ans.push_back(ss.top());
		ss.pop();
	}
	for(int i=ans.size()-1;i>=0;i--){
		cout<<s[ans[i]];
	}
  putchar(10);
	return 0;
}
