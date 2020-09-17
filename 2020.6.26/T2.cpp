//
// Created by swift on 2020/6/26.
//

#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,x;
int tmp[50],num[10000001];
int bas[33][50];
void pre(){
    for(int i=2;i<=32;i++){
        long long tmp=1;
        bas[i][0]=tmp;
        for(int j=1;j<=50;j++){
            tmp*=i;
            if(tmp>10000000)break;
            bas[i][j]=tmp;
        }
    }
}
int main(){
    pre();
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&x);
    for(int now=a;now<=b;now++) {
        for (int i = 0; i < now; i++)
            for (int j = 0; j < now; j++) {
                if(i==j)continue;
                for (int k = 0; k <= 49; k++) {
                    if (k % 2 == 0)tmp[k] = i;
                    else tmp[k] = j;
                }
                long long sum = 0;
                for (int k = 0; k <= 49; k++) {
                    if(bas[now][k]==0)break;
                    if((long long)(bas[now][k])*(long long)(tmp[k])>10000000)break;
                    sum+=bas[now][k]*tmp[k];
                    if(sum>10000000)break;
                    if(tmp[k]==0)continue;
                    if(sum==1){
                        cout<<">>"<<now<<" "<<k<<" "<<i<<" "<<j<<endl;
                    }
                    num[sum]++;
                }
            }
    }
    for(int i=c;i<=d;i++){
        if(num[i]==x){
            printf("%d\n",i);
        }
    }
    return 0;
}
/*
 * 5 6 1 10000000 2
 * >> 1
 */