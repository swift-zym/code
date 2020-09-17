#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main(){
  struct tm* tmp_time=(struct tm*)malloc(sizeof(struct tm));
  strptime("20131120","%Y%m%d",tmp_time);
  time_t t=mktime(tmp_time);
  printf("%ld\n",t);
  return 0;
}
