//题目名称：最大长方形
#include<bits/stdc++.h>
using namespace std;
struct tri{
    long long h;
    int id;
}wo[100005];
long long d[100005];
int main(){
    int n,i,j;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%lld",&d[i]);
    d[n+1]=0;
    wo[1].h=d[1];
    wo[1].id=1;
    int top=1;
    long long ans=0;
    for(i=2;i<=n+1;i++){
        if(d[i]>=wo[top].h){
            wo[++top].h=d[i];
            wo[top].id=i;
        }
        else{
            while(top>=0&&wo[top].h>d[i]){
                long long tmp=(i-wo[top].id)*wo[top].h;
                if(tmp>ans)ans=tmp;
                top--;
            }
            wo[++top].h=d[i];
            //wo[top].id=i;
        }
    }
    cout<<ans;
    #ifdef WIN32
	system("pause");
	#endif
    return 0;
}
