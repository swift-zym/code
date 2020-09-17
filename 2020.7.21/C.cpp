#include<iostream>
#include<vector>
using namespace std;
int t;
int n;
vector<int>ans;
int a[100001],b[100001];
void rev(int x){
  ans.push_back(x);
  int mid=x/2;
  for(int i=1;i<=x;i++)a[i]^=1;
  if(x%2==0)
  for(int i=1;i<=mid;i++){
    swap(a[i],a[mid+mid-i+1]);
  }
  else{
  mid++;
  for(int i=1;i<=mid;i++){
    swap(a[i],a[mid-i+mid]);
  }
  }
}
int main(){
  scanf("%d",&t);
  while(t--){
    ans.clear();
    scanf("%d",&n);
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
      a[i]=s[i-1]-'0';
    }
    cin>>s;
    for(int i=1;i<=n;i++){
      b[i]=s[i-1]-'0';
    }
    for(int i=n;i>=1;i--){
      if(a[i]==b[i])continue;
      if(a[1]==b[i])rev(1);
      /*for(int j=1;j<=n;j++){
        cout<<a[j];
      }
      cout<<endl;*/
      rev(i);
      /*for(int j=1;j<=n;j++){
        cout<<a[j];
      }
      cout<<endl;*/
    }
    /*for(int i=1;i<=n;i++){
      if(a[i]!=b[i]){
        puts("err");
        return 0;
      }
    }*/
    printf("%d ",int(ans.size()));
    for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
    printf("\n");
  }
  return 0;
}
/*
01011
11100
11011
00100
10100
01000
*/
