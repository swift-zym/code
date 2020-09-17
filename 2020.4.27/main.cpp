#include<bits/stdc++.h>
using namespace std;
struct http_request{
    int code;
    string message;
    //TODO:Add some information that is can be real send.
    void do_it(){
        puts("Start to send http request...");
        //TODO:Send This http request Really
        puts("Send http request finished...Stand by");
    }
}now_1,now_2;
int now_code;
struct http_test{
    http_request SendHttpCode(int code){
        if(code==404){
            return{404,"404 NOT FOUND"};
        }
        else if(code=403){
            return{403,"403 REFUSED"};
        }
        else{
            return{500,"500 SERVER ERROR"};
        }
    }
    int GetHttpCode(http_request hr){
        return hr.code;
    }
}now;
int main(){
    now_1=now.SendHttpCode(404);
    now_2=now.SendHttpCode(500);
    now_code=now.GetHttpCode(now_1);
    now_1.do_it();
    now_2.do_it();
    
    return 0;
}