//
// Created by swift on 2020/8/9.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[11],y[11],q[11];
int n=100,m=17,z=9;
signed main(){
    srand(time(0));
    for(int t=1;t<=100;t++){
        int mi=1e18,posx,posy;
        for(int i=1;i<=m;i++){
            x[i]=rand()%n+1;y[i]=rand()%n+1;
            q[i]=rand()%10+1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                int ans=0;
                for(int k=1;k<=m;k++){
                    ans+=q[k]+(abs(i-x[k])+abs(j-y[k]))*z;
                }
                if(ans<mi){
                    mi=ans;
                    posx=i;posy=j;
                }
            }
        bool flag=0;
        for(int i=1;i<=m;i++){
            if(posx==x[i]&&posy==y[i])flag=1;
        }
        if(flag){
            puts("Accept");
        }
        else{
            cout<<n<<" "<<m<<" "<<z<<endl;
            for(int i=1;i<=m;i++){
                cout<<x[i]<<" "<<y[i]<<" "<<q[i]<<endl;
            }
            cout<<"Answer="<<posx<<" "<<posy<<endl;
            cout<<mi<<endl;
            puts("WrongAnswer");
            cin>>n;
            return 0;
        }
    }
    return 0;
}