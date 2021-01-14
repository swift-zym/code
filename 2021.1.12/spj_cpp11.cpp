#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
int val;
bool is_red(int x){
    return (x<=9&&x%2)||(12<=x&&x<=18&&!x%2)||(19<=x&&x<=27&&x%2)||(30<=x&&!x%2);
}
bool is_black(int x){
    return !is_red(x);
}
void game_finish(int x){
    char result[100];
    sprintf(result,"|%d|%d",val,x);
    if(x<36)
    quitf(_wa,result);
    else
    quitf(_ok,result);
    exit(0);
}
int main(int argc,char *argv[]){
    registerTestlibCmd(argc,argv);
    val=ouf.readInt();
    if(!(val>=1&&val<=100)){
        quitf(_fail,"The value is illegal");
        return 0;
    }
    string str=ouf.readToken();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rand_num(seed);
    int id=rand_num()%36+1;
    while(!id)id=rnd.next()*36;
    for(auto &&c:str){
        if(c>='A'&&c<='Z'){
            c='a'+c-'A';
        }
    }
    if(str=="red"){
        if(is_red(id)){
            game_finish(2);
        }
        else{
            game_finish(0);
        }
    }
    if(str=="black"){
        if(is_black(id)){
            game_finish(2);
        }
        else{
            game_finish(0);
        }
    }
    if(str=="1st_12"){
        if(id>=1&&id<=12){
            game_finish(3);
        }
        else{
            game_finish(0);
        }
    }
    if(str=="2nd_12"){
        if(id>=13&&id<=24){
            game_finish(3);
        }
        else{
            game_finish(0);
        }
    }
    if(str=="3rd_12"){
        if(id>=25&&id<=36){
            game_finish(3);
        }
        else{
            game_finish(0);
        }
    }
    if(str=="1_to_18"){
        if(id>=1&&id<=18){
            game_finish(2);
        }
        else{
            game_finish(0);
        }
    }
    if(str=="19_to_36"){
        if(id>=18&&id<=36){
            game_finish(2);
        }
        else{
            game_finish(0);
        }
    }
    if(str=="odd"){
        if(id%2==1){
            game_finish(2);
        }
        else{
            game_finish(0);
        }
	}
    if(str=="even"){
        if(id%2==0){
            game_finish(2);
        }
        else{
            game_finish(0);
        }
	}
	for(auto c:str){
		if(c<'0'||c>'9'){
    		quitf(_fail,"The selected location is illegal");
			return 0;
		}
	}
    int number_id=stoi(str);
    if(number_id>=1&&number_id<=36){
        if(id==number_id){
            game_finish(36);
        }
        else{
            game_finish(0);
        }
    }
    quitf(_fail,"The selected location is illegal");
    return 0;
}