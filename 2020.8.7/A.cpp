//
// Created by swift on 2020/8/7.
//
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,jie[101],a[101],b[101],bb[101],i,j;
int main(){
    scanf("%lld%lld",&n,&m);
    jie[0]=1;
    for(i=1;i<n;i++)
        jie[i]=jie[i-1]*i;
    int tot=0;
    m=m-1;
    for(i=n-1;i>=0;i--){
        long long q=0,x=0,now;
        now=m/jie[i];
        m%=jie[i];
        for(j=1;j<=n;j++){
            if(bb[j]==0)++q;
            if(q==now+1){
                b[++tot]=j;
                break;
            }
        }
        bb[b[tot]]=1;
    }
    for(i=1;i<=n;i++)
        printf("%lld ",b[i]);
    return 0;
}
/*
Your Account Details

Your account is now active.
Main Hosting Details
Control panel username
frlm_26446921
Control panel password	**********
Control panel URL
cpanel.freela.ml
MySQL username
frlm_26446921
MySQL password
**********
MySQL hostname
sql100.freela.ml
FTP username
frlm_26446921
FTP password
**********
FTP host name	ftp.freela.ml


Your Website URL's
Home page
http://msannuoi.freela.ml
 */