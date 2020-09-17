#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
bool np[501];
void preWork(){
    np[1]=1;
    for(int i=2;i<=500;i++){
        if(!np[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=500;j++){
            np[i*prime[j]]=1;
            if(prime[j]%i==0)break;
        }
    }
}
int get(int a){
    int ans=1;
    for(int i=0;i<prime.size();i++){
        int tmp=0;
        while(a%prime[i]==0){
            a/=prime[i];
            tmp++;
        }
        ans*=(tmp+1);
    }
    return ans;
}
int main(){
    preWork();
    int i=1,j=0;
    while(1){
        j+=i++;
        if(get(j)>500){
            cout<<j<<endl;
            #ifdef WIN32
            system("pause");
            #endif
            return 0;
        }
    }
    return 0;
}