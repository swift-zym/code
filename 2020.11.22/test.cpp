#include<bits/stdc++.h>
using namespace std;
int n,sum;
set<int>st;
int mi(){
    return *st.begin();
}
int mx(){
    auto tmp=st.end();
    tmp--;
    return *tmp;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        st.insert(a);
        sum+=a;
        if(i>=3)
        printf("%0.2lf\n",double(sum-mi()-mx())/(i-2));
    }
    return 0;
}